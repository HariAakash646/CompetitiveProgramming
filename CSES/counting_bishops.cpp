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

lli mod = 1e9 + 7;

int n, k;

int cnt(int x) {
    
    if(x % 2 == 0) {
        if(x % 4 == 0) return x / 2 + 1;
        else return x / 2;
    }
    else {
        if(x % 4 == 1) return (x+1) / 2 + 1;
        else return (x+1) / 2;
    }
    
}

int main() {
    
    scd(n);
    scd(k);

    if(k > 2*n) {
        printf("0");
        return 0;
    }
    if(n == 1) {
        printf("1");
        return 0;
    }

    vector<vll> dp(2*n-1, vll(k+1));

    forr(i, 0, 2*n-1) {
        forr(j, 0, k+1) {
            if(j == 0) {
                dp[i][j] = 1;
                continue;
            }
            if(i >= 2 && j <= cnt(i)) {
                dp[i][j] = dp[i-2][j];
                dp[i][j] += dp[i-2][j-1] * (cnt(i)-(j-1));
                dp[i][j] %= mod;
            }
            else if(j == 1) {
                dp[i][j] = cnt(i);
            } 
        }
    }

    lli tot = 0;

    forr(j, 0, k+1) {
        tot += dp[2*n-2][j] * dp[2*n-3][k-j];
        tot %= mod;
    }
    printf("%lld", tot);
}