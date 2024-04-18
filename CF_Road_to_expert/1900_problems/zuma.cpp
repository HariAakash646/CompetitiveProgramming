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
    int n;
    scd(n);
    vi vec(n + 1);
    frange(i, n)
    {
        scd(vec[i + 1]);
    }
    vvi dp(n + 2, vi(n + 2));
    forr(j, 1, n + 1)
    {
        for (int i = n; i > 0; i--)
        {
            if (i > j)
            {
                dp[i][j] = 0;
            }
            else if (i == j)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = 1 + dp[i + 1][j];
                if (vec[i] == vec[i + 1])
                {
                    dp[i][j] = min(dp[i][j], 1 + dp[i + 2][j]);
                }
                forr(k, i + 2, j + 1)
                {
                    if (vec[i] == vec[k])
                    {
                        // printf("%d\n", dp[i + 1][k - 1] + dp[k + 1][j]);
                        dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j]);
                    }
                }
            }
        }
    }
    printf("%d", dp[1][n]);
}