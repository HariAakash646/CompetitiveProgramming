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
    vi h(n+1);
    forr(i, 1, n+1) {
        scd(h[i]);
    }
    vll b(n+1);
    forr(i, 1, n+1) {
        sclld(b[i]);
    }
    vll dp(n+1);
    stack<pair<lli, int>> stk;
    
    forr(i, 1, n+1) {
        lli v = dp[i-1] + b[i];
        lli ma = -1e18;
        while(stk.size() && h[i] < h[stk.top().s]) {
            v = max(v, dp[stk.top().s] + b[i]);
            v = max(v, dp[stk.top().s-1] + b[i]);
            v = max(v, stk.top().f + b[i]);
            ma = max(ma, max(stk.top().f, dp[stk.top().s]));
            // printf("pop: %d %d\n", stk.top().f, stk.top().s);
            stk.pop();
        }

        if(!stk.size()) {
            // stk.push(mp(h[i], i));
            v = max(v, b[i]);
            // dp[i] = v;
            // printf("push: %d %d\n", stk.top().f, stk.top().s);
        }
        else {
            v = max(v, dp[stk.top().s] + b[i]);
            v = max(v, dp[stk.top().s]);
            // v = max(v, stk.top().f);
            // v = max(v, stk.top().f + b[i]);
            // stk.push(mp(h[i], i));
            
            // dp[i] = v;
            // printf("push: %d %d\n", stk.top().f, stk.top().s);
        }
        stk.push(mp(ma, i));
        dp[i] = v;
        // printf("%lld ", dp[i]);
    }
    printf("%lld", dp[n]);
}