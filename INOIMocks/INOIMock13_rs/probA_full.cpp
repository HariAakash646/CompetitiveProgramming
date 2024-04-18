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
    int n, l;
    scd(n);
    scd(l);
    vi vec(n);
    frange(i, n) scd(vec[i]);
    sort(all(vec));
    vec.pb(1e6);
    if(n == 1) {
        printf("1");
        return 0;
    }

    vector<vector<vll>> dp(n, vector<vll>(n+2, vll(3*(l+1))));
    if(2*(vec[1] - vec[0]) <= l)
        dp[0][1][2*(vec[1] - vec[0])] = 1;
    if((vec[1] - vec[0]) <= l)
        dp[0][1][(vec[1] - vec[0])+l+1] = 2;
    dp[0][1][2*(l+1)] = 1;

    forr(i, 1, n) {
        forr(j, 1, n+1) {
            forr(k, 0, l+1) {
                int c = k - (2*j) * (vec[i+1] - vec[i]);
                if(c >= 0) {
                    dp[i][j][k] += 2*j*dp[i-1][j][c] + dp[i-1][j-1][c] + dp[i-1][j+1][c] * j * (j+1);
                    dp[i][j][k] %= mod;
                }
                c = k - (2*(j)-1) * (vec[i+1] - vec[i]);
                if(c >= 0) {
                    dp[i][j][k+l+1] += (2*j-1)*dp[i-1][j][c+l+1] + dp[i-1][j-1][c+l+1] + dp[i-1][j+1][c+l+1] * (j * j);
                    dp[i][j][k+l+1] %= mod;
                    dp[i][j][k+l+1] += 2*j*dp[i-1][j][c] + 2*dp[i-1][j-1][c];
                    dp[i][j][k+l+1] %= mod;
                }
                c = k - (2*(j)-2) * (vec[i+1] - vec[i]);
                if(c >= 0) {
                    dp[i][j][k+2*(l+1)] += (2*j-2)*dp[i-1][j][c+2*(l+1)] + (j!=2) * dp[i-1][j-1][c+2*(l+1)] + dp[i-1][j+1][c+2*(l+1)] * ((j-1) * j + (j == 1));
                    dp[i][j][k+2*(l+1)] %= mod;
                    dp[i][j][k+2*(l+1)] += (j-1 + (j==1))*dp[i-1][j][c+l+1] + dp[i-1][j-1][c+l+1];
                    dp[i][j][k+2*(l+1)] %= mod;
                }
            }
        }
    }  
    lli tot = 0;
    frange(i, l+1) tot += dp[n-1][1][i+2*(l+1)];
    tot %= mod;
    printf("%lld", tot);
}