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
    // usaco();
    int h, w;
    scd(h);
    scd(w);
    int n;
    scd(n);
    vvi dp(h+1, vi(w+1));
    forr(i, 1, h+1) {
        forr(j, 1, w+1) {
            dp[i][j] = i * j;
        }
    }
    frange(i, n) {
        int a, b;
        scd(a);
        scd(b);
        dp[a][b] = 0;
    }

    forr(i, 1, h+1) {
        forr(j, 1, w+1) {
            forr(x, 1, i) {
                dp[i][j] = min(dp[i][j], dp[x][j] + dp[i-x][j]);
            }
            forr(y, 1, j) {
                dp[i][j] = min(dp[i][j], dp[i][y] + dp[i][j-y]);
            }
        }
    }
    printf("%d", dp[h][w]);
}