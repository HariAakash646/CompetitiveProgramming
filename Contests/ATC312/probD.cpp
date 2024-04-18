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

lli mod = 998244353;

int main()
{
    string str;
    cin >> str;
    int n = str.size();
    vector<vll> dp(n + 1, vll(n + 1));

    dp[0][0] = 1;
    forr(i, 1, n + 1)
    {
        forr(j, 0, n + 1)
        {
            if (str[i - 1] == '(')
            {
                if (j > 0)
                    dp[i][j] = dp[i - 1][j - 1];
            }
            else if (str[i - 1] == ')')
            {
                if (j < n)
                {
                    dp[i][j] = dp[i - 1][j + 1];
                }
            }
            else
            {
                if (j > 0)
                    dp[i][j] = dp[i - 1][j - 1];
                if (j < n)
                    dp[i][j] += dp[i - 1][j + 1];
            }
            dp[i][j] %= mod;
        }
    }
    printf("%lld", dp[n][0]);
}