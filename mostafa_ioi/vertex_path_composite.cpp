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

const lli mod = 998244353;

struct Data {
    pair<lli, lli> lv=mp(1, 0);
    pair<lli, lli> rv=mp(1, 0);
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
        T out;
        out.lv = mp(x.lv.f * y.lv.f % mod, (x.lv.f * y.lv.s + x.lv.s)%mod);
        out.rv = mp(x.rv.f * y.rv.f % mod, (y.rv.f * x.rv.s + y.rv.s)%mod);
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
        return query(0, 0, size - 1, lx, rx);
    }
};

vi sze;
vector<Data> val;
vi heavy, head, pos, depth, par;

vvi graph, lift;

SegTree<Data> segtree;

int dfs_sze(int x, int p) {
    sze[x] = 1;
    depth[x] = depth[p] + 1;
    par[x] = p;
    lift[0][x] = p;
    int ma = 0;

    for(auto e : graph[x]) {
        if(e != p) {
            int sz = dfs_sze(e, x);
            sze[x] += sz;
            if(sz > ma) {
                ma = sz;
                heavy[x] = e;
            }
        }
    }

    return sze[x];
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


int id = 0;

void decompose(int x, int h, int p) {
    // printf("%d\n", x);
    head[x] = h;
    pos[x] = id++;
    segtree.set(pos[x], val[x]);
    if(heavy[x])
        decompose(heavy[x], h, x);

    for(auto e : graph[x]) {
        if(e != p && e != heavy[x]) {
            decompose(e, e, x);
        } 
    }

}

void init(int n) {
    Data tmp;
    segtree.init(n, tmp);
    par = depth = head = pos = heavy = sze = vi(n+1);
    dfs_sze(1, 0);
    decompose(1, 1, 0);
    segtree.build();
}

Data query(int a, int b) {
    Data out;
    while(head[a] != head[b]) {
        // printf("")
        if(depth[head[a]] > depth[head[b]]) swap(a, b);
        out = segtree.operation(segtree.query(pos[head[b]], pos[b]), out);
        b = par[head[b]];
    }
    if(pos[a] > pos[b]) swap(a, b);
    out = segtree.operation(segtree.query(pos[a], pos[b]), out);
    return out;
}

int main() {
    // usaco();
    int n, q;
    scd(n);
    scd(q);
    val = vector<Data>(n+1);

    forr(i, 1, n+1) {
        lli a, b;
        sclld(a);
        sclld(b);
        val[i].rv = val[i].lv = mp(a, b);
    }
    graph = vvi(n+1);
    lift = vvi(20, vi(n+1));

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        a++;
        b++;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    init(n);

    forr(i, 1, 20) {
        forr(j, 1, n+1) {
            lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }

    frange(_, q) {
        int t;
        scd(t);
        if(t) {
            int a, b;
            scd(a);
            scd(b);
            a++;
            b++;
            lli x;
            sclld(x);
            int l = lca(a, b);
            pair<lli, lli> out = mp(1, 0);
            if(l == b) {
                out = query(a, l).lv;
            }
            else if(l == a) {
                out = query(b, l).rv;
            }
            else {
                out = query(a, l).lv;
                l = binlift(b, depth[b]-depth[l]-1);
                auto v2 = query(b, l).rv;
                out = mp(v2.f*out.f%mod, (v2.f*out.s+ v2.s)%mod);
            }
            printf("%lld\n", (out.f * x + out.s) % mod);
        }
        else {
            int p;
            scd(p);
            p++;
            lli c, d;
            sclld(c);
            sclld(d);
            Data tmp;
            tmp.lv = tmp.rv = mp(c, d);
            segtree.update(pos[p], tmp);
        }
    }
}