#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

typedef tree<
int,
null_type,
less_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

int n, k1, k2;
vvi graph, cent;
vb vis;
vi sze;
vi dist;

int find_sze(int x, int p) {
    sze[x] = 1;
    for(auto e : graph[x]) {
        if(!vis[e] && e != p) {
            sze[x] += find_sze(e, x);
        }
    }
    return sze[x];
} 

int find_cent(int x, int p, int n) {
    for(auto e : graph[x]) {
        if(e != p) {
            if(!vis[e] && sze[e] > n/2) {
                return find_cent(e, x, n);
            }
        }
    }
    return x;
}


int init_cent(int x, int p) {
    find_sze(x, 0);

    int c = find_cent(x, 0, sze[x]);
    vis[c] = true;
    if(p) {
        cent[p].pb(c);
        cent[c].pb(p);
    }

    for(auto e : graph[c]) {
        if(!vis[e]) {
            init_cent(e, c);
        }
    }
    return c;
} 

vvi lift;

void dfs(int x, int p, int d) {
    dist[x] = d;
    lift[0][x] = p;

    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x, d+1);
        }
    }
}

int binlift(int x, int c) {
    frange(i, 20) {
        if(c & (1<<i)) {
            x = lift[i][x];
        }
    }
    return x;
}

int lca(int u, int v) {
    if(dist[u] > dist[v]) swap(u, v);

    v = binlift(v, dist[v] - dist[u]);
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

int distf(int u, int v) {
    int l = lca(u, v);
    return dist[u] + dist[v] - 2 * dist[l];
}

vector<ordered_set> val;
vvi child;
lli tot = 0;

void compute(int x, int p) {
    val[x].insert(0);
    child[x].pb(x);
    for(auto e : cent[x]) {
        if(e != p) {
            compute(e, x);
            for(auto v : child[e]) {
                int d = distf(v, x);
                int kt1 = k1 - d;
                int kt2 = k2 - d;
                tot += val[x].order_of_key(kt2+1) - val[x].order_of_key(kt1);
                child[x].pb(v);
            }
            for(auto v : child[e]) val[x].insert(distf(v, x));

        }
    }
}

int main() {
    // usaco();
    scd(n);
    scd(k1);
    scd(k2);

    cent = graph = vvi(n+1);

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    sze = dist = vi(n+1);
    lift = vvi(20, vi(n+1));

    dfs(1, 0, 0);

    forr(i, 1, 20) {
        forr(j, 1, n+1) {
            lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }

    vis = vb(n+1);

    int c = init_cent(1, 0);

    // printf("%d " ,c);
    child = vvi(n+1);
    val = vector<ordered_set>(n+1);
    compute(c, 0);

    printf("%lld", tot);





}