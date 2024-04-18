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
    int t;
    scd(t);

    frange(_, t) {
        int n, m, r;
        scd(n);
        scd(m);
        scd(r);

        vector<vector<seti>> grid(n+1, vector<seti>(m+1));

        frange(i, r) {
            int t;
            scd(t);
            int d, c;
            scd(d);
            scd(c);

            if(d == 1) {
                frange(j, m+1) grid[c][j].insert(t);
            }
            else {
                frange(j, n+1) grid[j][c].insert(t);
            }
        }

        vector<vvi> dp(n+1, vvi(m+1, vi(r+1)));

        frange(i, r+1) {
            if(grid[0][0].find(i) != grid[0][0].end()) break;
            dp[0][0][i] = true;
        }

        frange(i, n+1) {
            frange(j, m+1) {
                frange(k, r+1) {
                    if(grid[i][j].find(i + j + k) == grid[i][j].end()) {
                        if(k > 0) 
                            dp[i][j][k] = dp[i][j][k-1];
                        if(i -1 >= 0) dp[i][j][k] = dp[i][j][k] || dp[i-1][j][k];
                        if(j - 1 >= 0) dp[i][j][k] = dp[i][j][k] || dp[i][j-1][k];
                    }
                }
            }
        }

        int mi = -1;
        for(int i=r; i>=0; i--) {
            if(dp[n][m][i]) mi = n + m + i;
        }
        printf("%d\n", mi);
    }
}