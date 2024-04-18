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
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

vvi graph;
vb vis;
vi vec;
vector<lli> dp1;

vi dfs(int node, vi &path)
{
    if (vis[node])
        return {};
    vis[node] = true;
    int a = -1e9;
    int b = -1e9;
    path.pb(node);
    if (path.size() >= 2)
        a = dp1[*prev(prev(path.end()))] + vec[node];
    if (path.size() >= 1)
        b = dp1[*prev(path.end())];
    dp1[node] = max(a, b);

    for (auto e : graph[node])
    {
        if (!vis[e])
        {
            auto p = dfs(e, path);
        }
    }
    path.pop_back();
    return path;
}

int main()
{
    int n, q;
    scd(n);
    scd(q);
    vec = vi(n + 1);
    forr(i, 1, n + 1)
    {
        scd(vec[i]);
    }
    graph = vvi(n + 1);
    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dp1 = vector<lli>(n + 10);
    vi path1 = {};
    dfs(1, path1);
    frange(_, q)
    {
        int a, b;
        scd(a);
        scd(b);

        printf("%lld\n", dp1[b]);
    }
}