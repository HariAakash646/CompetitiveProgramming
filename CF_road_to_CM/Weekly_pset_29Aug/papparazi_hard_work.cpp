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
    int r, n;
    scd(r);
    scd(n);
    vector<pair<pii, int>> vec(n + 1);

    forr(i, 1, n + 1)
    {
        scd(vec[i].s);
        scd(vec[i].f.f);
        scd(vec[i].f.s);
    }
    vec[0] = mp(mp(1, 1), 0);
    vi pref(n + 1, -1e9);
    vi dp(n + 1, -1e9);

    pref[0] = dp[0] = 0;

    forr(i, 1, n + 1)
    {
        auto p = vec[i];

        for (int j = i - 1; j >= 0; j--)
        {
            if (p.s - vec[j].s > 2 * r)
            {
                dp[i] = max(dp[i], pref[j] + 1);
                break;
            }
            if (abs(p.f.f - vec[j].f.f) + abs(p.f.s - vec[j].f.s) <= p.s - vec[j].s)
                dp[i] = max(dp[i], dp[j] + 1);
        }

        pref[i] = max(pref[i - 1], dp[i]);
    }
    printf("%d", pref[n]);
}