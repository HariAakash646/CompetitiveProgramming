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
struct MinSegTree
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
        return min(x, y); // Any required operation
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

template <class T>
struct SumSegTree
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
        return x + y; // Any required operation
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

int n;
vector<vii> graph;
vll vec;
vi depth;
vi st, st2, en2;
vi euler;
int t1 = -1;
int t2 = 0;

void dfs(int x, int par, int d, int v)
{
    st2[x] = t2++;
    depth[x] = d;
    vec[x] = v;
    st[x] = euler.size();
    euler.pb(x);
    for (auto e : graph[x])
    {
        if (e.f != par)
        {
            dfs(e.f, x, d + 1, e.s);
            euler.pb(x);
        }
    }
    en2[x] = t2++;
}

int main()
{
    int n;
    scd(n);
    st = depth = st2 = en2 = vi(n + 1);
    vec = vll(n + 1);
    graph = vector<vii>(n + 1);
    vii edges(n);
    frange(i, n - 1)
    {
        int a, b, c;
        scd(a);
        scd(b);
        scd(c);
        graph[a].pb({b, c});
        graph[b].pb({a, c});
        edges[i + 1] = {a, b};
    }
    dfs(1, 0, 0, 0);
    MinSegTree<pii> mintree;
    mintree.init(euler.size(), mp(1e9, 0));
    // forr(i, 1, n + 1)
    // {
    //     mintree.set(st[i], mp(depth[i], i));
    // }
    frange(i, euler.size())
    {
        mintree.set(i, mp(depth[euler[i]], euler[i]));
    }
    SumSegTree<lli> sumtree;
    sumtree.init(2 * n, 0);
    forr(i, 1, n + 1)
    {
        sumtree.set(st2[i], vec[i]);
        sumtree.set(en2[i], -vec[i]);
    }
    mintree.build();
    sumtree.build();
    int q;
    scd(q);
    frange(_, q)
    {
        int t;
        scd(t);
        int a, b;
        scd(a);
        scd(b);
        if (t == 2)
        {
            int l = mintree.query(min(st[a], st[b]), max(st[a], st[b])).s;
            lli tot = sumtree.query(st2[0], st2[a]) + sumtree.query(st2[0], st2[b]) - 2 * sumtree.query(st2[0], st2[l]);
            printf("%lld\n", tot);
        }
        else
        {
            int u = edges[a].f;
            int v = edges[a].s;
            if (depth[u] > depth[v])
                swap(u, v);
            sumtree.update(st2[v], b);
            sumtree.update(en2[v], -b);
        }
    }
}