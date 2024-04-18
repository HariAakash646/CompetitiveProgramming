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
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

struct Data {
    lli val = 0;
    lli lv = 0;
    lli rv = 0;
    lli totv = 0;

    int ma = 0;
    int l = 0;
    int r = 0;
    int lid=-1, rid;
};

template <class T>
struct LazySegTree
{
    int size = 1, n;
    vector<T> segtree;
    vector<lli> laz1;
    vector<pair<lli, int>> laz2;
    vector<lli> vec;

    void init(int l)
    {
        n = l;

        while (size < n)
            size *= 2;

        segtree= vector<T>(2 * size);
        laz1 = vll(2*size);
        laz2 = vector<pair<lli, int>>(2*size, mp(2e18, 0));
        vec = vll(size);
    }

    T operation(T x, T y)
    {
        if(x.lid == -1) return y;
        if(y.lid == -1) return x;
        Data out;
        if(x.ma > y.ma) {
            out.ma = x.ma;
            out.val = x.val;
        }
        else {
            out.ma = y.ma;
            out.val = y.val;
        }
        if(x.rv == y.lv && x.r + y.l > out.ma) {
            out.val = x.rv;
            out.ma = x.r + y.l;
        }
        out.l = x.l;
        out.lv = x.lv;
        if(x.l == x.rid - x.lid + 1 && x.lv == y.lv) {
            out.lv = x.lv;
            out.l = x.l + y.l;
        }
        out.r = y.r;
        out.rv = y.rv;
        if(y.r == y.rid - y.lid + 1 && y.rv == x.rv) {
            out.rv = y.rv;
            out.r = y.r + x.r;
        }
        out.lid = x.lid;
        out.rid = y.rid;
        out.totv = x.totv + y.totv;
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
            segtree[x].totv = segtree[x].val = vec[l];
            segtree[x].ma = segtree[x].l = segtree[x].r = 1;
            segtree[x].lv = vec[l];
            segtree[x].rv = vec[r];
            segtree[x].lid = l;
            segtree[x].rid = r;
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

    void propagate(int x, int l, int r)
    {
        if(laz2[x].f != 2e18) {
            segtree[x].totv = (r-l+1) * laz2[x].f;
            segtree[x].val = segtree[x].lv = segtree[x].rv = laz2[x].f;
            segtree[x].l = segtree[x].r = segtree[x].ma=r-l+1;
            if (l < r)
            {
                if(laz2[x].s >= laz2[2*x+1].s)
                {
                    laz2[2 * x + 1] = laz2[x];
                    laz1[2*x+1] = 0;
                }
                if(laz2[x].s >= laz2[2*x+2].s)
                {
                    laz2[2 * x + 2] = laz2[x];
                    laz1[2*x+2] = 0;
                }
            }
            laz2[x] = mp(2e18, 0);
        }
        segtree[x].val += laz1[x];
        segtree[x].totv += (r-l+1) * laz1[x];
        segtree[x].lv += laz1[x];
        segtree[x].rv += laz1[x];
        if (l < r)
        {
            laz1[2 * x + 1] += laz1[x];
            laz1[2 * x + 2] += laz1[x];
        }
        laz1[x] = 0;
    }

    void patch(int x, int l, int r, int lx, int rx, lli val)
    {
        propagate(x, l, r);
        if (lx <= l && r <= rx)
        {
            laz1[x] += val;
            return;
        }
        int mid = (l + r) / 2;
        if (lx <= mid)
        {
            patch(2 * x + 1, l, mid, lx, rx, val);
        }
        if (rx >= mid + 1)
        {
            patch(2 * x + 2, mid + 1, r, lx, rx, val);
        }
        propagate(2 * x + 1, l, mid);
        propagate(2 * x + 2, mid + 1, r);
        recalculate(x);
    }

    void patch(int lx, int rx, lli val)
    {
        if(rx < lx) return;
        patch(0, 0, size - 1, lx, rx, val);
    }

    void rewrite(int x, int l, int r, int lx, int rx, pair<lli, int> val)
    {
        propagate(x, l, r);
        if (lx <= l && r <= rx)
        {
            laz2[x] = val;
            laz1[x] = 0;
            return;
        }
        int mid = (l + r) / 2;
        if (lx <= mid)
        {
            rewrite(2 * x + 1, l, mid, lx, rx, val);
        }
        if (rx >= mid + 1)
        {
            rewrite(2 * x + 2, mid + 1, r, lx, rx, val);
        }
        propagate(2 * x + 1, l, mid);
        propagate(2 * x + 2, mid + 1, r);
        recalculate(x);
    }

    void rewrite(int lx, int rx, pair<lli, int> val)
    {
        if(rx < lx) return;
        rewrite(0, 0, size - 1, lx, rx, val);
    }

    T query(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            Data tmp;
            return tmp;
        }
        propagate(x, l, r);
        if (lx <= l && r <= rx)
        {
            // printf("%d %d %lld %d\n", l, r, segtree[x].val, segtree[x].ma);
            return segtree[x];
        }
        int mid = (l + r) / 2;
        T v1 = query(2 * x + 1, l, mid, lx, rx);
        T v2 = query(2 * x + 2, mid + 1, r, lx, rx);
        return operation(v1, v2);
    }

    int query(int lx, int rx)
    {
        if(lx > rx) return 0;
        return query(0, 0, size - 1, lx, rx).ma;
    }

    lli sum(int lx, int rx)
    {
        if(lx > rx) return 0;
        return query(0, 0, size - 1, lx, rx).totv;
    }
};

int main() {
    // usaco();
    int n, q;
    scd(n);
    scd(q);

    LazySegTree<Data> segtree;
    segtree.init(n+1);

    lli pre = 0;

    frange(i, n) {
        lli v;
        sclld(v);
        segtree.set(i, v-pre);
        pre = v;
    }

    segtree.build();

    frange(i, q) {
        int t;
        scd(t);

        if(t == 2) {
            int l, r;
            lli sv, c;
            scd(l);
            scd(r);
            l--;
            r--;
            sclld(sv);
            sclld(c);
            lli v1 = segtree.sum(0, r+1);
            segtree.rewrite(l, l, mp(sv-segtree.sum(0, l-1), i+1));
            segtree.rewrite(l+1, r, mp(c, i+1));
            segtree.rewrite(r+1, r+1, mp(v1-(sv+c*(r-l)), i+1));
        }
        else if(t == 1) {
            int l, r;
            lli sv, c;
            scd(l);
            scd(r);
            l--;
            r--;
            sclld(sv);
            sclld(c);
            segtree.patch(l, l, sv);
            segtree.patch(l+1, r, c);
            segtree.patch(r+1, r+1, -(sv+c*(r-l)));
        }
        else {
            int l, r;
            scd(l);
            scd(r);
            l--;
            r--;
            printf("%d\n", segtree.query(l+1, r)+1);
        }
    }

}