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
vi dist;
vii dp, dp2;
vii val;

pii maxp(pii x, pii y)
{
    y.f--;
    if (x.f > y.f)
    {
        return x;
    }
    else if (x.f == y.f)
    {
        if (x.s < y.s)
        {
            return x;
        }
    }
    return y;
}

void dfs(int x, int par)
{
    for (auto e : graph[x])
    {
        if (e != par)
        {
            dfs(e, x);
            dp[x] = maxp(dp[x], val[e]);
            dp[x] = maxp(dp[x], dp[e]);
        }
    }
}

void dfs2(int x, int par)
{
    pii ma = {-1e9, 1e9};
    pii secma = {-1e9, 1e9};
    int mi = 1e9, secmi = -1;
    for (auto e : graph[x])
    {
        if (e != par)
        {
            // printf("%d %d\n", e, x);
            dp2[e] = maxp(dp2[e], val[x]);
            dp2[e] = maxp(dp2[e], dp2[x]);
            pii tmp = dp[e];
            dp[e] = maxp(dp[e], {val[e].f + 1, val[e].s});
            if (dp[e].f > ma.f)
            {
                secma = ma;
                secmi = mi;
                ma = dp[e];
                mi = e;
            }
            else if (dp[e].f == ma.f && dp[e].s < ma.s)
            {
                secma = ma;
                secmi = mi;
                ma = dp[e];
                mi = e;
            }
            else if (dp[e].f > secma.f)
            {
                secma = dp[e];
                secmi = e;
            }
            else if (dp[e].f == secma.f && dp[e].s < secma.s)
            {
                secma = dp[e];
                secmi = e;
            }
            dp[e] = tmp;
        }
    }
    // cout << x << " " << ma.f << " " << mi << " " << secma.f << "\n";
    for (auto e : graph[x])
    {
        if (e != par)
        {
            if (mi != e)
                dp2[e] = maxp(dp2[e], {ma.f - 1, ma.s});
            else
                dp2[e] = maxp(dp2[e], {secma.f - 1, secma.s});
            dfs2(e, x);
        }
    }
}

int main()
{
    int n;
    lli k;
    scd(n);
    sclld(k);

    graph = vvi(n + 1);
    val = dp = dp2 = vii(n + 1, mp(-1e9, 1e9));

    forr(i, 1, n + 1)
    {
        scd(val[i].f);
        val[i].s = i;
    }

    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dfs(1, 0);
    dfs2(1, 0);

    vi dirg(n + 1);
    forr(i, 1, n + 1)
    {
        if (dp[i].f > dp2[i].f)
        {
            dirg[i] = dp[i].s;
            // printf("%d %d\n", dp[i].f, dp[i].s);
        }
        else if (dp[i].f == dp2[i].f && dp[i].s < dp2[i].s)
        {
            dirg[i] = dp[i].s;
            // printf("%d %d\n", dp[i].f, dp[i].s);
        }
        else
        {
            dirg[i] = dp2[i].s;
            // printf("%d %d\n", dp2[i].f, dp2[i].s);
        }
        // printf("%d %d\n", max(dp[i], dp2[i]));
    }
    vvi lift(61, vi(n + 1));

    forr(i, 1, n + 1)
    {
        lift[0][i] = dirg[i];
    }

    forr(i, 1, 61)
    {
        forr(j, 1, n + 1)
        {
            lift[i][j] = lift[i - 1][lift[i - 1][j]];
        }
    }
    int x = 1;
    frange(i, 61)
    {
        if (k & (1LL << i))
        {
            x = lift[i][x];
        }
    }
    printf("%d", x);
}