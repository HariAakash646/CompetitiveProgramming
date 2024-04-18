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
    int n, k;
    scd(n);
    scd(k);
    vll vec(n+1);
    vec[0] = 1e9;
    forr(i, 1, n+1) sclld(vec[i]);
    vector<vll> dp(k+1, vll(n+1, 1e17));
    dp[0][0] = 0;

    forr(i, 1, k+1) {
        stack<pair<int, lli>> stk;
        stk.push(mp(i-1, dp[i-1][i-1]));
        forr(j, i, n+1) {
            lli mi = 1e17;
            while(stk.size() && vec[j] > vec[stk.top().f]) {
                mi = min(mi, stk.top().s);
                stk.pop();
            }
            dp[i][j] = mi + vec[j];
            if(stk.size()) dp[i][j] = min({dp[i][j], dp[i][stk.top().f], dp[i-1][stk.top().f]+vec[j]});
            stk.push(mp(j, min(dp[i-1][j], mi)));
        }
    }
    printf("%lld", dp[k][n]);
}