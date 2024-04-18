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

vvi graph;
vii edges;
vi depth;
string out;

void dfs(int x, int par)
{
    depth[x] = depth[par] + 1;
    for (auto e : graph[x])
    {
        if (e != par)
        {
            dfs(e, x);
        }
    }
}

void dfs2(int x, int par)
{
    out[x - 1] = '1';
    for (auto e : graph[x])
    {
        if (e != par)
        {
            dfs2(e, x);
        }
    }
}

int main()
{
    int n, m, p;
    cin >> n >> m >> p;

    if (m == n - 1)
    {
        graph = vvi(n + 1);
        edges = vii(m);
        depth = vi(n + 1);
        frange(i, m)
        {
            int a, b;
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
            edges[i] = mp(a, b);
        }
        dfs(1, 0);
        printf("%d\n", p);
        frange(i, p)
        {
            int u = edges[i].f;
            int v = edges[i].s;
            if (depth[u] > depth[v])
                swap(u, v);
            out = "";
            frange(i, n) out += '0';
            dfs2(v, u);
            cout << out << "\n";
        }
    }
    else
    {
        printf("%d\n", p);
        int id = 2;
        frange(j, p)
        {
            string out = "";
            frange(i, n) out += '0';
            frange(i, min(n, 64))
            {
                if (id & (1LL << i))
                {
                    out[i] = '1';
                }
            }
            id += 2;
            cout << out << "\n";
        }
    }
}