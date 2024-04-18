#include <bits/stdc++.h>
 
using namespace std;
 
#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
 
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
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
    int t;
    scd(t);
    frange(_, t) {
        int n, m, k, d;
        scd(n);
        scd(m);
        scd(k);
        scd(d);
        vector<vll> dp(n, vll(m));
        vector<vll> vec(n, vll(m));

        frange(i, n) {
            frange(j, m) sclld(vec[i][j]);
        }

        frange(i, n) {
            dp[i][0] = 1;

            deque<int> dq;
            dq.pb(0);

            forr(j, 1, m) {
                while(dq.size() && dq.front() < j - d - 1) dq.pop_front();
                dp[i][j] = dp[i][dq.front()] + vec[i][j] + 1;
                while(dq.size() && dp[i][dq.back()] >= dp[i][j]) dq.pop_back();
                dq.pb(j);
            }
        }

        lli mi = 1e18;
        vll pref(n+1);
        // pref[0] = dp[0][n-1];
        forr(i, 1, n+1) pref[i] = pref[i-1] + dp[i-1][m-1];

        forr(i, k, n+1) {
            mi = min(mi, pref[i] - pref[i-k]);
        }
        printf("%lld\n", mi);
    }
}