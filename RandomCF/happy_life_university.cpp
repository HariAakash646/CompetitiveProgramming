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

vvi graph, colg;
vi vec;
vi st, en, near;
vi coln;
int timer = -1;

void dfs(int x, int p) {
    near[x] = coln[vec[x]];
    st[x] = ++timer;
    coln[vec[x]] = x;
    for(auto e : graph[x]) {
        if(e!=p) {
            dfs(e, x);
            
        }
    }
    coln[vec[x]] = near[x];
    en[x] = timer;
}

LazySegTree<lli> segtree;
lli ma = 1;

void dfs2(int x, int p) {
    
    seti out;
    lli m1 = 1;
    lli m2 = 1;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs2(e, x);
            
        }
    }
    for(auto p : colg[x]) segtree.update(st[p], en[p], -1);
    segtree.update(st[x], en[x], 1);
    for(auto e : graph[x]) {
        if(e != p) {
            lli v = segtree.query(st[e], en[e]);
            if(v > m1) {
                m2 = m1;
                m1 = v;
            }
            else m2 = max(m2, v);
        }
    }
    // forr(i, 1, vec.size()) printf("%lld ", segtree.query(st[i], st[i]));
    // printf("\n");
    ma = max(ma, m1*m2);
    
}

int main() {
    // usaco();
    int t;
    scd(t);
    frange(_, t) {
        int n;
        scd(n);
        graph = vvi(n+1);
        vec = vi(n+1);

        forr(i, 2, n+1) {
            int p;
            scd(p);
            graph[p].pb(i);
            graph[i].pb(p);
        }

        forr(i, 1, n+1) scd(vec[i]);

        st = en = vi(n+1);
        coln = near = vi(n+1, -1);
        timer = -1;
        dfs(1, 0);
        colg = vvi(n+1);
        forr(i, 1, n+1) {
            if(near[i] != -1) colg[near[i]].pb(i);
        }

        segtree.init(timer+1, 0);

        ma = 1;
        dfs2(1, 0);

        printf("%lld\n", ma);
    }
}