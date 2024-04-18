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

vb vis;
vvi graph;

int dfs(int x)
{
    if (vis[x])
        return 0;
    vis[x] = true;
    int c = 1;
    for (auto e : graph[x])
    {
        c += dfs(e);
    }
    return c;
}

int main()
{
    int n, m;
    scd(n);
    scd(m);

    graph = vvi(n + 1);

    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
    }
    vi out;
    forr(i, 1, n + 1)
    {
        vis = vb(n + 1);
        int c = dfs(i);
        if (c == n)
            out.pb(i);
    }
    if (out.size() == 1)
        printf("%d", out[0]);
    else
        printf("%d", -1);
}