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
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vll vec(n);
        frange(i, n) sclld(vec[i]);
        vll val(n - 2);
        frange(i, n - 2)
        {
            val[i] = (vec[i] + vec[i + 1] + vec[i + 2]) % 3;
            // printf("%lld ", val[i]);
        }
        // printf("\n");
        vector<vvi> dp(n - 2, vvi(3, vi(3)));
        dp[0][0][0] = (3 - val[0]) % 3;
        dp[0][1][0] = (1 - val[0] + 3) % 3;
        dp[0][2][0] = (2 - val[0] + 3) % 3;
        // dp[0][0][1] = (3 - val[0]) % 3;
        // dp[0][1][1] = (1 - val[0] + 3) % 3;
        // dp[0][2][1] = (2 - val[0] + 3) % 3;
        // dp[0][0][2] = (3 - val[0]) % 3;
        // dp[0][1][2] = (1 - val[0] + 3) % 3;
        // dp[0][2][2] = (2 - val[0] + 3) % 3;
        forr(i, 1, (n - 2))
        {
            frange(j, 3)
            {
                frange(k, 3)
                {
                    dp[i][j][k] = dp[i - 1][(k + 3 - (j - val[i] + 3) % 3) % 3][(3 - (j - val[i] + 3) % 3) % 3] + (j - val[i] + 3) % 3;
                }
            }
        }
        int out = min({dp[n - 2 - 1][0][0], dp[n - 2 - 1][1][1] + 2, dp[n - 2 - 1][2][2] + 1, dp[n - 2 - 1][1][0] + 2, dp[n - 2 - 1][2][0] + 1});
        if (n - 2 - 2 >= 0)
        {
            out = min(out, int(dp[n - 2 - 2][val[n - 2 - 1]][val[n - 2 - 1]] + (3 - val[n - 2 - 1])));
        }
        printf("%d\n", out);
    }
}