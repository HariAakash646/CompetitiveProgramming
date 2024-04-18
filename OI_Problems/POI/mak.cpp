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

    vb sieve(1e4+1, true);
    sieve[1] = false;

    vi prime;
    forr(i, 2, 1e4+1) {
        if(sieve[i]) {
            prime.pb(i);
            for(int j=2*i; j<=1e4; j+=i) {
                sieve[j] = false;
            }
        }
    }

    int d;
    scd(d);

    frange(_, d) {
        int n;
        scd(n);
        int x = 70;
        vector<vector<ld>> dp(x+1, vector<ld>(n+1, -1e9));
        frange(i, n+1) dp[0][i] = 0;

        forr(i, 1, x+1) {
            frange(j, n+1) {
                dp[i][j] = dp[i-1][j];
                if(j > 0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
                ld v = log((ld)prime[i-1]);
                for(int k=1, exp=0; k<=j; k*=prime[i-1], exp++) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-k] + v * exp);
                }
            }
        }
        vi val;
        int curr = n;
        for(int i=x; i>=1; i--) {
            if(dp[i-1][curr] == dp[i][curr]) {
                continue;
            }
            ld v = log((ld)prime[i-1]);
            for(int k=1, exp=0; k<=curr; k*=prime[i-1], exp++) {
                if(dp[i][curr] == dp[i-1][curr-k] + v * exp) {
                    curr -= k;
                    val.pb(k);
                    break;
                }
            }
        }

        vi out(n+1);
        int id = 1;
        sort(all(val));
        int tot = 0;
        for(auto e : val) tot += e;
        frange(i, n-tot) val.pb(1);
        sort(all(val));
        for(auto e : val) {
            forr(i, id, id+e-1) {
                out[i] = i+1;
            }
            out[id+e-1] = id;
            id = id + e;
        }
        forr(i, 1, n+1) printf("%d ", out[i]);
        printf("\n");

    }
}