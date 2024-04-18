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
    int n, x;
    scd(n);
    scd(x);
    int ma = 0;
    vi vec(n+2);
    int tot = 0;
    forr(i, 1, n+1) {scd(vec[i]); ma = max(ma, vec[i]); tot += vec[i];}
    // vec[0] = vec[n];
    // vec[n+1] = vec[1];
    // vvi dp(n+1, vi(n*ma+1, -1e9));
    // dp[0][0] = 0;
    // forr(i, 1, n+1) {
    //     tot += vec[i];
    //     forr(j, 0, n*ma+1) {
    //         int v = vec[i-1] & vec[i];
    //         if(j - vec[i+1] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-vec[i+1]] + v);
    //         v = vec[i-1] & vec[i+1];
    //         if(j - vec[i] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-vec[i]] + v);
    //         v = vec[i] & vec[i+1];
    //         if(j - vec[i-1] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-vec[i-1]] + v);
    //     }
    // }
    // ma = 0;
    // frange(i, min((int)dp[n].size(), tot + x + 1)) ma = max(ma, dp[n][i]);
    printf("%d", tot);
}