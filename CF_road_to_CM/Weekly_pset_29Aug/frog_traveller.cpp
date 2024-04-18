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
    vi v1(n + 1), v2(n + 1);
    forr(i, 1, n + 1) scd(v1[i]);
    forr(i, 1, n + 1) scd(v2[i]);
    vvi ing(n + 1);
    forr(i, 1, n + 1)
    {
        int v = i - v1[i];
        v += v2[v];
        ing[v].pb(i);
    }
    vi dp(n + 1, 1e9);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (auto e : ing[i])
            dp[i] = min(dp[i], dp[e] + 1);
    }
    if (dp[0] == 1e9)
    {
        printf("-1");
        return 0;
    }
    printf("%d\n", dp[0]);
    vi out;
    out.pb(0);
    int curr = 0;
    while (curr != n)
    {
        for (auto e : ing[curr])
        {
            if (dp[e] == dp[curr] - 1)
            {
                curr = e;
                break;
            }
            out.pb(curr);
        }
    }
    reverse(all(out));
    for (auto e : out)
        printf("%d ", e);
}