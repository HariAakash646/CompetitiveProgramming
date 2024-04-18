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
    vector<pair<lli, int>> vec(n + 1);

    forr(i, 1, n + 1)
    {
        scd(vec[i].s);
        sclld(vec[i].f);
    }
    // sort(vec.begin() + 1, vec.end());
    vector<vll>
        dp(n + 1, vll(n + 1, 1e18));
    dp[0][0] = 0;

    forr(i, 1, n + 1)
    {
        forr(j, 0, n + 1)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][max(0, j - (vec[i].s + 1))] + vec[i].f);
        }
    }
    lli mi = 1e18;
    forr(i, 1, n + 1) mi = min(mi, dp[i][n]);
    printf("%lld", mi);
}