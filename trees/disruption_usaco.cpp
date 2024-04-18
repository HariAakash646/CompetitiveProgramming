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
struct LazySegTree
{
    int size = 1, n;
    vector<pair<T, T>> segtree;
    vector<T> vec;

    T def1; // Assign a value

    void init(int l, T d1)
    {
        n = l;
        def1 = d1;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, mp(def1, def1));
        vec.assign(size, def1);
    }

    T operation(T x, T y)
    {
        return min(x, y); // Any required operation
    }

    void recalculate(int x)
    {
        segtree[x].f = operation(segtree[2 * x + 1].f, segtree[2 * x + 2].f);
    }

    void build(int x, int l, int r)
    {
        if (l == r)
        {
            segtree[x].f = vec[l];
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

    void propagate(int x, int l, int r)
    {
        segtree[x].f = operation(segtree[x].f, segtree[x].s);
        if (l < r)
        {
            segtree[2 * x + 1].s = operation(segtree[2 * x + 1].s, segtree[x].s);
            segtree[2 * x + 2].s = operation(segtree[2 * x + 2].s, segtree[x].s);
        }
        segtree[x].s = 1e9;
    }

    void update(int x, int l, int r, int lx, int rx, T val)
    {
        propagate(x, l, r);
        if (lx <= l && r <= rx)
        {
            segtree[x].s += val;
            return;
        }
        int mid = (l + r) / 2;
        if (lx <= mid)
        {
            update(2 * x + 1, l, mid, lx, rx, val);
        }
        if (rx >= mid + 1)
        {
            update(2 * x + 2, mid + 1, r, lx, rx, val);
        }
        propagate(2 * x + 1, l, mid);
        propagate(2 * x + 2, mid + 1, r);
        recalculate(x);
    }

    void update(int lx, int rx, T val)
    {
        if (lx > rx)
            swap(lx, rx);
        update(0, 0, size - 1, lx, rx, val);
    }

    T query(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            return def1;
        }
        propagate(x, l, r);
        if (lx <= l && r <= rx)
        {
            return segtree[x].f;
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

template <class T>
struct HLD
{
    int n;
    int curpos;
    vvi graph;
    vector<int> parent, depth, heavy, head, pos;
    LazySegTree<T> tree;

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
        printf("%d %d\n", u, v);
        if (u >= graph.size() || v >= graph.size())
        {
            printf("%d %d\n", u, v);
            return;
        }
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
            tree.set(pos[i], vals[i]);
        }
        tree.build();
    }

    void update(int a, int b, T x)
    {
        while (head[a] != head[b])
        {
            if (depth[a] > depth[b])
                swap(a, b);
            tree.update(pos[b], pos[head[b]], x);
            b = parent[head[b]];
        }
        tree.update(pos[a], pos[b], x);
    }

    T query(int id)
    {
        T res = tree.query(pos[id], pos[id]);
        return res;
    }
};

vector<vii> graph;
vi st, en;
int timer = 0;

vi par;
vector<vii> child;

void euler(int x, int pr, int id)
{
    st[x] = ++timer;
    par[x] = id;
    for (auto e : graph[x])
    {
        if (e.f != pr)
        {
            euler(e.f, x, e.s);
            child[x].pb(mp(en[e.f], e.s));
        }
    }
    en[x] = timer;
}

int main()
{
    int n, m;
    scd(n);
    scd(m);
    HLD<int> hld;
    hld.init(n - 1, 1e9);

    vii edges(n);
    vvi edv(n + 1);
    graph = vector<vii>(n + 1);
    forr(i, 1, n)
    {
        int a, b;
        scd(a);
        scd(b);
        for (auto e : edv[a])
            hld.setedge(e, i);
        for (auto e : edv[b])
            hld.setedge(e, i);
        edv[a].pb(i);
        edv[b].pb(i);
        edges[i] = {a, b};
        graph[a].pb({b, i});
        graph[b].pb({a, i});
    }

    par = st = en = vi(n + 1);
    child = vector<vii>(n + 1);

    euler(1, 0, 0);

    forr(i, 1, n + 1) sort(all(child[i]));

    // hld.hld();
    // vi vec(n + 1, 1e9);

    // hld.initval(vec);

    // frange(i, m)
    // {
    //     int a, b, r;
    //     scd(a);
    //     scd(b);
    //     scd(r);
    //     int u, v;
    //     if (st[a] <= st[b] && st[b] <= en[a])
    //     {
    //         auto it = lower_bound(all(child[a]), mp(st[b], 0));
    //         if (it == child[a].end())
    //         {
    //             printf("%d %d\n", a, b);
    //             continue;
    //         }
    //         u = (*it).s;
    //     }
    //     else
    //     {
    //         u = par[a];
    //     }
    //     if (st[b] <= st[a] && st[a] <= en[b])
    //     {
    //         auto it = lower_bound(all(child[b]), mp(st[a], 0));
    //         if (it == child[b].end())
    //         {
    //             printf("%d %d\n", a, b);
    //             continue;
    //         }
    //         v = (*it).s;
    //     }
    //     else
    //     {
    //         v = par[b];
    //     }
    //     hld.update(u, v, r);
    // }

    // forr(i, 1, n)
    // {
    //     printf("%d\n", hld.query(i));
    // }
}