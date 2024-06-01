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
vll fact, invv;

lli inv(lli a) {
  return a <= 1 ? a : mod - (mod/a) * inv(mod % a) % mod;
}

lli combi(int n, int r) {
    return (fact[n] * invv[n-r] % mod) * invv[r] % mod; 
}

int n;
lli l, r, z;

lli solve(lli x) {
    vector<vll> dp(61, vll(n+1));
    dp[60][0] = 1;
    for(int i=60; i>=1; i--) {
        // printf("%d: ", i);
        frange(j, n+1) {
            int c = 2*j + ((x & (1LL<<(i-1))) != 0);
            // printf("%lld %d v: %d\n", x, i-1, int(x & (1LL<<(i-1)) != 0));
            frange(k, min(n, c)+1) {
                if(k % 2 != int((z&(1LL<<(i-1))) != 0)) continue;
                // printf("%d %d %d %d\n", i, j, k, c);
                dp[i-1][min(n, c-k)] += dp[i][j] * combi(n, k) % mod;
                dp[i-1][min(n, c-k)] %= mod;
            }
            // printf("%lld ", dp[i][j]);
        }
        // printf("\n");

    }

    lli tot = 0;
    frange(i, n+1) {
        // printf("%lld ", dp[0][i]);
        tot += dp[0][i];
        tot %= mod;
    }
    // printf("\n");
    return tot;
}



int main() {
    // usaco();
    fact = vll(2001, 1);
    invv = vll(2001);
    invv[0] = inv(fact[0]);
    forr(i, 1, 2001) {fact[i] = (fact[i-1] * i) % mod; invv[i] = inv(fact[i]);}
    
    scd(n);
    
    sclld(l);
    sclld(r);
    sclld(z);

    printf("%lld", (solve(r) - solve(l-1)+mod)%mod);
    

}