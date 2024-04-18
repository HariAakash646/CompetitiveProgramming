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
    int n, k;
    scd(n);
    scd(k);

    vector<vector<ld>> dp(n+1, vector<ld>(k+1));
    dp[0][1] = 1;

    forr(i, 1, n+1) {
        forr(j, 1, k+1) {
            forr(l, 1, j) {
                dp[i][j] += dp[i-1][l] / k;
            }
            dp[i][j] += dp[i-1][j] * ld(j) / ld(k);
        }
    }

    ld tot = 0;
    forr(i, 1, k+1) tot += i * dp[n][i];

    cout << fixed << setprecision(6) << tot;
}