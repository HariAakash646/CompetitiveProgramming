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

lli ma = 0;

struct Data
{
    lli val = 0;
    int st, en;
};

vi sze, disset;
vector<Data> dat;
vvi lift;
vector<vll> liftma;
vvi graph;
vi depth;

void dfs(int x, int p, int d)
{
    lift[0][x] = p;
    liftma[0][x] = dat[x].val;
    depth[x] = d;
    for (auto e : graph[x])
    {
        if (e != p)
            dfs(e, x, d + 1);
    }
}

pair<lli, int> binlift(int x, int c)
{
    lli tot = 0;
    frange(i, 20)
    {
        if (c & (1 << i))
        {
            tot += liftma[i][x];
            x = lift[i][x];
        }
    }
    return mp(tot, x);
}

lli lca(int u, int v)
{
    if (depth[u] > depth[v])
        swap(u, v);
    auto out = binlift(v, depth[v] - depth[u]);

    v = out.s;
    if (u == v)
        return out.f + liftma[0][u];
    lli tot = out.f;
    for (int i = 19; i >= 0; i--)
    {
        int x = lift[i][u];
        int y = lift[i][v];
        if (x != y)
        {
            tot += liftma[i][u];
            tot += liftma[i][v];
            u = x;
            v = y;
        }
    }
    return tot + liftma[0][u] + liftma[0][v] + liftma[0][lift[0][u]];
}

Data combine(Data x, Data y)
{
    Data out = x;

    if (y.val > out.val)
        out = y;
    vi v1 = {x.st, x.en};
    vi v2 = {y.st, y.en};
    for (auto e : v1)
    {
        for (auto p : v2)
        {
            lli v = lca(e, p);
            if (v > out.val)
            {
                out.val = v;
                out.st = e;
                out.en = p;
            }
        }
    }
    return out;
}

int findf(int x)
{
    while (x != disset[x])
    {
        x = disset[x];
    }
    return x;
}

void unionf(int x, int y)
{
    x = findf(x);
    y = findf(y);
    if (x == y)
        return;
    if (sze[x] < sze[y])
    {
        swap(x, y);
    }
    disset[y] = x;
    sze[x] = max(sze[x], sze[y] + 1);
    dat[x] = combine(dat[x], dat[y]);
    ma = max(ma, dat[x].val);
}

int main()
{
    int n, q;
    scd(n);
    scd(q);

    graph = vvi(n + 1);
    lift = vvi(20, vi(n + 1));
    liftma = vector<vll>(20, vll(n + 1));
    depth = vi(n + 1);

    dat = vector<Data>(n + 1);
    sze = vi(n + 1, 1);
    disset = vi(n + 1);
    forr(i, 1, n + 1) disset[i] = i;

    vector<pair<int, pii>> edges(n - 1);
    frange(i, n - 1)
    {
        int a, b;
        lli v;
        scd(a);
        scd(b);
        scd(v);
        graph[a].pb(b);
        graph[b].pb(a);
        edges[i] = mp(v, mp(a, b));
    }

    sort(all(edges));

    forr(i, 1, n + 1)
    {
        sclld(dat[i].val);
        dat[i].st = dat[i].en = i;
        ma = max(ma, dat[i].val);
    }
    dfs(1, 0, 0);

    forr(i, 1, 20)
    {
        forr(j, 1, n + 1)
        {
            liftma[i][j] = liftma[i - 1][j] + liftma[i - 1][lift[i - 1][j]];
            lift[i][j] = lift[i - 1][lift[i - 1][j]];
        }
    }

    map<int, lli> val;
    val[0] = ma;

    for (auto p : edges)
    {
        unionf(p.s.f, p.s.s);
        val[p.f] = ma;
    }

    frange(i, q)
    {
        int e;
        scd(e);
        auto it = prev(val.upper_bound(e));
        printf("%lld\n", (*it).s);
    }
}