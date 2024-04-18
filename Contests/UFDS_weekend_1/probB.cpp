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

        segtree.assign(2 * size, mp(def1, 0));
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
        segtree[x].f += (r - l + 1) * segtree[x].s;
        if (l < r)
        {
            segtree[2 * x + 1].s += segtree[x].s;
            segtree[2 * x + 2].s += segtree[x].s;
        }
        segtree[x].s = 0;
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
    LazySegTree<int> segtree;
    segtree.init(1e6 + 1, 0);
    segtree.build();
    vi vec(n);
    frange(i, n)
    {
        scd(vec[i]);
        if (i >= 1)
        {
            segtree.update(min(vec[i], vec[i - 1]), max(vec[i], vec[i - 1]), 1);
            segtree.update(vec[i - 1], vec[i - 1], -1);
        }
    }
    segtree.update(vec[0], vec[0], 1);

    frange(_, q)
    {
        int t;
        scd(t);
        if (t == 1)
        {
            int i, k;
            scd(i);
            scd(k);
            i--;
            if (i > 0)
            {
                segtree.update(min(vec[i], vec[i - 1]), max(vec[i], vec[i - 1]), -1);
            }
            if (i < n - 1)
            {
                segtree.update(min(vec[i], vec[i + 1]), max(vec[i], vec[i + 1]), -1);
            }
            if (i > 0 && i < n - 1)
            {
                segtree.update(vec[i], vec[i], 1);
            }
            vec[i] = k;

            if (i > 0)
            {
                segtree.update(min(vec[i], vec[i - 1]), max(vec[i], vec[i - 1]), 1);
            }
            if (i < n - 1)
            {
                segtree.update(min(vec[i], vec[i + 1]), max(vec[i], vec[i + 1]), 1);
            }
            if (i > 0 && i < n - 1)
            {
                segtree.update(vec[i], vec[i], -11);
            }
        }
        else
        {
            int k;
            scd(k);
            printf("%d\n", segtree.query(k, k));
        }
    }
}