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
    // freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);
}

int main() {
    usaco();
    int n, h;
    scd(n);
    scd(h);

    vector<pair<int, pii>> vec(n);
    frange(i, n) {
        scd(vec[i].f);
        scd(vec[i].s.f);
        scd(vec[i].s.s);
    }

    vll dp(1<<n, -1e18);
    dp[0] = 1e18;
    lli ma = -1;
    forr(i, 1, 1<<n) {
        lli hg = 0;
        frange(j, n) {
            if(i & (1<<j)) {
                dp[i] = max(dp[i], min(dp[i^(1<<j)] - vec[j].s.f, (lli)vec[j].s.s));
                hg += vec[j].f;
            }
        }
        if(hg >= h) ma = max(ma, dp[i]);
    }
    if(ma < 0) printf("Mark is too tall");
    else printf("%lld", ma);

    

}