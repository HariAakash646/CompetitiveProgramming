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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define PB push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
    int n, x;
    scd(n);
    scd(x);
    vector<int> coins(n);
    frange(i, n)
    {
        scd(coins[i]);
    }
    vi dp(x + 1, -1e9 - 5);
    dp[0] = 0;
    int min_c = *min_element(coins.begin(), coins.end());
    forr(i, min_c, x + 1, 1)
    {
        int m = 1e9 + 5;
        for (int c : coins)
        {
            if (i >= c && dp[i - c] >= 0)
            {
                m = min(m, dp[i - c] + 1);
                dp[i] = m;
            }
        }
        }
    if (dp[x] < 0)
        printf("-1");
    else
        printf("%d", dp[x]);
    return 0;
}