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
    vii vec(n + 1);
    int tot = 0;

    forr(i, 1, n + 1)
    {
        scd(vec[i].f);
        tot += vec[i].f;
        vec[i].s = i;
    }
    sort(vec.begin() + 1, vec.end(), greater<>());
    vector<vb> dp(n + 1, vb(tot + 1));
    dp[0][0] = true;

    forr(i, 1, n + 1)
    {
        frange(j, tot + 1)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - vec[i].f >= 0 && j - vec[i].f <= tot / 2)
            {
                dp[i][j] = dp[i][j] || dp[i - 1][j - vec[i].f];
            }
            // printf("%d ", (int)dp[i][j]);
        }
        // printf("\n");
    }
    for (int i = tot; i >= tot / 2 + 1; i--)
    {
        if (dp[n][i])
        {
            // printf("%d\n", i);
            vi out;
            int v = i;
            for (int k = n; k >= 1; k--)
            {
                if (v - vec[k].f >= 0 && dp[k - 1][v - vec[k].f] && v - vec[k].f <= tot / 2)
                {
                    out.pb(vec[k].s);
                    v -= vec[k].f;
                }
            }
            printf("%d\n", out.size());
            for (auto e : out)
                printf("%d ", e);
            break;
        }
    }
}