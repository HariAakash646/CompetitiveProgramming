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
    int t, n, k;
    scd(t);
    scd(n);
    scd(k);

    vii vec(n);
    frange(i, n) {
        scd(vec[i].f);
        scd(vec[i].s);
    }
    int tot = 0;
    if(t == 1) {
        vii curr;
        forr(i, 0, n) {
            if(!curr.size() || vec[i].f - vec[i-1].f <= k) curr.pb(vec[i]); 
            else {
                if(curr.size() % 2) {
                    int v = 1e9;
                    frange(j, curr.size()) {
                        if(j % 2 == 0) v = min(v, curr[j].s);
                        else if(curr[j+1].f - curr[j-1].f <= k) v = min(v, curr[j].s);
                    }
                    tot += v;
                }
                curr = {};
                curr.pb(vec[i]);
            }
        }
        if(curr.size() % 2) {
            int v = 1e9;
            frange(j, curr.size()) {
                if(j % 2 == 0) v = min(v, curr[j].s);
                else if(curr[j+1].f - curr[j-1].f <= k) v = min(v, curr[j].s);
            }
            tot += v;
        }
        printf("%d", tot);

    }
    else {
        vec.pb(mp(0,0));
        sort(all(vec));
        vll pref(n+1);
        vll pos(n+1);
        
        forr(i, 1, n+1) pos[i] = vec[i].f;

        vll dp(n+2, -1e18), dp2(n+2);

        for(int i=n; i>=1; i--) {
            int id = upper_bound(all(pos), pos[i] + k) - pos.begin() - 1;
            if((id - i) % 2 == 0) {
                dp2[i] = max(dp[id+1], dp2[id+1]) + vec[i].s;
            }
            else {
                dp2[i] = dp[id] + vec[i].s;
                
            }
            if(i < n && pos[i+1] - pos[i] <= k)
                dp[i] = max(dp[i+2], dp2[i+2]); 
            if(i < n-1 && pos[i+2] - pos[i] <= k) {
                
                id = upper_bound(all(pos), pos[i+1] + k) - pos.begin() - 1;
                
                if((id - (i+1)) % 2) {
                    dp[i] = max(dp[i], max(dp[id+1], dp2[id+1]) + vec[i+1].s);
                }
                else {
                    if((id+1) <= n) {
                        dp[i] = max(dp[i], dp[id] + vec[i+1].s);
                    }
                }
                
                
            }
        }
        printf("%lld", max(dp2[1], dp[1]));

    }
}