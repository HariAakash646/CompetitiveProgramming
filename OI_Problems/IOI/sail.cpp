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

template <class T>
struct LazySegTree
{
    int size = 1, n;
    vector<pair<pair<pair<T, int>, T>, T>> segtree;
    vector<T> vec;

    T def1; // Assign a value

    void init(int l, T d1)
    {
        n = l;
        def1 = d1;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, mp(mp(mp(def1, 0), def1), 0));
        vec.assign(size, def1);
    }

    pair<T, int> operation(pair<T, int> x, pair<T, int> y)
    {
        return min(x, y); // Any required operation
    }

    T sum(T x, T y) {
        return x + y;
    }

    void recalculate(int x)
    {
        segtree[x].f.f = operation(segtree[2 * x + 1].f.f, segtree[2 * x + 2].f.f);
        segtree[x].f.s = sum(segtree[2*x+1].f.s, segtree[2*x+2].f.s);
    }

    void build(int x, int l, int r)
    {
        if (l == r)
        {
            segtree[x].f.f.f = segtree[x].f.s = vec[l];
            segtree[x].f.f.s = l;
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
        segtree[x].f.f.f += segtree[x].s;
        segtree[x].f.s += (r - l + 1) * segtree[x].s;
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

    pair<T, int> query_min(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            return mp(1e18, 0);
        }
        propagate(x, l, r);
        if (lx <= l && r <= rx)
        {
            return segtree[x].f.f;
        }
        int mid = (l + r) / 2;
        pair<T, int> v1 = query_min(2 * x + 1, l, mid, lx, rx);
        pair<T, int> v2 = query_min(2 * x + 2, mid + 1, r, lx, rx);
        return operation(v1, v2);
    }

    pair<T, int> query_min(int lx, int rx)
    {
        return query_min(0, 0, size - 1, lx, rx);
    }

    T query_sum(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            return def1;
        }
        propagate(x, l, r);
        if (lx <= l && r <= rx)
        {
            return segtree[x].f.s;
        }
        int mid = (l + r) / 2;
        T v1 = query_sum(2 * x + 1, l, mid, lx, rx);
        T v2 = query_sum(2 * x + 2, mid + 1, r, lx, rx);
        return v1 + v2;
    }

    T query_sum(int lx, int rx)
    {
        return query_sum(0, 0, size - 1, lx, rx);
    }
};

int main() {
    // usaco();
    int n;
    scd(n);
    vii vec(n);
    frange(i, n) {
        scd(vec[i].f);
        vec[i].f--;
        scd(vec[i].s);
    }
    sort(all(vec));

    LazySegTree<lli> segtree;
    segtree.init(n, 0);
    segtree.build();
    lli tot = 0;
    for(auto p : vec) {
        int v = p.s;
        int lim = p.f;
        while(v > 0) {
            int id = segtree.query_min(0, lim).s;
            tot += segtree.query_sum(id, min(lim, id+v-1));
            segtree.update(id, min(lim, id+v-1), 1);
            v = v - (lim - id + 1);
            lim = id-1;
        }
        // frange(i, 10) printf("%lld ", segtree.query_sum(i, i));
        // printf("%lld\n", tot);
    }
    printf("%lld", tot);
}