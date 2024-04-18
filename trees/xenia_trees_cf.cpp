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

struct CentroidDecomposition
{

    vector<seti> graph;
    vi sub;
    vvi centg, adj;
    vvi lift, lift2;
    vi dist;
    vi red;
    int n;

    void init(int sz)
    {
        n = sz;
        adj = centg = vvi(n + 1);
        graph = vector<seti>(n + 1);
        dist = sub = vi(n + 1);
        red = vi(n + 1, 1e9);
        lift2 = lift = vvi(21, vi(n + 1));
    }

    void setedge(int u, int v)
    {
        graph[u].insert(v);
        graph[v].insert(u);
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int dfs(int x, int par)
    {
        sub[x] = 1;
        for (auto e : graph[x])
        {
            if (e != par)
            {
                sub[x] += dfs(e, x);
            }
        }
        return sub[x];
    }

    int centroid(int x, int p, int n)
    {
        for (auto e : graph[x])
        {
            if (e != p && sub[e] > n / 2)
            {
                int v = centroid(e, x, n);
                return v;
            }
        }
        return x;
    }

    int decomp(int x)
    {
        int c = dfs(x, 0);
        int cen = centroid(x, 0, c);
        seti st = graph[cen];
        for (auto e : st)
        {
            graph[cen].erase(e);
            graph[e].erase(cen);
            int ce = decomp(e);
            centg[cen].pb(ce);
            centg[ce].pb(cen);
            lift[0][ce] = cen;
        }
        return cen;
    }

    void distdfs(int x, int p, int d)
    {
        dist[x] = d;
        lift2[0][x] = p;
        for (auto e : adj[x])
        {
            if (e != p)
            {
                distdfs(e, x, d + 1);
            }
        }
    }

    void build()
    {
        int root = decomp(1);
        distdfs(root, 0, 0);

        forr(i, 1, 21)
        {
            forr(j, 1, n + 1)
            {
                lift[i][j] = lift[i - 1][lift[i - 1][j]];
                lift2[i][j] = lift2[i - 1][lift2[i - 1][j]];
            }
        }
    }

    int binlift(int x, int c, vvi &lift)
    {
        frange(i, 21)
        {
            if (c & (1 << i))
            {
                x = lift[i][x];
            }
        }
        return x;
    }

    int lca(int u, int v, vvi &lift)
    {
        if (dist[u] > dist[v])
            swap(u, v);
        v = binlift(v, dist[v] - dist[u], lift);
        if (u == v)
            return u;

        for (int i = 20; i >= 0; i--)
        {
            if (lift[i][u] != lift[i][v])
            {
                u = lift[i][u];
                v = lift[i][v];
            }
        }
        return lift[0][u];
    }

    int distf(int x, int y)
    {
        int l = lca(x, y, lift2);
        return dist[x] + dist[y] - 2 * dist[l];
    }

    int query(int u)
    {
        int x = u;
        int mi = 1e9;
        while (x)
        {
            mi = min(mi, red[x] + distf(x, u));
            x = lift[0][x];
        }
        return mi;
    }

    void update(int u)
    {
        int x = u;
        while (x)
        {
            red[x] = min(red[x], distf(u, x));
            x = lift[0][x];
        }
    }
};

int main()
{
    int n, m;
    scd(n);
    scd(m);

    CentroidDecomposition centroid;
    centroid.init(n);

    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        centroid.setedge(a, b);
    }

    centroid.build();
    centroid.update(1);
    frange(_, m)
    {
        int t, u;
        scd(t);
        scd(u);
        if (t == 1)
            centroid.update(u);
        else
            printf("%d\n", centroid.query(u));
    }
}