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

    
    vll pref(n+1);

    forr(i, 1, n+1) {
        lli a;
        sclld(a);
        pref[i] = pref[i-1] + a;
    }

    
    lli lo = 0;
    lli hi = 1e12;
    while(lo != hi) {
        lli mid = (lo+hi)/2;
        deque<pair<lli, int>> stk;
        stk.pb(mp(0, 0));

        vll dp(n+1);
        vi cnt(n+1);

        forr(j, 1, n+1) {
            dp[j] = dp[j-1];
            cnt[j] = cnt[j-1];
            if(stk.front().f + pref[j] - mid > dp[j]) {
                dp[j] = stk.front().f + pref[j] - mid;
                cnt[j] = cnt[stk.front().s]+1;
            }
            while(stk.size() && stk.back().f <= dp[j] - pref[j]) {
                stk.pop_back();
            }
            stk.pb(mp(dp[j] - pref[j], j));
            // printf("%lld ", dp[i][j]);
        }
        if(cnt[n] <= k) hi = mid;
        else lo = mid+1;
    }

    deque<pair<lli, int>> stk;
    stk.pb(mp(0, 0));

    vll dp(n+1);
    vi cnt(n+1);

    forr(j, 1, n+1) {
        dp[j] = dp[j-1];
        cnt[j] = cnt[j-1];
        if(stk.front().f + pref[j] - lo > dp[j]) {
            dp[j] = stk.front().f + pref[j] - lo;
            cnt[j] = cnt[stk.front().s]+1;
        }
        while(stk.size() && stk.back().f <= dp[j] - pref[j]) {
            stk.pop_back();
        }
        stk.pb(mp(dp[j] - pref[j], j));
        // printf("%lld ", dp[i][j]);
    }

    printf("%lld", dp[n] + lo * cnt[n]);
}