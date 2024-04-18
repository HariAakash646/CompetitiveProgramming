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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

lli mod = 998244353;

int main()
{
    int n, k;
    scd(n);
    scd(k);
    vector<vll> dp(n + 1, vll(k + 1));

    dp[0][0] = 1;
    frange(i, n + 1) dp[i][0] = 1;

    forr(i, 1, n + 1)
    {
        forr(j, 1, k + 1)
        {
            dp[i][j] = (dp[i - 1][j - 1] * (k - (j - 1))) % mod;
        }
    }
    lli tot = 0;
    forr(i, 1, n + 1)
    {
        tot += dp[i][k];
        tot %= mod;
    }
    lli fact = 1;
    forr(i, 1, (n - k + 1))
    {
        fact = (fact * k) % mod;
    }
    tot = (tot * fact) % mod;
    lli fact2 = 1;
    forr(i, 1, (n - k))
    {
        fact2 = fact2 * i % mod;
    }
    forr(i, 1, n + 1)
    {
        lli v = 1;
        forr(j, 1, k)
        {
            if (i + j < n)
            {
                v *= (k - j + 1);
                v %= mod;
                tot -= fact2 * (v * dp[i][k] % mod) % mod;
                tot += mod;
                tot %= mod;
            }
        }
    }
    printf("%lld", tot);
}