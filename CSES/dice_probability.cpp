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

const lli mod = 1e9 + 7;

int main() {
    int n, a, b;
    scd(n);
    scd(a);
    scd(b);

    vector<vector<ld>> dp(n+1, vector<ld>(6*n+1));

    dp[0][0] = 1;

    forr(i, 1, n+1) {
        forr(j, 1, 6*n+1) {
            forr(k, 1, 7) {
                if(j - k >= 0) dp[i][j] += dp[i-1][j-k] / 6.0;
            }
        }
    }

    ld tot = 0;
    forr(i, a, b+1) tot += dp[n][i];

    cout << fixed << setprecision(6) << tot;
}