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
    int n;
    scd(n);

    vector<vll> vec(n, vll(n));

    frange(i, n) {
        frange(j, n) sclld(vec[i][j]);
    }

    vll dp(1<<n, -1e18);

    dp[0] = 0;

    forr(mask, 1, 1<<n) {
        lli tot = 0;
        frange(i, n) {
            forr(j, i+1, n) {
                if((mask & (1<<i)) && (mask & (1<<j))) tot += vec[i][j];
            }
        }
        dp[mask] = tot;
        for(int i = mask; i > 0; i = (i-1) & mask) {
            dp[mask] = max(dp[mask], dp[i] + dp[mask ^ i]);
        }
    }

    printf("%lld", dp[(1<<n)-1]);
}