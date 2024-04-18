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


void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

lli mod = 1e9 + 7;

int main() {
    usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n, k;
        scd(n);
        scd(k);

        vi vec(n+1);
        forr(i, 1, n+1) scd(vec[i]);

        vector<vector<pair<lli, lli>>> dp(n+1, vector<pair<lli, lli>>(n+1, mp(0, 1))), dp2(n+1, vector<pair<lli, lli>>(n+1));

        dp[1][vec[1]] = mp(1, 1);


        forr(i, 2, n+1) {

            forr(j, 1, n+1) {
                dp[i][j] = dp[i-1][j];
                dp2[i][j] = dp2[i-1][j];
                if(j == vec[i]) {
                    if(dp[i-1][j].f + 1 > dp[i-1][0].f + 1) {
                        dp[i][j] = mp(dp[i-1][j].f + 1, dp[i-1][j].s);
                        // dp[i][0].s += dp[i-1][j].s;
                    }
                    else if(dp[i-1][0].f + 1 > dp[i-1][j].f + 1) {
                        dp[i][j] = mp(dp[i-1][0].f + 1, dp[i-1][0].s);
                    }
                    else {
                        dp[i][j] = mp(dp[i-1][0].f + 1, dp[i-1][0].s + dp[i-1][j].s);
                    }
                    if(dp[i][j].f % k == 0) {
                        if(dp[i][j].f > dp2[i][j].f) {
                            dp2[i][j] = dp[i][j];
                        }
                        // else {
                        //     dp2[i][j].s += dp[i][j].s;
                        // }
                    }
                    else {
                        if(dp[i][j].f / k != 0) {
                            dp2[i][j].s *= 2;
                        }
                    }
                }
                if(dp2[i][j].f > dp[i][0].f) {
                    dp[i][0] = dp2[i][j];
                }
                else if(dp2[i][j].f == dp[i][0].f) {
                    dp[i][0].s += dp2[i][j].s; 
                }
            }
        }
        printf("%lld\n", dp[n][0].s % mod);
    }
}