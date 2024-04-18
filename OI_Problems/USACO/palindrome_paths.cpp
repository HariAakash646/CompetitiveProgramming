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
    freopen("palpath.in", "r", stdin);
    freopen("palpath.out", "w", stdout);
}

int n;

lli mod = 1e9 + 7;

vvi grid;
vector<vector<vi>> dp;

lli rec(int x1, int y1, int x2, int y2) {
    if(x1 > x2 || y1 > y2) return 0;
    if(mp(x1, y1) == mp(x2, y2)) {
        return 1;
    }
    if(dp[x1][y1][n-1-x2] != -1) return dp[x1][y1][n-1-x2];

    lli v = 0;
    if(grid[x1+1][y1] == grid[x2-1][y2]) {
        v += rec(x1+1, y1, x2-1, y2);
    }
    if(grid[x1+1][y1] == grid[x2][y2-1]) {
        v += rec(x1+1, y1, x2, y2-1);
    }
    if(grid[x1][y1+1] == grid[x2-1][y2]) {
        v += rec(x1, y1+1, x2-1, y2);
    }
    if(grid[x1][y1+1] == grid[x2][y2-1]) {
        v += rec(x1, y1+1, x2, y2-1);
    }
    v %= mod;
    dp[x1][y1][n-1-x2] = v;
    return v;

}

int main() {
    usaco();
    cin >> n;
    grid = vvi(n, vi(n));

    dp = vector<vector<vi>>(n);
    frange(i, n) {
        dp[i] = vector<vi>(n-i);
        frange(j, n-i) {
            dp[i][j] = vi(i+j+1, -1);
        }
    }
    frange(i, n) {
        string str;
        cin >> str;
        frange(j, n) {
            grid[i][j] = str[j] - 'A';
            // if(i + j < n)
            //     val1[i+j][grid[i][j]].pb(mp(i, j));
            // else 
            //     val2[(n-1-i) + (n-1-j)][grid[i][j]].pb(mp(i, j));
        }
    }
    lli out = 0;
    if(grid[0][0] == grid[n-1][n-1]) out = rec(0, 0, n-1, n-1);
    printf("%lld", out);

}