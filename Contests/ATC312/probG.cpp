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
vll dp;
vll sub;
vll dp2;

void dfs(int x, int par)
{
    sub[x] = 1;
    lli c = graph[x].size();
    if (par != 0)
        c--;
    for (auto e : graph[x])
    {
        if (e != par)
        {
            dfs(e, x);

            dp[x] += (c - 1) * (c - 2) * sub[e];
            sub[x] += sub[e];
        }
    }
    lli v = sub[x] - 1;
    for (auto e : graph[x])
    {
        if (e != par)
        {
            v -= sub[e];
            dp2[x] += sub[e] * v;
            dp[x] += dp2[e] * (sub[x] - sub[e]);
        }
    }
    // printf("%d %lld\n", x, dp2[x]);
}

int main()
{
    int n;
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
    dp2 = dp = vll(n + 1);
    sub = vll(n + 1, 1);
    dfs(1, 0);
    printf("%lld", dp[1]);
}