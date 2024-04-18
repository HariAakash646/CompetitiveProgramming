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

int main() {
    // usaco();
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);
    int n, k;
    scd(n);
    scd(k);

    vi vec(n);

    frange(i, n) scd(vec[i]);

    frange(i, n) vec.pb(vec[i]);

    vector<vector<vll>> dp(k, vector<vll>(2*n, vll(2*n, 1e18)));

    frange(i, n) {
        for(int j=i; j<=i+n-1; j++) {
            lli inc = 0;
            lli dec = 0;
            lli tot = 0;
            forr(k, i, j+1) {
                tot += vec[k]*(k-i);
                // dec += vec[k];
            }

            // forr(k, i, j+1) {
            //     tot -= dec;
            //     tot += inc;
            //     dec -= vec[k];
            //     inc += vec[k];
            //     dp[0][i][j] = min(dp[0][i][j], tot);
            // }
            dp[0][i][j] = tot;
            // printf("%d %d %lld\n", i, j, dp[0][i][j]);
        }
    }

    forr(i, 1, k) {
        frange(j, n) {
            for(int l=j; l<=j+n-1; l++) {
                forr(r, j, l) {
                    frange(e, i)
                        dp[i][j][l] = min(dp[i][j][l], dp[e][j][r] + dp[i-(e+1)][r+1][l]);
                }
            }
        }
    }

    lli mi = 1e18;

    frange(i, n) {
        mi = min(mi, dp[k-1][i][i+n-1]);
    }
    printf("%lld", mi);
}