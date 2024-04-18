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
    vector<pair<pair<lli, lli>, int>> vec(n + 1);
    int tot = 0;
    forr(i, 1, n + 1)
    {
        sclld(vec[i].f.f);
        sclld(vec[i].f.s);
        scd(vec[i].s);
        tot += vec[i].s;
    }

    vector<vll> dp(tot + 1, vll(n + 1, 1e18));

    forr(i, 0, n + 1) dp[0][i] = 0;

    forr(i, 1, tot + 1)
    {
        forr(j, 1, n + 1)
        {
            dp[i][j] = min(dp[i][j - 1], dp[max(0, i - vec[j].s)][j - 1] + max(0LL, (vec[j].f.s - vec[j].f.f + 1) / 2));
        }
    }

    printf("%lld", dp[(tot + 1) / 2][n]);
}