#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t);
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

struct Data {
    lli tot = 0, prf = 0, suf = 0, ma = 0;
};

template <class T>
struct SegTree
{
    int size = 1, n;
    vector<T> segtree;
    vector<lli> vec;

    T def; // Assign a value

    void init(int l, T defv)
    {
        n = l;
        def = defv;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, def);
        vec.assign(size, 0LL);
    }

    T operation(T x, T y)
    {
        T out;
        out.tot = x.tot + y.tot;
        out.ma = max({x.ma, y.ma, x.suf + y.prf});
        out.prf = max(x.prf, x.tot + y.prf);
        out.suf = max(y.suf, y.tot + x.suf);
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
            lli val = vec[l];
            segtree[x].prf = segtree[x].suf = segtree[x].ma = max(0LL, val);
            segtree[x].tot = val;
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

    void update(int x, int l, int r, int id, lli val)
    {
        if (l == r)
        {
            segtree[x].prf = segtree[x].suf = segtree[x].ma = max(0LL, val);
            segtree[x].tot = val;
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

    void update(int id, lli val)
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

int main() {
	// usaco();
	int n, q;
	scd(n);
	vi vec(n);
	frange(i, n) scd(vec[i]);

	SegTree<Data> segtree;
    Data tmp;
    segtree.init(n, tmp);

    frange(i, n) segtree.set(i, vec[i]);
    segtree.build();
    printf("%lld\n", segtree.query(0, n-1).ma);
    scd(q);
    frange(_, q) {
        int x;
        lli y;
        scd(x);
        sclld(y);
        
        segtree.update(x, y);
        printf("%lld\n", segtree.query(0, n-1).ma);
    }

}