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
    // freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
    freopen("pieaters.in", "r", stdin);
   freopen("pieaters.out", "w", stdout);
}

int main() {
    usaco();
    int n, m;
    scd(n);
    scd(m);
    vvi vec(n+2, vi(n+2));
    vector<vvi> mxv(n+2, vvi(n+2, vi(n+2)));

    frange(i, m) {
        int w, l, r;
        scd(w);
        scd(l);
        scd(r);
        vec[l][r] = max(vec[l][r], w);
        if(l == r) mxv[l][r][l] = vec[l][r];
    }

    
    forr(l, 1, n+1) {
        for(int j=1; j+l<=n; j++) {
            forr(i, j, j+l+1) {
                mxv[j][j+l][i] = max({mxv[j+1][j+l][i], mxv[j][j+l-1][i], vec[j][j+l]});
            }
        }
    }
    

    vector<vll> dp(n+2, vll(n+2));

    // forr(i, 1, n+1) {
    //     for(auto p : left[i]) {
    //         if(p.f == i) {
    //             dp[i][i] = max(dp[i][i], p.s);
    //         }
    //     }
    // }

    forr(l, 0, n+1) {
        for(int j=1; j+l<=n; j++) {
            dp[j][j+l] = max(dp[j+1][j+l], dp[j][j+l-1]);
            forr(i, j, j+l+1) {
                dp[j][j+l] = max(dp[j][j+l], dp[j][i-1] + mxv[j][j+l][i] + dp[i+1][j+l]); 
            }
        }
    }

    printf("%lld", dp[1][n]);

}