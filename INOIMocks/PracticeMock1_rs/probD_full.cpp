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


void usaco() {
    // freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
}

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
        return max(x, y); // Any required operation
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
        segtree[x].f += segtree[x].s;
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

int main() {
    usaco();
    int c, t;
    scd(c);
    scd(t);

    frange(_, t) {
        int n, m, k;
        lli d;
        scd(n);
        scd(m);
        scd(k);
        sclld(d);

        vector<pair<pii, lli>> vec(m+1);
        vii pos(m+1);

        forr(i, 1, m+1) {
            scd(vec[i].f.f);
            vec[i].f.f++;
            scd(vec[i].f.s);
            sclld(vec[i].s);
        }        

        sort(all(vec));
        forr(i, 1, m+1) pos[i] = mp(vec[i].f.f, i);
        forr(i, 1, m+1) pos.pb(mp(vec[i].f.f - vec[i].f.s-1, 0));
        sort(all(pos));

        LazySegTree<lli> segtree;
        segtree.init(2*m+1, 0);
        // vll dp(m+1);

        lli ma = 0;

        frange(i, 2*m+1) segtree.set(i, (pos[i].f+1)*d);
        segtree.build();
        forr(j, 1, 2*m+1) {
            int i;
            if(pos[j].s) {
                i = pos[j].s;
            }
            else {
                segtree.update(j, j, ma);
                continue;
            }
            if(vec[i].f.s > k) continue;
            int id = lower_bound(all(pos), mp(vec[i].f.f - vec[i].f.s, 0)) - pos.begin() - 1;
            segtree.update(0, id, vec[i].s);
            int id2 = lower_bound(all(pos), mp(vec[i].f.f - k-1, 0)) - pos.begin();
            if(id2 >= 0 && id2 <= id) {
                lli v = segtree.query(max(0, id2), id) - vec[i].f.f * d;
                // printf("%")
                segtree.update(j, j, v);
                // printf("%d %d %d %lld %lld\n", i, id2, id, v, vec[i].f.f * d);
                ma = max(ma, v);
            }

            // ma = max(ma, dp[i-1]);

            // dp[i] = ma;

        }
        printf("%lld\n", ma);
    }
}