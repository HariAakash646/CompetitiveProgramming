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

lli mod = 1e9+7;

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
        vi col(n+1);

        vector<vll> dp(n+1, vll(n+1));

        // frange(i, n+1) dp[i][0] = 1;
        dp[0][0] = 1;
        forr(i, 1, n+1) {
            forr(j, 1, n+1) {
                if(j % k == 1) {
                    frange(l, i) {
                        dp[i][j] += dp[l][j-1];
                        dp[i][j] %= mod;
                    }
                    dp[i][j] += dp[col[vec[i]]][j];
                    dp[i][j] %= mod;
                }
                else {
                    dp[i][j] = (dp[col[vec[i]]][j-1] + dp[col[vec[i]]][j]) % mod;
                }
                
            }
            col[vec[i]] = i;
        }
        vll ans(n+1);
        forr(i, 0, n+1) {
            lli ma = 0;
            forr(j, 1, n+1) ma = max(ma, dp[col[j]][i]);
            ans[i] = ma;
        }
        lli out = 1;
        for(int i=0; i<=n; i+=k) {
            if(ans[i]) {printf("%d ", i);out = ans[i];}
        }
        printf("%lld\n", out);
    }
}