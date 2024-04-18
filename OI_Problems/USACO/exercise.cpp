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
    // freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
    freopen("exercise.in", "r", stdin);
   freopen("exercise.out", "w", stdout);
}

int main() {
    usaco();
    int n;
    scd(n);
    vb sieve(n+1, true);
    sieve[1] = false;
    vi prime;
    prime.pb(1);
    forr(i, 1, n+1) {
        if(sieve[i]) {
            for(int j=2*i; j<=n; j+=i) sieve[j] = false;
            prime.pb(i);
        }
    }
    int x = prime.size();
    lli m;
    sclld(m);
    vector<vll> dp(x, vll(n+1));
    frange(j, n+1)
        dp[0][j] = 1;
    forr(i, 1, x) {
        forr(j, 0, n+1) {
            dp[i][j] += dp[i-1][j];
            // if(j > 0) {
            //     dp[i][j] += dp[i][j-1];
            //     dp[i][j] %= m;
            // }
            for(int k=prime[i]; k<=j; k=k*prime[i]%m) {
                dp[i][j] += dp[i-1][j-k] * k % m;
                dp[i][j] %= m;
            }

        }
    }
    // lli tot = 0;
    // frange(i, x) {
    //     tot += dp[i][n];
    //     tot %= m;
    // }
    printf("%lld\n", dp[x-1][n]);


}