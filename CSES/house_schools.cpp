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

vector<vll> cost, dp;

void rec(int x, int l, int r, int lx, int rx) {
    int mid = (l+r)/2;
    int opt=lx;

    forr(i, lx, min(rx, mid)+1) {
        if(dp[x-1][i-1] + cost[i][mid] < dp[x][mid]) {
            dp[x][mid] = dp[x-1][i-1] + cost[i][mid];
            opt = i;
        }
    }
    if(l < mid) {
        rec(x, l, mid-1, lx, opt);
    }
    if(r > mid) {
        rec(x, mid+1, r, opt, rx);
    }
}

int main() {
    // usaco();
    int n, k;
    scd(n);
    scd(k);

    vll vec(n+1);

    forr(i, 1, n+1) sclld(vec[i]);

    cost = vector<vll>(n+1, vll(n+1));

    forr(i, 1, n+1) {
        cost[i][i] = 0;
        lli l = vec[i];
        lli r = 0;
        int id = i;
        lli tot = 0;
        forr(j, i+1, n+1) {
            r += vec[j];
            tot += vec[j] * (j - id);
            lli v1 = tot - r + l;
            while(v1 <= tot && id < j) {
                tot = v1;
                // printf("%lld ", tot);
                id++;
                l += vec[id];
                r -= vec[id];
                v1 = tot - r + l;
            }
            cost[i][j] = tot;
            // printf("%lld\n", tot);
        }
        // printf("\n");
    }

    dp = vector<vll>(k+1, vll(n+1, 2e18));
    dp[0][0] = 0;

    forr(i, 1, k+1) {
        rec(i, 1, n, 1, n);
    }
    printf("%lld", dp[k][n]);
}