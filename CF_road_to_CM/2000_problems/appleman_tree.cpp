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

lli mod = 1e9 + 7;

vvi graph;
vll dp1, dp2;
vi vec;

void dfs(int x, int par)
{
    dp1[x] = 0;
    dp2[x] = 1;

    for (auto e : graph[x])
    {
        if (e != par)
        {
            dfs(e, x);
            dp1[x] *= dp2[e];
            dp1[x] %= mod;
            dp1[x] += dp2[x] * dp1[e];
            dp1[x] %= mod;
            dp2[x] *= dp2[e];
            dp2[x] %= mod;
        }
    }
    if (vec[x])
    {
        dp1[x] = dp2[x];
    }
    else
    {
        dp2[x] += dp1[x];
    }
}

int main()
{
    int n;
    scd(n);
    graph = vvi(n + 1);

    dp1 = dp2 = vll(n + 1);
    vec = vi(n + 1);

    forr(i, 2, n + 1)
    {
        int p;
        scd(p);
        p++;
        graph[p].pb(i);
        graph[i].pb(p);
    }
    forr(i, 1, n + 1) scd(vec[i]);
    dfs(1, 0);
    printf("%lld", dp1[1]);
}