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
 
int n, d;
vvi graph;
vi sze;
 
void dfs1(int x, int p) {
    sze[x] = 1;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs1(e, x);
            sze[x] += sze[e];
        }
    }
}
 
int cent(int x, int p) {
    for(auto e : graph[x]) {
        if(e != p) {
            if(sze[e] > n/2) {
                return cent(e, x);
            }
        }
    }
    return x;
}
 
vi par, depth;
vii leav;
 
void dfs2(int x, int p, int d) {
    depth[x] = d;
    par[x] = p;
    if(graph[x].size() <= 1) {
        leav.pb(mp(d, x));
    }
    for(auto e : graph[x]) {
        if(e != p) {
            dfs2(e, x, d+1);
        }
    }
}
 
int main() {
    // usaco();
    scd(n);
    scd(d);
 
    graph = vvi(n+1);
 
    forr(i, 2, n+1) {
        int x;
        scd(x);
        x++;
        graph[x].pb(i);
        graph[i].pb(x);
    }
 
    sze = vi(n+1);
    dfs1(1, 0);
 
    int c = cent(1, 0);
 
    depth = par = vi(n+1);
    dfs2(c, 0, 1);
 
    sort(all(leav), greater<>());
 
    priority_queue<pii> pq;
    for(auto p : leav) pq.push(p);
 
    vi dist(n+1, 1e9);
    vi out;
    while(pq.size()) {
        auto p = pq.top();
        pq.pop();
 
        int x = p.s;
 
        out.pb(x);
        int v = 0;
        while(x) {
            if(dist[x] + v < d) {
                out.pop_back();
                break;
            }
            dist[x] = min(dist[x], v);
            v++;
            x = par[x];
            if(v >= d && x) {
                pq.push(mp(depth[x], x));
                break;
            }
        }
    }
 
    printf("%d\n", (int)out.size());
    // for(auto e : out) printf("%d ", e);
 
}