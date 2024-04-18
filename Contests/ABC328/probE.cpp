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

vvi graph; 
vb vis;

void dfs(int x) {
    if(vis[x]) return;
    vis[x] = true;
    for(auto e : graph[x]) dfs(e);
}

int main() {
    // usaco();
    int n, m;
    lli k;
    scd(n);
    scd(m);
    sclld(k);

    vector<pair<pii, lli>> edges;

    frange(i, m) {
        int a, b;
        lli w;
        scd(a);
        scd(b);
        sclld(w);
        edges.pb(mp(mp(a, b), w));
    }
    lli mi = 1e18;
    frange(i, 1<<m) {
        if(__builtin_popcount(i) == n-1) {
            graph = vvi(n+1);
            lli tot = 0;
            frange(j, m) {
                if(i & (1<<j)) {
                    graph[edges[j].f.f].pb(edges[j].f.s);
                    graph[edges[j].f.s].pb(edges[j].f.f);
                    tot += edges[j].s;
                    tot %= k;
                }
            }
            if(tot < mi) {
                vis = vb(n+1);
                dfs(1);
                bool done = true;
                forr(i, 1, n+1) {
                    if(!vis[i]) done = false;
                }
                if(done) mi = tot;
            }
        }
    }
    printf("%lld", mi);
}