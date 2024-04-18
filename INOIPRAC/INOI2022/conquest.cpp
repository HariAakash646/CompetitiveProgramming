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
vi path;

bool dfs(int x, int par, int v)
{
    if (x == v)
        return true;
    for (auto e : graph[x])
    {
        if (e != par)
        {
            bool out = dfs(e, x, v);
            if (out)
            {
                path.pb(e);
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, q;
    scd(n);
    scd(q);
    graph = vvi(n + 1);

    vll val(n + 1);

    forr(i, 1, n + 1) sclld(val[i]);

    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    frange(_, q)
    {
        int a, b;
        scd(a);
        scd(b);
        path = {};
        dfs(a, 0, b);
        path.pb(a);
        reverse(all(path));
        vector<pair<lli, lli>> dp(path.size());
        dp[0].f = val[path[0]];
        forr(i, 1, path.size())
        {
            dp[i].f = dp[i - 1].s + val[path[i]];
            dp[i].s = max(dp[i - 1].f, dp[i - 1].s);
        }
        printf("%lld\n", max(dp[path.size() - 1].f, dp[path.size() - 1].s));
    }
}