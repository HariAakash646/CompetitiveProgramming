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
    int n;
    scd(n);
    vi vec(n);

    frange(i, n) scd(vec[i]);

    vvi dp(n, vi(3, 1e9));
    dp[0][vec[0] + 1] = 0;

    forr(i, 1, n)
    {
        frange(j, 3)
        {
            int v = j - 1;
            if (vec[i] == v)
            {
                frange(k, j + 1) dp[i][j] = min(dp[i][j], dp[i - 1][k]);
            }
            else if (v == 1)
            {
                int x = 0;
                if (vec[i] == 0)
                {
                    x = 1;
                }
                else
                {
                    x = 2;
                }
                dp[i][j] = min(dp[i][j], dp[i - 1][2] + x);
                if (vec[i - 1] == 1)
                {
                    frange(k, 3)
                    {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + x);
                    }
                }
            }
            else if (v == 0)
            {
                int x = 1;

                if (vec[i] == 1)
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][0] + x);
                }
                if (vec[i - 1] + vec[i] == 0)
                {
                    frange(k, 2) dp[i][j] = min(dp[i][j], dp[i - 1][k] + x);
                }
            }
            else
            {
                int x = 0;
                if (vec[i] == 0)
                {
                    x = 1;
                }
                else
                    x = 2;
                dp[i][j] = min(dp[i][j], dp[i - 1][0] + x);
                // if(vec[i-1] == -1) {

                // }
            }
        }
    }
    int v = min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    if (v == 1e9)
        printf("BRAK");
    else
        printf("%d", v);
}