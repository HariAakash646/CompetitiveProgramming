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
lli m;
vvi graph;
vll dp1, dp2, dp3;
vll ans;

void dfs1(int x, int prev)
{
    dp1[x] = 1;
    dp2[x] = 1;
    vll pref(graph[x].size() + 2, 1), suff(graph[x].size() + 2, 1);

    for (auto e : graph[x])
    {
        if (e != prev)
        {
            dfs1(e, x);
            dp1[x] = (dp1[x] * dp1[e]) % m;
        }
    }
    dp1[x]++;
    frange(i, graph[x].size())
    {
        if (graph[x][i] != prev)
        {
            pref[i + 1] = (pref[i] * (dp1[graph[x][i]])) % m;
        }
        else
            pref[i + 1] = pref[i];
    }
    for (int i = graph[x].size() - 1; i >= 0; i--)
    {
        if (graph[x][i] != prev)
        {
            suff[i + 1] = (suff[i + 2] * (dp1[graph[x][i]])) % m;
        }
    }
    frange(i, graph[x].size())
    {
        if (graph[x][i] != prev)
        {
            dp3[graph[x][i]] = (pref[i] * suff[i + 2]) % m;
        }
    }
}

void dfs2(int x, int prev)
{
    dp2[x] = (1 + dp2[prev] * dp3[x]) % m;
    for (auto e : graph[x])
    {
        if (e != prev)
            dfs2(e, x);
    }
}

int main()
{
    scd(n);
    sclld(m);
    // m = 1e9 + 7;
    graph = vvi(n + 1);

    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    ans = dp1 = dp2 = dp3 = vll(n + 1);
    dfs1(1, 0);
    dfs2(1, 0);
    forr(i, 1, n + 1)
        printf("%lld\n", ((dp1[i] - 1 + m) * dp2[i]) % m);
}