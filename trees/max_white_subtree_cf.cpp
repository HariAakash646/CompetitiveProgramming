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

vi vec;
vvi graph;
vi dp1, dp2;

void dfs(int x, int prev)
{
    dp1[x] = vec[x];
    for (auto e : graph[x])
    {
        if (e != prev)
        {
            dfs(e, x);
            if (dp1[e] > 0)
                dp1[x] += dp1[e];
        }
    }
}

void dfs2(int x, int prev)
{
    dp2[x] = dp1[x];
    for (auto e : graph[x])
    {
        if (e != prev)
        {
            int ogx = dp1[x];
            int oge = dp1[e];
            dp1[x] = dp1[x] - max(0, dp1[e]);
            dp1[e] = dp1[e] + max(0, dp1[x]);
            dfs2(e, x);
            dp1[x] = ogx;
            dp1[e] = oge;
        }
    }
}

int main()
{
    int n;
    scd(n);

    vec = vi(n + 1);
    graph = vvi(n + 1);

    forr(i, 1, n + 1)
    {
        int a;
        scd(a);
        if (a)
            vec[i] = 1;
        else
            vec[i] = -1;
    }

    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dp1 = dp2 = vi(n + 1);
    dfs(1, 0);
    dfs2(1, 0);

    forr(i, 1, n + 1) printf("%d ", dp2[i]);
}