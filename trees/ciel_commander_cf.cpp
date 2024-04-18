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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct CentroidDecomposition
{

    vector<seti> graph;
    vi sub;
    vvi centg, adj;
    vvi lift, lift2;
    vi dist;
    vi out;
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

    int decomp(int x, int v)
    {
        int c = dfs(x, 0);
        int cen = centroid(x, 0, c);
        out[cen] = v;
        seti st = graph[cen];
        for (auto e : st)
        {
            graph[cen].erase(e);
            graph[e].erase(cen);
            int ce = decomp(e, v + 1);
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
        int root = decomp(1, 0);
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
};

int main()
{
    fastio();
    int n;
    cin >> n;

    CentroidDecomposition centroid;
    centroid.init(n);

    frange(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        centroid.setedge(a, b);
    }

    centroid.build();

    forr(i, 1, n + 1)
    {
        cout << char('A' + centroid.out[i]) << " ";
    }
}