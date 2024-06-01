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

const lli mod = 1e9 + 9;

int main()
{
    int n, m, k;
    scd(n);
    scd(m);
    scd(k);
    vi v1(n + 1), v2(m + 1);
    forr(i, 1, n + 1) scd(v1[i]);
    forr(i, 1, m + 1) scd(v2[i]);
    sort(all(v1));
    sort(all(v2));

    vector<vll> dp(n + 1, vll(k + 1));
    frange(i, n + 1)
        dp[i][0] = 1;
    forr(i, 1, n + 1)
    {
        forr(j, 1, min(i + 1, k + 1))
        {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] * max(0LL, lower_bound(all(v2), v1[i]) - (v2.begin() + 1) - (j - 1))) % mod;
            printf("%lld ", dp[i][j]);
        }
        printf("\n");
    }
    printf("%lld", dp[n][k]);
}