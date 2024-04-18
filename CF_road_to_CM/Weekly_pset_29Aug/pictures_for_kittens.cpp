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
    int n, k, x;
    scd(n);
    scd(k);
    scd(x);

    vll vec(n + 1);
    forr(i, 1, n + 1) sclld(vec[i]);

    vector<vll> dp(x + 1, vll(n + 1, -1e18));
    dp[0][0] = 0;

    forr(i, 1, x + 1)
    {
        vb enter(n + 1);
        deque<pair<lli, int>> q;
        q.push_back(mp(dp[i - 1][0], 0));
        forr(j, 1, n + 1)
        {
            if (q.front().s < j - k)
                q.pop_front();
            dp[i][j] = q.front().f + vec[j];
            while (q.size() && dp[i - 1][j] > q.back().f)
            {
                q.pop_back();
            }
            q.push_back(mp(dp[i - 1][j], j));
            // forr(l, max(0, j - k), j) dp[i][j] = max(dp[i][j], dp[i - 1][l] + vec[j]);
        }
    }
    if (n / k > x)
        printf("-1");
    else
    {
        lli ma = 0;
        for (int i = n; i >= n - k + 1; i--)
        {
            ma = max(ma, dp[x][i]);
        }
        printf("%lld", ma);
    }
    // printf("%lld", *max_element(all(dp[x])));
}