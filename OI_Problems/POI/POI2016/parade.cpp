// Not working
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
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

vvi graph;
vi dp;
vi dp1;
vi deg;

void dfs(int x, int prev)
{
    int m1 = 1;
    int m2 = 1;
    for (auto e : graph[x])
    {
        if (e != prev)
        {
            dfs(e, x);
            if (dp1[e] >= m1)
            {
                m2 = m1;
                m1 = dp1[e];
            }
            else if (dp1[e] > m2)
            {
                m2 = dp1[e];
            }
        }
    }

    dp[x] = m1 + m2 + max(0, deg[x] - 3);
    dp1[x] = m1 + max(0, deg[x] - 2);
}

int main()
{
    int n;
    scd(n);
    graph = vvi(n + 1);
    deg = vi(n + 1);
    frange(i, n - 1)
    {
        int a, b;

        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
        deg[a]++;
        deg[b]++;
    }
    int l = 0;
    forr(i, 1, n + 1)
    {
        if (deg[i] == 1)
            l++;
    }
    dp1 = dp = vi(n + 1);
    dfs(1, 0);
    int ans = 0;
    forr(i, 1, n + 1)
    {
        if (deg[i] > 1)
            ans = max(ans, max(dp[i], dp1[i]) + 1);
    }
    printf("%d", ans - (l == n - 1));
}