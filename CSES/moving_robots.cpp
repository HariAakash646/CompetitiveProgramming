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
    int k;
    scd(k);

    vector<vector<ld>> vec(8, vector<ld>(8, 1));

    frange(i, 8) {
        frange(j, 8) {
            vector<vector<vector<ld>>> dp(k+1, vector<vector<ld>>(8, vector<ld>(8)));
            dp[0][i][j] = 1;
            forr(i, 0, k) {
                frange(x, 8) {
                    frange(y, 8) {
                        int c=0;
                        if(x + 1 < 8) {
                            c++;
                        }
                        if(x-1>=0) {
                            c++;
                        }
                        if(y + 1 < 8) {
                            c++;
                        }
                        if(y - 1 >=0) {
                            c++;
                        }
                        if(x + 1 < 8) {
                            dp[i+1][x+1][y] += dp[i][x][y] / c;
                        }
                        if(x-1>=0) {
                            dp[i+1][x-1][y] += dp[i][x][y] / c;
                        }
                        if(y + 1 < 8) {
                            dp[i+1][x][y+1] += dp[i][x][y] / c;
                        }
                        if(y - 1 >=0) {
                            dp[i+1][x][y-1] += dp[i][x][y] / c;
                        }
                    }
                }
            }
            frange(x, 8) {
                frange(y, 8) {
                    vec[x][y] *= (1-dp[k][x][y]);
                }
            }
        }
    }

    ld exp = 0;
    frange(i, 8) {
        frange(j, 8) exp += vec[i][j];
    }

    cout << fixed << setprecision(6) << exp;
}