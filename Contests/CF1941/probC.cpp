#include <bits/stdc++.h>
 
using namespace std;
 
#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
 
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
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
    // usaco();
    fastio();
    int t;
    cin >> t;
    frange(_, t) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        vvi dp(5, vi(n, 1e9));
        if(str[0] == 'm') {
            dp[1][0] = 0;
            dp[0][0] = 1;
        }
        else if(str[0] == 'p') {
            dp[2][0] = 0;
            dp[0][0] = 1;
        }
        else {
            dp[0][0] = 0;
        }

        forr(i, 1, n) {
            if(str[i] == 'p') {
                dp[2][i] = min({dp[0][i-1], dp[1][i-1], dp[2][i-1], dp[4][i-1]});
                dp[0][i] = dp[0][i-1] + 1;
            }
            else if(str[i] == 'm') {
                dp[1][i] = min({dp[0][i-1], dp[1][i-1], dp[2][i-1], dp[3][i-1], dp[4][i-1]});
                dp[0][i] = dp[0][i-1] + 1;
            }
            else if(str[i] == 'a') {
                dp[3][i] = min(dp[3][i-1] + 1, dp[1][i-1]);
                dp[0][i] = min({dp[0][i-1], dp[2][i-1], dp[3][i-1], dp[4][i-1]});
            }
            else if(str[i] == 'i') {
                dp[4][i] = min(dp[4][i-1] + 1, dp[2][i-1]);
                dp[0][i] = min({dp[0][i-1], dp[1][i-1], dp[3][i-1], dp[4][i-1]});
            }
            else if(str[i] == 'e') {
                dp[0][i] = min({dp[0][i-1], dp[1][i-1], dp[3][i-1], dp[2][i-1]});
            }
            else {
                int mi = 1e9;
                frange(j, 5) mi = min(dp[j][i-1], mi);
                dp[0][i] = mi;
            }
            frange(j, 5) {dp[j][i] = min(dp[j][i], dp[j][i-1]+1);}
            // printf("\n");
        }
        int mi = 1e9;
        frange(i, 5) mi = min(dp[i][n-1], mi);
        cout << mi << "\n";
    }
}