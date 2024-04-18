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

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

// int dp[101][2049] = {int(1e9)};

int main() {
    // usaco();
    int n, a, b;
    scd(n);
    scd(a);
    scd(b);

    vll vec(n+1);
    forr(i, 1, n+1) sclld(vec[i]);

    // forr(i, 0, n+1) {
    //     forr(j, 0, 2049) dp[i][j] = 1e9;
    // }

    vector<map<lli, int>> dp(n+1);
    dp[0][0] = 0;
    
    forr(j, 0, n) {
        int mi = 1e9;
        for(auto k : dp[j]) {
            if(k.s > mi) continue;
            lli v = 0;
            forr(l, j+1, n+1) {
                v += vec[l];
                if(dp[l].find(k.f | v) == dp[l].end()) dp[l][k.f|v] = k.s+1;
                else
                dp[l][k.f | v] = min(dp[l][k.f | v], k.s + 1); 
            }
            
        }
    }
    

    lli mi = 1e18;

    // forr(i, a, b+1) {
    //     frange(k, 513) {
    //         if(dp[i][n][k]) mi = min(mi, k);
    //     }
    // }

    // frange(k, 2049) {
    //     if(dp[n][k] <= b) mi = min(mi, k);
    // }
    for(auto k : dp[n]) {
        if(k.s <= b) mi = min(mi, k.f);
    }

    // forr(i, 1, 1<<n) {
    //     if(a <= __builtin_popcount(i) && __builtin_popcount(i) <= b && (i & (1<<(n-1)))) {
    //         lli tot = 0;
    //         lli v = 0;
    //         frange(j, n) {
    //             v += vec[j];
    //             if(i & (1<<j)) {
    //                 tot = tot | v;
    //                 v = 0;
    //             }
    //         }
    //         mi = min(mi, tot);
    //     }
    // }
    
    printf("%lld", mi);
}