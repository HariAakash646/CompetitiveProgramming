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

lli mod = 1e9 + 7;

vvi graph;
vi vec;

vll dp1, dp2, dp3;

void dfs(int x, int prev)
{
    if (vec[x])
    {
        if (vec[x] == 1)
            dp1[x] = 1;
        if (vec[x] == 2)
            dp2[x] = 1;
        if (vec[x] == 3)
            dp3[x] = 1;
    }
    else
    {
        dp1[x] = 1;
        dp2[x] = 1;
        dp3[x] = 1;
    }
    for (auto e : graph[x])
    {
        if (e != prev)
        {
            dfs(e, x);
            dp1[x] = (dp1[x] * ((dp2[e] + dp3[e]) % mod)) % mod;
            dp2[x] = (dp2[x] * ((dp1[e] + dp3[e]) % mod)) % mod;
            dp3[x] = (dp3[x] * ((dp2[e] + dp1[e]) % mod)) % mod;
        }
    }
}

int main()
{
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);
    int n, k;
    scd(n);
    scd(k);
    graph = vvi(n + 1);
    vec = vi(n + 1);
    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    frange(i, k)
    {
        int k, c;
        scd(k);
        scd(c);
        vec[k] = c;
    }
    dp1 = dp2 = dp3 = vll(n + 1);
    dfs(1, 0);
    printf("%lld", (dp1[1] + dp2[1] + dp3[1]) % mod);
}