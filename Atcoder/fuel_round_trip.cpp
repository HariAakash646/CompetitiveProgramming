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
    int n, h;
    scd(n);
    scd(h);

    vll pos(n+1);
    frange(i, n) sclld(pos[i+1]);

    vector<pair<lli, int>> vec(n+1);
    frange(i, n-1) {
        sclld(vec[i+1].f);
        scd(vec[i+1].s);
    }

    vector<vector<vll>> dp(n+1, vector<vll>(h+1, vll(h+1, 1e18))), dp1(n+1, vector<vll>(h+1, vll(h+1, 1e18)));

    frange(i, h+1) {dp[n][i][i] = 0; dp1[n][i][i] = 0;}
    // frange(i, h+1) dp[n][i][min(h, i+vec[n].s)] = vec[n].f;

    for(int i=n-1; i>=0; i--) {
        for(int j=h; j>=0; j--) {
            frange(k, h+1) {
                if(j - (pos[i+1] - pos[i]) >= 0 && k + (pos[i+1] - pos[i]) <= h) {
                    dp[i][j][k] = min(dp[i][j][k], dp1[i+1][max(0LL, j - (pos[i+1] - pos[i]))][min(lli(h), k + (pos[i+1] - pos[i]))]);
                }
                if(k + (pos[i+1] - pos[i]) - vec[i].s <= h && k + (pos[i+1] - pos[i]) - vec[i].s >= 0 && j - (pos[i+1] - pos[i]) >= 0) {
                    dp1[i][j][k] = min(dp1[i][j][k], dp[i+1][j - (pos[i+1] - pos[i])][k + (pos[i+1] - pos[i]) - vec[i].s] + vec[i].f);
                }
                if(k + (pos[i+1] - pos[i]) <= h && j - (pos[i+1] - pos[i]) + vec[i].s >= 0 && j - (pos[i+1] - pos[i]) + vec[i].s <= h) {
                    dp1[i][j][k] = min(dp1[i][j][k], dp[i+1][j - (pos[i+1] - pos[i]) + vec[i].s][k + (pos[i+1] - pos[i])] + vec[i].f);
                }
                // if(j + vec[i].s <= h) dp1[i][j][k] = min(dp1[i][j][k], dp[i][j + vec[i].s][k] + vec[i].f);
                // if(k - vec[i].s >= 0) dp1[i][j][k] = min(dp1[i][j][k], dp[i][j][k-vec[i].s] + vec[i].f);
                // dp1[i][j][k] = min(dp1[i][j][k], dp[i][min(h, j + vec[i].s)][k] + vec[i].f);
                // dp1[i][j][k] = min(dp1[i][j][k], dp[i][j][max(0, k-vec[i].s)] + vec[i].f);
                dp1[i][j][k] = min(dp1[i][j][k], dp[i][j][k]);
                // printf("%lld ", dp1[i][j][k]);
            }
            // printf("\n");
        }
        // printf("\n");
    }
    lli x = *min_element(all(dp1[0][h]));
    if(x == 1e18) x = -1;
    printf("%lld", x);
}