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
    int n, h;
    scd(n);
    scd(h);
    vll vec(n + 1);
    forr(i, 1, n + 1) sclld(vec[i]);

    vector<vll> dp(n + 1, vll(h + 1));
    // dp[0][0] = 1;

    dp[1][0] = (vec[1] == h) + (vec[1] == h - 1);
    dp[1][1] = (vec[1] == h - 1);

    forr(i, 2, n + 1)
    {
        int j = h - vec[i];
        if (j < 0)
            continue;
        dp[i][j] = (dp[i - 1][j]) % mod;
        if (j > 0)
        {
            dp[i][j - 1] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
            dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
        }
        if (j > 1)
        {
            dp[i][j - 1] = (dp[i][j - 1] + dp[i - 1][j - 1]) % mod;
        }
    }
    printf("%lld", dp[n][0]);
}