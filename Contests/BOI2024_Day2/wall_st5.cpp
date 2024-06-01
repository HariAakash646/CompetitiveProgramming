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

int main() {
    // usaco();
    int n;
    scd(n);
    vii vec(n+1);
    forr(i, 1, n+1) scd(vec[i].f);
    forr(i, 1, n+1) scd(vec[i].s);

    vector<vll> dp1(n+2, vll(3)), dp2(n+2, vll(3)), suf1(n+2, vll(3)), suf2(n+2, vll(3));
    dp1[0][0] = 1;
    dp2[n+1][0] = 1;

    forr(i, 1, n+1) {
        forr(j, 0, vec[i].f+1) {
            dp1[i][vec[i].f] += dp1[i-1][j];
            dp1[i][vec[i].f] %= mod;
        }
        forr(j, vec[i].f+1, 3) {
            dp1[i][j] += dp1[i-1][j];
            dp1[i][j] %= mod;
        }
        forr(j, 0, vec[i].s+1) {
            dp1[i][vec[i].s] += dp1[i-1][j];
            dp1[i][vec[i].s] %= mod;
        }
        forr(j, vec[i].s+1, 3) {
            dp1[i][j] += dp1[i-1][j];
            dp1[i][j] %= mod;
        }
        suf1[i][2] = dp1[i][2];
        for(int j=1; j>=0; j--) {
            suf1[i][j] = (dp1[i][j] + suf1[i][j+1]) % mod;
        }
    }

    for(int i=n; i>=1; i--) {
        forr(j, 0, vec[i].f+1) {
            dp2[i][vec[i].f] += dp2[i+1][j];
            dp2[i][vec[i].f] %= mod;
        }
        forr(j, vec[i].f+1, 3) {
            dp2[i][j] += dp2[i+1][j];
            dp2[i][j] %= mod;
        }
        forr(j, 0, vec[i].s+1) {
            dp2[i][vec[i].s] += dp2[i+1][j];
            dp2[i][vec[i].s] %= mod;
        }
        forr(j, vec[i].s+1, 3) {
            dp2[i][j] += dp2[i+1][j];
            dp2[i][j] %= mod;
        }
        suf2[i][2] = dp2[i][2];
        for(int j=1; j>=0; j--) {
            suf2[i][j] = (dp2[i][j] + suf2[i][j+1]) % mod;
        }
    }

    lli tot = 0;

    forr(i, 2, n) {
        forr(j, vec[i].f+1, 3) {
            tot += (dp1[i-1][j] * suf2[i+1][j] % mod) * (j-vec[i].f) % mod;
            tot %= mod;
            if(j<2)
                tot += (suf1[i-1][j+1] * dp2[i+1][j] % mod) * (j-vec[i].f) % mod;
            tot %= mod;
        }
        forr(j, vec[i].s+1, 3) {
            tot += (dp1[i-1][j] * suf2[i+1][j] % mod) * (j-vec[i].s) % mod;
            tot %= mod;
            if(j<2)
                tot += (suf1[i-1][j+1] * dp2[i+1][j] % mod) * (j-vec[i].s) % mod;
            tot %= mod;
        }
    }
    printf("%lld", tot);
}