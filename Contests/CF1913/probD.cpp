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

        vll dp(n+1);
        vll pref(n+1);
        dp[0] = 1;
        pref[0] = 1;
        stack<int> stk;
        // stk.push(0);
        lli val = 0;
        forr(i, 1, n+1) {
            while(stk.size() && vec[i] < vec[stk.top()]) {
                val -= dp[stk.top()];
                val += mod;
                val %= mod;
                stk.pop();
            }
            dp[i] = (pref[i-1] + val) % mod;
            if(stk.size()) {
                dp[i] -= pref[stk.top()];
                dp[i] += mod;
                dp[i] %= mod;
            }
            // printf("%lld ", dp[i]);

            pref[i] = (pref[i-1] + dp[i]) % mod;
            val += dp[i];
            val %= mod;
            stk.push(i);
        }

        // lli tot = dp[stk.top()];
        // int c = 0;
        // while(stk.size()) {
        //     auto p = stk.top();
        //     tot += dp[p];
        //     tot %= mod;
        //     stk.pop();
        //     c++;
        // }
        printf("%lld\n", val);
    }
}