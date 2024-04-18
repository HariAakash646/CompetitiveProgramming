#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;


void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

int main() {
    // usaco();
    int n, m, k;
    scd(n);
    scd(m);
    scd(k);

    vvi graph(k+2);

    map<pii, int> mpos;
    vvi row(n+1);
    vvi col(m+1);
    vii coord(k+2);
    vb on(k+2);
    bool last = true;
    int lid = k+1;
    forr(i, 1, k+1) {
        int a, b;
        scd(a);
        scd(b);
        mpos[mp(a, b)] = i;
        if(mpos.find(mp(a+1, b)) != mpos.end()) {
            int v = mpos[mp(a+1, b)];
            graph[i].pb(v);
            graph[v].pb(i);
        }
        if(mpos.find(mp(a, b+1)) != mpos.end()) {
            int v = mpos[mp(a, b+1)];
            graph[i].pb(v);
            graph[v].pb(i);
        }
        if(mpos.find(mp(a-1, b)) != mpos.end()) {
            int v = mpos[mp(a-1, b)];
            graph[i].pb(v);
            graph[v].pb(i);
        }
        if(mpos.find(mp(a, b-1)) != mpos.end()) {
            int v = mpos[mp(a, b-1)];
            graph[i].pb(v);
            graph[v].pb(i);
        }

        row[a].pb(i);
        col[b].pb(i);
        coord[i] = mp(a, b);
        on[i] = true;
        if(a == n && b == m) {
            last = false;
            lid = i;
        }
    }
    
    if(last) {row[n].pb(k+1);
        col[m].pb(k+1);
        coord[k+1] = mp(n, m);}

    deque<pii> dq;
    vb vis(k+2);
    dq.push_back(mp(1, 0));
    vi dist(k+2, 1e9);
    dist[1] = 0;
    while(dq.size()) {
        auto p = dq.front();
        dq.pop_front();
        if(vis[p.f]) continue;
        vis[p.f] = true;
        for(auto e : graph[p.f]) {
            if(p.s < dist[e]) {
                dist[e] = p.s;
                dq.push_front(mp(e, p.s));
            }
        }
        int x = coord[p.f].f;
        int y = coord[p.f].s;
        for(int i=-2; i<=2; i++) {
            if(x + i >= 0 && x + i <= n) {
                for(auto e : row[x+i]) {
                    if(abs(i) == 2 && !on[e]) continue;
                    if(p.s + 1 < dist[e]) {
                        dist[e] = p.s+1;
                        dq.push_back(mp(e, p.s+1));
                    }
                }
            } 
        }

        for(int i=-2; i<=2; i++) {
            if(y + i >= 0 && y + i <= m) {
                for(auto e : col[y+i]) {
                    if(abs(i) == 2 && !on[e]) continue;
                    if(p.s + 1 < dist[e]) {
                        dist[e] = p.s+1;
                        dq.push_back(mp(e, p.s+1));
                    }
                }
            } 
        }

    }

    if(dist[lid] < 1e9) printf("%d", dist[lid]);
    else printf("-1");

}