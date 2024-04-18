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

    if(a == 1) 
    {
        lli mask = (1LL<<46) - 1;
    
        for(int i=45; i>=0; i--) {
            // dp = vector<vll>(n+1, vll(b+1, 1e18 - 1));
            mask = mask ^ (1LL<<i);
            vi dp(n+1, 1e9);
            dp[0] = 0;
            forr(j, 0, n) {
                
                if(dp[j] < 1e9) {
                    lli tot = 0;
                    for(int l=j+1; l<=n; l++) {
                        tot += vec[l];
                        
                        if((mask | tot) == mask) dp[l] = min(dp[l], dp[j]+1);
                    }
                }
                
            }
    
        
            if(dp[n] > b) mask = mask | (1LL<<i);
        }
    
        // forr(i, 1, n+1) {
        //     forr(j, 1, b+1) printf("%lld ", dp[i][j]);
        //     printf("\n");
        // }
    
        // lli mi = 1e15;
        // forr(i, a, b+1) mi = min(mi, val[n][i]);
        printf("%lld", mask);
    }
    else {
        lli mask = (1LL<<46) - 1;
 
        for(int i=45; i>=0; i--) {
            // dp = vector<vll>(n+1, vll(b+1, 1e18 - 1));
            mask = mask ^ (1LL<<i);
            vector<vb> dp(n+1, vb(b+1));
            dp[0][0] = true;
            forr(j, 0, n) {
                forr(k, 0, b) {
                    if(dp[j][k]) {
                        lli tot = 0;
                        for(int l=j+1; l<=n; l++) {
                            tot += vec[l];
                            
                            if((mask | tot) == mask) dp[l][k+1] = true;
                        }
                    }
                }
            }
     
            bool done = false;
            forr(k, a, b+1) {
                if(dp[n][k]) done = true;
            }
            if(!done) mask = mask | (1LL<<i);
        }
     
        // forr(i, 1, n+1) {
        //     forr(j, 1, b+1) printf("%lld ", dp[i][j]);
        //     printf("\n");
        // }
     
        // lli mi = 1e15;
        // forr(i, a, b+1) mi = min(mi, val[n][i]);
        printf("%lld", mask);
    }
}