// Unsolved. Small bugs.
#include <bits/stdc++.h>
#include <iostream>

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
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

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
    vvi dp(r + 1, vi(c + 1, 0));
    dp[1][1] = 1;
    forr(i, 1, r + 1)
    {
        forr(j, 1, c + 1)
        {
            if (grid[i][j] == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if (dp[i][j])
                continue;
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            if (i - d > 0)
            {
                int dl = dp[i - d][j];
                forr(k, i - d, i)
                {
                    if (dp[k][j] == 0)
                    {
                        dl = 0;
                        break;
                    }
                }
                dp[i][j] -= dl;
            }

            if (j - d > 0)
            {
                int dl = dp[i][j - d];
                forr(k, j - d, j)
                {
                    if (dp[i][k] == 0)
                    {
                        dl = 0;
                        break;
                    }
                }
                dp[i][j] -= dl;
            }

            dp[i][j] %= mod;
        }
    }
    printf("%d", dp[r][c]);
}