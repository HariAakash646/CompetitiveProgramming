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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    usaco();
    // fastio();
    int n, m;
    cin >> n >> m;
    lli c = 0;
    int cnt = 0;
    vector<vb> grid(n, vb(m));
    frange(i, n) {
        string str;
        cin >> str;
        // cout << str << "\n";
        frange(j, m) {
            if(str[j] == '#') grid[i][j] = true;
        }
    }
    vector<vll> dp(n, vll(m));
    dp[0][0] = 1;
    frange(j, m-1) {
        lli ma = 0;
        lli tot = 0;
        frange(i, n) {
            if(dp[i][j] > ma) {
                ma = dp[i][j];
                for(int k=i; k<n; k++) {
                    if(!grid[k][j+1]) {
                        dp[k][j+1] += tot;
                        break;
                    }
                }
                tot = 0;
                if(!grid[i][j+1]) dp[i][j+1] +=ma;
            }
            else {
                tot += dp[i][j];
                if(!grid[i][j+1] && (i==0 || grid[i-1][j+1])) dp[i][j+1] += ma;
            }
            if(!grid[i][j]) {
                ma = 0;
                tot = 0;
            }
            // if(dp[i][j] == 0) {
            //     // printf("%d %d %d %d\n", i, j, (int)grid[i][j+1], (int)grid[i-1][j+1]);
            //     if(!grid[i][j+1] && (i==0 || grid[i-1][j+1])) dp[i][j+1] += ma;
            // }

        }
        for(int i=n-1; i>=0; i--) {
            if(!grid[i][j+1]) {
                dp[i][j+1] += tot;
                break;
            }
        }
    }
    // frange(i, n) {
    //     frange(j, m) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for(int i=n-1; i>=0; i--) {
        if(grid[i][m-1]) break;
        c += dp[i][m-1];
    }
    cout << c;
}