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

struct Data
{
    int val = 0;
    int pref = 0;
    int suf = 0;
    int r = 0;
    int l = 0;
};

template <class T>
struct SegTree
{
    int size = 1, n;
    vector<T> segtree;
    vi vec;

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

    T operation(T x, T y)
    {
        Data out;
        out.pref = x.pref;
        if (x.suf == x.r - x.l + 1 && vec[x.r] == vec[y.l])
        {
            out.pref = x.suf + y.pref;
        }
        out.suf = y.suf;
        if (y.pref == y.r - y.l + 1 && vec[x.r] == vec[y.l])
        {
            out.suf = x.suf + y.pref;
        }
        out.val = max(x.val, y.val);
        if (vec[x.r] == vec[y.l])
        {
            out.val = max(out.val, x.suf + y.pref);
        }
        out.l = x.l;
        out.r = y.r;
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
            Data elem;
            elem.l = l;
            elem.r = r;
            elem.val = 1;
            elem.pref = 1;
            elem.suf = 1;
            segtree[x] = elem;
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
    vi vec(n);
    frange(i, n) scd(vec[i]);
    SegTree<Data> segtree;
    Data emp;
    segtree.init(n - 1, emp);

    frange(i, n - 1)
    {
        segtree.set(i, vec[i + 1] - vec[i]);
    }
    segtree.build();
    frange(i, q)
    {
        int t, l, r;
        scd(t);
        scd(l);
        scd(r);
        l--;
        r--;
        if (t == 3)
        {
            if (l == r)
                printf("1\n");
            else
            {
                Data v = segtree.query(l, r - 1);
                printf("%d\n", v.val + 1);
            }
        }
    }
}