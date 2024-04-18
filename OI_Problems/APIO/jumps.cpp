#include <bits/stdc++.h>
#include "jumps.h"

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

// void usaco()
// {
//     freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
// //    freopen("problem.out", "w", stdout);
// }

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
        out.f = min(x.f, y.f);
        out.s = max(x.s, y.s);
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

    T query(int lx, int rx)
    {
        return query(0, 0, size - 1, lx, rx);
    }
};

struct SegTreeDesc
{
    int size = 1, n;
    vector<pair<bool, pii>> segtree;
    vector<int> vec;

    pair<bool, pii> def = mp(true, mp(-1, -1)); // Assign a value

    void init(int l)
    {
        n = l;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, mp(true, mp(-1, -1)));
        vec.assign(size, -1);
    }

    pair<bool, pii> operation(pair<bool, pii> x, pair<bool, pii> y)
    {
        pair<bool, pii> out;
        out.f = false;
        if(x.f && y.f) {
            if(x.s.s > y.s.f) {
                out.f = true;
                if(x.s.f != -1)
                    out.s.f = x.s.f;
                else out.s.f = y.s.f;
                if(y.s.s != -1)
                    out.s.s = y.s.s;
                else out.s.s = x.s.s;
            }
            else if(x.s.s == -1) {
                out = y;
            }
            else if(y.s.f == -1) {
                out = x;
            }
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
            segtree[x] = mp(true, mp(vec[l], vec[l]));
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

    pair<bool, pii> query(int x, int l, int r, int lx, int rx)
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
        pair<bool, pii> v1 = query(2 * x + 1, l, mid, lx, rx);
        pair<bool, pii> v2 = query(2 * x + 2, mid + 1, r, lx, rx);
        return operation(v1, v2);
    }

    bool query(int lx, int rx)
    {
        return query(0, 0, size - 1, lx, rx).f;
    }
};

struct SegTreeAsc
{
    int size = 1, n;
    vector<pair<bool, pii>> segtree;
    vector<int> vec;

    pair<bool, pii> def = mp(true, mp(-1, -1)); // Assign a value

    void init(int l)
    {
        n = l;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, mp(true, mp(-1, -1)));
        vec.assign(size, -1);
    }

    pair<bool, pii> operation(pair<bool, pii> x, pair<bool, pii> y)
    {
        pair<bool, pii> out;
        out.f = false;
        if(x.f && y.f) {
            if(x.s.s < y.s.f) {
                out.f = true;
                if(x.s.f != -1)
                    out.s.f = x.s.f;
                else out.s.f = y.s.f;
                if(y.s.s != -1)
                    out.s.s = y.s.s;
                else out.s.s = x.s.s;
            }
            else if(x.s.s == -1) {
                out = y;
            }
            else if(y.s.f == -1) {
                out = x;
            }
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
            segtree[x] = mp(true, mp(vec[l], vec[l]));
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

    pair<bool, pii> query(int x, int l, int r, int lx, int rx)
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
        pair<bool, pii> v1 = query(2 * x + 1, l, mid, lx, rx);
        pair<bool, pii> v2 = query(2 * x + 2, mid + 1, r, lx, rx);
        return operation(v1, v2);
    }

    bool query(int lx, int rx)
    {
        return query(0, 0, size - 1, lx, rx).f;
    }
};

template <class T>
struct RMQ {
    vector<vector<T>> table;
    int n;


    int level(int x) {
        return 31 - __builtin_clz(x);
    }

    T oper(T x, T y) {
        return max(x, y);
    }

    void build(vector<T> val) {
        n = val.size();
        table = vector<vector<T>>(n, vector<T>(22));
        frange(i, n) {
            table[i][0] = val[i];
        }
        forr(j, 1, 22) {
            frange(i, n) {
                table[i][j] = oper(table[i][j-1], table[min(n-1, i+(1<<(j-1)))][j-1]);
            }
        }
    }

    T query(int l, int r) {
        int x = level(r - l + 1);
        return oper(table[l][x], table[r-(1<<x)+1][x]);
    }
};

vector<SegTree<pii>> lift(20);
RMQ<int> rmq;


void init(int n, std::vector<int> vec) {
    rmq.build(vec);
    lift[0].init(n, mp(1e9, -1));
    SegTreeDesc sgd;
    SegTreeAsc sga;

    sgd.init(n);
    sga.init(n);

    frange(i, n) {
        sga.set(i, vec[i]);
        sgd.set(i, vec[i]);
    }
    sgd.build();
    sga.build();

    frange(i, n) {
        int v = vec[i];
        int lo = 0;
        int hi = i;

        while(lo != hi) {
            int mid = (lo + hi)/2;
            int v = rmq.query(mid, i);
            if(v <= vec[i] && sgd.query(mid, i-1)) {
                printf("%d %d\n", v, mid);
                hi = mid;
            }
            else {
                lo = mid+1;
            }
        }
        pii out;
        out.f = lo;

        lo = i;
        hi = n-1;
        while(lo != hi) {
            int mid = (lo + hi+1)/2;
            int v = rmq.query(i, mid);
            if(v <= vec[i] && sga.query(i+1, mid)) {
                lo = mid;
            }
            else {
                hi = mid-1;
            }
        }
        out.s = lo;
        lift[0].set(i, out);
    }
    lift[0].build();
    forr(i, 1, 20) {
        lift[i].init(n, mp(1e9, -1));
        frange(j, n) {
            pii p = lift[i-1].query(j, j);
            pii out = lift[i-1].query(p.f, p.s);
            lift[i].set(j, out);
        }
        lift[i].build();
    }
}

bool intersect(pii x, pii y) {
    pii out = mp(min(x.f, y.f), max(x.s, y.s));

    int l1 = x.s - x.f + 1 + y.s - y.f + 1;
    int l2 = out.s - out.f + 1;

    return l2 < l1;
}

int minimum_jumps(int a, int b, int c1, int d) {
    pii p1 = mp(a, b);
    pii p2 = mp(c1, d);
    if(intersect(p1, p2)) return 0;
    int c = 0;
    for(int i=19; i>=0; i--) {
        pii pt = lift[i].query(p2.f, p2.s);
        if(!intersect(pt, p1)) {
            p2 = pt;
            c += (1<<i);
        }
    }
    printf("%d %d %d %d %d %d\n", a, b, c1, d, p2.f, p2.s);
    p2 = lift[0].query(p2.f, p2.s);
    printf("%d %d %d %d %d %d\n", a, b, c1, d, p2.f, p2.s);
    if(intersect(p2, p1)) {
        return c+1;
    }
    else
        return -1;
}