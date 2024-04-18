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
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;


void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

template<class T>
struct Dat {
    lli ma = -1e18;
    lli mpr = -1e18;
    lli ms = -1e18;
    lli tot = 0;
};

template <class T>
struct SegTree
{
    int size = 1, n;
    vector<Dat<T>> segtree;
    vector<T> vec;

    T def; // Assign a value

    void init(int l, T defv)
    {
        n = l;
        def = defv;

        while (size < n)
            size *= 2;

        Dat<T> tmp;
        segtree.assign(2 * size, tmp);
        vec.assign(size, def);
    }

    Dat<T> operation(Dat<T> x, Dat<T> y)
    {
        Dat<T> out;
        out.ma = max(x.ma, y.ma);
        out.ma = max(out.ma, x.ms + y.mpr);
        out.tot = x.tot + y.tot;

        out.mpr = max(x.mpr, x.tot + y.mpr);
        out.ms = max(y.ms, y.tot + x.ms);

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
            segtree[x].tot = vec[l];
            segtree[x].ma = vec[l];
            segtree[x].mpr = vec[l];
            segtree[x].ms = vec[l];
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
            segtree[x].tot = val;
            segtree[x].ma = val;
            segtree[x].mpr = val;
            segtree[x].ms = val;
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

    Dat<T> query(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            Dat<T> tmp;
            return tmp;
        }
        if (lx <= l && r <= rx)
        {
            return segtree[x];
        }
        int mid = (l + r) / 2;
        Dat<T> v1 = query(2 * x + 1, l, mid, lx, rx);
        Dat<T> v2 = query(2 * x + 2, mid + 1, r, lx, rx);
        return operation(v1, v2);
    }

    T query(int lx, int rx)
    {
        return query(0, 0, size - 1, lx, rx).ma;
    }
};

int main() {
    // usaco();
    int n;
    scd(n);
    vll vec(n);
    frange(i, n) {
        sclld(vec[i]);
    }

    SegTree<lli> segtree;
    segtree.init(n, 0);

    frange(i, n) segtree.set(i, vec[i]);
    segtree.build();

    int q;
    scd(q);

    frange(_, q) {
        int t, x, y;
        scd(t);
        scd(x);
        scd(y);

        if(t == 1) {
            printf("%lld\n", segtree.query(x-1, y-1));
        }
        else segtree.update(x-1, y);
    }
}