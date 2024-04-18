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

lli mod = 998244353;

int main()
{
    int n, k;
    scd(n);
    scd(k);

    vi vec(n + 1);
    forr(i, 1, n + 1) scd(vec[i]);

    if (n <= 3000)
    {
        vvi cnt(n + 1, vi(n + 1));

        forr(i, 1, n + 1)
        {
            vi cn(n + 1);
            int c = 0;
            forr(j, i, n + 1)
            {
                cn[vec[j]]++;
                if (cn[vec[j]] == 1)
                    c++;
                else if (cn[vec[j]] == 2)
                    c--;
                cnt[i][j] = c;
            }
        }

        // for (auto v : cnt)
        // {
        //     for (auto e : v)
        //     {
        //         printf("%d ", e);
        //     }
        //     printf("\n");
        // }

        vll dp(n + 1);
        dp[0] = 1;
        forr(i, 1, n + 1)
        {
            frange(j, i)
            {
                if (cnt[j + 1][i] <= k)
                    dp[i] = (dp[i] + dp[j]) % mod;
            }
        }
        printf("%lld", dp[n]);
    }
    else
    {
        vll dp(n + 1);
        dp[0] = 1;
        forr(i, 1, n + 1)
        {
            dp[i] += 2 * dp[i - 1];
            dp[i] %= mod;
            // dp[i] += dp[i - 1];
        }
        printf("%lld", (dp[n] - dp[n - 1] + mod) % mod);
    }
}