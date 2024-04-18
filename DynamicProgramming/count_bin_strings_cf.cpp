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

lli mod = 998244353;

int main() {
    // usaco();
    int n;
    scd(n);
    vvi grid(n+1, vi(n+1));

    frange(i, n) {
        forr(j, i, n) {
            scd(grid[i+1][j+1]);
        }
    }

    vector<vll> dp(n+1, vll(n+1));

    if(grid[1][1] != 2)
        dp[1][0] = 2;

    forr(i, 2, n+1) {
        forr(j, 0, i) {
            bool done = true;
            forr(k, j+1, i+1) {
                if(grid[k][i] == 2) done = false;
            }
            forr(k, 1, j+1) {
                if(grid[k][i] == 1) done = false;
            }

            if(done) {
                if(j == i-1) {
                    forr(k, 0, i) {
                        dp[i][j] += dp[i-1][k];
                        dp[i][j] %= mod;
                    }
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        } 
    }

    lli out = 0;
    forr(i, 0, n+1) {
        out += dp[n][i];
        out %= mod;
    }
    printf("%lld", out);

}