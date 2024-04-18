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

const lli mod = 1e8 + 7;

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n, m, k;
        scd(n);
        scd(m);
        scd(k);

        vi a(n+1, -1), b(m+1, -1);

        frange(i, n) scd(a[i+1]);
        frange(i, m) scd(b[i+1]);

        vector<vector<vll>> dp1(n+1, vector<vll>(m+1, vll(k+1))), dp2(n+1, vector<vll>(m+1, vll(k+1)));
        dp1[0][0][0] = 1;

        forr(i, 0, n+1) {
            forr(j, 0, m+1) {
                forr(l, 1, k+1) {
                    if(i > 0) {
                        if(a[i] != a[i-1])
                            dp1[i][j][l] = dp1[i-1][j][l-1];
                        else dp1[i][j][l] = dp1[i-1][j][l];
                        if(a[i] != b[j])
                            dp1[i][j][l] += dp2[i-1][j][l-1];
                        else dp1[i][j][l] += dp2[i-1][j][l];
                    }

                    if(j > 0) {
                        if(b[j] != b[j-1])
                            dp2[i][j][l] = dp2[i][j-1][l-1];
                        else dp2[i][j][l] = dp2[i][j-1][l];
                        if(b[j] != a[i])
                            dp2[i][j][l] += dp1[i][j-1][l-1];
                        else dp2[i][j][l] += dp1[i][j-1][l];
                    }
                    dp1[i][j][l] %= mod;
                    dp2[i][j][l] %= mod;
                }
            }
        }
        printf("%lld\n", (dp1[n][m][k] + dp2[n][m][k]) % mod);
    }
}