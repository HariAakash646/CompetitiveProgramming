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
            segtree[x] = min(segtree[x], val);
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
    freopen("boards.in", "r", stdin);
    freopen("boards.out", "w", stdout);
    int n, p;
    scd(n);
    scd(p);

    set<int> st;
    map<int, seti> imp;

    map<pii, pii> jump;

    st.insert(0);
    st.insert(n);
    imp[0].insert(0);
    imp[n].insert(n);

    frange(i, p) {
        int x1, y1, x2, y2;
        scd(x1);
        scd(y1);
        scd(x2);
        scd(y2);
        jump[mp(x1, y1)] = mp(x2, y2);
        imp[x1].insert(y1);
        imp[x2].insert(y2);
        st.insert(y1);
        st.insert(y2);
    }

    int sz = st.size();
    int id = 0;

    mpii mv;

    for(auto e : st) mv[e] = id++;

    SegTree<lli> segtree;
    segtree.init(sz, 1e17);
    segtree.build();
    map<pii, lli> dp;
    dp[mp(0, 0)] = 0;

    for(auto p1 : imp) {
        int x = p1.f;
        seti st1 = p1.s;
        // lli curr = 1e17;
        for(auto y : st1) {
            lli mi = 1e17;
            if(dp.find(mp(x, y)) != dp.end()) mi = dp[mp(x, y)];
            mi = min(mi, segtree.query(0, mv[y]) + x + y);
            if(jump.find(mp(x, y)) != jump.end()) {
                pii pt = jump[mp(x, y)];
                if(dp.find(pt) == dp.end()) dp[pt] = mi;
                else dp[pt] = min(mi, dp[pt]);
            }
            dp[mp(x, y)] = mi;
            segtree.update(mv[y], mi-x-y);
        }
    }

    printf("%lld", dp[mp(n, n)]);

}