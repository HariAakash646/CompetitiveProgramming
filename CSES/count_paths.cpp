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
vi dp, rem;
vvi path;
vvi lift;
vi depth;

void dfs1(int x, int p, int d) {
    depth[x] = d;
    lift[0][x] = p;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs1(e, x, d+1);
        }
    }
}

int binlift(int x, int c) {
    frange(i, 20) {
        if(c & (1<<i)) x = lift[i][x];
    }
    return x;
}

int lca(int u, int v) {
    if(depth[v] > depth[u]) swap(u, v);
    u = binlift(u, depth[u] - depth[v]);

    if(u == v) return u;

    for(int i=19; i>=0; i--) {
        int ut = lift[i][u];
        int vt = lift[i][v];
        if(ut != vt) {
            u = ut;
            v = vt;
        }
    }
    return lift[0][u];
}

void dfs(int x, int p) {
    for(auto e : path[x]) {
        dp[x]++;
        dp[e]--;
    }
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x);
            dp[x] += dp[e];
        }
    }
}

int main() {
    // usaco();

    int n;
    scd(n);
    graph = path = vvi(n+1);
    int m;
    scd(m);

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    lift = vvi(20, vi(n+1));
    depth = vi(n+1);

    dfs1(1, 0, 0);

    forr(i, 1, 20) {
        forr(j, 1, n+1) {
            lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }

    rem = vi(n+1);

    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        int l = lca(a, b);
        path[a].pb(l);
        path[b].pb(l);
        rem[l]++;
    }


    dp = vi(n+1);
    dfs(1, 0);

    forr(i, 1, n+1) printf("%d ", dp[i]+rem[i]);
}