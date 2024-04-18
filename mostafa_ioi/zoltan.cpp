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

const lli mod = 1e9 + 7;

struct Data {
    int len = -1e9;
    lli cnt = 0;
};

template <class T>
struct SegTree
{
    int size = 1, n;
    vector<T> segtree;
    vector<T> vec;
    vi lazy;

    T def; // Assign a value

    void init(int l, T defv)
    {
        n = l;
        def = defv;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, def);
        vec.assign(size, def);
        lazy = vi(2*size, 0);
    }

    T operation(T x, T y)
    {
        T out;
        if(x.len > y.len) {
            out = x;
        }
        else if(y.len > x.len) {
            out = y;
        }
        else {
            out = x;
            out.cnt += y.cnt;
            out.cnt %= mod;
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

    void propagate(int x, int l, int r)
    {
        segtree[x].len += lazy[x];
        if (l < r)
        {
            lazy[2 * x + 1] += lazy[x];
            lazy[2 * x + 2] += lazy[x];
        }
        lazy[x] = 0;
    }

    void update(int x, int l, int r, int id, T val)
    {
        propagate(x, l, r);
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
        propagate(2*x+1, l, mid);
        propagate(2*x+2, mid+1, r);
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
        if(lx > rx) return def;
        return query(0, 0, size - 1, lx, rx);
    }

    void update2(int x, int l, int r, int lx, int rx, int val)
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
            update2(2 * x + 1, l, mid, lx, rx, val);
        }
        if (rx >= mid + 1)
        {
            update2(2 * x + 2, mid + 1, r, lx, rx, val);
        }
        propagate(2 * x + 1, l, mid);
        propagate(2 * x + 2, mid + 1, r);
        recalculate(x);
    }

    void update2(int lx, int rx, int val)
    {
        if(lx > rx) return;
        update2(0, 0, size - 1, lx, rx, val);
    }
};

int main() {
    // usaco();
    int n;
    scd(n);

    SegTree<Data> seg1, seg2;
    Data tmp;
    seg1.init(n+2, tmp);
    seg2.init(n+2, tmp);
    tmp.len = 0;
    tmp.cnt = 1;
    seg1.set(0, tmp);
    seg2.set(n+1, tmp);
    seg1.build(); seg2.build();
    vi vec(n);

    seti st;
    frange(i, n) {
        scd(vec[i]);
        st.insert(vec[i]);
    }

    mpii mv;
    int id = 1;
    for(auto e : st) mv[e] = id++;

    frange(i, n) {
        int v = mv[vec[i]];
        Data out = seg1.query(0, v-1);
        out.len++;
        
        Data og = seg1.query(v, v);
        if(out.len < og.len) {
            out = og;
        }
        else if(out.len == og.len) {
            out.cnt += og.cnt;
            out.cnt %= mod;
        }
        
        seg1.update(v, out);
        seg2.update2(1, v-1, 1);
        out = seg2.query(v+1, n+1);

        out.len++;
        
        og = seg2.query(v, v);
        if(out.len < og.len) {
            out = og;
        }
        else if(out.len == og.len) {
            out.cnt += og.cnt;
            out.cnt %= mod;
        }
        
        seg2.update(v, out);
        seg1.update2(v+1, n, 1);
    }

    Data v1 = seg1.query(1, n);
    Data v2 = seg2.query(1, n);
    Data out;
    if(v1.len > v2.len) {
        out = v1;
    }
    else if(v2.len > v1.len) {
        out = v2;
    }
    else {
        out.len = v1.len;
        out.cnt = (v1.cnt + v2.cnt)%mod;
    }
    if(st.size() == 1) {
        lli out = n;
        forr(i, 1, n) {
            out *= 2;
            out %= mod;
        }
        printf("1 %lld", out);
    }
    else
    printf("%d %lld", v1.len, v1.cnt);
}