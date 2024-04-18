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
    // usaco();
    int n, x;
    scd(n);
    scd(x);

    vi vec(n+1);
    forr(i, 1, n+1) scd(vec[i]);

    sort(vec.begin()+1, vec.end(), greater<>());

    int v = 0;

    forr(i, 1, n/2+1) v += vec[i];

    vector<vector<vi>> dp(n+1, vector<vi>(n+1, vi(v+1)));
    dp[0][0][0] = 1;

    forr(i, 1, n+1) {
        forr(j, 0, i+1) {
            forr(k, 0, v+1) {
                dp[i][j][k] = (dp[i-1][j][k] * lli(j+1)) % mod;
                if(j > 0 && k - vec[i] >= 0) {
                    dp[i][j][k] += dp[i-1][j-1][k-vec[i]];
                    dp[i][j][k] %= mod;
                }
                if(j < n && k + vec[i] <= v) {
                    dp[i][j][k] += (dp[i-1][j+1][k+vec[i]] * lli(j+1)) % mod;
                    dp[i][j][k] %= mod;
                }
            }
        }
    }

    int tot = 0;
    frange(i, min(x+1, v+1)) {
        tot += dp[n][0][i];
        tot %= mod;
    }

    printf("%d", tot);
}