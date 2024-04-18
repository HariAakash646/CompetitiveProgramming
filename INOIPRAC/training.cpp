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
    lli st;
    scd(n);
    sclld(st);
    vll vec(n + 1);
    vec[0] = st;

    forr(i, 1, n + 1)
    {
        lli x = vec[i - 1];
        lli v = 0;
        while (x > 0)
        {
            v += x % 10;
            x /= 10;
        }
        vec[i] = vec[i - 1] + v * v * v;
    }
    vll exp(n + 1);
    forr(i, 1, n + 1) sclld(exp[i]);

    vector<vll> dp(n + 1, vll(n + 1, -1e18 - 10));
    dp[0][0] = 0;

    forr(i, 1, n + 1)
    {
        frange(j, n + 1)
        {
            dp[i][j] = dp[i - 1][j] + exp[i] * vec[j];
            if (j >= 1)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            }
        }
    }
    printf("%lld", *max_element(all(dp[n])));
}