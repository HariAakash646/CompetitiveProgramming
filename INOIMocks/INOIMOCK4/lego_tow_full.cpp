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

lli mod = 1e9 + 7;

int main()
{
    int n;
    scd(n);
    vi vec(n);
    frange(i, n)
    {
        scd(vec[i]);
    }
    vector<vi> mindp(n, vi(n, 1e9));
    frange(i, n) mindp[i][i] = vec[i];
    forr(l, 1, n)
    {
        for (int i = 0; i + l < n; i++)
        {
            mindp[i][i + l] = min(mindp[i][i + l - 1], mindp[i + 1][i + l]);
        }
    }

    vector<vll> dp(n, vll(n));
    dp[0][0] = 1;
    vector<vll> prev(n, vll(n));
    frange(i, n)
        prev[0][i] = 1;

    forr(i, 1, n)
    {
        frange(j, i + 1)
        {
            // frange(k, j + 1) dp[i][j] += dp[i - 1][k];
            dp[i][j] = prev[i - 1][j];
            if (j >= 1)
                prev[i][j] = prev[i][j - 1] + dp[i][j];
            else
                prev[i][j] = dp[i][j];
            prev[i][j] %= mod;
        }
        forr(j, i + 1, n) prev[i][j] = prev[i][j - 1];
    }
    lli tot = 0;
    frange(i, n) tot = (tot + dp[n - 1][i]) % mod;
    printf("%lld", tot);
}
