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

template <class T>
struct IterativeSegTree
{
    int size = 1, n;
    vector<T> segtree;

    T def; // Assign a value

    void init(int l, T defv)
    {
        n = l;
        def = defv;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, def);
    }

    T operation(T x, T y)
    {
        return x ^ y; // Any required operation
    }

    void build()
    {
        for (int i = n - 1; i > 0; --i)
            segtree[i] = operation(segtree[i << 1], segtree[i << 1 | 1]);
    }

    void set(int id, T val)
    {
        segtree[n + id] = val;
    }

    void update(int id, T val)
    {
        id += n;
        for (segtree[id] = val; id > 1; id >>= 1)
            segtree[id >> 1] = operation(segtree[id], segtree[id ^ 1]);
    }

    T query(int l, int r)
    {
        T res = def;
        r++;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = operation(res, segtree[l++]);
            if (r & 1)
                res = operation(res, segtree[--r]);
        }
        return res;
    }
};

template <class T>
struct HLD
{
    int n;
    int curpos;
    vvi graph;
    vector<T> parent, depth, heavy, head, pos;
    IterativeSegTree<T> tree;

    T def;

    void init(int l, T defv)
    {
        n = l;
        def = defv;
        tree.init(n, def);

        parent = vector<T>(n + 1);
        depth = vector<T>(n + 1);
        heavy = vector<T>(n + 1, -1);
        head = vector<T>(n + 1);
        pos = vector<T>(n + 1);
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

    void initval(vector<T> vals)
    {
        forr(i, 1, n + 1)
        {
            tree.set(pos[i], vals[i]);
        }
        tree.build();
    }

    void update(int id, T val)
    {
        tree.update(pos[id], val);
    }

    T query(int a, int b)
    {
        T res = def;
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
    freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);
    int n, q;
    scd(n);
    scd(q);
    vi vec(n + 1);
    forr(i, 1, n + 1) scd(vec[i]);

    HLD<int> hldtree;
    hldtree.init(n, 0);

    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        hldtree.setedge(a, b);
    }

    hldtree.hld();
    hldtree.initval(vec);

    frange(_, q)
    {
        int t;
        scd(t);
        if (t == 1)
        {
            int i, v;
            scd(i);
            scd(v);
            hldtree.update(i, v);
        }
        else
        {
            int i, j;
            scd(i);
            scd(j);
            printf("%d\n", hldtree.query(i, j));
        }
    }
}