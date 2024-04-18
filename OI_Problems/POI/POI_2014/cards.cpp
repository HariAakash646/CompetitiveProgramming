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

struct Seg
{
    bool ff = false;
    bool fs = false;
    bool sf = false;
    bool ss = false;
    int l1, l2, r1, r2;
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
        out.l1 = x.l1;
        out.l2 = x.l2;
        out.r1 = y.r1;
        out.r2 = y.r2;
        if (x.ff && y.ff && x.r1 <= y.l1)
        {
            out.ff = true;
        }
        if (x.ff && y.sf && x.r1 <= y.l2)
        {
            out.ff = true;
        }
        if (x.fs && y.sf && x.r2 <= y.l2)
        {
            out.ff = true;
        }
        if (x.sf && y.fs && x.r1 <= y.l1)
        {
            out.ss = true;
        }
        if (x.sf && y.ss && x.r1 <= y.l2)
        {
            out.ss = true;
        }
        if (x.ss && y.ss && x.r2 <= y.l2)
        {
            out.ss = true;
        }

        if (x.sf && y.ff && x.r1 <= y.l1)
        {
            out.sf = true;
        }
        if (x.sf && y.sf && x.r1 <= y.l2)
        {
            out.sf = true;
        }
        if (x.ss && y.sf && x.r2 <= y.l2)
        {
            out.sf = true;
        }
        if (x.ff && y.fs && x.r1 <= y.l1)
        {
            out.fs = true;
        }
        if (x.ff && y.ss && x.r1 <= y.l2)
        {
            out.fs = true;
        }
        if (x.fs && y.ss && x.r2 <= y.l2)
        {
            out.fs = true;
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

    bool query(int lx, int rx)
    {
        T v = query(0, 0, size - 1, lx, rx);
        return v.ff || v.ss || v.fs || v.sf;
    }
};

int main()
{
    int n;
    scd(n);

    SegTree<Seg> segtree;
    Seg val;

    // val.fs = true;
    // val.sf = true;
    segtree.init(n, val);
    val.ff = true;
    val.ss = true;
    frange(i, n)
    {
        int a, b;
        scd(a);
        scd(b);
        val.l1 = a;
        val.l2 = b;
        val.r1 = a;
        val.r2 = b;
        segtree.set(i, val);
    }
    segtree.build();
    int m;
    scd(m);
    if (segtree.query(0, n - 1))
    {
        printf("TAK\n");
    }
    else
        printf("NIE\n");
    frange(i, m)
    {
        int x, y;
        scd(x);
        scd(y);
        x--;
        y--;
        Seg tmp = segtree.vec[x];
        segtree.update(x, segtree.vec[y]);
        segtree.update(y, tmp);
        segtree.vec[x] = segtree.vec[y];
        segtree.vec[y] = tmp;
        if (segtree.query(0, n - 1))
        {
            printf("TAK\n");
        }
        else
            printf("NIE\n");
    }
    for (auto p : segtree.vec)
        printf("%d %d\n", p.l1, p.l2);
}
