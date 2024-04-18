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

lli mod = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    frange(_, t)
    {
        int n;
        cin >> n;
        string seq;
        cin >> seq;
        vector<vector<pair<lli, lli>>> dp(n, vector<pair<lli, lli>>(3));
        if (seq[0] == '*' || seq[0] == '4')
        {
            dp[0][0].f = 1;
            dp[0][0].s = 0;
        }
        forr(i, 1, n)
        {
            // dp[i][0].f = dp[i][0].s = dp[i - 1][0].f + dp[i-1][0].s;
            // dp[i][1].f = dp[i][1].s = dp[i - 1][1].f + dp[i-1][1].s;
            // dp[i][2].f = dp[i][2].s = dp[i - 1][2].f + dp[i-1][2].s;
            if (seq[i] == '4')
            {
                dp[i][0].f = dp[i - 1][0].f + dp[i - 1][0].s + 1;
                dp[i][2].f = dp[i - 1][2].f + dp[i - 1][2].s + dp[i - 1][1].f + dp[i - 1][1].s;
                dp[i][1].f = dp[i - 1][1].f + dp[i - 1][1].s;
            }
            if (seq[i] == '0')
            {
                dp[i][1].s = dp[i - 1][1].f + dp[i - 1][1].s + dp[i - 1][0].f + dp[i - 1][0].s;

                dp[i][0].s = dp[i - 1][0].f + dp[i - 1][0].s;
                dp[i][2].s = dp[i - 1][2].f + dp[i - 1][2].s;
            }
            if (seq[i] == '*')
            {
                dp[i][0].f = dp[i - 1][0].f + dp[i - 1][0].s + 1;
                dp[i][0].s = dp[i - 1][0].f + dp[i - 1][0].s;
                dp[i][1].s = dp[i - 1][1].f + dp[i - 1][1].s + dp[i - 1][0].f + dp[i - 1][0].s;
                dp[i][1].f = dp[i - 1][1].f + dp[i - 1][1].s;
                dp[i][2].f = dp[i - 1][2].f + dp[i - 1][2].s + dp[i - 1][1].f + dp[i - 1][1].s;
                dp[i][2].s = dp[i - 1][2].f + dp[i - 1][2].s;
            }
            dp[i][0].f %= mod;
            dp[i][1].f %= mod;
            dp[i][2].f %= mod;
            dp[i][0].s %= mod;
            dp[i][1].s %= mod;
            dp[i][2].s %= mod;
        }
        // for (auto v : dp)
        // {
        //     for (auto e : v)
        //     {
        //         printf("%d ", e);
        //     }
        //     printf("\n");
        // }
        // lli tot = 0;
        // frange(i, n)
        // {
        //     tot += dp[i][2];
        //     tot %= mod;
        // }
        cout << dp[n - 1][2].f + dp[n - 1][2].s << "\n";
    }
}