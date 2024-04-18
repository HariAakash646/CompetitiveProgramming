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
    int t;
    scd(t);
    frange(_, t)
    {
        int k, n;
        scd(k);
        scd(n);
        if (k == 1)
        {
            if (n % 3 == 0)
                printf("1\n");
            else
                printf("0\n");
        }
        else if (k == 2)
        {
            vll dp(n + 1);
            dp[0] = 1;
            forr(i, 1, n + 1)
            {
                if (i - 2 >= 0)
                    dp[i] += dp[i - 2];
                if (i - 3 >= 0)
                    dp[i] += dp[i - 3];
                dp[i] %= mod;
            }
            printf("%lld\n", dp[n]);
        }
        else
        {
            vll dp(n + 1), dp1(n + 1), dp2(n + 1), dp3(n + 1), dp4(n + 1);
            dp[0] = 1;
            forr(i, 1, n + 1)
            {
                dp[i] += dp[i - 1];
                dp1[i] += dp4[i - 1];
                dp3[i] += dp1[i - 1];
                dp3[i] += dp2[i - 1];
                if (i - 3 >= 0)
                    dp[i] += dp[i - 3];

                if (i - 2 >= 0)
                {
                    dp4[i] += 2 * dp[i - 2];
                    dp2[i] += dp3[i - 2];
                    dp4[i] += dp1[i - 2];
                    // dp3[i] += dp2[i - 2];
                }
                dp[i] += dp2[i];
                dp[i] %= mod;
                dp2[i] %= mod;
                dp3[i] %= mod;
                dp1[i] %= mod;
                dp4[i] %= mod;
            }
            printf("%lld\n", dp[n]);
        }
    }
}