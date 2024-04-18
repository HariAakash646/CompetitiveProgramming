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
    int n, m;
    scd(n);
    scd(m);

    vll v1(n + 1);
    vector<pair<lli, pii>> v2(m + 1);
    vii tim(m + 1);

    forr(i, 1, n + 1) sclld(v1[i]);
    lli mv = 0;
    lli mav = 0;
    forr(i, 1, m + 1)
    {
        sclld(v2[i].f);
        scd(v2[i].s.f);
        scd(v2[i].s.s);
        mv += v2[i].s.f;
        mav += v2[i].s.s;
    }
    if (n < mv || n > mav)
    {
        printf("-1");
        return 0;
    }
    sort(all(v1));
    sort(all(v2));
    vector<vll> dp(m + 1, vll(n + 1, 1e12));

    // forr(i, 0, m + 1) dp[i][0] = 0;
    forr(i, 1, m + 1)
    {
        dp[i][0] = 0;
        if (v2[i].s.f != 0)
            break;
    }

    forr(i, 1, n + 1)
    {
        vector<vll> curr(m + 1, vll(n + 1, 1e12));

        forr(j, 1, m + 1)
        {
            forr(k, v2[j - 1].s.f, v2[j - 1].s.s + 1)
            {
                curr[j][0] = min(curr[j][0], curr[j - 1][k]);
            }
            forr(k, 1, n + 1)
            {
                curr[j][k] = dp[j][k - 1] + abs(v1[i] - v2[j].f);
            }
        }
        dp = curr;
    }
    lli mi = 1e18;
    forr(j, v2[m].s.f, v2[m].s.s + 1) mi = min(mi, dp[m][j]);

    printf("%lld", mi);
}