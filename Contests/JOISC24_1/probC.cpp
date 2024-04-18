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
    int n;
    lli c;
    scd(n);
    sclld(c);

    vector<pair<lli, lli>> vec(n);
    frange(i, n) {
        sclld(vec[i].f);
        sclld(vec[i].s);
    }
    sort(all(vec));

    vector<vll> dp(n, vll(n+1, 1e18));
    vector<vll> dp1(n, vll(n+1, 1e18));

    forr(i, 1, n+1) {
        dp[0][i] = (i-1) * vec[0].s;
    }

    forr(i, 1, n) {
        forr(j, 0, n+1) {
            lli tot = 0;

            for(int k=i-1; k>=0; k--) {
                if(vec[i].f == vec[k].f) continue;
                dp[i][j] = min(dp[i][j], dp[k][j] + (i-k-1) * vec[i].s + ((vec[i].f+1)*(i-k-1) - tot) * c);
                // if(j >= (i-k-1)) dp[i][j] = min(dp[i][j], dp[k][j]);
                if(i-k>= 2 && j < n) {
                    dp[i][j] = min(dp[i][j], dp[k][j+1] + (i-k-2) * vec[i].s + ((vec[i].f+1)*(i-k-1) - tot) * c);
                }
                tot += vec[i].f;
            }
            dp[i][j] = min(dp[i][j], (i-1) * vec[i].s + c*((vec[i].f+1)*(i-1) - tot) + j * vec[i].s);
            if(j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + vec[i].s);
            if(vec[i].f ==vec[i-1].f) {
                dp1[i][j] = dp[i-1][j] + c;
                if(j > 0) dp1[i][j] = min(dp1[i][j], dp1[i][j-1] + vec[i].s);
            }
            else if(vec[i].f == vec[i-1].f+1) {
                dp1[i][j] = dp1[i-1][j] + c;
                if(j > 0) dp1[i][j] = min(dp1[i][j], dp1[i][j-1] + vec[i].s);
            }
            else dp1[i][j] = dp[i][j];

        }
        
    }
    printf("%lld", min(*min_element(all(dp[n-1])), *min_element(all(dp1[n-1]))));

}