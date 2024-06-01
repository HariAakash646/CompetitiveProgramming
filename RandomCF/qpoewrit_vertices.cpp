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

vector<vii> graph;
vvi lift;
vvi liftv;
vi depth;

void dfs(int x, int p) {
    depth[x] = depth[p] + 1;
    for(auto e : graph[x]) {
        if(e.f != p) {
            lift[0][e.f] = x;
            liftv[0][e.f] = e.s;
            dfs(e.f, x);
        }
    }
}

pii binlift(int x, int c) {
    pii out = mp(x, 0);
    // printf("%d:\n", x);
    frange(i, 20) {
        if(c & (1<<i)) {
            out = mp(lift[i][out.f], max(out.s, liftv[i][out.f]));
            // printf("%d %d\n", out.f, out.s);
        }
    }
    return out;
}

pii lca(int u, int v) {
    if(depth[u] > depth[v]) swap(u, v);
    pii out = binlift(v, depth[v]-depth[u]);
    v = out.f;
    int ma = out.s;
    // printf("%d ", ma);
    if(u == v) {
        return mp(u, ma);
    }

    for(int i=19; i>=0; i--) {
        int ut = lift[i][u];
        int vt = lift[i][v];
        if(ut != vt) {
            ma = max(ma, liftv[i][u]);
            ma = max(ma, liftv[i][v]);
            
            u = ut;
            v = vt;
        }
    }

    return mp(lift[0][u], max({ma, liftv[0][u], liftv[0][v]}));
}

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
        if(!x.f) return y;
        if(!y.f) return x;
        T out=lca(x.f, y.f);

        out.s = max({x.s, y.s, out.s});
        // printf("%d %d %d %d\n", x.f, y.f, out.f, out.s);
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
        // printf("%d %d:\n", lx, rx);
        return query(0, 0, size - 1, lx, rx);
    }
};


vi sze, disset;

int findf(int x) {
    if(x == disset[x]) return x;
    disset[x] = findf(disset[x]);
    return disset[x];
}

void unionf(int u, int v) {
    u = findf(u);
    v = findf(v);
    if(u==v) return;
    if(sze[v] > sze[u]) swap(u, v);

    disset[v] = u;
    sze[u] = max(sze[u], sze[v]+1);
}


int main() {
    // usaco();
    int t;
    scd(t);
    frange(_, t) {
        int n, m, q;
        scd(n);
        scd(m);
        scd(q);

        disset = sze = vi(n+1);
        forr(i, 1, n+1) disset[i] = i;

        graph = vector<vii>(n+1);

        forr(i, 1, m+1) {
            int a, b;
            scd(a);
            scd(b);
            if(findf(a) != findf(b)) {
                unionf(a, b);
                graph[a].pb(mp(b, i));
                graph[b].pb(mp(a, i));
            }
        }

        depth = vi(n+1);
        lift = liftv = vvi(20, vi(n+1));

        dfs(1, 0);
        forr(i, 1, 20) {
            forr(j, 1, n+1) {
                lift[i][j] = lift[i-1][lift[i-1][j]];
                liftv[i][j] = max(liftv[i-1][j], liftv[i-1][lift[i-1][j]]);
            }
        }
        SegTree<pii> segtree;
        segtree.init(n+1, mp(0, 0));
        forr(i, 1, n+1) segtree.set(i, mp(i, 0));
        segtree.build();
        frange(_, q) {
            int l, r;
            scd(l);
            scd(r);
            printf("%d\n", segtree.query(l, r).s);
        }
        printf("\n");
    }
}