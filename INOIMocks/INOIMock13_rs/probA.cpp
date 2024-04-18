#include <bits/stdc++.h>
 
using namespace std;
 
#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
 
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;
typedef multiset<int> mseti;
 
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
    int l;
    scd(l);

    vector<vector<vll>> dp(1<<n, vector<vll>(n, vll(l+1, 0)));
    vi vec(n);
    frange(i, n) {
        scd(vec[i]);
    }

    frange(i, n) {
        dp[1<<i][i][0] = 1;
    }

    forr(i, 1, 1<<n) {
        frange(j, n) {
            frange(k, l+1) {
                if(dp[i][j][k]) continue;
                frange(e, n) {
                    if(e != j && (i & (1<<e))) {
                        int d = abs(vec[e] - vec[j]);
                        if(k >= d)
                        {
                            dp[i][j][k] += dp[i^(1<<j)][e][k-d];
                            dp[i][j][k] %= mod;
                        }
                    }
                }
            }
        }
    }
    lli tot = 0;
    frange(j, n) {
        frange(k, l+1) {
            tot += dp[(1<<n)-1][j][k];
            tot %= mod;
        }
    }
    printf("%lld\n", tot);

}