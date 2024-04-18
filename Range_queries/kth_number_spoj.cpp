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

    int query(int x, int l, int r, int lx, int rx, int v)
    {
        if (lx > r || rx < l)
        {
            return 0;
        }
        if (lx <= l && r <= rx)
        {
            return upper_bound(all(segtree[x]), v) - segtree[x].begin();
        }
        int mid = (l + r) / 2;
        int v1 = query(2 * x + 1, l, mid, lx, rx, v);
        int v2 = query(2 * x + 2, mid + 1, r, lx, rx, v);
        return v1 + v2;
    }

    int query(int lx, int rx, int v)
    {
        return query(0, 0, size - 1, lx, rx, v);
    }
};

int main()
{
    int n;
    scd(n);
    int q;
    scd(q);

    SegTree<vi> tree;
    tree.init(n, vi());

    frange(i, n)
    {
        int a;
        scd(a);
        tree.set(i, a);
    }
    tree.build();

    frange(_, q)
    {
        int i, j, k;
        scd(i);
        scd(j);
        scd(k);
        i--;
        j--;
        int hi = 1e9;
        int lo = -1e9;

        while (lo != hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (tree.query(i, j, mid) >= k)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        printf("%d\n", lo);
    }
}