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
vll val;
vector<pair<lli, lli>> dp1, dp2;

void dfs(int x, int par)
{
    if (par)
    {
        dp1[x].f = dp1[par].s + val[x];
        dp1[x].s = max(dp1[par].f, dp1[par].s);
        dp2[x].f = dp2[par].s + val[x];
        dp2[x].s = max(dp2[par].f, dp2[par].s);
    }
    for (auto e : graph[x])
    {
        if (e != par)
        {
            dfs(e, x);
        }
    }
}

int main()
{
    int n, q;
    scd(n);
    scd(q);
    graph = vvi(n + 1);

    val = vll(n + 1);

    forr(i, 1, n + 1) sclld(val[i]);

    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dp1 = dp2 = vector<pair<lli, lli>>(n + 1);
    dp1[1].f = val[1];
    dfs(1, 0);
    frange(_, q)
    {
        int a, b;
        scd(a);
        scd(b);
        lli ma = max({dp1[b].f + dp1[a].f - val[1], dp1[b].s + dp1[a].f - val[1], dp1[b].f + dp1[a].s - val[1], dp1[b].s + dp1[a].s - val[1]});
        ma = max({ma, dp2[b].f + dp2[a].f, dp2[b].s + dp2[a].f, dp2[b].f + dp2[a].s, dp2[b].s + dp2[a].s});
        printf("%lld\n", ma);
    }
}