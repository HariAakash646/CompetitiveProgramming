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
    usaco();
    int n, k;
    scd(n);
    scd(k);

    vector<vector<vll>> dp(k+1, vector<vll>(n, vll(n)));
    vector<vll> su(n, vll(n));

    vll v1(2*n);
    vll vr(n), vc(n);

    lli tot = 1;

    forr(i, 1, k+1) {
        frange(r, n) {
            frange(c, n) {
                dp[i][r][c] = tot;
                dp[i][r][c] -= v1[r+c];
                if(r > c) dp[i][r][c] -= vr[r-c];
                else dp[i][r][c] -= vc[c-r];
                dp[i][r][c] += su[r][c];
                dp[i][r][c] += 3*mod;
                dp[i][r][c] %= mod;
            }
        }
        tot = 0;
        // vc = vr = vll(n);
        // v1 = vll(2*n);

        frange(r, n) {
            frange(c, n) {
                tot += dp[i][r][c];
                su[r][c] += dp[i][r][c];
                v1[r+c] += dp[i][r][c];
                if(r > c) {
                    vr[r-c] += dp[i][r][c];
                    vr[r-c] %= mod;
                }
                else {
                    vc[c-r] += dp[i][r][c];
                    vc[c-r] %= mod;
                }
                tot %= mod;
                v1[r+c] %= mod;
                su[r][c] %= mod;
            }
        }
    }
    printf("%lld", tot);
}