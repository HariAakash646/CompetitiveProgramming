#include <bits/stdc++.h>

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

vvi binlift;
vi depth;
vvi graph;
vi par, val;
vvi binele;

int combine(int v1, int v2)
{

    return max(v1, v2);
}

void dfs(int x, int par, int d)
{
    depth[x] = d;
    for (auto e : graph[x])
    {
        if (e != par)
        {
            dfs(e, x, d + 1);
        }
    }
}

int lift(int x, int c)
{
    frange(i, 20)
    {
        if (c & (1 << i))
        {
            x = binlift[x][i];
        }
    }
    return x;
}

int liftele(int x, int c)
{
    int out = 0;
    frange(i, 20)
    {
        if (c & (1 << i))
        {
            out = combine(out, binele[x][i]);
            x = binlift[x][i];
        }
    }
    return out;
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    int out = liftele(u, depth[u] - depth[v]);

    // for (auto e : out)
    //     printf("%d ", e);
    // printf("\n");
    u = lift(u, depth[u] - depth[v]);
    if (u == v)
    {

        out = combine(out, val[v]);
        return out;
    }
    for (int i = 19; i >= 0; i--)
    {
        int ut = binlift[u][i];
        int vt = binlift[v][i];
        if (ut != vt)
        {
            out = combine(out, binele[u][i]);
            // for (auto e : out)
            //     printf("%d ", e);
            // printf("\n");
            out = combine(out, binele[v][i]);
            // for (auto e : out)
            //     printf("%d ", e);
            // printf("\n");
            u = ut;
            v = vt;
        }
    }
    int l = binlift[u][0];
    // vi vec(5);
    // vec[0] = val[l];
    // vec[1] = val[u];
    // vec[2] = val[v];
    out = combine(out, val[u]);
    out = combine(out, val[v]);
    out = combine(out, val[l]);
    return out;
}

int main()
{
    int n;
    scd(n);
    graph = vvi(n + 1);
    par = val = vi(n + 1);
    depth = vi(n + 1);
    forr(i, 1, n + 1)
    {
        scd(val[i]);
    }
    forr(i, 2, n + 1)
    {
        scd(par[i]);

        graph[par[i]].pb(i);
        graph[i].pb(par[i]);
    }
    dfs(1, 0, 0);

    binlift = vvi(n + 1, vi(20));
    forr(i, 1, n + 1)
    {
        binlift[i][0] = par[i];
    }
    forr(i, 1, 20)
    {
        forr(j, 1, n + 1)
        {
            binlift[j][i] = binlift[binlift[j][i - 1]][i - 1];
        }
    }
    binele = vvi(n + 1, vi(20));
    forr(i, 1, n + 1)
    {
        binele[i][0] = val[i];
    }
    forr(i, 1, 20)
    {
        forr(j, 1, n + 1)
        {
            binele[j][i] = combine(binele[binlift[j][i - 1]][i - 1], binele[j][i - 1]);
        }
    }
    int q;
    scd(q);
    frange(_, q)
    {
        int u, v, k;
        scd(u);
        scd(v);
        scd(k);
        k--;
        int out = lca(u, v);
        printf("%d\n", out);
        // for (auto e : out)
        //     printf("%d ", e);
        // printf("\n");
    }
}