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

vvi graph;
vi depth;
vvi lift;
vi st, en;
int timer = 0;

void dfs(int x, int p) {
    depth[x] = depth[p]+1;
    lift[0][x] = p;
    st[x] = ++timer;

    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x);
        }
    }
    en[x] = ++timer;
}

int binlift(int x, int c) {
    frange(i, 20) {
        if(c & (1<<i)) x = lift[i][x];
    }
    return x;
}

int lca(int u, int v) {
    if(depth[u] > depth[v]) swap(u, v);
    v = binlift(v, depth[v] - depth[u]);
    if(u == v) return v;

    for(int i=19; i>=0; i--) {
        int ut = lift[i][u];
        int vt = lift[i][v];
        if(ut != vt) {
            u = ut;
            v = vt;
        }
    }
    return lift[0][u];
}

template <class T>
struct BIT
{
    int size;
    vector<T> bit;
    vector<T> vec;

    BIT(int n) : size(n), bit(n + 1), vec(n + 1) {}

    int lsb(int x)
    {
        return x & (-x);
    }

    void set(int id, T v)
    {
        add(id, v - vec[id]);
    }

    void add(int id, T v)
    {
        if (id == 0)
            return;
        vec[id] += v;
        while (id <= size)
        {
            bit[id] += v;
            id += lsb(id);
        }
    }

    T query(int id)
    {
        T tot = 0;
        if (id == 0)
            return tot;
        while (id >= 1)
        {
            tot += bit[id];
            id -= lsb(id);
        }
        return tot;
    }
};

bool cmp(pair<int, pii> x, pair<int, pii> y) {
    return depth[x.f] > depth[y.f];
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);

    graph = vvi(n+1);
    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    depth = st = en = vi(n+1);
    lift = vvi(20, vi(n+1));
    dfs(1, 0);

    forr(i, 1, 20) {
        forr(j, 1, n+1) {
            lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }

    BIT<int> bit(2*n+1);

    vector<pair<int, pii>> vec(m);

    frange(i, m) {
        scd(vec[i].s.f);
        scd(vec[i].s.s);
        vec[i].f = lca(vec[i].s.f, vec[i].s.s);
    }

    sort(all(vec), cmp);
    int c = 0;
    vi out;
    for(auto p : vec) {
        int v = (bit.query(st[p.s.f]) - bit.query(st[p.f]-1)) + (bit.query(st[p.s.s]) - bit.query(st[p.f]-1));
        if(!v) {
            c++;
            bit.add(st[p.f], 1);
            bit.add(en[p.f], -1);
            out.pb(p.f);
        }
    }
    printf("%d\n", c);
    for(auto e : out) printf("%d ", e);
}