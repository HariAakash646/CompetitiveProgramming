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
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

int main()
{
    int n, m;
    cin >> n >> m;
    string str1, str2;
    cin >> str1 >> str2;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    int ma = 0;
    forr(i, 1, n + 1)
    {
        forr(j, 1, m + 1)
        {
            if (dp[i - 1][j] - 1 > dp[i][j - 1] - 1)
            {
                dp[i][j] = dp[i - 1][j] - 1;
            }
            else
            {
                dp[i][j] = dp[i][j - 1] - 1;
            }
            if (str1[i - 1] == str2[j - 1])
            {
                if (dp[i - 1][j - 1] + 2 > dp[i][j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 2;
                }
            }
            if (dp[i][j] < 0)
            {
                dp[i][j] = 0;
            }
            ma = max(ma, dp[i][j]);
        }
    }
    printf("%d", ma);
}