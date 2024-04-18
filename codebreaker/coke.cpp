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

bool cmp(pair<lli, lli> x, pair<lli, lli> y) {
    return x.s * y.f < y.s * x.f;
}

int main() {
    // usaco();
    int n, k;
    scd(n);
    scd(k);
    vector<pair<lli, lli>> vec(n);

    frange(i, n) {
        sclld(vec[i].f);
    }
    frange(i, n) {
        sclld(vec[i].s);
    }
    sort(all(vec), cmp);
    // for(auto p : vec) printf("%lld %lld\n", p.f, p.s);

    vector<vll> dp(n, vll(k+1, -1e18));
    dp[0][0] = 0;
    if(vec[0].f <= k)
        dp[0][vec[0].f] = 0;

    forr(i, 1, n) {
        frange(j, k+1) {
            dp[i][j] = dp[i-1][j];
            if(j - vec[i].f >= 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-vec[i].f] + (j-vec[i].f)*vec[i].s);
            }
        }
    }

    printf("%lld", *max_element(all(dp[n-1])));



}