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

int n, k;
vvi graph;
vvll dp;
vll dist;

void dfs(int x, int prev)
{
    dp[x][0] = 1;
    for (auto e : graph[x])
    {
        if (e != prev)
        {
            dfs(e, x);
            forr(i, 1, k + 1)
            {
                dp[x][i] += dp[e][i - 1];
            }
        }
    }
    // frange(i, k + 1)
    // {
    //     dist[x] += dp[x][i] * dp[x][k - i];
    //     if (i == (k - i))
    //         dist[x] -= dp[x][i];
    // }

    for (auto e : graph[x])
    {
        if (e != prev)
        {
            frange(i, k - 1)
            {
                dist[x] += dp[e][i] * (dp[x][k - (i + 1)] - dp[e][k - (i + 1) - 1]);
            }
        }
    }
    dist[x] /= 2;
    dist[x] += dp[x][k];
}

int main()
{

    scd(n);
    scd(k);
    graph = vvi(n + 1);
    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dp = vvll(n + 1, vll(k + 1));
    dist = vll(n + 1);
    dfs(1, 0);
    lli tot = 0;
    forr(i, 1, n + 1)
    {
        tot += dist[i];
    }
    printf("%lld", tot);
}