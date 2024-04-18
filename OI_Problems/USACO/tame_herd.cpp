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
    freopen("taming.in", "r", stdin);
   freopen("taming.out", "w", stdout);
}

int main() {
    usaco();
    int n;
    scd(n);

    vi vec(n);
    frange(i, n) scd(vec[i]);

    vector<vvi> dp(n, vvi(n+1, vi(n+1, 1e9)));

    dp[0][1][0] = 0;
    if(vec[0]) dp[0][1][0]++;

    forr(i, 1, n) {
        forr(j, 1, n+1) {
            frange(k, n+1) {
                dp[i][j][0] = min(dp[i][j][0], dp[i-1][j-1][k] + (vec[i] != 0)); 
            }
            forr(k, 1, n+1) {
                dp[i][j][k] = dp[i-1][j][k-1] + (vec[i] != k);
            }
        }
    }

    forr(j, 1, n+1) {
        printf("%d\n", *min_element(all(dp[n-1][j])));
    }
}