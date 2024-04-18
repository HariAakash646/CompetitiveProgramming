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
vi dp1;
vi dp2;

void dfs(int x, int prev)
{
    for (auto e : graph[x])
    {
        if (e != prev)
        {
            dfs(e, x);

            dp2[x] += max(dp1[e], dp2[e]);
        }
    }
    for (auto e : graph[x])
    {
        if (e != prev)
        {
            dp1[x] = max(dp1[x], dp2[e] + 1 + dp2[x] - max(dp1[e], dp2[e]));
        }
    }
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
    dp1 = vi(n + 1, 0);
    dp2 = vi(n + 1, 0);
    dfs(1, 0);
    printf("%d", max(dp1[1], dp2[1]));
}