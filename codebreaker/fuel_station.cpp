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

int n;
lli d;

struct Data {
    int l = 0;
    int r = 0;
    lli tot = 0;
    lli mi = 1e18;
};

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
        T tmp;
        tmp.l = x.l;
        tmp.r = y.r;
        tmp.tot = x.tot + y.tot - (y.l - x.r);
        tmp.mi = min(x.mi, y.mi + x.tot - (y.l - x.r));
        return tmp;
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

bool cmp(pair<pii, pii> x, pair<pii, pii> y) {
    return x.s.s < y.s.s;
}


int main() {
    // usaco();
    scd(n);
    sclld(d);

    vector<pair<pii, pii>> vec(n);

    frange(i, n) {
        scd(vec[i].f.f);
        scd(vec[i].s.f);
        scd(vec[i].s.s);
    }

    sort(all(vec));
    SegTree<Data> segtree;
    Data tmp;
    segtree.init(n+2, tmp);
    tmp.l = 0;
    tmp.r = 0;
    tmp.mi = 0;
    tmp.tot = 0;
    segtree.set(0, tmp);
    tmp.l = d;
    tmp.r = d;
    tmp.mi = tmp.tot = 0;
    segtree.set(n+1, tmp);

    sort(all(vec));
    frange(i, n) {
        vec[i].f.s = i+1;
        tmp.l = tmp.r = vec[i].f.f;
        tmp.mi = 0;
        tmp.tot = vec[i].s.f;
        segtree.set(i+1, tmp);
    }

    segtree.build();
    sort(all(vec), cmp);
    int id = 0;

    int hi = 1e9;
    int lo = 0;
    for(auto p : vec) {
        Data out = segtree.query(0, n+1);
        if(out.mi + p.s.s >= 0) {
            hi = p.s.s;
            break;
        }
        Data tmp;
        tmp.l = p.f.f;
        tmp.r = p.f.f;
        tmp.tot = 0;
        tmp.mi = 0;
        segtree.update(p.f.s, tmp);
    }
    Data out = segtree.query(0, n+1);
    printf("%lld", -out.mi);
}