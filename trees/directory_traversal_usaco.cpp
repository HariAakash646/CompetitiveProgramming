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

void usaco()
{
    freopen("dirtraverse.in", "r", stdin);
    freopen("dirtraverse.out", "w", stdout);
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vvi graph;
vb file;
vll val;
vll sub;
vll dp, dp2;

void dfs(int x)
{
    if (file[x])
    {
        sub[x]++;
        return;
    }
    for (auto e : graph[x])
    {
        dfs(e);
        sub[x] += sub[e];
        if (file[e])
        {
            dp[x] += val[e];
        }
        else
        {
            dp[x] += dp[e] + (val[e] + 1) * sub[e];
        }
    }
}

void dfs2(int x)
{
    for (auto e : graph[x])
    {
        if (!file[e])
        {
            dp2[e] = dp[x] - (dp[e] + (val[e] + 1) * sub[e]) + 3 * (sub[1] - sub[e]) + dp2[x];
            dfs2(e);
        }
    }
    // for (auto e : graph[x])
    //     dfs2(e);
}

int main()
{
    usaco();
    fastio();
    int n;
    cin >> n;

    graph = vvi(n + 1);
    file = vb(n + 1);
    sub = dp = dp2 = val = vll(n + 1);

    forr(i, 1, n + 1)
    {
        string str;
        cin >> str;
        val[i] = str.size();
        int m;
        cin >> m;
        if (m == 0)
            file[i] = true;
        frange(j, m)
        {
            int a;
            cin >> a;
            graph[i].pb(a);
        }
    }
    dfs(1);
    dfs2(1);

    lli mi = 2e18;
    forr(i, 1, n + 1)
    {
        if (!file[i])
        {
            mi = min(mi, dp[i] + dp2[i]);
            // printf("%d %lld\n", i, dp[i] + dp2[i]);
        }
    }
    printf("%lld", mi);
}