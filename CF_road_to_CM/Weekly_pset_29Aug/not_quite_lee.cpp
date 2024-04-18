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

lli mod = 1e9 + 7;

int main()
{
    int n;
    scd(n);
    vi vec(n + 1);

    forr(i, 1, n + 1) scd(vec[i]);

    vector<pair<lli, lli>> dp(n + 1);
    dp[0].f = 1;

    forr(i, 1, n + 1)
    {
        if (vec[i] % 4 == 2)
        {
            dp[i].f = dp[i - 1].f + dp[i - 1].s;
            dp[i].s = dp[i - 1].s + dp[i - 1].f;
        }
        else
        {
            dp[i].f = dp[i - 1].f * 2;
            dp[i].s = dp[i - 1].s * 2;
        }
        dp[i].f %= mod;
        dp[i].s %= mod;
    }

    lli tot = 0;
    // forr(i, 1, n + 1)
    // {
    //     tot += dp[i].f;
    //     tot %= mod;
    // }
    printf("%lld", dp[n].f);
}