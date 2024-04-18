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
    int n, m, k;
    scd(n);
    scd(m);
    scd(k);
    string s1, s2;
    cin >> s1 >> s2;

    vector<vvi> dp(n + 1, vvi(m + 1, vi(k + 1))), dp2(n + 1, vvi(m + 1, vi(k + 1)));

    forr(i, 1, n + 1)
    {
        forr(j, 1, m + 1)
        {
            forr(l, 1, k + 1)
            {
                dp[i][j][l] = max(dp[i - 1][j][l], dp[i][j - 1][l]);
                if (s1[i - 1] == s2[j - 1])
                {
                    dp2[i][j][l] = max(dp2[i][j][l], dp2[i - 1][j - 1][l] + 1);
                    dp2[i][j][l] = max(dp2[i][j][l], dp[i - 1][j - 1][l - 1] + 1);
                }
                dp[i][j][l] = max(dp[i][j][l], dp2[i][j][l]);
            }
        }
    }
    printf("%d", dp[n][m][k]);
}