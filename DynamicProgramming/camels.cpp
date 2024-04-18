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
    int n, t;
    scd(n);
    scd(t);
    vector<vector<vector<vector<vll>>>> dp(n + 1, vector<vector<vector<vll>>>(t + 1, vector<vector<vll>>(t + 1, vector<vll>(5, vll(5)))));

    forr(i, 1, 3)
    {
        forr(j, 1, 5)
        {
            forr(k, 1, 5)
            {
                dp[i][0][0][j][k] = 1;
            }
        }
    }
    forr(i, 3, n + 1)
    {
        forr(j, 0, t + 1)
        {
            forr(k, 0, t + 1)
            {
                forr(y1, 1, 5)
                {
                    forr(y2, 1, 5)
                    {
                        if (y1 == y2)
                            continue;
                        forr(y, 1, 5)
                        {
                            if (y == y1)
                                continue;
                            if (y < y1)
                            {
                                if (y1 > y2)
                                {
                                    if (j > 0)
                                        dp[i][j][k][y][y1] += dp[i - 1][j - 1][k][y1][y2];
                                }
                                else
                                {
                                    dp[i][j][k][y][y1] += dp[i - 1][j][k][y1][y2];
                                }
                            }
                            else
                            {
                                if (y1 < y2)
                                {
                                    if (k > 0)
                                        dp[i][j][k][y][y1] += dp[i - 1][j][k - 1][y1][y2];
                                }
                                else
                                {
                                    dp[i][j][k][y][y1] += dp[i - 1][j][k][y1][y2];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    lli tot = 0;
    forr(y1, 1, 5)
    {
        forr(y2, 1, 5) tot += dp[n][t][t - 1][y1][y2];
    }
    printf("%lld", tot);
}