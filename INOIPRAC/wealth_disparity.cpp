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
vi wealth;
vi dp;

void dfs(int x, int par)
{
    dp[x] = wealth[x];
    for (auto e : graph[x])
    {
        if (e != par)
        {
            dfs(e, x);
            dp[x] = min(dp[x], dp[e]);
        }
    }
}

int main()
{
    int n;
    scd(n);
    graph = vvi(n + 1);
    wealth = vi(n + 1);
    dp = vi(n + 1, 1e9);
    forr(i, 1, n + 1) scd(wealth[i]);
    int a;
    int boss;
    forr(i, 1, n + 1)
    {
        scd(a);
        if (a == -1)
        {
            boss = i;
            continue;
        }
        graph[a].pb(i);
        graph[i].pb(a);
    }
    int ma = -1e9;
    dfs(boss, 0);

    forr(i, 1, n + 1)
    {
        ma = max(ma, wealth[i] - dp[i]);
    }
    printf("%d", ma);
}