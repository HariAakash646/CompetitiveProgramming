#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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

int lower(vi &vec, int x)
{
    int hi = vec.size();
    int lo = 0;
    while (lo != hi)
    {
        int mid = (hi + lo) / 2;
        if (vec[mid] < x)
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return lo;
}

int upper(vi &vec, int x)
{
    int hi = vec.size();
    int lo = 0;
    while (lo != hi)
    {
        int mid = (hi + lo) / 2;
        if (vec[mid] <= x)
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return lo;
}

template <class T>
struct SegTree
{
    int size = 1, n;
    vector<T> segtree;
    vector<int> vec;

    T def; // Assign a value

    void init(int l, T defv)
    {
        n = l;
        def = defv;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, def);
        vec.assign(size, 0);
    }

    void operation(T x, T y, T &v3)
    {
        v3.assign(x.size() + y.size(), 0);
        merge(all(x), all(y), v3.begin(), greater<int>());
    }

    void recalculate(int x)
    {
        operation(segtree[2 * x + 1], segtree[2 * x + 2], segtree[x]);
    }

    void build(int x, int l, int r)
    {
        if (l == r)
        {
            segtree[x].pb(vec[l]);
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

    void set(int id, int val)
    {
        vec[id] = val;
    }

    void update(int x, int l, int r, int id, T val)
    {
        if (l == r)
        {
            segtree[x].pb(val);
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

    int query(int x, int l, int r, int lx, int rx, int k)
    {
        if (l == r)
        {
            return segtree[x][0];
        }
        // if (lx <= l && r <= rx)
        // {
        //     return segtree[x].end() - lower_bound(all(segtree[x]), v);
        // }
        int mid = (l + r) / 2;
        int p = lower(segtree[2 * x + 1], lx) - upper(segtree[2 * x + 1], rx);
        if (p >= k)
            return query(2 * x + 1, l, mid, lx, rx, k);
        else
            return query(2 * x + 2, mid + 1, r, lx, rx, k - p);
    }

    int query(int lx, int rx, int k)
    {
        return query(0, 0, size - 1, lx, rx, k);
    }
};

template <class T>
struct HLD
{
    int n;
    int curpos;
    vvi graph;
    vector<int> parent, depth, heavy, head, pos, idx;
    SegTree<T> tree;

    T def;

    void init(int l, T defv)
    {
        n = l;
        def = defv;
        tree.init(n, def);

        parent = vector<int>(n + 1);
        depth = vector<int>(n + 1);
        heavy = vector<int>(n + 1, -1);
        head = vector<int>(n + 1);
        pos = vector<int>(n + 1);
        idx = vector<int>(n + 1);
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
        idx[curpos] = v;
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

    void initval(T vals)
    {
        forr(i, 1, n + 1)
        {
            tree.set(i, pos[vals[i]]);
        }
        tree.build();
    }

    void update(int id, T val)
    {
        tree.update(pos[id], val);
    }

    int query(int a, int b, int v)
    {
        int tot = 0;
        while (head[a] != head[b])
        {
            if (depth[head[a]] > depth[head[b]])
                swap(a, b);
            int cur = tree.query(pos[head[b]], pos[b], v);
            v = cur;
            b = parent[head[b]];
        }

        if (depth[a] > depth[b])
            swap(a, b);
        tot = tree.query(pos[a], pos[b], v);
        return idx[tot];
    }
};

int main()
{
    int n;
    scd(n);
    HLD<vi> hld;
    vi em;
    hld.init(n, em);
    vii vec(n + 1);
    vi v1(n);
    frange(i, n)
    {
        int a;
        scd(a);
        vec[i] = {a, i + 1};
        v1[i] = a;
    }
    forr(i, 2, n + 1)
    {
        int a;
        scd(a);

        hld.setedge(a, i);
    }
    sort(all(vec), greater<>());
    vi vals(n + 1);
    frange(i, n)
    {
        vals[i + 1] = vec[i].s;
    }
    hld.hld();
    hld.initval(vals);

    int q;
    scd(q);
    frange(_, q)
    {
        int u, v, k;
        scd(u);
        scd(v);
        scd(k);

        printf("%d\n", v1[hld.query(u, v, k) - 1]);
    }
}