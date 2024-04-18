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

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vi vec(n + 1);
        frange(i, n) scd(vec[i + 1]);

        vvi dp(n + 1, vi(n + 1));

        forr(i, 1, n + 1)
        {
            if (vec[i] > vec[i - 1])
            {
                dp[i][0] = dp[i - 1][0] + 1;
            }
            else
                break;
        }
        forr(i, 1, n + 1)
        {
            forr(j, 1, n + 1)
            {
                // dp[i][j] = dp[i - 1][j - 1];
                if (vec[i] > vec[i - 1])
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
                }

                forr(k, 0, i - 1)
                {
                    if (vec[i] > vec[k])
                    {
                        dp[i][j] = max(dp[i][j], dp[k][j - 1] + 1);
                    }
                    // else
                    // {
                    //     dp[i][j] = max(dp[i][j], dp[k][j - 1]);
                    // }
                }
                // printf("%d ", dp[i][j]);
            }
            // printf("\n");
        }
        int ma = 0;
        forr(k, 1, n + 1)
        {
            ma = max(ma, dp[n][k]);
            forr(i, 1, n)
            {
                ma = max(dp[i][k - 1], ma);
            }
            printf("%d ", n - ma);
        }
        printf("\n");
    }
}