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

int mod = 20011;

int main()
{
    int r, c, d;
    scd(r);
    scd(c);
    scd(d);
    ++d;
    vvi grid(r + 1, vi(c + 1));
    frange(i, r)
    {
        frange(j, c)
        {
            scd(grid[i + 1][j + 1]);
        }
    }
    vector<vector<vii>> dp(r + 1, vector<vii>(c + 1, vii(d)));
    dp[1][1][0].f = dp[1][1][0].s = 1;
    forr(i, 1, r + 1)
    {
        forr(j, 1, c + 1)
        {
            if (i == 1 && j == 1)
                continue;
            if (grid[i][j] == 0)
                continue;
            forr(k, 1, d)
            {
                dp[i][j][1].f += dp[i - 1][j][k].s;
                dp[i][j][1].s += dp[i][j - 1][k].f;
                dp[i][j][1].f %= mod;
                dp[i][j][1].s %= mod;
            }
            forr(k, 1, d)
            {
                dp[i][j][k].f += dp[i - 1][j][k - 1].f;
                dp[i][j][k].s += dp[i][j - 1][k - 1].s;
                dp[i][j][k].f %= mod;
                dp[i][j][k].s %= mod;
            }
        }
    }
    int tot = 0;
    forr(i, 1, d)
    {
        tot += dp[r][c][i].f + dp[r][c][i].s;
        tot %= mod;
    }
    printf("%d", tot);
}