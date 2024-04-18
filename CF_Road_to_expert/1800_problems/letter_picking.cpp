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
    cin >> t;
    frange(_, t)
    {
        string str;
        cin >> str;
        int n = str.size();

        vvi dp(n, vi(n));

        frange(i, n - 1)
        {
            if (str[i] != str[i + 1])
                dp[i][i + 1] = 1;
            else
                dp[i][i + 1] = 0;
        }
        forr(k, 2, n)
        {
            for (int i = 0; i + k < n; i++)
            {
                int r = i + k;
                if (k % 2 == 0)
                {
                    if (dp[i + 1][r] == -1 || dp[i][r - 1] == -1)
                    {
                        dp[i][r] = -1;
                    }
                    else if (dp[i + 1][r] == 0 && dp[i][r - 1] == 0)
                    {
                        dp[i][r] = min(str[i], str[r]);
                    }
                    else if (dp[i + 1][r] == 0)
                    {
                        dp[i][r] = str[i];
                    }
                    else if (dp[i][r - 1] == 0)
                    {
                        dp[i][r] = str[r];
                    }
                    else
                    {
                        dp[i][r] = 1;
                    }
                }
                else
                {
                    if (dp[i + 1][r] == 1 || dp[i][r - 1] == 1)
                    {
                        dp[i][r] = 1;
                    }
                    else if (dp[i + 1][r] >= 2 && dp[i][r - 1] >= 2)
                    {
                        if (dp[i + 1][r - 1] == 0)
                        {
                            if (str[i] != str[r])
                                dp[i][r] = 1;
                            else
                                dp[i][r] = 0;
                        }
                        else
                        {
                            if (str[i] < dp[i + 1][r] || str[r] < dp[i][r - 1])
                            {
                                dp[i][r] = 1;
                            }
                            else if (int(str[i]) == dp[i + 1][r] || int(str[r]) == dp[i][r - 1])
                            {
                                dp[i][r] = 0;
                            }
                            else
                            {
                                dp[i][r] = -1;
                            }
                        }
                    }
                    else if (dp[i + 1][r] >= 2)
                    {
                        if (str[i] < dp[i + 1][r])
                        {
                            dp[i][r] = 1;
                        }
                        else if (int(str[i]) == dp[i + 1][r])
                            dp[i][r] = 0;
                        else
                            dp[i][r] = -1;
                    }
                    else if (dp[i][r - 1] >= 2)
                    {
                        if (str[r] < dp[i][r - 1])
                        {
                            dp[i][r] = 1;
                        }
                        else if (int(str[r]) == dp[i][r - 1])
                            dp[i][r] = 0;
                        else
                            dp[i][r] = -1;
                    }
                    else
                    {
                        dp[i][r] = -1;
                    }
                }
            }
        }
        if (dp[0][n - 1] == 1)
            printf("Alice\n");
        else if (dp[0][n - 1] == -1)
            printf("Bob\n");
        else
            printf("Draw\n");
        // printf("%d\n", dp[0][2]);
    }
}