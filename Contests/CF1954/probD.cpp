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

const lli mod = 998244353;

int main() {
    // usaco();
    int n;
    scd(n);

    vi vec(n+1);
    forr(i, 1, n+1) scd(vec[i]);
    sort(all(vec));
    vector<vll> dp(n+1, vll(5001));
    dp[0][0] = 1;

    lli tot = 0;

    forr(i, 1, n+1) {
        frange(j, 5001) {
            if(vec[i] > j) {
                tot += vec[i] * dp[i-1][j];
                tot %= mod;
            }
            else {
                tot += ((vec[i] + j + 1)/2) * dp[i-1][j];
                tot %= mod;
            }
            dp[i][j] = dp[i-1][j];
            if(j - vec[i] >= 0) {
                dp[i][j] += dp[i-1][j-vec[i]];
                dp[i][j] %= mod;
            }
        }
    }
    printf("%lld", tot);
}