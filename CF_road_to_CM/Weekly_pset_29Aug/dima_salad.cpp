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
    vi a(n + 1), b(n + 1);
    int tot = 0;
    forr(i, 1, n + 1)
    {
        scd(a[i]);
        tot += a[i];
    }

    forr(i, 1, n + 1)
    {
        scd(b[i]);
        b[i] *= k;
        tot += b[i];
    }
    vvi dp(n + 1, vi(2 * tot + 1, -1e9));
    dp[0][tot] = 0;
    // printf("%d\n", tot);
    forr(i, 1, n + 1)
    {
        forr(j, -tot, tot + 1)
        {
            // printf("%d %d\n", tot + j + (a[i] - b[i]), tot + j);
            if (tot + j + (a[i] - b[i]) >= 0 && tot + j + (a[i] - b[i]) <= 2 * tot)
                dp[i][j + tot] = max(dp[i - 1][tot + j + (a[i] - b[i])] + a[i], dp[i - 1][tot + j]);
            else
                dp[i][j] = dp[i - 1][j + tot];
        }
    }
    if (dp[n][tot] > 0)
        printf("%d", dp[n][tot]);
    else
        printf("-1");
}