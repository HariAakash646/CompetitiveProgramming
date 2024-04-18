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
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;

    vector<vvi> dp(n, vvi(n, vi(n + 1, -1)));

    frange(i, n)
    {
        if (str[i] == 'C')
        {
            dp[i][i][1] = 1;
        }
        // dp[i][i][0] = 1;
    }

    int tot = 0;
    for (auto e : str)
    {
        if (e == 'C')
            tot++;
    }

    forr(i, 1, n)
    {
        for (int l = 0; l + i < n; l++)
        {
            int r = l + i;
            // dp[l][r][0] = 1;
            int cnt = 0;
            forr(j, l, r + 1)
            {
                if (str[j] == 'C')
                    cnt++;
            }
            if (cnt >= 1)
            {
                dp[l][r][1] = 0;
                if (!dp[l + 1][r][1] && !dp[l][r - 1][1])
                {
                    dp[l][r][1] = 1;
                }
                else if (!dp[l + 1][r][1])
                {
                    if (str[r] == 'C')
                    {
                        dp[l][r][1] = 1;
                    }
                }
                else if (!dp[l][r - 1][1])
                {
                    if (str[l] == 'C')
                    {
                        dp[l][r][1] = 1;
                    }
                }
                else
                {
                    if (str[r] == 'C' && str[l] == 'C')
                    {
                        dp[l][r][1] = 1;
                    }
                }
            }
            forr(j, 2, k + 1)
            {
                if (cnt < j)
                    continue;
                dp[l][r][j] = 0;
                if (!dp[l + 1][r][j] && !dp[l][r - 1][j])
                {
                    dp[l][r][j] = 1;
                }
                else if (!dp[l + 1][r][j])
                {
                    if (str[r] == 'C')
                    {
                        if (!dp[l][r - 1][j - 1])
                        {
                            dp[l][r][j] = 1;
                        }
                    }
                }
                else if (!dp[l][r - 1][j])
                {
                    if (str[l] == 'C')
                    {
                        if (!dp[l + 1][r][j - 1])
                        {
                            dp[l][r][j] = 1;
                        }
                    }
                }
                else
                {
                    if (str[r] == 'C' && str[l] == 'C')
                    {
                        if (!dp[l + 1][r][j - 1] && !dp[l][r - 1][j - 1])
                        {
                            dp[l][r][j] = 1;
                        }
                    }
                }
            }
        }
    }

    if (dp[0][n - 1][k] == 1)
    {
        printf("NE");
    }
    else
    {
        printf("DA");
    }
}