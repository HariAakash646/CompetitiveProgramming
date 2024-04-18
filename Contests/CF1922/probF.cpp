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
    int t;
    scd(t);

    frange(_, t) {
        int n, x;
        scd(n);
        scd(x);
        vi vec(n+1);
        forr(i, 1, n+1) {
            scd(vec[i]);
        }

        vvi pref(x+1, vi(n+1));

        forr(i, 1, x+1) {
            forr(j, 1, n+1) {
                pref[i][j] = pref[i][j-1];
                if(i == vec[j]) pref[i][j]++;
            }
        }

        // if(x == 2) {
        //     printf("%d\n", min(pref[1][n] - pref[1][0], pref[2][n] - pref[2][0]));
        // }

        // vvi dp(n+1, vi(n+1, 1e9));

        // for(int l=0; l<n; l++) {
        //     for(int i=1; i+l<=n; i++) {
        //         int j = i + l;
        //         if(i == j) {
        //             dp[i][j] = 0;
        //             continue;
        //         }
        //         bool d1 = false, d2 = false;
        //         forr(k, 1, x+1) {
        //             if(pref[k][j] - pref[k][i-1] == j - i + 1) {
        //                 d1 = true;
        //             }
        //             if(pref[k][j] - pref[k][i-1] == 0) d2 = true;
        //         }
        //         if(d1) dp[i][j] = 0;
        //         else if(d2) dp[i][j] = 1;
        //         else {
        //             for(int k=i; k<j; k++) {
        //                 dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + 1);
        //             }
        //         }

        //     }
        // }
        // printf("%d\n", dp[1][n]);
        // int mi = 1e9;

        // forr(i, 1, x+1) {
        //     vi pos;
        //     pos.pb(0);
        //     forr(j, 1, n+1) {
        //         if(vec[j] == i) pos.pb(j);
        //     }
        //     pos.pb(n+1);
        //     int tot = 0;
        //     forr(j, 1, pos.size()) {
        //         if(pos[j] - pos[j-1] > 1) tot++;
        //     }
        //     printf("%d: ", i);
        //     for(auto e : pos) printf("%d ", e);
        //     printf("\n");
        //     mi = min(mi, tot);
        // }
        // printf("%d\n", mi);
    }

}