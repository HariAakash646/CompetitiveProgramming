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
    vll v1(n + 1), v2(m + 1);
    vector<pair<lli, int>> vec;
    vec.pb({0, 0});
    vi sink, tap;
    forr(i, 1, n + 1)
    {
        sclld(v1[i]);
        vec.pb({v1[i], 0});
    }
    forr(i, 1, m + 1)
    {
        sclld(v2[i]);
        vec.pb({v2[i], 1});
    }
    sort(all(vec));
    forr(i, 1, n + 1)
    {
        if (vec[i].s)
            tap.pb(i);
        else
            sink.pb(i);
    }
    vector<vll> dp(n + m + 1, vll(n + m + 1));

    forr(l, 1, n + m)
    {
        for (int i = 1; i + l <= n + m; i++)
        {
            int j = i + l;
            dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            if (vec[i].s)
            {
                for (auto e : sink)
                {
                    if (e > i && e <= j)
                    {
                        dp[i][j] = max(dp[i][j], dp[i + 1][e - 1] + dp[e + 1][j] + abs(vec[i].f - vec[e].f));
                    }
                }
            }
            else
            {
                for (auto e : tap)
                {
                    if (e > i && e <= j)
                    {
                        dp[i][j] = max(dp[i][j], dp[i + 1][e - 1] + dp[e + 1][j] + abs(vec[i].f - vec[e].f));
                    }
                }
            }
            if (vec[j].s)
            {
                for (auto e : sink)
                {
                    if (e >= i && e < j)
                    {
                        dp[i][j] = max(dp[i][j], dp[i][e - 1] + dp[e + 1][j - 1] + abs(vec[j].f - vec[e].f));
                    }
                }
            }
            else
            {
                for (auto e : tap)
                {
                    if (e >= i && e < j)
                    {
                        dp[i][j] = max(dp[i][j], dp[i][e - 1] + dp[e + 1][j - 1] + abs(vec[j].f - vec[e].f));
                    }
                }
            }
        }
    }
    printf("%lld", dp[1][n + m]);
}