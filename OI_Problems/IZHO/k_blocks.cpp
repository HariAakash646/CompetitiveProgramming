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
    int n, k;
    scd(n);
    scd(k);

    vll vec(n+1);
    forr(i, 1, n+1) sclld(vec[i]);

    vector<vll> dp(k+1, vll(n+1, 1e18));

    dp[0][0] = 0;

    forr(i, 1, k+1) {
        deque<pii> stk;
        // stk.push(mp(1e9, 0));
        forr(j, 1, n+1) {
            dp[i][j] = dp[i-1][j-1] + vec[j];
            while(stk.size() && stk.back().f < vec[j]) {
                dp[i][j] = min(dp[i][j], dp[i-1][stk.top().s-1] + vec[j]);
                stk.pop();
            }
            if(stk.size()) {
                dp[i][j] = min(dp[i][j], dp[i-1][stk.top().s] + vec[j]);
                dp[i][j] = min(dp[i][j], dp[i][stk.top().s-1]);
            }
            else dp[i][j] = min(dp[i][j], dp[i-1][0] + vec[j]);
            stk.push(mp(vec[j], j));
            
        }
    }
    printf("%lld", dp[k][n]);

}