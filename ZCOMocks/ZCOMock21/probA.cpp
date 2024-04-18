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

const int MN = 1e6 + 5;
int dp[MN][26] = {0};
int val[26][26] = {(int)1e9};

int main() {
    // usaco();
    fastio();
    int n;
    cin >> n;
    string str;
    cin >> str;

    // vvi dp(n+1, vi(26));
    // vvi val(26, vi(26, 1e9));
    frange(i, n+1) frange(j, 26) dp[i][j] = 0;
    frange(i, 26) frange(j, 26) val[i][j] = 1e9;
    int ma = 0;
    int mi = 1e9;
    vi pre(26, 0);
    forr(i, 1, n+1) {
        int x = str[i-1] - 'a';
        
        frange(j, 26) {
            if(i != 0) {
                dp[i][j] = dp[i-1][j];
            }
            for(int k=pre[x]; k<i; k++) {
                val[j][x] = min(val[j][x], dp[k][j] - dp[k][x]);
            }
        }
        dp[i][x]++;
        pre[x] = i;
        frange(j, 26) {
            ma = max(ma, dp[i][x] - dp[i][j] - val[x][j]);
            ma = max(ma, dp[i][j] - dp[i][x] - val[j][x]);
        }
        // printf("%d %d %d %d\n", ma, dp[i][2], dp[i][0], val[2][0]);
    }
    cout << ma;
}