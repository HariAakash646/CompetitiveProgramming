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

struct Data {
    lli nn=0, yy=0, ny=0, yn=0;
};

template <class T>
struct SegTree
{
    int size = 1, n;
    vector<T> segtree;
    vector<T> vec;

    T def; // Assign a value

    void init(int l, T defv)
    {
        n = l;
        def = defv;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, def);
        vec.assign(size, def);
    }

    T operation(T x, T y)
    { 
        if(x.yy < 0) return y;
        if(y.yy < 0) return x;
        T out;
        out.nn = max(x.nn+y.yn, x.ny+y.nn);
        out.ny = max(x.ny+y.ny, x.nn + y.yy);
        out.yn = max(x.yn + y.yn, x.yy + y.nn);
        out.yy = max(x.yy + y.ny, x.yn + y.yy);
        // out.ny = max(out.nn, out.ny);
        // out.yn = max(out.nn, out.yn);
        // out.yy = max({out.yy, out.ny, out.yn});
        return out;
    }

    void recalculate(int x)
    {
        segtree[x] = operation(segtree[2 * x + 1], segtree[2 * x + 2]);
    }

    void build(int x, int l, int r)
    {
        if (l == r)
        {
            segtree[x] = vec[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * x + 1, l, mid);
        build(2 * x + 2, mid + 1, r);
        recalculate(x);
    }

    void build()
    {
        build(0, 0, size - 1);
    }

    void set(int id, T val)
    {
        vec[id] = val;
    }

    void update(int x, int l, int r, int id, T val)
    {
        if (l == r)
        {
            segtree[x] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (id <= mid)
        {
            update(2 * x + 1, l, mid, id, val);
        }
        else
        {
            update(2 * x + 2, mid + 1, r, id, val);
        }
        recalculate(x);
    }

    void update(int id, T val)
    {
        update(0, 0, size - 1, id, val);
    }

    T query(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            return def;
        }
        if (lx <= l && r <= rx)
        {
            return segtree[x];
        }
        int mid = (l + r) / 2;
        T v1 = query(2 * x + 1, l, mid, lx, rx);
        T v2 = query(2 * x + 2, mid + 1, r, lx, rx);
        return operation(v1, v2);
    }

    T query(int lx, int rx)
    {
        if(rx < lx) {
            T tmp;
            return tmp;
        }
        return query(0, 0, size - 1, lx, rx);
    }
};

vll vec;
vvi graph;
vvi lift;
vi depth;

void dfs(int x, int p) {
    depth[x] = depth[p]+1;
    lift[0][x] = p;
    for(auto e : graph[x]) {
        if(e != p) dfs(e, x);
    }
}

int binlift(int x, int c) {
    frange(i, 20) {
        if(c & (1<<i)) x = lift[i][x];
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

vvi val;
vii quer;

map<pii, pair<lli, lli>> out;

SegTree<Data> seg;
int id=0;

void dfs2(int x, int p) {
    Data tmp;
    tmp.ny = tmp.yn = tmp.nn = 0;
    tmp.yy = vec[x];
    seg.update(id, tmp);
    

    for(auto l : val[x]) {
        Data v = seg.query(id-(depth[x] - depth[l] - 1), id);
        out[mp(x, l)] = mp(max({v.yy, v.yn, v.ny, v.nn}), max(v.ny, v.nn));
    }

    id++;

    for(auto e : graph[x]) {
        if(e != p) dfs2(e, x);
    }
    id--;
    tmp.yy = tmp.ny = tmp.yn = tmp.nn= -1e16;
    seg.update(id, tmp);
    
}
 
int main() {
    // usaco();
    int n, q;
    scd(n);
    scd(q);

    vec = vll(n+1);

    forr(i, 1, n+1) sclld(vec[i]);

    graph = vvi(n+1);
    lift = vvi(20, vi(n+1));

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    depth = vi(n+1);

    dfs(1, 0);
    forr(i, 1, 20) {
        forr(j, 1, n+1) lift[i][j] = lift[i-1][lift[i-1][j]];
    }

    quer = vii(q);
    val = vvi(n+1);

    frange(i, q) {
        int u, v;
        scd(u);
        scd(v);
        quer[i] = mp(u, v);
        int l = lca(u, v);
        val[u].pb(l);
        val[v].pb(l);
    }
    Data tmp;
    tmp.yy = tmp.ny = tmp.yn = tmp.nn= -1e16;
    seg.init(n+1, tmp);
    seg.build();

    dfs2(1, 0);

    for(auto p : quer) {
        int u = p.f;
        int v = p.s;
        int l = lca(u,v);
        auto v1 = out[mp(u, l)];
        auto v2 = out[mp(v, l)];
        printf("%lld\n", max(v1.f + v2.f, v1.s + v2.s + vec[l]));
        // printf("%lld %lld %lld %lld %lld\n", v1.f, v1.s, v2.f, v2.s, vec[l]);
    }
}