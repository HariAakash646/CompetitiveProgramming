#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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
    freopen("input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);
        vll vec(n);
        frange(i, n) sclld(vec[i]);
        vll pref(n);
        pref[0] = vec[0];
        forr(i, 1, n) pref[i] = pref[i-1] + vec[i];

        vector<vll> dp(n+1, vll(2*sqrt(n)+1));
        forr(i, 0, n+1)
        dp[i][0] = 1e18;
        int ma = 0;
        for(int i=n-1; i>=0; i--) {
            forr(j, 1, min(n+1, int(2*sqrt(n)+1))) {
                dp[i][j] = dp[i+1][j];
                if(i+j<=n) {
                    lli v;
                    if(i > 0)
                        v = pref[i+j-1] - pref[i-1];
                    else v = pref[i+j-1];
                    if(v<dp[i+j][j-1]) {
                        // printf("%d %d %lld\n", i, j, v);
                        dp[i][j] = max(dp[i][j], v);
                        ma = max(ma, j);
                    }
                }
            }
        }
        printf("%d\n", ma);
    }
}