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
    int n;
    scd(n);
    vi vec(n + 1);

    frange(i, n) scd(vec[i + 1]);

    vvi dp(n + 1, vi(512, 1e9));

    dp[0][0] = 0;

    forr(i, 1, n + 1)
    {
        frange(j, 512)
        {
            dp[i][j] = dp[i - 1][j];
            if (dp[i - 1][j ^ vec[i]] < vec[i])
            {
                dp[i][j] = min(vec[i], dp[i][j]);
            }
        }
    }
    vi out;
    frange(i, 512)
    {
        if (dp[n][i] != 1e9)
            out.pb(i);
    }
    printf("%d\n", out.size());
    for (auto e : out)
        printf("%d ", e);
}