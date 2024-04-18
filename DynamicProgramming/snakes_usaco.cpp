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

int main()
{
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    int n, k;
    scd(n);
    scd(k);
    vll vec(n + 1);
    frange(i, n) sclld(vec[i + 1]);

    vector<vll> dp(n + 1, vll(k + 1));
    lli ma = 0;
    forr(i, 1, n + 1)
    {
        ma = max(ma, vec[i]);
        dp[i][0] = ma * i;
    }
    forr(i, 1, n + 1)
    {
        forr(j, 1, k + 1)
        {
            // dp[i][j] = dp[i - 1][j - 1] + vec[i];
            dp[i][j] = 1e18;
            ma = vec[i];
            for (int l = i - 1; l >= 0; l--)
            {
                dp[i][j] = min(dp[i][j], dp[l][j - 1] + ma * (i - l));
                ma = max(ma, vec[l]);
            }
        }
    }
    lli tot = 0;
    for (auto e : vec)
        tot += e;
    printf("%lld", *min_element(all(dp[n])) - tot);
}