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
    int n;
    scd(n);
    vi vec(n+1);
    int tot = 0;
    forr(i, 1, n+1) {
        scd(vec[i]);
        tot += vec[i];
    }
    vector<vi> dp(n+1, vi(2e5+1, -1e9));

    dp[0][1e5] = 0;
    forr(i, 1, n+1) {
        forr(j, -1e5, 1e5+1) {
            dp[i][j+1e5] = dp[i-1][j+1e5];
            if(j - vec[i] >= -1e5) {
                dp[i][j+1e5] = max(dp[i][j+1e5], dp[i-1][j-vec[i] + 1e5] + vec[i]);
            }
            if(j + vec[i] <= 1e5) {
                dp[i][j+1e5] = max(dp[i][j+1e5], dp[i-1][j+vec[i] + 1e5] + vec[i]);
            }
        }
    }

    int ma = dp[n][1e5];
    printf("%d", ma / 2 + (tot - ma));
}