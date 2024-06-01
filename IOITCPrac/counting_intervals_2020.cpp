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

vi disset, sze;

int findf(int x) {
    if(x == disset[x]) return x;
    disset[x] = findf(disset[x]);
    return disset[x];
}

void unionf(int u, int v) {
    u = findf(u);
    v = findf(v);
    if(u==v) return;
    if(sze[u] > sze[v]) swap(u, v);
    disset[u] = v;
    sze[v] = max(sze[v], sze[u]+1);
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

        segtree.assign(2 * size, mp(def1, -1));
        vec.assign(size, def1);
    }

    T operation(T x, T y)
    {
        return x + y; // Any required operation
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
        if(segtree[x].s==-1) return;
        segtree[x].f = (r - l + 1) * segtree[x].s;
        if (l < r)
        {
            segtree[2 * x + 1].s = segtree[x].s;
            segtree[2 * x + 2].s = segtree[x].s;
        }
        segtree[x].s = -1;
    }

    void update(int x, int l, int r, int lx, int rx, T val)
    {
        propagate(x, l, r);
        if (lx <= l && r <= rx)
        {
            segtree[x].s = val;
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
            return 0;
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

vvi minv;
vi vec;

void init(int n) {
    minv = vvi(20, vi(n+1));
    forr(i, 1, n+1) minv[0][i] = vec[i];

    forr(i, 1, 20) {
        forr(j, 1, n+1) {
            minv[i][j] = max(minv[i-1][j], minv[i-1][min(n, j+(1<<(i-1)))]);
        }
    }
}

int query(int l, int r) {
    int len = r - l + 1;
    int msb = 31 - __builtin_clz(len);

    return max(minv[msb][l], minv[msb][r-(1<<msb)+1]);
}


int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);

    disset = sze = vi(n+1);
    forr(i, 1, n+1) disset[i] = i;

    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        unionf(a, b);
    }

    vi cnt(n+1), ma(n+1), mi(n+1, 1e9);

    forr(i, 1, n+1) {
        int x = findf(i);
        cnt[x]++;
        mi[x] = min(mi[x], i);
        ma[x] = max(ma[x], i);
        
    }

    forr(i, 1, n+1) {
        mi[i] = mi[findf(i)];
        ma[i] = ma[findf(i)];
    }

    vec = ma;
    init(n);
    LazySegTree<int> tree;
    tree.init(n+1, 1);
    tree.build();
    lli c = 0;

    forr(i, 1, n+1) {
        if(mi[i] != i) tree.update(mi[i]+1, i, 0);
        if(ma[i] > i) continue;
        int lo = 1;
        int hi = i;
        while(lo != hi) {
            int mid = (lo+hi)/2;
            if(query(mid, i) <= i) hi = mid;
            else lo = mid+1;
        }
        // forr(i, 1, n+1) printf("%d ", tree.query(i, i));
        // printf("\n");
        // printf("%d %d %d\n", i, lo, tree.query(lo, i));
        c += tree.query(lo, i);
    }

    printf("%lld", c);
}