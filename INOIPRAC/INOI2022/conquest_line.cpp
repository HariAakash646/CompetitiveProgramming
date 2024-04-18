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

struct Dat
{
    lli v11 = 0;
    lli v12 = 0;
    lli v21 = 0;
    lli v22 = 0;
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
        out.v11 = max({x.v12 + y.v11, x.v11 + y.v21, x.v12 + y.v21});
        out.v12 = max({x.v12 + y.v12, x.v11 + y.v22, x.v12 + y.v22});
        out.v21 = max({x.v22 + y.v11, x.v21 + y.v21, x.v22 + y.v21});
        out.v22 = max({x.v22 + y.v12, x.v21 + y.v22, x.v22 + y.v22});
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

int main()
{
    int n, q;
    scd(n);
    scd(q);
    SegTree<Dat> segtree;
    Dat tmp;
    segtree.init(n, tmp);
    frange(i, n)
    {
        lli v;
        sclld(v);
        Dat d;
        d.v11 = v;
        segtree.set(i, d);
    }
    segtree.build();
    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
    }

    frange(_, q)
    {
        int a, b;
        scd(a);
        scd(b);
        a--;
        b--;
        Dat out = segtree.query(a, b);
        printf("%lld\n", max({out.v11, out.v12, out.v21, out.v22}));
    }
}