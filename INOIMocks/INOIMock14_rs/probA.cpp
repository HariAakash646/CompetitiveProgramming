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
//    freopen("problem.out", "w", stdout);
}

int n, p, q;
vll vec;

bool check(lli w) {
    vector<vll> dp(n, vll(q+1, 1e9));
    frange(i, q+1) dp[0][i] = 0;
    dp[0][0] = 1;

    int i1 = -1;
    int i2 = -1;
    
    

    forr(i, 1, n) {
        while(i1 < n-1 && vec[i1+1] <= vec[i] - w) i1++;
        while(i2 < n-1 && vec[i2+1] <= vec[i] - 2 * w) i2++;
        frange(j, q+1) {
            
            if(i1 != -1)
                dp[i][j] = dp[i1][j] + 1;
            else dp[i][j] = 1;
            
            if(j >= 1) {
                if(i2 != -1)
                    dp[i][j] = min(dp[i][j], dp[i2][j-1]); 
                else dp[i][j] = 0;
            }
        }
    }
    lli mi = 1e9;
    frange(i, q+1) mi = min(mi, dp[n-1][i]);
    return mi <= p;
}

int main() {
    // usaco();
    scd(n);
    scd(p);
    scd(q);

    vec = vll(n);
    frange(i, n) sclld(vec[i]);
    sort(all(vec));
    if(p + q>=n) {
        printf("1");
        return 0;
    }
    else {
        lli lo = 0;
        lli hi = 1e9;

        while(lo != hi) {
            lli mid = (lo+hi)/2;
            if(check(mid)) {
                hi = mid;
            }
            else {
                lo = mid+1;
            }
        }
        printf("%lld", lo);
    }
}