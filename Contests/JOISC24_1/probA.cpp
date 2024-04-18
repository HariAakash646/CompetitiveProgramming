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
    vector<pair<T, T>> segtree;
    vector<T> lazy;
    vector<T> vec;


    void init(int l)
    {
        n = l;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, mp(0LL, 0LL));
        lazy.assign(2*size, 0LL);
        vec.assign(size, 0LL);
    }

    pair<T, T> operation(pair<T, T> x, pair<T, T> y)
    {
        pair<T, T> out;
        out.f = x.f + y.f;
        out.s = max(x.f, y.f);
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
            segtree[x] = mp(vec[l], vec[l]);
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
        segtree[x].f += (r - l + 1) * lazy[x];
        segtree[x].s += lazy[x];
        if (l < r)
        {
            lazy[2 * x + 1] += lazy[x];
            lazy[2 * x + 2] += lazy[x];
        }
        lazy[x] = 0;
    }

    void update(int x, int l, int r, int lx, int rx, T val)
    {
        propagate(x, l, r);
        if (lx <= l && r <= rx)
        {
            lazy[x] += val;
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

    T query_sum(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            return 0;
        }
        propagate(x, l, r);
        if (lx <= l && r <= rx)
        {
            return segtree[x].f;
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

    int query_id(int x, int l, int r, T v) {
        propagate(x, l, r);
        // printf("%d\n", segtree[x].s);
        if(l == r) {
            if(segtree[x].s >= v) return l;
            else return -1;
        }
        
        int mid = (l+r)/2;
        propagate(2*x+1, l, mid);
        if(segtree[2*x+1].s >= v) return query_id(2*x+1, l, mid, v);
        propagate(2*x+2, mid+1, r);
        if(segtree[2*x+2].s >= v) return query_id(2*x+2, mid+1, r, v);
        return -1;
    }

    int query_id(T v) {
        return query_id(0, 0, size-1, v);
    }
};

int n, q;
lli d;
vll vec;
vll lef, rig, rig2;
vll suf, sufv;
vll val, out;
vector<pair<int, pii>> quer;
LazySegTree<lli> segtree;

void rec(int l, int r, vector<pair<int, pii>> quer) {
    if(l > r) return;
    if(l == r) {    
        for(auto p : quer) {
            out[p.f] = 0;
        }
        return;
    }
    int mid = (l + r)/2;
    lef[mid] = 0;
    val[mid] = vec[mid];
    sufv[mid] = suf[mid] = 0;
    map<lli, int> mv;
    mv[0] = mid;
    for(int i=mid-1; i>=l; i--) {
        if(vec[i] > val[i+1]) {
            lef[i] = lef[i+1] + ((vec[i] - val[i+1] + d - 1) / d);
            val[i] = vec[i] - ((vec[i] - val[i+1] + d - 1) / d) * d;
        }
        else {
            val[i] = vec[i];
            lef[i] = lef[i+1];
        }
        suf[i] = suf[i+1] + (val[i+1] - val[i])/d;
        sufv[i] = sufv[i+1] + suf[i];
        mv[suf[i]] = i;
    }
    rig[mid] = 0;
    rig[mid+1] = 0;
    rig2[mid+1] = 0;
    val[mid+1] = vec[mid+1];
    forr(i, mid+1, r+1) segtree.update(i, i, -segtree.query_sum(i, i));
    for(int i=mid+2; i<=r; i++) {
        if(vec[i] < vec[i-1]) {
            rig2[i] = rig2[i-1] + max(0LL, ((vec[i-1] - vec[i] + d - 1) / d) - segtree.query_sum(mid+1, mid+1));
            int id = segtree.query_id((vec[i-1] - vec[i] + d - 1) / d);
            if(id == -1) id = mid;
            // printf("%d %d\n", i, id);
            rig[i] = rig[i-1] + ((vec[i-1] - vec[i] + d - 1) / d) * (i - id - 1) - segtree.query_sum(mid+1, id);
        }
        else {
            segtree.update(mid+1, i, (vec[i] - vec[i-1])/d);
            rig[i] = rig[i-1];
            rig2[i] = rig2[i-1];
        }
    }

    forr(i, mid+1, r+1) segtree.update(i, i, -segtree.query_sum(i, i));
    

    vector<pair<int, pii>> lv, rv;

    for(auto p : quer) {
        if(p.s.f <= mid && p.s.s > mid) {
            lli tot = lef[p.s.f] + rig[p.s.s];
            lli v = 0;
            // printf("%d %d:  ", p.s.f, p.s.s);
            // printf("%lld %lld ", lef[p.s.f], rig[p.s.s]);
            lli v1 = vec[mid+1] - d * rig2[p.s.s];
            if(val[mid] > v1) {
                lli dif = (val[mid] - v1 + d - 1) / d;
                auto it = mv.upper_bound(dif);
                it--;
                int id = max(p.s.f, (*it).s);
                if(id == p.s.f) {
                    v = dif - suf[id];
                }
                tot += dif * (mid - id + 1) - sufv[id];
                // printf("%lld %lld %lld ", v, dif, sufv[id]);
            }
            // printf("\n");
            if(val[p.s.f] - v * d >= 0)
                out[p.f] = tot;
            else out[p.f] = -1;
        }
        else if(p.s.s <= mid) {
            lv.pb(p);
        }
        else {
            rv.pb(p);
        }
    }

    if(lv.size()) rec(l, mid, lv);
    if(rv.size()) rec(mid+1, r, rv);

}

int main() {
    // usaco();
    scd(n);
    sclld(d);

    vec = vll(n+1);
    forr(i, 1, n+1) sclld(vec[i]);

    scd(q);
    quer = vector<pair<int, pii>>(q);

    frange(i, q) {
        quer[i].f = i;
        scd(quer[i].s.f);
        scd(quer[i].s.s);
    }

    rig2 = sufv = lef = rig = val = suf = vll(n+1);
    out = vll(q);
    segtree.init(n+1);
    segtree.build();
    rec(1, n, quer);

    frange(i, q) printf("%lld\n", out[i]);
}