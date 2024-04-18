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
    frange(i, k) {
        int l, u;
        scd(l);
        scd(u);
        pos[u] = i;
        key[l] = i;
    }

    vector<map<int, lli>> dist(n+1);
    vector<vb> vis(n+1, vb(1<<k));

    priority_queue<pair<lli, pii>> pq;
    pq.push(mp(0, mp(1, 0)));
    dist[1][0] = 0;
    int cnt = 0;
    int scam = 1e6;
    while(pq.size()) {
        auto p = pq.top();
        pq.pop();
        dist[p.s.f].erase(p.s.s);
        if(vis[p.s.f][p.s.s]) continue;
        cnt++;
        if(cnt > scam) break;
        vis[p.s.f][p.s.s] = true;
        int x = p.s.f;
        int un = p.s.s;
        // printf("%d\n", x);
        if(x == n) {
            printf("%lld", -p.f);
            return 0;
        }
        if(key[x] != -1) {
            un = un | (1<<key[x]);
        }

        for(auto e : graph[x]) {
            if(pos[e.f] != -1) {
                if(!(un & (1<< pos[e.f]))) continue;
            }
            if(dist[e.f].find(un) == dist[e.f].end()) dist[e.f][un] = 1e18;
            if(-p.f + e.s < dist[e.f][un]) {
                dist[e.f][un] = -p.f + e.s;
                pq.push(mp(-dist[e.f][un], mp(e.f, un)));
            }
        }
    }
    printf("-1");
}