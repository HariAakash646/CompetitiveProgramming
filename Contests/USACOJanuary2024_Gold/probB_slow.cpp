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
typedef vector<lli> vll;

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

const lli mod = 1e9 + 7;

lli binexp(lli v, lli c) {
    if(c == 0) return 1;
    lli out = binexp(v, c/2);
    out = out * out;
    out %= mod;
    if(c % 2) out *= v;
    return out % mod;
}

int main() {
    usaco();
    int n, q, c;
    scd(n);
    scd(q);
    scd(c);

    vii vec(q);
    vi pos(n+1, 1e9+10);
    frange(i, q) {
        scd(vec[i].f);
        scd(vec[i].s);
        pos[vec[i].s] = min(pos[vec[i].s], vec[i].f);
    }

    sort(all(vec));

    vector<vll> dp(n+1, vll(c+1));
    forr(i, 1, c+1) dp[1][i] = 1;

    forr(i, 2, n+1) {
        forr(j, 1, c+1) {
            if(pos[i] != 1e9+10) {
                forr(k, 1, j) {
                    dp[i][j] += dp[pos[i]][k] * binexp(k, (i - pos[i] - 1)) % mod;
                    dp[i][j] %= mod;
                }
                dp[i][j] %= mod;
            }
            else {
                forr(k, 1, j) {
                    dp[i][j] += dp[i-1][k];
                    dp[i][j] %= mod;
                }
                dp[i][j] += j * dp[i-1][j];
                dp[i][j] %= mod;
            }
            // printf("%lld ", dp[i][j]);
        }
        // printf("\n");
    }

    lli tot = 0;
    forr(i, 1, c+1) {
        tot += dp[n][i];
        tot %= mod;
    }
    tot %= mod;

    printf("%lld", tot);


}