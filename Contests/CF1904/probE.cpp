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
        vec.assign(size, 0);
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

int n, q;
vvi graph;
vi depth, st, en;
int timer = -1;
LazySegTree<lli> segtree;
 
void dfs1(int x, int p, int d) {
    depth[x] = d;
    st[x] = ++timer;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs1(e, x, d+1);
        } 
    }
    en[x] = timer;
}

vector<vector<pair<int, vi>>> quer;
vi out;
vi depx;

void dfs2(int x, int p, int d) {
    depx[d] = x;
    for(auto v : quer[x]) {
        for(auto e : v.s) {
            if(st[e] <= st[x] && st[x] <= en[e]) {
                segtree.update(0, n-1, -1e9);
                segtree.update(st[depx[depth[e]+1]], en[depx[depth[e]+1]], 1e9);
            }
            else {
                segtree.update(st[e], en[e], -1e9);
            }
        }
        out[v.f] = segtree.query(0, n-1);
        for(auto e : v.s) {
            if(st[e] <= st[x] && st[x] <= en[e]) {
                segtree.update(0, n-1, 1e9);
                segtree.update(st[depx[depth[e]+1]], en[depx[depth[e]+1]], -1e9);
            }
            else {
                segtree.update(st[e], en[e], 1e9);
            }
        }
    }
    for(auto e : graph[x]) {
        if(e != p) {
            segtree.update(0, n-1, 1);
            segtree.update(st[e], en[e], -2);
            dfs2(e, x, d+1);
            segtree.update(0, n-1, -1);
            segtree.update(st[e], en[e], 2);
        }
    }
}

int main() {
    // usaco();
    
    scd(n);
    scd(q);

    graph = vvi(n+1);
    st = en = depth = vi(n+1);
 
    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }



    dfs1(1, 0, 0);

    segtree.init(n, -2e9);
    forr(i, 1, n+1) {
        segtree.set(st[i], depth[i]);
    }
    segtree.build();
    
    quer = vector<vector<pair<int, vi>>>(n+1);    

    frange(j, q) {
        int x;
        scd(x);
        int k;
        scd(k);
        vi val(k);
        frange(i, k) scd(val[i]);

        quer[x].pb(mp(j, val));
    }

    out = vi(q);
    depx = vi(n+1);

    dfs2(1, 0, 0);

    for(auto e : out) printf("%d\n", e);

}