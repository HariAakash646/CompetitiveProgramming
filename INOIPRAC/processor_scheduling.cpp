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
    int t;
    scd(t);
    frange(_, t)
    {
        int n, m;
        scd(n);
        scd(m);
        vll v1(n + 1);
        vector<pair<lli, lli>> v2(m + 1);
        forr(i, 1, n + 1) sclld(v1[i]);
        forr(i, 1, m + 1) sclld(v2[i].s);
        forr(i, 1, m + 1) sclld(v2[i].f);
        sort(all(v2));
        vector<vll> dp(n + 1, vll(m + 1, 2e18 + 10));
        dp[0][0] = 0;
        forr(i, 0, n + 1)
        {
            forr(j, 0, m + 1)
            {
                if (i > 0)
                {
                    dp[i][j] = dp[i - 1][j] + v1[i];
                }
                if (j > 0)
                {
                    if (dp[i][j - 1] < v2[j].f)
                        dp[i][j] = min(dp[i][j], max(v2[j].f, dp[i][j - 1] + v2[j].s));
                }
            }
        }
        if (dp[n][m] < 2e18 + 10)
            printf("%lld\n", dp[n][m]);
        else
            printf("-1\n");
    }
}