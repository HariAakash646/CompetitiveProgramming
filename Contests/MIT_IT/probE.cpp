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
    int t;
    scd(t);

    frange(_, t) {
        
        int n, q, c;
        scd(n);
        scd(q);
        scd(c);

        vector<pair<lli, lli>> vec(n);

        frange(i, n) {
            sclld(vec[i].f);
            sclld(vec[i].s);
        }

        sort(all(vec));

        vector<vll> dp(n, vll(n, 1e18));

        frange(i, n) {
            dp[i][i] = 0;
        }

        forr(l, 1, n) {
            for(int i=0; i+l<n; i++) {
                int j = i+l;
                for(int k=i; k<j; k++) {
                    lli v = dp[i][k] + dp[k+1][j];
                    v += min({abs(vec[i].s - vec[k+1].s), abs(vec[k].s - vec[j].s), abs(vec[k+1].s - vec[k].s), abs(vec[i].s - vec[j].s)});
                    dp[i][j] = min(dp[i][j], v);
                }
                // printf("%lld ", dp[i][j]);
            }
        }

        frange(_, q) {
            lli v;
            sclld(v);

            vll dp2(n+1, 1e18);
            dp2[0] = 0;

            for(int i=1; i<=n; i++) {
                for(int j=0; j<i; j++) {
                    lli v2 = dp2[j] + min(abs(vec[j].s - v), abs(vec[i-1].s - v)) + dp[j][i-1];
                    dp2[i] = min(dp2[i], v2);
                }
            }
            printf("%lld\n", dp2[n]);
        }
    }
    
}