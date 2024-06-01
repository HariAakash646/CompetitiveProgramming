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

const int MAX = 3e5 + 10;

lli dp[MAX][11];

int main() {
    // usaco();
    int t;
    scd(t);
    frange(_, t) {
        int n, k;
        scd(n);
        scd(k);
        vll vec(n+1);
        forr(i, 1, n+1) sclld(vec[i]);

        forr(i, 1, n+1) {
            frange(j, k+1) dp[i][j] = 1e8;
        }
        frange(i, k+1) dp[0][i] = 0;

        forr(i, 1, n+1) {
            frange(j, k+1) {
                dp[i][j] = dp[i-1][j] + vec[i];
                lli mi = vec[i];

                for(int l=i; l>=1 && i-l<=j; l--) {
                    mi = min(mi, vec[l]);
                    // printf("%d %d %d %lld %lld\n", i, j, l, mi, dp[l-1][j-(i-l)]);
                    dp[i][j] = min(dp[i][j], dp[l-1][j-(i-l)] + (i-l+1) * mi);
                }
                // printf("%lld ", dp[i][j]);
            }
            // printf("\n");
        }
        printf("%lld\n", dp[n][k]);
    }
}