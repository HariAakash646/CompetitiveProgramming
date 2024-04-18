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
struct Data
{
    T sum = 0;
    T sma = 0;
    T ma = 0;
    T lazy = -1;
    int mcnt = 0;
};

template <class T>
struct LazySegTree
{
    int size = 1, n;
    vector<Data<T>> segtree;
    vector<T> vec;

    T def1; // Assign a value

    void init(int l, T d1)
    {
        n = l;
        def1 = d1;

        while (size < n)
            size *= 2;

        Data<T> d;
        segtree.assign(2 * size, d);
        vec.assign(size, def1);
    }

    void recalculate(int x)
    {
        segtree[x].sum = segtree[2 * x + 1].sum + segtree[2 * x + 2].sum;
        segtree[x].mcnt = 0;
        segtree[x].sma = 0;
        if (segtree[2 * x + 1].ma >= segtree[2 * x + 2].ma)
        {
            segtree[x].ma = segtree[2 * x + 1].ma;
            segtree[x].mcnt += segtree[2 * x + 1].mcnt;
        }
        if (segtree[2 * x + 2].ma >= segtree[2 * x + 1].ma)
        {
            segtree[x].ma = segtree[2 * x + 2].ma;
            segtree[x].mcnt += segtree[2 * x + 2].mcnt;
        }
        if (segtree[2 * x + 1].ma != segtree[x].ma)
        {
            segtree[x].sma = segtree[2 * x + 1].ma;
        }
        if (segtree[2 * x + 2].ma != segtree[x].ma)
        {
            segtree[x].sma = max(segtree[x].sma, segtree[2 * x + 2].ma);
        }
        if (segtree[2 * x + 1].sma != segtree[x].ma)
        {
            segtree[x].sma = max(segtree[x].sma, segtree[2 * x + 1].sma);
        }
        if (segtree[2 * x + 2].sma != segtree[x].ma)
        {
            segtree[x].sma = max(segtree[x].sma, segtree[2 * x + 2].sma);
        }
    }

    void build(int x, int l, int r)
    {
        if (l == r)
        {
            segtree[x].sum = vec[l];
            segtree[x].ma = vec[l];
            segtree[x].mcnt = 1;
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

    void setval(int id, T val)
    {
        vec[id] = val;
    }

    void propagate(int x, int l, int r)
    {
        if (segtree[x].lazy == -1)
            return;
        segtree[x].sum += segtree[x].mcnt * (segtree[x].lazy - segtree[x].ma);
        segtree[x].ma = segtree[x].lazy;

        if (l < r)
        {
            int mid = (l + r) / 2;
            minset(2 * x + 1, l, mid, l, mid, segtree[x].lazy);
            minset(2 * x + 2, mid + 1, r, mid + 1, r, segtree[x].lazy);
        }
        segtree[x].lazy = -1;
    }

    bool breakCon(int x, T val)
    {
        if (segtree[x].lazy == -1)
            return val >= segtree[x].ma;
        else
            return val >= segtree[x].lazy;
    }

    bool tagCon(int x, T val)
    {
        return val > segtree[x].sma;
    }

    void minset(int x, int l, int r, int lx, int rx, T val)
    {

        if (rx < l || lx > r || breakCon(x, val))
            return;
        propagate(x, l, r);
        if (lx <= l && r <= rx && tagCon(x, val))
        {
            segtree[x].lazy = val;
            return;
        }
        int mid = (l + r) / 2;

        minset(2 * x + 1, l, mid, lx, rx, val);
        minset(2 * x + 2, mid + 1, r, lx, rx, val);

        propagate(2 * x + 1, l, mid);
        propagate(2 * x + 2, mid + 1, r);
        recalculate(x);
    }

    void minset(int lx, int rx, T val)
    {
        minset(0, 0, size - 1, lx, rx, val);
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
            return segtree[x].sum;
        }
        int mid = (l + r) / 2;
        T v1 = query(2 * x + 1, l, mid, lx, rx);
        T v2 = query(2 * x + 2, mid + 1, r, lx, rx);
        return v1 + v2;
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
    LazySegTree<lli> segtree;
    segtree.init(n, 0);

    frange(i, n)
    {
        lli a;
        sclld(a);
        segtree.setval(i, a);
    }
    segtree.build();
    scd(q);

    frange(_, q)
    {
        int t;
        scd(t);
        if (t == 1)
        {
            int l, r;
            lli x;
            scd(l);
            scd(r);
            sclld(x);
            l--;
            r--;
            segtree.minset(l, r, x);
        }
        else
        {
            int l, r;
            scd(l);
            scd(r);
            l--;
            r--;
            printf("%lld\n", segtree.query(l, r));
        }
    }
}
