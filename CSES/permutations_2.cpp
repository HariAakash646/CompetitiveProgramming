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
    // usaco();
    int n;
    scd(n);

    vector<vll> dp1(n+1, vll(n+3)), dp2(n+1, vll(n+3)), dp0(n+1, vll(n+3));

    dp2[1][1] = 1;

    forr(i, 2, n+1) {
        forr(j, 1, n+1) {
            dp0[i][j] = ((dp0[i-1][j+1] * j % mod * (j+1)) + (dp1[i-1][j+1] * j % mod * j) + (dp2[i-1][j+1] * (j-1) % mod * j)) % mod;
            dp1[i][j] = ((dp0[i-1][j] * 2 * j) + (dp1[i-1][j] * (2 * j - 1)) + (dp2[i-1][j] * (2 * j - 2))) % mod;  
            dp2[i][j] = (dp0[i-1][j-1] + dp1[i-1][j-1] + dp2[i-1][j-1]) % mod;
        }
    }

    printf("%lld", (dp0[n][1] + dp1[n][1] + dp2[n][1]) % mod);
}