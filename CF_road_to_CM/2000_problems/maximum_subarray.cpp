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

int main()
{
    int t;
    scd(t);

    frange(_, t)
    {
        int n, k;
        lli x;
        scd(n);
        scd(k);
        sclld(x);

        vll vec(n + 1);
        forr(i, 1, n + 1) sclld(vec[i]);

        vector<vll> dp(n + 1, vll(k + 1));
        forr(i, 1, n + 1)
        {
            frange(j, k + 1)
            {
                // if (i > j)
                dp[i][j] = vec[i] - x;
                if (j >= 1)
                {
                    dp[i][j] = max(dp[i][j], vec[i] + x);
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + vec[i] + x);
                };
                if (i > j)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + vec[i] - x);
            }
        }
        lli ma = 0;
        forr(i, 1, n + 1) ma = max(ma, dp[i][k]);
        printf("%lld\n", ma);
    }
}