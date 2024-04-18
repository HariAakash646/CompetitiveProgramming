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

lli inf = 1e13;

int main()
{
    lli h, n, c;
    sclld(h);
    sclld(n);
    sclld(c);
    vector<lli> dis(n + 1), cos(n + 1);
    forr(i, 1, n + 1)
    {
        sclld(dis[i]);
        sclld(cos[i]);
    }
    vector<vll> dp(n + 1, vll(c + 1, inf));
    // frange(i, n + 1)
    // {
    //     dp[0][i] = 0;
    // }
    for (lli j = 0; j < c + 1; j++)
    {
        dp[1][j] = j * cos[1];
    }
    for (lli i = 2; i < n + 1; i++)
    {
        for (lli j = 0; j < c + 1; j++)
        {

            dp[i][j] = dp[i - 1][dis[i] - dis[i - 1]] + cos[i] * j;
            if (j >= 1)
            {
                dp[i][j] = min(dp[i][j - 1] + cos[i], dp[i][j]);
            }
            if (j + dis[i] - dis[i - 1] <= c)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j + dis[i] - dis[i - 1]]);
            }
        }
    }

    printf("%lld", dp[n][h - dis[n]]);
}