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

const int MAXN = 2005;

lli dp[MAXN][MAXN];

int main() {
    // usaco();
    int n, st, en;
    scd(n);
    scd(st);
    scd(en);

    if(n == 2 || n == 3) {
        printf("1");
        return 0;
    }


    forr(i, 1, n+1) {
        forr(j, 1, n+2) {
            dp[i][j] = 0;
        }
    }
    dp[1][1] = 1;

    forr(i, 2, n+1) {
        forr(j, 1, n+1) {
            if(i != st && i != en)
                dp[i][j] = ((j+1 - (i>en) - (i>st)) * (j - (i>en) - (i>st)) + (i > st) * (j-(i>en)) + (i>en) * (j-(i>st))) * dp[i-1][j+1] % mod;
            else dp[i][j] = (j - (i>en) - (i>st)) * dp[i-1][j];
            dp[i][j] += dp[i-1][j-1];

            dp[i][j] %= mod;
        }
    }

    if(n == st || n == en) printf("%lld", dp[n-1][1]);
    else printf("%lld", dp[n-1][2]);

}   