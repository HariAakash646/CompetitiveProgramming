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
    // usaco();
    int t;
    scd(t);
    frange(_, t) {
        int n;
        scd(n);

        vll vec(n+1);
        vll pref(n+1);

        forr(i, 1, n+1) {
            sclld(vec[i]);
            // printf("%lld ", vec[i]);
            pref[i] = pref[i-1] + vec[i];
        }

        if(pref[n] < 0) {
            printf("-1\n");
            continue;
        }

        // printf("%lld ", pref[n]);

        vector<pair<lli, lli>> pref2(n);
        frange(i, n) {
            pref2[i] = mp(pref[i+1], i+1);
        }

        pref2.pb(mp(0, 0));

        sort(all(pref2));
        vi pos(n+1), val(n+1);

        frange(i, n+1) {
            pos[pref2[i].s] = i;
            val[i] = pref2[i].s;
        }

        SegTree<lli> segtree;
        segtree.init(n+1, 1e18);

        segtree.set(pos[0], 0);

        segtree.build();

        queue<int> q;
        vll dp(n+1);

        forr(i, 1, n+1) {            
            if(vec[i] < 0) {
                while(q.size()) {
                    int e = q.front();
                    q.pop();
                    // if(vec[e+1] >= 0)
                        segtree.update(pos[e], dp[e]-e);
                    // else segtree.update(pos[e], dp[e]-e);
                }
                q = {};
            }
            lli v = segtree.query(0, pos[i]) + i;
            dp[i] = v-1;
            if(vec[i] >= 0) dp[i] = min(dp[i-1], v-1);
            q.push(i);
        }
        lli mi = 1e18;
        for(int i=n; i>=0; i--) {
            mi = min(mi, dp[i]);
            if(vec[i] < 0) break;
        }
        printf("%lld\n", mi);

    }
}