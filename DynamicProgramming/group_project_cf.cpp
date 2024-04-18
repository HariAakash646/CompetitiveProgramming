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

int main()
{
    int n, k;
    scd(n);
    scd(k);
    vi vec(n + 1);
    forr(i, 1, n + 1) scd(vec[i]);
    sort(all(vec));
    vector<vector<vi>> dp(n + 1, vector<vi>(n + 1, vi(k + 1)));

    dp[0][0][0] = 1;
    // dp[1][0][0] = 1;
    // dp[1][1][0] = 1;
    forr(i, 1, n + 1)
    {
        forr(j, 0, n + 1)
        {
            forr(l, 0, k + 1)
            {
                int v = vec[i] - vec[i - 1];
                int l1 = l + j * v;
                if (l1 > k)
                    continue;
                dp[i][j][l1] = (dp[i][j][l1] + dp[i - 1][j][l]) % mod;
                dp[i][j][l1] = (dp[i][j][l1] + (lli(dp[i - 1][j][l]) * j) % mod) % mod;
                if (j > 0)
                {
                    dp[i][j - 1][l1] += (lli(dp[i - 1][j][l]) * j) % mod;
                    dp[i][j - 1][l1] %= mod;
                }
                if (j < i)
                {
                    dp[i][j + 1][l1] += dp[i - 1][j][l];
                    dp[i][j + 1][l1] %= mod;
                }
            }
        }
    }
    int tot = 0;
    forr(i, 0, k + 1) tot = (tot + dp[n][0][i]) % mod;
    tot %= mod;
    printf("%d", tot);
}