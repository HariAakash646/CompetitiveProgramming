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
        return min(x, y); // Any required operation
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


int main() {
    usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);
        vii vec(n+1);
        vec[0] = mp(-2e9, -2e9);

        frange(i, n) {
            scd(vec[i+1].s);
            scd(vec[i+1].f);
        }

        sort(all(vec));

        SegTree<pii> segtree;
        segtree.init(n+1, mp(2e9, -1));
        segtree.build();
        // vii dp(n+1, mp(0, -1));
        vi dp1(n+1), dp2(n+1, -1e9), dp3(n+1, -1e9);
        forr(i, 1, n+1) {
            // pii pi = vec[i];
            // int id = lower_bound(all(vec), mp(pi.s, int(-2e9))) - vec.begin();
            // pii p = segtree.query(id, n);
            // int mi = p.f;
            // mi = min(mi, dp[id-1].f + 1);
            // dp[i].f = mi;
            // if(p.s != -1)
            //     segtree.update(p.s, mp(dp[p.s].s, p.s));
            // pii p2 = segtree.query(id, n);
            // if(p2.s!=-1)
            //     mi = p2.f;
            // else mi = dp[id-1].s+1;
            // if(p.s != -1)
            //     segtree.update(p.s, p);
            // mi = max(mi, dp[i-1].f);
            // dp[i].s = mi;
            // segtree.update(i, mp(dp[i].f, i));
            // printf("%d %d %d %d %d\n", p2.f, p2.s, id, dp[i].f, dp[i].s);
            dp1[i] = dp1[i-1] + (vec[i-1].)
        }
        printf("%d\n", dp[n].s);
    }
}