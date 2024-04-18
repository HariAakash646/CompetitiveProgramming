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
vii par;
vvi lift;
vi depth;
vii edg;
map<pii, int> med;

void dfs(int x, int p, int d) {
    depth[x] = d;
    if(p != 0) {
        par[x] = mp(p, med[mp(x, p)]);
        lift[0][x] = p;
    } 

    for(auto e : graph[x]) {
        if(e != p) dfs(e, x, d+1);
    }
}

int binlift(int x, int k) {
    frange(i, 20) {
        if(k & (1<<i)) {
            x = lift[i][x];
        }
    }
    return x;
}

int lca(int u, int v) {
    if(depth[u] > depth[v]) swap(u, v);
    v = binlift(v, depth[v]-depth[u]);
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

seti curr;

void dfs2(int x, int l) {
    if(depth[x] <= depth[l]) return;
    if(par[x].s != -1) curr.insert(par[x].s);
    dfs2(par[x].f, l);
    par[x] = mp(l, -1);
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);

    graph = vvi(n+1);

    edg = vii(m);

    frange(i, m) {
        scd(edg[i].f);
        scd(edg[i].s);
        if(edg[i].s < edg[i].f) swap(edg[i].f, edg[i].s);
        med[edg[i]] = i;
        med[mp(edg[i].s, edg[i].f)] = i;
    }

    vb tree(m);

    frange(i, n-1) {
        int id;
        scd(id);
        id--;
        graph[edg[id].f].pb(edg[id].s);
        graph[edg[id].s].pb(edg[id].f);
        tree[id] = true;
    }

    lift = vvi(20, vi(n+1));
    par = vii(n+1);
    depth = vi(n+1);
    dfs(1, 0, 0);

    forr(i, 1, 20) {
        forr(j, 1, n+1) {
            lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }

    vi pos(m, -1);
    seti st;

    forr(i, 1, m+1) st.insert(i);
    frange(i, m) {
        if(tree[i]) {
            if(pos[i] != -1) continue;
            pos[i] = *st.begin();
            st.erase(st.begin());
        }
        else {
            if(pos[i] != -1) continue;
            curr = {};
            int l = lca(edg[i].f, edg[i].s);
            dfs2(edg[i].f, l);
            dfs2(edg[i].s, l);
            for(auto e : curr) {
                if(pos[e] != -1) continue;
                pos[e] = *st.begin();
                st.erase(*st.begin());
            }
            pos[i] = *st.begin();
            st.erase(st.begin());
        }
    }

    frange(i, m) printf("%d ", pos[i]);
}