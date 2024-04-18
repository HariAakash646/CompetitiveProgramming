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

int n;
vvi graph;
vi vec;
vi st, en;
int timer = -1;

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
        vi v3(x.size() + y.size());
        merge(all(x), all(y), v3.begin());
        return v3;
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

    void set(int id, int val)
    {
        vec[id][0] = val;
    }

    int query(int x, int l, int r, int lx, int rx, int k)
    {
        if (lx > r || rx < l)
        {
            return 0;
        }
        if (lx <= l && r <= rx)
        {
            return upper_bound(all(segtree[x]), k) - lower_bound(all(segtree[x]), k);
        }
        int mid = (l + r) / 2;
        int v1 = query(2 * x + 1, l, mid, lx, rx, k);
        int v2 = query(2 * x + 2, mid + 1, r, lx, rx, k);
        return v1 + v2;
    }

    int query(int lx, int rx, int k)
    {
        return query(0, 0, size - 1, lx, rx, k);
    }
};

void dfs(int x, int par, int d)
{
    st[x] = ++timer;
    vec[x] = d;
    for (auto e : graph[x])
    {
        if (e != par)
        {
            dfs(e, x, d + 1);
        }
    }
    en[x] = timer;
}

int main()
{
    scd(n);
    vec = vi(n + 1);
    graph = vvi(n + 1);
    forr(i, 2, n + 1)
    {
        int p;
        scd(p);
        graph[p].pb(i);
        graph[i].pb(p);
    }
    st = en = vi(n + 1);
    dfs(1, 0, 0);
    SegTree<vi> segtree;
    segtree.init(n, vi(1, 0));

    forr(i, 1, n + 1)
    {
        segtree.set(st[i], vec[i]);
    }
    segtree.build();
    int q;
    scd(q);
    forr(i, 1, q + 1)
    {
        int u, d;
        scd(u);
        scd(d);
        printf("%d\n", segtree.query(st[u], en[u], d));
    }
}