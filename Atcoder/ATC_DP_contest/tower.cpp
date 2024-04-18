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
    
    vector<pair<pii, lli>> vec(n+1);

    frange(i, n) {
        scd(vec[i].f.s);
        scd(vec[i].f.f);
        sclld(vec[i].s);
        vec[i].f.f += vec[i].f.s;
    }

    sort(all(vec));

    vector<vll> dp(n+1, vll(2e4+1));

    forr(i, 1, n+1) {
        forr(j, 1, 2e4+1) {
            dp[i][j] = dp[i-1][j];
            if(vec[i].f.s <= j && vec[i].f.f >= j) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-vec[i].f.s] + vec[i].s);
            }
            // printf("%lld ", dp[i][j]);
        }
        // printf("\n");
    }
    printf("%lld", *max_element(all(dp[n])));
}