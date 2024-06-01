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
// #define s second
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
const int MAXN = 1e5+5;
const int sz = 400;
int dp[MAXN][sz+1];

int main() {
    // usaco();
    int n;
    scd(n);
    
    frange(i, n) {
        forr(j, 0, 401) dp[i][j] = 0;
    }

    vll cnt(n);
    cnt[0] = 1;
    // vector<vll> dp(n, vll(sz+1));

    frange(i, n) {
        lli d, x;
        sclld(d);
        sclld(x);
        if(d) {
            if(d <= sz) {
                dp[i][d] += cnt[i];
                if(dp[i][d] >= mod) dp[i][d] -= mod; 
                lli p = i+lli(d)*x;
                if(p+d<n) {
                    dp[p+d][d] -= cnt[i];
                    if(dp[p+d][d] < 0)
                        dp[p+d][d] += mod;
                    cnt[p+d] -= cnt[i];
                    if(cnt[p+d] < 0)
                        cnt[p+d] += mod;
                }
            }
            else {
                forr(j, 1, x+1) {
                    lli p = i + lli(j)*d;
                    if(p<n) {
                        cnt[p] += cnt[i];
                        if(cnt[p] >= mod)
                            cnt[p] -= mod;
                    }
                    else break;
                }
            }
        }
        forr(j, 1, sz+1) {
            if(i+j<n) {
                dp[i+j][j] += dp[i][j];
                if(dp[i+j][j] >= mod)
                    dp[i+j][j] -= mod;
                cnt[i+j] += dp[i][j];
                if(cnt[i+j] >= mod)
                    cnt[i+j] -= mod;
            } 
            else break;
        }
    }
    lli tot = 0;
    frange(i, n) {
        tot += cnt[i];
        if(tot >= mod) tot -= mod;
    }
    printf("%lld", tot);
}