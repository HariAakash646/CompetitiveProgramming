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

lli inv(lli a) {
  return a <= 1 ? a : mod - (mod/a) * inv(mod % a) % mod;
}

vll fact;

lli combi(int n, int r) {
    return (fact[n] * inv(fact[r]) % mod) * inv(fact[n-r]) % mod; 
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);
    fact = vll(2*n+1);

    fact[0] = 1;
    forr(i, 1, 2*n+1) fact[i] = (fact[i-1] * i) % mod;

    vii vec(m);
    frange(i, m) {
        scd(vec[i].f);
        scd(vec[i].s);
    }

    sort(all(vec));
    vll dp(m);

    frange(i, m) {
        dp[i] = combi(vec[i].f + vec[i].s-2, vec[i].f-1);
        frange(j, i) {
            if(vec[j].f <= vec[i].f && vec[j].s <= vec[i].s) {
                dp[i] -= (dp[j] * combi(vec[i].f - vec[j].f + vec[i].s - vec[j].s, vec[i].f - vec[j].f)) % mod;
                dp[i] += mod;
                dp[i] %= mod;
            }
        }
    }

    frange(i, m) {
        dp[i] *= combi(n-vec[i].f + n - vec[i].s, n-vec[i].f);
        dp[i] %= mod;
    }

    lli tot = combi(2*n-2, n-1);

    frange(i, m) {
        tot -= dp[i];
        tot += mod;
        tot %= mod;
    }

    printf("%lld", tot);


}