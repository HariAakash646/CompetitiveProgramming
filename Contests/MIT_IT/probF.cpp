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

vvi dp;
vvi cost;

void rec(int x, int l, int r, int optl, int optr) {
    int mid = (l+r)/2;
    int opt = optl;

    for(int i=optl; i<=min(optr, mid-1); i++) {
        if(dp[x-1][i] + cost[i+1][mid] > dp[x][mid]) {
            dp[x][mid] = dp[x-1][i] + cost[i+1][mid];
            opt = i;
        }
    }

    if(l <= mid-1) {
        rec(x, l, mid-1, optl, opt);
    }
    if(r >= mid+1) {
        rec(x, mid+1, r, opt, optr);
    }
}

int main() {
    fastio();
    // usaco();
    int t;
    cin >> t;

    frange(_, t) {
        int n;
        cin >> n;

        string str;
        cin >> str;

        dp = vvi(n+1, vi(n+1, -1e9));
        cost = vvi(n+1, vi(n+1));

        forr(i, 1, n+1) {
            int v = 0;
            forr(j, i, n+1) {
                v += (str[j-1] == '1');
                cost[i][j] = (v > (j-i+1)/2);
            }
        }
        dp[0][0] = 0;

        forr(i, 1, n+1) {
            // forr(j, 1, n+1) {
            //     int v = str[j-1] - '0';
            //     for(int l=j-1; l>=0; l--) {
            //         dp[i][j] = max(dp[i][j], dp[i-1][l] + (v > (j-l)/2));
            //         v += (str[l-1] == '1');
            //     }
            // }
            rec(i, 1, n, 0, n-1);
        }

        forr(i, 1, n+1) cout<<  dp[i][n] << " ";
        cout<<"\n";


    }
}