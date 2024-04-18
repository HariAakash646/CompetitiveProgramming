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

const lli mod = 1e9 + 9;

int main() {
    // usaco();
    freopen("team.in", "r", stdin);
    freopen("team.out", "w", stdout);
    int n, m, k;
    scd(n);
    scd(m);
    scd(k);

    vll v1(n+1), v2(m+1);

    forr(i, 1, n+1) sclld(v1[i]);
    forr(i, 1, m+1) sclld(v2[i]);
    sort(v1.begin()+1, v1.end(), greater<>());
    sort(v2.begin()+1, v2.end(), greater<>());

    vector<vector<vll>> dp(k+1, vector<vll>(n+1, vll(m+1)));
    frange(i, n+1) {
        frange(j, m+1) dp[0][i][j] = 1;
    }

    forr(i, 1, k+1) {
        forr(j, 1, n+1) {
            forr(l, 1, m+1) {
                dp[i][j][l] += (dp[i][j-1][l] + dp[i][j][l-1] - dp[i][j-1][l-1] + mod) % mod;
                if(v1[j] > v2[l]) dp[i][j][l] += dp[i-1][j-1][l-1];
                dp[i][j][l] %= mod;
            }
        }
    }

    printf("%lld", dp[k][n][m]);
}