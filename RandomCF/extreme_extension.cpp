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

const lli mod = 998244353;

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);
        vi vec(n+1);
        forr(i, 1, n+1) scd(vec[i]);
        vector<vector<pair<int, lli>>> dp(2);

        dp[0].pb(mp(0, 0));
        lli tot = 0;
        forr(i, 1, n+1) {
            lli v = vec[i];
            lli c2 = 1;
            int id = 0;
            int id2 = dp[0].size()-1;
            for(int j=1; j<=v;j++) {
                lli c = (vec[i]+j-1) / j;
                // if(j>1 && c == (vec[i]+j-2)/(j-1)) continue;
                while(id+1<dp[0].size() && dp[0][id+1].f <= vec[i]/c) {
                    id++;
                }
                
                dp[1].pb(mp(j, (dp[0][id].s + (c-1) * i) % mod));
                if(c <= j) break;
                while(dp[0][id2].f>vec[i]/j) id2--;
                dp[1].pb(mp(c, (dp[0][id2].s + (j-1) * i) % mod));
                
                // printf("%lld %lld %lld\n", vec[i], j, dp[i][j]);
                // dp[i][c] = ((*it).s + lli(j-1) * i) % mod;
                // printf("%lld %lld %lld\n", vec[i], c, j-1);
                // if(c < j) break;
                // printf("%lld %lld %lld\n", vec[i], v, c);
            }
            // tot += dp[1][vec[i]];
            dp[0]=dp[1];
            sort(all(dp[0]));
            tot += dp[0].back().s;
            tot %= mod;
            dp[1] = {};

        }
        // lli tot = 0;
        // forr(i, 1, n+1) {
        //     // printf("%lld ", dp[i][vec[i]]);
        //     tot += dp[i][vec[i]];
        //     tot %= mod;
        // }
        printf("%lld\n", tot);
    }
}