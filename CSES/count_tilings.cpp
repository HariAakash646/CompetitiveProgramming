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

const lli mod = 1e9 + 7;

int main() {
    int n, m;
    scd(n);
    scd(m);

    vector<vector<vll>> dp(m, vector<vll>(n+1, vll(1<<n)));

    dp[0][0][0] = 1;

    frange(i, m) {
        frange(j, n) {
            frange(k, 1<<n) {
                if(k & (1<<(j))) {
                    dp[i][j+1][k^(1<<(j))] += dp[i][j][k];
                    dp[i][j+1][k^(1<<(j))] %= mod;
                }
                else {
                    if(i != m-1) {
                        dp[i][j+1][k^(1<<(j))] += dp[i][j][k];
                        dp[i][j+1][k^(1<<(j))] %= mod;
                    }
                    
                    if(j+2 <= n && !(k & (1<<(j+1)))) {
                        dp[i][j+2][k] += dp[i][j][k];
                        dp[i][j+2][k] %= mod;
                    }
                }
            }
        }
        if(i == m-1) continue;
        frange(k, 1<<n) {
            // int id = 0;
            // int v = k;
            // frange(j, n) {
            //     if(k & (1<<j)) {
            //         id = j+1;
            //         v = (v ^ (1<<j));
            //     }
            //     else break;
            // }
            dp[i+1][0][k] += dp[i][n][k];
            dp[i+1][0][k] %= mod;
        }
    }
    printf("%lld", dp[m-1][n][0]);
}