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

int dp[lli(1e5 + 1)][2][2][2][2];

int root, sp;
vvi graph;
vb vis;
vi curr, cyc;
int inf = 1e9;

bool dfs(int x, int prev)
{
    if (vis[x])
    {
        bool done = false;
        for (auto e : curr)
        {
            if (e == x)
            {
                done = true;
            }
            if (done)
                cyc.pb(e);
        }
        return true;
    }
    curr.pb(x);
    vis[x] = true;
    for (auto e : graph[x])
    {
        if (e != prev)
        {
            bool out = dfs(e, x);
            if (out)
                return true;
        }
    }
    curr.pop_back();
    return false;
}

void dfs_dp(int x, int prev)
{
    int mi0[2][2], mi1[2][2];
    frange(i, 2)
    {
        frange(j, 2)
        {
            mi0[i][j] = inf;
            mi1[i][j] = inf;
        }
    }
    frange(i, 2)
    {
        frange(j, 2)
        {
            frange(k, 2)
            {
                dp[x][i][0][j][k] = 1;
            }
        }
    }
    for (auto e : graph[x])
    {
        if (e != prev)
        {
            dfs_dp(e, x);
            frange(i, 2)
            {
                frange(j, 2)
                {
                    dp[x][0][0][i][j] += dp[e][0][1][i][j];
                    dp[x][0][1][i][j] += dp[e][1][1][i][j];
                    mi0[i][j] = min(mi0[i][j], dp[e][0][0][i][j] - dp[e][0][1][i][j]);
                    mi1[i][j] = min(mi1[i][j], dp[e][1][0][i][j] - dp[e][1][1][i][j]);
                }
            }
        }
    }
    frange(i, 2)
    {
        frange(j, 2)
        {
            dp[x][1][0][i][j] = dp[x][0][0][i][j] + mi0[i][j];
            dp[x][1][1][i][j] = dp[x][0][1][i][j] + mi1[i][j];
        }
    }
    if (x == root)
    {
        frange(i, 2)
        {
            frange(j, 2)
            {
                frange(k, 2)
                {
                    frange(l, 2)
                    {
                        if (i != l)
                        {
                            dp[x][i][j][k][l] = inf;
                        }
                        if (j != k)
                        {
                            dp[x][i][j][k][l] = inf;
                        }
                    }
                }
            }
        }
    }
    if (x == sp)
    {
        frange(i, 2)
        {
            frange(j, 2)
            {
                frange(k, 2)
                {
                    frange(l, 2)
                    {

                        if (i == 1 && k == 0)
                        {
                            if (j == 0)
                                dp[x][i][j][k][l] -= mi0[k][l];
                            else
                                dp[x][i][j][k][l] -= mi1[k][l];
                        }
                        if (j != l)
                        {
                            dp[x][i][j][k][l] = inf;
                        }
                        if (i == 0 && k == 0)
                        {
                            dp[x][i][j][k][l] = inf;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int n;
    scd(n);
    graph = vvi(n + 1);
    frange(i, n)
    {
        int a, b;
        scd(a);
        scd(b);

        graph[a].pb(b);
        graph[b].pb(a);
    }
    vis = vb(n + 1);
    dfs(1, 0);
    // printf("%d\n", cyc.size());
    // for (auto e : cyc)
    //     printf("%d ", e);
    root = cyc[0];
    sp = cyc[1];
    graph[root].erase(find(all(graph[root]), sp));
    graph[sp].erase(find(all(graph[sp]), root));
    dfs_dp(root, -1);
    int ans = inf;
    frange(i, 2)
    {
        frange(j, 2)
        {
            frange(k, 2)
            {
                frange(l, 2)
                {
                    ans = min(ans, dp[root][i][j][k][l]);
                }
            }
        }
    }
    if (ans >= 1e8)
        printf("-1");
    else
        printf("%d", ans);
}