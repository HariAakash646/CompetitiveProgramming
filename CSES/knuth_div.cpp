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
    int n;
    scd(n);

    vll vec(n+1);
    vll pref(n+1);
    forr(i, 1, n+1) {sclld(vec[i]); pref[i] = pref[i-1] + vec[i];}

    vvi opt(n+1, vi(n+1));
    vector<vll> dp(n+2, vll(n+2, 1e18));

    forr(i, 1, n+1) {
        dp[i][i] = 0;
        opt[i][i] = i;
    }

    for(int l=1; l<n; l++) {
        for(int i=1; i+l<=n; i++) {
            int j = i + l;

            forr(k, opt[i][j-1], opt[i+1][j]+1) {
                lli v = dp[i][k] + dp[k+1][j] + pref[j] - pref[i-1];
                if(v < dp[i][j]) {
                    dp[i][j] = v;
                    opt[i][j] = k;
                }
            }
        }
    }

    printf("%lld", dp[1][n]);


}