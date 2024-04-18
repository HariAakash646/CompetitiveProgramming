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

int n, m;
vector<vii> graph;
vvi ancestor, val;
vi par, pval, depth;

void dfs(int x, int prev, int val, int d)
{
    par[x] = prev;
    pval[x] = val;
    depth[x] = d;
    for (auto e : graph[x])
    {
        if (e.f != prev)
            dfs(e.f, x, e.s, d + 1);
    }
}

int lift(int x, int c)
{
    frange(i, 20)
    {
        if (c & (1 << i))
            x = ancestor[x][i];
    }
    return x;
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    u = lift(u, depth[u] - depth[v]);
    // printf("%d %d\n", u, v);
    if (u == v)
        return u;
    for (int i = 19; i >= 0; i--)
    {
        int ut = ancestor[u][i];
        int vt = ancestor[v][i];

        if (ut != vt)
        {
            u = ut;
            v = vt;
        }
    }
    return ancestor[u][0];
}

int milift(int x, int c)
{
    int mi = 1e9;
    frange(i, 20)
    {
        if (c & (1 << i))
        {
            mi = min(mi, val[x][i]);
            x = ancestor[x][i];
        }
    }
    return mi;
}

int main()
{
    scd(n);
    scd(m);
    graph = vector<vii>(n + 1);

    frange(i, m)
    {
        int a, b, x;
        scd(a);
        scd(b);
        scd(x);
        graph[a].pb({b, x});
        graph[b].pb({a, x});
    }
    depth = par = pval = vi(n + 1);
    dfs(1, 0, 0, 0);
    ancestor = val = vvi(n + 1, vi(20));

    forr(i, 1, n + 1)
    {
        ancestor[i][0] = par[i];
        val[i][0] = pval[i];
    }

    forr(j, 1, 20)
    {
        forr(i, 1, n + 1)
        {
            ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
            val[i][j] = min(val[i][j - 1], val[ancestor[i][j - 1]][j - 1]);
        }
    }

    int q;
    scd(q);

    frange(_, q)
    {
        int a, b;
        scd(a);
        scd(b);
        int l = lca(a, b);
        int mi = milift(a, depth[a] - depth[l]);
        mi = min(mi, milift(b, depth[b] - depth[l]));
        printf("%d\n", mi);
    }
}