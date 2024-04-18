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
    // usaco();
    int n, k;
    scd(n);
    scd(k);

    // vector<vector<vll>> dp(n+1, vector<vll>(k+1, vll(k+1)));
    
    // forr(i, 1, k+1) dp[1][i][i] = 1;

    // forr(i, 2, n+1) {
    //     forr(j, 2, min(i, k)+1) {
    //         forr(l, 1, k+1) {
    //             int r = l + j - 1;
    //             if(r > k) break;
    //             dp[i][l][r] = (j * dp[i-1][l][r] + dp[i-1][l+1][r] + dp[i-1][l][r-1]) % mod;
    //         }
    //     }
    // }

    // vector<vll> dp(n+2, vll(k+2));

    // forr(i, 1, k+1) dp[1][i] = 1;

    // forr(i, 2, n+1) {
    //     forr(j, 1, k+1) {
    //         dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
    //         dp[i][j] %= mod;
    //     }
    // }

    
    // lli tot = 0;
    // forr(i, 1, k+1) {
    //     // printf("%lld ", dp[n][i]);
    //     tot += dp[n][i];
    //     tot %= mod;
    // }

    vector<vector<vector<vll>>> dp(n+1, vector<vector<vll>>(k+2, vector<vll>(k+2, vll(k+2))));

    forr(i, 1, k+1) dp[1][i][i][i] = 1;

    forr(i, 2, n+1) {
        forr(j, 2, k+1) {
            forr(l, 1, k+1) {
                int r = l + j - 1;
                if(r > k) break;

                forr(t, l, r+1) {
                    dp[i][l][r][t] += (dp[i-1][l][r][t-1] + dp[i-1][l][r][t+1]) % mod;
                }
                dp[i][l][r][r] += dp[i-1][l][r-1][r-1];
                dp[i][l][r][l] += dp[i-1][l+1][r][l+1];
                dp[i][l][r][r] %= mod;
                dp[i][l][r][l] %= mod;
            }
        }
    }

    lli tot = 0;
    forr(i, 1, k+1) {
        forr(j, i+1, k+1) {
            forr(r, i, j+1) tot += dp[n][i][j][r];
            tot %= mod;
        }
    }


    printf("%lld", tot%mod);
}