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
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

int n;
vvi graph;
vi subsze;
vll dp;
lli ans = 0;

void dfs(int x, int prev)
{
    subsze[x] = 1;
    for (auto e : graph[x])
    {
        if (e != prev)
        {
            dfs(e, x);
            subsze[x] += subsze[e];
            dp[x] += dp[e];
        }
    }
    dp[x] += subsze[x];
}

void dfs1(int x, int prev)
{
    ans = max(ans, dp[x]);
    for (auto e : graph[x])
    {
        if (e != prev)
        {
            dp[x] -= dp[e] + subsze[e];
            subsze[x] -= subsze[e];
            subsze[e] += subsze[x];
            dp[e] += dp[x] + subsze[x];
            dfs1(e, x);
            dp[e] -= dp[x] + subsze[x];
            subsze[e] -= subsze[x];
            subsze[x] += subsze[e];
            dp[x] += dp[e] + subsze[e];
        }
    }
}

int main()
{
    scd(n);
    graph = vvi(n + 1);
    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    subsze = vi(n + 1);
    dp = vll(n + 1);
    dfs(1, 0);
    dfs1(1, 0);
    lli ma = 0;

    printf("%lld", ans);
}