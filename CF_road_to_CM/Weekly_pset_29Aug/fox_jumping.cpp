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

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int n;
    scd(n);
    vi len(n + 1), cost(n + 1);

    forr(i, 1, n + 1) scd(len[i]);
    forr(i, 1, n + 1) scd(cost[i]);

    map<int, int> prev, dp;
    prev[0] = 0;

    forr(i, 1, n + 1)
    {
        dp = {};
        for (auto p : prev)
        {
            if (dp.find(p.f) == dp.end())
            {
                dp[p.f] = p.s;
            }
            dp[p.f] = min(dp[p.f], p.s);
            int g = gcd(p.f, len[i]);
            if (dp.find(g) == dp.end())
            {
                dp[g] = p.s + cost[i];
            }
            dp[g] = min(dp[g], p.s + cost[i]);
        }
        prev = dp;
    }
    if (dp[1])
        printf("%d", dp[1]);
    else
        printf("-1");
}