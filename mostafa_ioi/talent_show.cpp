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
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
    int n, w;
    scd(n);
    scd(w);

    vvi dp(n+1, vi(w+1, -1e9));
    vi pre(1000*n+1, 1e9);

    vii vec(n+1); 
    forr(i, 1, n+1) {
        scd(vec[i].f);
        scd(vec[i].s);
    }

    dp[0][0] = 0;

    forr(i, 0, n) {
        vi curr(1000*n+1, 1e9);
        forr(j, 0, w+1) {
            if(dp[i][j] < 0) continue;
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(j + vec[i+1].f < w) dp[i+1][j+vec[i+1].f] = max(dp[i+1][j+vec[i+1].f], dp[i][j] + vec[i+1].s);
            else curr[dp[i][j] + vec[i+1].s] = min(curr[dp[i][j]+vec[i+1].s], j + vec[i+1].f);
        }   
        forr(j, 0, 1000*n+1) {
            curr[j] = min(curr[j], pre[j]);
            if(j + vec[i+1].s <= 1000*n) curr[j+vec[i+1].s] = min(curr[j+vec[i+1].s], pre[j] + vec[i+1].f);
        }
        pre = curr;
    }

    lli ma = 0;

    frange(j, 1000*n+1) {
        if(pre[j] == 1e9) continue;
        ma = max(ma, 1000 * lli(j) / pre[j]);
    }
    printf("%lld", ma);
}