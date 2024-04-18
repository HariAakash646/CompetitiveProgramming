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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
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
        return x + y; // Any required operation
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
        if(lx > rx) return 0;
        return query(0, 0, size - 1, lx, rx);
    }
};

int main() {
    // usaco();
    int n, m, q;
    scd(n);
    scd(m);
    scd(q);

    vector<pair<int, lli>> vec(m);

    frange(i, m) scd(vec[i].f);

    frange(i, m) sclld(vec[i].s);

    multiset<pair<int, lli>> st;

    for(auto p : vec) st.insert(p);

    SegTree<lli> segtree;
    segtree.init(n+1, 0);

    for(auto it=st.begin(); it != prev(st.end()); it++) {
        lli x = (*next(it)).f - (*it).f - 1;
        lli v = (*it).s;
        lli tot = ((x * (x+1))/2) * v;
        segtree.set((*it).f, tot);

    }

    segtree.build();    

    frange(_, q) {
        int t;
        scd(t);
        if(t == 1) {
            int x;
            lli v;
            scd(x);
            sclld(v);
            auto it = st.lower_bound(mp(x, 0));
            lli x1 = (*it).f - x - 1;
            lli tot = (x1 * (x1 + 1) / 2) * v;
            segtree.update(x, tot);
            it--;
            x1 = x - (*it).f - 1;
            lli v2 = (*it).s;
            tot = (x1 * (x1 + 1) / 2) * v2;
            segtree.update((*it).f, tot);
            st.insert(mp(x, v));
        }
        else {
            int l, r;
            scd(l);
            scd(r);
            auto it = st.lower_bound(mp(l, 0));
            int l1 = (*it).f;
            auto it2 = st.lower_bound(mp(r, 0));
            int r1 = l1-1;
            auto it3 = st.lower_bound(mp(l, 0));
            auto it4 = st.lower_bound(mp(r, 0));
            it2--;
            if(l == r) {
                lli v = 0;
                if(it != st.begin()) v = (*prev(it)).s;
                printf("%lld\n", (l1 - l) * v);
                continue;
            }
            if(prev(it3) == prev(it4)) {
                it3--;
                lli v = (*it3).s;
                
                lli x = (*it4).f - l;
                lli x2 = (*it4).f - r - 1;
                // printf("%lld %lld %lld ", v, x, x2);
                lli d = x * (x+1)/2 - x2 * (x2+1)/2;
                printf("%lld\n", v * d);
                continue;
            }
            if(it2 != st.begin()) {
                r1 = (*prev(it2)).f;
            }
            lli tot = segtree.query(l1, r1);
            // printf("%lld ", tot);
            if(it != st.begin()) {
                lli v = (*prev(it)).s;
                lli x = l1 - l;
                tot += v * (x * (x+1)/2);

            }
            // printf("%lld ", tot);
            if(it2 != prev(st.end())) {
                lli v = (*it2).s;
                lli x = (*next(it2)).f - (*it2).f - 1;
                lli x2 = (*next(it2)).f - r - 1;
                lli d = x * (x+1)/2 - x2 * (x2+1)/2;
                tot += v * d;
            }
            printf("%lld\n", tot);

        }
    }



}