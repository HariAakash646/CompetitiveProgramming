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

void usaco() {
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

int main() {
    // usaco();
    int n, m, h;
    scd(n);
    scd(m);
    scd(h);

    vector<vll> dp(n, vll(m));
    dp[0][0] = 1;

    frange(i, n-1) {
        forr(j, 1, m) {
            if(i == 0) continue;
            dp[i][j] += dp[i][j-1];
            if(dp[i][j] > 5e8) dp[i][j] = 5e8 + 1;
        }
        frange(j, h) {
            int b, c;
            scd(b);
            scd(c);
            if(b <= i) continue;
            if(i == 0) {
                dp[b][c] += 1;
            }
            else {
                forr(k, 0, m) {
                    if(k + c >= m) break;
                    dp[b][k+c] += dp[i][k];
                    if(dp[b][k+c] > 5e8) dp[b][k+c] = 5e8+1;
                }
            }
        }
    }

    frange(i, m) {
        if(i > 0)
            dp[n-1][i] += dp[n-1][i-1];
        dp[n-1][i] = min((lli)5e8+1, dp[n-1][i]);
        printf("%lld ", dp[n-1][i]);
    }
}