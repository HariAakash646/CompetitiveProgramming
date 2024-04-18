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
    int n;
    scd(n);
    vector<pair<int, lli>> vec(n + 1);
    forr(i, 1, n + 1)
    {
        scd(vec[i].f);
        sclld(vec[i].s);
    }
    vector<vll> dp(n + 1, vll(2));

    dp[0][1] = -1e18;

    forr(i, 1, n + 1)
    {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
        if (!vec[i].f)
        {
            dp[i][0] = max(dp[i][0], dp[i - 1][0] + vec[i].s);
            dp[i][0] = max(dp[i][0], dp[i - 1][1] + vec[i].s);
        }
        else
        {
            dp[i][1] = max(dp[i][1], dp[i][0] + vec[i].s);
        }
    }
    printf("%lld", max(dp[n][0], dp[n][1]));
}