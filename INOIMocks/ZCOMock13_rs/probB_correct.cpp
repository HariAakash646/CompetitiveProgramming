#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;
typedef multiset<int> mseti;

void usaco() {
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

int main() {
    // usaco();
    int n, m, k;
    scd(n);
    scd(m);
    scd(k);
    vector<vector<pair<int, lli>>>  graph(n+1);

    frange(i, m) {
        int a, b;
        lli c;
        scd(a);
        scd(b);
        sclld(c);
        graph[a].pb(mp(b, c));
        graph[b].pb(mp(a, c));
    }

    vi pos(n+1, -1);
    vi key(n+1, -1);
    vi val(n+1, -1);
    vi inv(2*k+2);
    vi unl(n+1);
    val[1] = 0;
    val[n] = 1;
    inv[0] = 1;
    inv[1] = n;
    frange(i, k) {
        int l, u;
        scd(l);
        scd(u);
        pos[u] = i;
        key[l] = i;
        val[l] = 2 * (i+1);
        val[u] = 2 * (i+1) + 1;
        unl[l] = u;
        inv[2*(i+1)] = l;
        inv[2*(i+1)+1] = u;
    }

    vector<vll> dist(2*k+2, vll(n+1, 1e18));
    
    frange(i, 2*k+2) {
        int x = inv[i];
        dist[i][x] = 0;
        vb vis(n+1);
        priority_queue<pair<lli, int>> pq;
        pq.push(mp(0, x));

        while(pq.size()) {
            auto p = pq.top();
            pq.pop();
            if(vis[p.s]) continue;
            vis[p.s] = true;

            for(auto e : graph[p.s]) {
                
                if(-p.f + e.s < dist[i][e.f]) {
                    dist[i][e.f] = -p.f + e.s;
                    if(pos[e.f] == -1 || unl[x] == e.f)
                        pq.push(mp(-dist[i][e.f], e.f));
                }
                
            }
        }
    }

    vector<vll> dist2(2*k+2, vll(1<<k, 1e18));
    vector<vb> vis(2*k+2, vb(1<<k));
    priority_queue<pair<lli, pii>> pq;

    pq.push(mp(0, mp(0, 0)));
    dist2[0][0] = 0;

    while(pq.size()) {
        auto p = pq.top();
        pq.pop();
        if(vis[p.s.f][p.s.s]) continue;
        
        vis[p.s.f][p.s.s] = true;
        int x = inv[p.s.f];
        // printf("%d\n", x);
        int un = p.s.s;
        if(x == n) {
            printf("%lld", -p.f);
            return 0;
        }
        if(key[x] != -1) {
            un = un | (1<<key[x]);
        }

        frange(i, 2*k+2) {
            int e = inv[i];
            if(pos[e] != -1) {
                if(!(un & (1<< pos[e]))) continue;
            }
            if(-p.f + dist[p.s.f][e] < dist2[i][un]) {
                dist2[i][un] = -p.f + dist[p.s.f][e];
                pq.push(mp(-dist2[i][un], mp(i, un)));
            }
        }
    }
    printf("-1");

}