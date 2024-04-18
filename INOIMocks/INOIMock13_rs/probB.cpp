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
 
void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

vvi liftv;
vvi graph;
vi depth;

void dfs(int x, int p) {
    depth[x] = depth[p] + 1;
    liftv[0][x] = p;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x);
        }
    }
}

int lift(int x, int c) {
    frange(i, 20) {
        if(c & (1<<i)) {
            x = liftv[i][x];
        }
    }
    return x;
}

int lca(int x, int y) {
    if(depth[y] > depth[x]) swap(x, y);
    x = lift(x, depth[x] - depth[y]);
    if(x == y) return x;
    for(int i=19; i>=0; i--) {
        int xt = liftv[i][x];
        int yt = liftv[i][y];
        if(xt != yt) {
            x = xt;
            y = yt;
        }
    }
    return liftv[0][x];
}

vvi st;
vvi lc;
vll cost;
lli tot = 0;
vii pos;
vector<pair<map<int, lli>, lli>> val;

void dfs2(int x, int p) {
    val[x].f[x] = 0;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs2(e, x);
            if(val[x].f.size() < val[e].f.size()) swap(val[x], val[e]);
            for(auto pi : val[e].f) {
                val[x].f[pi.f] += pi.s + val[e].s - val[x].s;
            }
        }
    }
    lli ma = -1e18;
    
    // printf("%d\n", x);
    // for(auto e : mv) {
    //     printf("%d %lld\n", e.f, e.s);
    // }
    for(auto e : lc[x]) {
        ma = max(ma, val[x].f[pos[e].f] + val[x].f[pos[e].s] + 2*val[x].s + cost[e]);
    }
    
    if(ma > 0) {
        tot += ma;
        val[x].s -= ma;
    }
    
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
    depth = vi(n+1);
    liftv = vvi(20, vi(n+1));
    dfs(1, 0);
    

    forr(i, 1, 20) {
        forr(j, 1, n+1) {
            liftv[i][j] = liftv[i-1][liftv[i-1][j]];
        }
    }

    st = lc = vvi(n+1);
    int m;
    scd(m);
    cost = vll(m);
    pos = vii(m);
    forr(i, 0, m) {
        int a, b;
        scd(a);
        scd(b);
        sclld(cost[i]);
        lc[lca(a, b)].pb(i);
        st[a].pb(i);
        st[b].pb(i);
        pos[i] = mp(a, b);
    }

    val = vector<pair<map<int, lli>, lli>>(n+1);

    dfs2(1, 0);
    printf("%lld", tot);
}   