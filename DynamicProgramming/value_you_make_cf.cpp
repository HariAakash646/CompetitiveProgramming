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
    usaco();
    int n;
    scd(n);
    int k;
    scd(k);
    vi vec(n+1);
    forr(i, 1, n+1) scd(vec[i]);
    sort(all(vec));
    vector<vector<vb>> dp(n+1, vector<vb>(k+1, vb(k+1)));

    dp[0][0][0] = true;

    forr(i, 1, n+1) {
        forr(j, 0, k+1) {
            forr(l, 0, j+1) {
                dp[i][j][l] = dp[i-1][j][l];
                if(j - vec[i] >= 0) {
                    dp[i][j][l] = dp[i][j][l] || dp[i-1][j-vec[i]][l]; 
                    if(l - vec[i] >= 0) {
                        dp[i][j][l] = dp[i][j][l] || dp[i-1][j-vec[i]][l-vec[i]];
                    }
                }
            }
        }
    }

    vi val;
    frange(i, k+1) {
        if(dp[n][k][i]) val.pb(i);
    }
    sort(all(val));
    printf("%d\n", (int)vec.size());
    for(auto e : vec) printf("%d ", e);
    
}