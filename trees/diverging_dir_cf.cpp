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
        return min(x, y); // Any required operation
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

vector<vector<pair<int, lli>>> graph;
vvi lift;
vi depth;

int timer = 0;
vi st, en;

void dfs(int x, int d) {
    depth[x] = d;
    st[x] = timer++;
    for(auto e : graph[x]) {
        dfs(e.f, d+1);
    }
    en[x] = timer;
}

int binlift(int x, int c) {
    frange(i, 20) {
        if(c & (1<<i)) {
            x = lift[i][x];
        }
    }
    return x;
}

vector<pair<pii, lli>> edges;

vll dist;

void dfs_dist(int x) {
    for(auto e : graph[x]) {
        dist[e.f] = dist[x] + e.s;
        dfs_dist(e.f);
    }
} 

int main() {
    // usaco();
    int n, q;
    scd(n);
    scd(q);

    edges = vector<pair<pii, lli>>(2*n);
    graph = vector<vector<pair<int, lli>>>(n+1);

    lift = vvi(20, vi(n+1));

    frange(i, n-1) {
        int a, b;
        lli c;
        scd(a);
        scd(b);
        sclld(c);
        edges[i+1] = mp(mp(a, b), c);
        lift[0][b] = a;
        graph[a].pb({b, c});
    }

    vll upv(n+1);
    frange(i, n-1) {
        int a, b;
        lli c;
        scd(a);
        scd(b);
        sclld(c);
        edges[n+i] = mp(mp(a, b), c);
        upv[a] = c;

    }

    depth = vi(n+1);
    st = en = vi(n+1);
    dfs(1, 0);

    forr(i, 1, 20) {
        forr(j, 1, n+1) {
            lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }

    dist = vll(n+1);

    dfs_dist(1);

    LazySegTree<lli> segtree;
    segtree.init(timer+1, 1e18);

    forr(i, 1, n+1) {
        segtree.set(st[i], dist[i] + upv[i]);
    }
    segtree.build();

    frange(i, q) {
        int t;
        scd(t);
        if(t == 1) {
            int id;
            lli v;
            scd(id);
            sclld(v);
            if(id <= n-1) {
                auto p = edges[id];
                int a = p.f.f;
                int b = p.f.s;
                segtree.update(st[b], en[b]-1, v-p.s);
                edges[id].s = v;
            }
            else {
                auto p = edges[id];
                segtree.update(st[p.f.f], st[p.f.f], v-p.s);
                edges[id].s = v;
                upv[p.f.f] = v;
            }
        }
        else {
            int u, v;
            scd(u);
            scd(v);
            int vt = -1;
            if(depth[v] >= depth[u]) 
                vt = binlift(v, depth[v]- depth[u]);

            if(vt == u) {
                lli d1 = segtree.query(st[v], st[v]) - upv[v];
                lli d2 = segtree.query(st[u], st[u]) - upv[u];
                printf("%lld\n", d1 - d2);
            }
            else {
                lli dt = segtree.query(st[u], st[u]) - upv[u];
                lli d1 = segtree.query(st[u], en[u]-1) - dt;
                lli d2 = segtree.query(st[v], st[v]) - upv[v];
                printf("%lld\n", d1 + d2);
            }
        }
    }


}