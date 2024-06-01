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
    int n, m;
    scd(n);
    scd(m);

    vi vec(n+1);
    frange(i, n) scd(vec[i+1]);


    vector<vvi> dp(n+1, vvi(2*m+1, vi(m+2, 1e9)));
    forr(i, 1, m+1)
        dp[0][m][i]= 0;
    forr(i, 1, n+1) {
        forr(j, 0, 2*m+1) {
            for(int k=m; k>=0; k--) {
                int v = vec[i] - k;
                if(j+v>2*m || j+v < 0) continue;
                    dp[i][j][k] = min(dp[i][j][k+1], dp[i-1][j+v][k] + abs(j-m));
            }
            // printf("%d ", dp[i][j][0]);
        }
        // printf("\n");
    }
    printf("%d\n", dp[n][m][0]);
}