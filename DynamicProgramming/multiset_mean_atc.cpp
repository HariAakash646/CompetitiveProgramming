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
    int n, k;
    scd(n);
    scd(k);
    lli m;
    sclld(m);

    vector<vll> dp(n + 1, vll(n * n + 1));
    dp[0][0] = 1;

    forr(i, 1, n + 1)
    {
        frange(j, n * n + 1)
        {
            frange(l, k + 1)
            {
                if (j - l * i >= 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - l * i]) % m;
            }
        }
    }
    lli v = 0;
    forr(i, 1, n + 1)
    {
        v += i;
        lli ans = 0;

        for (int t = 0; t <= v * k; t++)
        {
            ans += (dp[i][t] * dp[n - i][t]) % m;
            ans %= m;
        }
        ans *= (k + 1);
        ans--;
        ans += m;
        ans %= m;
        printf("%lld\n", ans);
    }
}