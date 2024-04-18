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

template <class T>
struct SegTree
{
    int size = 1;
    int n;
    T defv;
    vector<T> vec;
    vector<T> segtree;

    void init(int l, T def)
    {
        n = l;
        defv = def;
        while (size < n)
            size *= 2;
        vec.assign(size, defv);
        segtree.assign(2 * size, mp(1e9, mp(1e9, 0)));
    }

    void set(int id, T v)
    {
        vec[id] = v;
    }

    T operation(T x, T y)
    {
        return min(x, y);
    }

    void recalculate(int x)
    {
        segtree[x] = operation(segtree[2 * x + 1], segtree[2 * x + 2]);
    }

    void build(int x, int l, int r)
    {
        if (l == r)
        {
            if (vec[l].s.s)
                segtree[x] = vec[l];
            else
                segtree[x] = mp(1e9, mp(vec[l].s.f, 0));
            return;
        }
        int mid = (l + r) / 2;
        build(2 * x + 1, l, mid);
        build(2 * x + 2, mid + 1, r);
        recalculate(x);
    }

    void build()
    {
        build(0, 0, n - 1);
    }

    void update(int x, int l, int r, int id)
    {
        if (l == r)
        {
            if (segtree[x].s.s)
            {
                segtree[x].f = 1e9;
                segtree[x].s.f = 1e9;
                segtree[x].s.s = 0;
            }
            else
            {
                segtree[x].f = vec[id].f;
                segtree[x].s.f = vec[id].s.f;
                segtree[x].s.s = 1;
            }
            return;
        }
        int mid = (l + r) / 2;
        if (id <= mid)
            update(2 * x + 1, l, mid, id);
        else
            update(2 * x + 2, mid + 1, r, id);
        recalculate(x);
    }

    void update(int id)
    {
        update(0, 0, n - 1, id);
    }

    T query(int x, int l, int r, int lx, int rx)
    {
        if (rx < l || lx > r)
        {
            return mp(1e9, mp(1e9, 0));
        }
        if (lx <= l && r <= rx)
        {
            return segtree[x];
        }
        int mid = (l + r) / 2;
        return operation(query(2 * x + 1, l, mid, lx, rx), query(2 * x + 2, mid + 1, r, lx, rx));
    }

    T query(int lx, int rx)
    {
        if (lx > rx)
            swap(lx, rx);
        return query(0, 0, n - 1, lx, rx);
    }
};

template <class T>
struct HLD
{
    int n;
    int curpos;
    vvi graph;
    vector<int> parent, depth, heavy, head, pos;
    SegTree<T> tree;

    T def;

    void init(int l, T defv)
    {
        n = l;
        def = defv;
        tree.init(n, def);

        parent = vi(n + 1);
        depth = vi(n + 1);
        heavy = vi(n + 1, -1);
        head = vi(n + 1);
        pos = vi(n + 1);
        graph = vvi(n + 1);

        curpos = 0;
    }

    void setedge(int u, int v)
    {
        graph[u].pb(v);
        graph[v].pb(u);
    }

    int dfs(int x)
    {
        int size = 1;
        int maxchild = 0;
        for (auto e : graph[x])
        {
            if (e != parent[x])
            {
                parent[e] = x;
                depth[e] = depth[x] + 1;
                int sze = dfs(e);
                size += sze;
                if (sze > maxchild)
                {
                    maxchild = sze;
                    heavy[x] = e;
                }
            }
        }
        return size;
    }

    void decompose(int v, int h)
    {
        head[v] = h;
        pos[v] = curpos;
        ++curpos;
        if (heavy[v] != -1)
        {
            decompose(heavy[v], h);
        }
        for (auto e : graph[v])
        {
            if (e != heavy[v] && e != parent[v])
            {
                decompose(e, e);
            }
        }
    }

    void hld()
    {
        dfs(1);
        decompose(1, 1);
    }

    void initval(vi vals)
    {
        forr(i, 1, n + 1)
        {
            tree.set(pos[i], mp(depth[i], mp(i, vals[i])));
        }
        tree.build();
    }

    void update(int id)
    {
        tree.update(pos[id]);
    }

    T query(int a, int b)
    {
        T res = mp(1e9, mp(1e9, 0));
        while (head[a] != head[b])
        {
            if (depth[head[a]] > depth[head[b]])
                swap(a, b);
            T cur_max = tree.query(pos[head[b]], pos[b]);
            res = tree.operation(res, cur_max);
            b = parent[head[b]];
        }

        if (depth[a] > depth[b])
            swap(a, b);
        T cur_max = tree.query(pos[a], pos[b]);
        res = tree.operation(res, cur_max);

        return res;
    }
};

int main()
{
    int n, q;
    scd(n);
    scd(q);
    HLD<pair<int, pii>> hld;
    pair<int, pii> p = {1e9, mp(1e9, 0)};
    hld.init(n, p);

    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        hld.setedge(a, b);
    }
    hld.hld();
    vi vec(n);

    hld.initval(vec);

    frange(i, q)
    {
        int t;
        scd(t);
        if (t == 0)
        {
            int id;
            scd(id);
            hld.update(id);
        }
        else
        {
            int b;
            scd(b);
            auto v = hld.query(1, b);
            if (v.f == 1e9)
                printf("-1\n");
            else
                printf("%d\n", v.s.f);
        }
    }
}