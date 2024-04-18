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
vi depth, sze;
vvi binlift;

void dfs(int x, int p, int d) {
    depth[x] = d;
    binlift[0][x] = p;
    sze[x] = 1;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x, d+1);
            sze[x] += sze[e];
        }
    }
    // printf("%d %d\n", x, sze[x]);
} 

int lift(int x, int c) {
    frange(i, 20) {
        if(c & (1<<i)) {
            x = binlift[i][x];
        }
    }
    return x;
}

int lca(int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);
    u = lift(u, depth[u] - depth[v]);

    if(u == v) return u;

    for(int i=19; i>=0; i--) {
        int ut = binlift[i][u];
        int vt = binlift[i][v];
        if(ut != vt) {
            u = ut;
            v = vt;
        }
    }
    return binlift[0][u];
}

int main() {
    // usaco();
    int n;
    scd(n);

    graph = vvi(n+1);

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    sze = depth = vi(n+1);
    binlift = vvi(20, vi(n+1));

    dfs(1, 0, 0);

    forr(i, 1, 20) {
        forr(j, 1, n+1) {
            binlift[i][j] = binlift[i-1][binlift[i-1][j]];
        }
    }

    int m;
    scd(m);

    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        int l = lca(a, b);
        if(depth[a] > depth[b]) swap(a, b);
        int v1 = depth[a] - depth[l];
        int v2 = depth[b] - depth[l];
        int c = (v1 + 1) + v2;
        // printf("%d ", c);
        if(c % 2) {
            int x = (c + 1)/2 - 1;
            int v = lift(b, x);
            int u = lift(b, x-1);
            int tot = sze[v] - sze[u];
            if(depth[a] == depth[b]) {
                tot += (n - sze[v]) - sze[lift(a, x-1)];
            }
            printf("%d\n", tot);
        }
        else printf("0\n");
    }
}