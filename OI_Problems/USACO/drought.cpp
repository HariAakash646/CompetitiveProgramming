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
    int n;
    scd(n);
    vi vec(n);

    frange(i, n) scd(vec[i]);

    if(n % 2 == 0) {
        vector<vll> dp(n, vll(1001)), pref(n, vll(1001));
        forr(i, 0, 1000+1) {
            if(i <= vec[0])
                dp[0][i] = 1;
            pref[0][i] = dp[0][i];
            if(i > 0) pref[0][i] += pref[0][i-1];
        }

        forr(i, 1, n) {
            forr(j, 0, 1000+1) {
                
                if(vec[i] >= j)
                    dp[i][j] = pref[i-1][vec[i]-j];
                pref[i][j] = dp[i][j];
                if(j > 0) {
                    pref[i][j] += pref[i][j-1];
                    pref[i][j] %= mod;
                }
            }
        }
        printf("%lld", dp[n-1][0]);
    }
    else {
        lli tot = 0;
        int mi = *min_element(all(vec));
        frange(x, mi+1) {
            frange(i, n) vec[i] -= x;
            vector<vll> dp(n, vll(1001)), pref(n, vll(1001));
            forr(i, 0, 1000+1) {
                if(i <= vec[0])
                    dp[0][i] = 1;
                pref[0][i] = dp[0][i];
                if(i > 0) pref[0][i] += pref[0][i-1];
            }

            forr(i, 1, n) {
                forr(j, 0, 1000+1) {
                    
                    if(vec[i] >= j)
                        dp[i][j] = pref[i-1][vec[i]-j];
                    pref[i][j] = dp[i][j];
                    if(j > 0) {
                        pref[i][j] += pref[i][j-1];
                        pref[i][j] %= mod;
                    }
                }
            }
            frange(i, n) vec[i] += x;
            tot += dp[n-1][0];
            tot %= mod;
        }
        printf("%lld", tot);
    }
}