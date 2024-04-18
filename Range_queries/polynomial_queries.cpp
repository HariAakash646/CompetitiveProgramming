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
    vector<pair<T, pair<T, T>>> segtree;
    vector<T> vec;

    T def1; // Assign a value

    void init(int l, T d1)
    {
        n = l;
        def1 = d1;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, mp(def1, mp(0LL, 0LL)));
        vec.assign(size, def1);
    }

    T operation(T x, T y)
    {
        return x + y; // Any required operation
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
        segtree[x].f += (((r - l) * segtree[x].s.s + 2 * segtree[x].s.f) * (r - l + 1)) / 2;
        int mid = (r + l) / 2;
        if (l < r)
        {
            segtree[2 * x + 1].s.f += segtree[x].s.f;
            segtree[2 * x + 2].s.f += segtree[x].s.f + segtree[x].s.s * (mid - l + 1);
            segtree[2 * x + 1].s.s += segtree[x].s.s;
            segtree[2 * x + 2].s.s += segtree[x].s.s;
        }
        segtree[x].s = {0, 0};
    }

    void update(int x, int l, int r, int lx, int rx, T val)
    {
        propagate(x, l, r);
        if (lx <= l && r <= rx)
        {
            segtree[x].s.f += val;
            segtree[x].s.s++;
            return;
        }
        int mid = (l + r) / 2;
        if (lx <= mid)
        {
            update(2 * x + 1, l, mid, lx, rx, val);
        }
        if (rx >= mid + 1)
        {
            update(2 * x + 2, mid + 1, r, lx, rx, val + max(0, mid - max(l, lx) + 1));
        }
        propagate(2 * x + 1, l, mid);
        propagate(2 * x + 2, mid + 1, r);
        recalculate(x);
    }

    void update(int lx, int rx, T val)
    {
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

int main()
{
    int n, q;
    scd(n);
    scd(q);

    LazySegTree<lli> segtree;
    segtree.init(n, 0);

    frange(i, n)
    {
        lli a;
        sclld(a);
        segtree.set(i, a);
    }
    segtree.build();

    frange(i, q)
    {
        int t;
        scd(t);

        if (t == 1)
        {
            int a, b;
            scd(a);
            scd(b);
            a--;
            b--;
            segtree.update(a, b, 1);
        }
        else
        {
            int a, b;
            scd(a);
            scd(b);
            a--;
            b--;
            printf("%lld\n", segtree.query(a, b));
        }
    }
}