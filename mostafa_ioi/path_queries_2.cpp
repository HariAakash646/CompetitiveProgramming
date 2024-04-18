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
 
    T def; // Assign a value
 
    void init(int l, T defv)
    {
        n = l;
        def = defv;
 
        while (size < n)
            size *= 2;
 
        segtree.assign(2 * size, def);
    }
 
    T operation(T x, T y)
    {
        return max(x, y); // Any required operation
    }
 
    void build()
    {
        for (int i = n - 1; i > 0; --i)
            segtree[i] = operation(segtree[i << 1], segtree[i << 1 | 1]);
    }
 
    void set(int id, T val)
    {
        segtree[n + id] = val;
    }
 
    void update(int id, T val)
    {
        id += n;
        for (segtree[id] = val; id > 1; id >>= 1)
            segtree[id >> 1] = operation(segtree[id], segtree[id ^ 1]);
    }
 
    T query(int l, int r)
    {
        T res = def;
        r++;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = operation(res, segtree[l++]);
            if (r & 1)
                res = operation(res, segtree[--r]);
        }
        return res;
    }
};

vi sze;
vi val;
vi heavy, head, pos, depth, par;

vvi graph;

SegTree<int> segtree;

int dfs_sze(int x, int p) {
    sze[x] = 1;
    depth[x] = depth[p] + 1;
    par[x] = p;
    int ma = 0;

    for(auto e : graph[x]) {
        if(e != p) {
            int sz = dfs_sze(e, x);
            sze[x] += sz;
            if(sz > ma) {
                ma = sz;
                heavy[x] = e;
            }
        }
    }

    return sze[x];
}

int id = 0;

void decompose(int x, int h, int p) {
    // printf("%d\n", x);
    head[x] = h;
    pos[x] = id++;
    segtree.set(pos[x], val[x]);
    if(heavy[x])
        decompose(heavy[x], h, x);

    for(auto e : graph[x]) {
        if(e != p && e != heavy[x]) {
            decompose(e, e, x);
        } 
    }

}

void init(int n) {
    segtree.init(n, 0);
    par = depth = head = pos = heavy = sze = vi(n+1);
    dfs_sze(1, 0);
    decompose(1, 1, 0);
    segtree.build();
}

int query(int a, int b) {
    int out = 0;
    while(head[a] != head[b]) {
        // printf("")
        if(depth[head[a]] > depth[head[b]]) swap(a, b);
        out = max(out, segtree.query(pos[head[b]], pos[b]));
        b = par[head[b]];
    }
    if(pos[a] > pos[b]) swap(a, b);
    out = max(out, segtree.query(pos[a], pos[b]));
    return out;
}

int main() {
    // usaco();
    int n, q;
    scd(n);
    scd(q);
    val = vi(n+1);

    forr(i, 1, n+1) scd(val[i]);
    graph = vvi(n+1);

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    init(n);

    frange(_, q) {
        int t;
        scd(t);
        int a, b;
        scd(a);
        scd(b);
        if(t == 1) {
            segtree.update(pos[a], b);
        }
        else {
            printf("%d ", query(a, b));
        }
    }
}