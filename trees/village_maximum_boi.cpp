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
    vi out, vec;
    int n;

    void init(int sz)
    {
        n = sz;
        adj = centg = vvi(n + 1);
        graph = vector<seti>(n + 1);
        dist = sub = vi(n + 1);
        out = vi(n + 1);
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

    void partition(int x, int p)
    {
        vec.pb(x);
        // printf("%d ", x);
        for (auto e : adj[x])
        {
            if (e != p)
            {
                partition(e, x);
            }
        }
    }

    int decomp(int x)
    {
        int c = dfs(x, 0);
        int cen = centroid(x, 0, c);
        vii v;
        for (auto e : adj[cen])
        {
            v.pb(mp(sub[e], e));
        }
        sort(all(v), greater<>());
        for (auto e : v)
        {
            partition(e.s, cen);
            // printf("\n");
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

        lli tot = 0;
        forr(i, 1, n + 1)
        {
            tot += dist[i];
        }
        printf("%lld\n", 2 * tot);
        vec.pb(root);
        frange(i, vec.size())
        {
            out[vec[i]] = vec[(i + n / 2) % n];
        }

        // if (i1 == i2)
        // {
        //     out[root] = vec[i1];
        //     out[vec[i1]] = root;
        // }
        // else
        // {
        //     int v;
        //     v = n;
        //     if (root == n)
        //         v = 1;
        //     int id = find(all(out), v) - out.begin();
        //     out[root] = root;
        //     swap(out[id], out[root]);
        // }
        forr(i, 1, n + 1) printf("%d ", out[i]);
    }
};

int main()
{
    int n;
    scd(n);

    CentroidDecomposition tree;
    tree.init(n);

    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        tree.setedge(a, b);
    }
    tree.build();
}
