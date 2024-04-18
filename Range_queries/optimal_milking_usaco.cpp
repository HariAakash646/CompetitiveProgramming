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

void usaco()
{
    freopen("optmilk.in", "r", stdin);
    freopen("optmilk.out", "w", stdout);
}

struct Data
{
    lli lr = 0;
    lli l = 0;
    lli r = 0;
    lli no = 0;
};

struct SegTree
{
    int size = 1, n;
    vector<Data> segtree;
    vector<lli> vec;

    void init(int l)
    {
        n = l;

        while (size < n)
            size *= 2;
        Data tmp;
        segtree.assign(2 * size, tmp);
        vec.assign(size, 0);
    }

    Data operation(Data x, Data y)
    {
        Data out;
        out.lr = max({x.lr + y.r, x.l + y.lr, x.l + y.r});
        out.l = max({x.lr + y.no, x.l + y.l, x.l + y.no});
        out.r = max({x.no + y.lr, x.no + y.r, x.r + y.r});
        out.no = max({x.r + y.no, x.no + y.l, x.no + y.no});

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
            segtree[x].lr = vec[l];
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

    void set(int id, lli val)
    {
        vec[id] = val;
    }

    void update(int x, int l, int r, int id, lli v)
    {
        if (l == r)
        {
            segtree[x].lr = v;
            return;
        }
        int mid = (l + r) / 2;
        if (id <= mid)
        {
            update(2 * x + 1, l, mid, id, v);
        }
        else
        {
            update(2 * x + 2, mid + 1, r, id, v);
        }
        recalculate(x);
    }

    void update(int id, lli v)
    {
        update(0, 0, size - 1, id, v);
        // frange(i, n) printf("%d %d\n", vec[i].f, vec[i].s);
        // build(0, 0, size - 1);
    }

    Data query(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            Data tmp;
            return tmp;
        }
        if (lx <= l && r <= rx)
        {
            return segtree[x];
        }
        int mid = (l + r) / 2;

        return operation(query(2 * x + 1, l, mid, lx, rx), query(2 * x + 2, mid + 1, r, lx, rx));
    }

    Data query(int lx, int rx)
    {
        return query(0, 0, size - 1, lx, rx);
    }
};

int main()
{
    usaco();
    int n, d;
    scd(n);
    scd(d);

    SegTree segtree;
    segtree.init(n);

    frange(i, n)
    {
        lli v;
        sclld(v);
        segtree.set(i, v);
    }
    segtree.build();
    lli tot = 0;
    frange(i, d)
    {
        int id;
        lli v;
        scd(id);
        id--;
        sclld(v);
        segtree.update(id, v);
        Data out = segtree.query(0, n - 1);
        tot += max({out.lr, out.l, out.r, out.no});
    }
    printf("%lld", tot);
}