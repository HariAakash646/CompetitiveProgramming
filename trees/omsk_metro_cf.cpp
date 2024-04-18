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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct Seg
{
    seti st, en, full;
    int tot = 0;
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
        out.tot = x.tot + y.tot;
        out.st = x.st;
        for (auto e : y.st)
        {
            out.st.insert(x.tot + e);
        }
        out.en = y.en;
        for (auto e : x.en)
        {
            out.en.insert(e + y.tot);
        }
        out.full = x.full;
        for (auto e : y.full)
            out.full.insert(e);
        for (auto e : out.st)
            out.full.insert(e);
        for (auto e : out.en)
            out.full.insert(e);
        for (auto e : x.en)
        {
            for (auto p : y.st)
                out.full.insert(e + p);
        }
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

        parent = vector<int>(n + 1);
        depth = vector<int>(n + 1);
        heavy = vector<int>(n + 1, -1);
        head = vector<int>(n + 1);
        pos = vector<int>(n + 1);
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
        T cur_max = tree.query(min(pos[a], pos[b]), max(pos[a], pos[b]));
        res = tree.operation(cur_max, res);

        return res;
    }
};

int main()
{
    fastio();
    int t;
    cin >> t;

    frange(_, t)
    {
        int n;
        cin >> n;
        vii edges;
        vector<pair<pii, int>> quer;
        vi wt;

        int c = 2;
        wt.pb(0);
        wt.pb(1);
        frange(i, n)
        {
            char typ;
            int u, v;
            cin >> typ >> u >> v;
            if (typ == '+')
            {
                edges.pb(mp(u, c));
                wt.pb(v);
                c++;
            }
            else
            {
                int k;
                cin >> k;
                quer.pb(mp(mp(u, v), k));
            }
        }
        n = edges.size() + 1;
        HLD<Seg> hld;
        Seg seg;
        hld.init(n, seg);
        for (auto p : edges)
        {
            hld.setedge(p.f, p.s);
        }
        vector<Seg> vec(n + 1);
        forr(i, 1, n + 1)
        {
            vec[i].tot = wt[i];
            vec[i].full.insert(wt[i]);
            vec[i].full.insert(0);
            vec[i].st.insert(wt[i]);
            vec[i].st.insert(0);
            vec[i].en.insert(wt[i]);
            vec[i].en.insert(0);
        }
        hld.hld();
        hld.initval(vec);

        for (auto p : quer)
        {
            auto out = hld.query(p.f.f, p.f.s);
            // for (auto e : out.full)
            //     printf("%d ", e);
            // printf("\n");
            if (out.full.find(p.s) != out.full.end())
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}