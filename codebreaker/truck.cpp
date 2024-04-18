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
        add(id, (v - vec[id] + mod) % mod);
    }

    void add(int id, T v)
    {
        if (id == 0)
            return;
        vec[id] += v+mod;
        vec[id] %= mod;
        while (id <= size)
        {
            bit[id] += v+mod;
            bit[id] %= mod;
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
            tot %= mod;
            id -= lsb(id);
        }
        return tot;
    }

};

vector<vector<pair<int, pair<lli, lli>>>> graph;
vi depth;
vll dist;
vvi lift;
vll val;
vi st, en;
int timer = 0;

void dfs(int x, int p) {
    lift[0][x] = p;
    st[x] = ++timer;
    for(auto e : graph[x]) {
        if(e.f != p) {
            dist[e.f] = (dist[x] + e.s.f) % mod;
            depth[e.f] = depth[x]+1;
            val[e.f] = e.s.s;
            dfs(e.f, x);
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

int main() {
    // usaco();
    int n;
    lli g;
    scd(n);
    sclld(g);

    graph = vector<vector<pair<int, pair<lli, lli>>>>(n+1);

    frange(i, n-1) {
        int a, b;
        lli d, t;
        scd(a);
        scd(b);
        sclld(d);
        sclld(t);
        graph[a].pb(mp(b, mp(d, t)));
        graph[b].pb(mp(a, mp(d, t)));
    }

    val = dist = vll(n+1);
    st = en = depth = vi(n+1);
    lift = vvi(20, vi(n+1));

    dfs(1, 0);

    forr(i, 1, 20) {
        forr(j, 1, n+1) {
            lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }

    BIT<lli> bit(2*n+1);
    BIT<lli> bit2(2*n+1);
    BIT<lli> bit3(2*n+1);
    forr(i, 1, n+1) {
        lli v = val[i] * dist[lift[0][i]] % mod;
        bit.set(st[i], v);
        bit.set(en[i], -v);
        bit2.set(st[i], val[i]);
        bit2.set(en[i], -val[i]);
        v = val[i] * dist[i] % mod;
        bit3.set(st[i], v);
        bit3.set(en[i], -v);
    }

    int q;
    scd(q);

    frange(_, q) {
        int t;
        scd(t);
        if(t == 1) {
            int x, y;
            scd(x);
            scd(y);
            int l = lca(x, y);
            lli d = ((dist[x] + dist[y] - 2*dist[l] + 2*mod) % mod) * g % mod;
            lli v1 = ((((bit2.query(st[x]) - bit2.query(st[l]) + mod) % mod) * dist[x]) % mod - (bit3.query(st[x]) - bit3.query(st[l]) + mod) % mod + mod) % mod;
            lli v2 = (((bit.query(st[y]) - bit.query(st[l]) + mod) % mod) - ((bit2.query(st[y]) - bit2.query(st[l]) + mod) % mod) * dist[l] % mod + mod) % mod;
            lli v3 = ((dist[x] - dist[l] + mod) % mod) * ((bit2.query(st[y]) - bit2.query(st[l]) + mod) % mod) % mod;
            lli out = (v1 + v2 + d + v3) % mod;

            printf("%lld\n", out);
        }
        else {
            int i, x, y;
            lli d;
            scd(x);
            scd(y);
            sclld(d);
            if(depth[x] > depth[y]) i = x;
            else i = y;
            val[i] = d;
            lli v = val[i] * dist[lift[0][i]] % mod;
            bit.set(st[i], v);
            bit.set(en[i], -v);
            bit2.set(st[i], val[i]);
            bit2.set(en[i], -val[i]);
            v = val[i] * dist[i] % mod;
            bit3.set(st[i], v);
            bit3.set(en[i], -v);
        }
    }
}