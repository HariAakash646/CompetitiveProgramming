#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

lli mod = 1e9 + 7;

int n;
lli g;

struct node
{
    int id;
    lli dist = 0, toll = 0;
};

vector<vector<node>> graph;
vii euler;
vii segtree;

void dfs(int x, int prev, int d)
{
    int c = 0;
    for (auto e : graph[x])
    {
        if (e.id != prev)
        {
            euler.pb({x, d});
            dfs(e.id, x, d + 1);
            euler.pb({x, d});
            c++;
        }
    }
    if (!c)
        euler.pb({x, d});
}

pii calculate(pii x, pii y)
{
    if (x.s < y.s)
        return x;
    else
        return y;
}

void build(int x, int l, int r)
{
    if (l == r)
    {
        segtree[x] = euler[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * x + 1, l, mid);
    build(2 * x + 2, mid + 1, r);
    segtree[x] = calculate(segtree[2 * x + 1], segtree[2 * x + 2]);
}

pii query(int x, int l, int r, int lx, int rx)
{
    if (lx <= l && r <= rx)
    {
        return segtree[x];
    }
    if (lx > r || rx < l)
    {
        return {-1, 1e9};
    }
    int mid = (l + r) / 2;
    pii o1 = query(2 * x + 1, l, mid, lx, rx);
    pii o2 = query(2 * x + 2, mid + 1, r, lx, rx);

    return calculate(o1, o2);
}

vll dist;

void dfs2(int x, int prev, lli d)
{
    dist[x] = d;
    for (auto e : graph[x])
    {
        if (e.id != prev)
        {
            dfs2(e.id, x, (d + e.dist) % mod);
        }
    }
}

// st6

pair<lli, bool> dfs16(int x, int v, int prev, lli d)
{
    if (x == v)
    {
        return {d, true};
    }

    for (auto e : graph[x])
    {
        if (e.id != prev)
        {
            pii p = dfs16(e.id, v, x, e.toll);
            if (p.s)
            {
                return {(p.f + d) % mod, true};
            }
        }
    }
    return {0, false};
}

pair<lli, bool> dfs26(int x, int v, int prev, lli d)
{
    if (x == v)
    {
        return {0, true};
    }

    for (auto e : graph[x])
    {
        if (e.id != prev)
        {
            pii p = dfs26(e.id, v, x, (d - e.toll + mod) % mod);
            if (p.s)
            {
                d -= e.toll;
                d = (d + mod) % mod;
                return {(p.f + (d * e.dist) % mod) % mod, true};
            }
        }
    }
    return {0, false};
}

pair<lli, bool> dfs36(int x, int v, int prev, lli d)
{
    if (x == v)
    {
        return {d, true};
    }

    for (auto e : graph[x])
    {
        if (e.id != prev)
        {
            pii p = dfs36(e.id, v, x, e.dist);
            if (p.s)
            {
                return {(p.f + d) % mod, true};
            }
        }
    }
    return {0, false};
}

int main()
{
    scd(n);
    sclld(g);
    lli tc = 0;
    graph = vector<vector<node>>(n + 1);
    frange(i, n - 1)
    {
        node e1, e2;
        int a, b;
        scd(a);
        scd(b);
        e1.id = b;
        e2.id = a;
        sclld(e1.dist);
        sclld(e1.toll);

        e2.dist = e1.dist;
        e2.toll = e1.toll;
        tc = e1.toll;
        graph[a].pb(e1);
        graph[b].pb(e2);
    }
    int q;
    scd(q);
    dfs(1, 0, 1);

    vi idx(n + 1, -1);

    frange(i, euler.size())
    {
        auto p = euler[i];
        if (idx[p.f] == -1)
        {
            idx[p.f] = i;
        }
    }
    vll toll(n + 1);
    forr(i, 1, n + 1)
    {
        toll[i] = (toll[i - 1] + ((i - 1) * tc) % mod) % mod;
    }
    int k = euler.size();
    int sze = 1;

    while (sze < k)
        sze *= 2;
    segtree = vii(2 * sze);
    forr(i, k, sze) euler.pb({-1, 1e9});
    build(0, 0, sze - 1);

    dist = vll(n + 1);
    dfs2(1, 0, 0);
    // for (auto e : toll)
    //     printf("%d ", e);
    frange(_, q)
    {
        int v;
        scd(v);
        int x, y;
        scd(x);
        scd(y);

        int lca = query(0, 0, sze - 1, min(idx[x], idx[y]), max(idx[x], idx[y])).f;

        printf("%lld\n", (toll[max(0LL, min(n, dist[x] + dist[y] - 2 * dist[lca]))] % mod + ((((dist[x] + dist[y] - 2 * dist[lca] + 5 * mod) % mod) * g) % mod)) % mod);
    }
}