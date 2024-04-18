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

vll fact;
vll invv;

lli inv(lli a) {
  return a <= 1 ? a : mod - (mod/a) * inv(mod % a) % mod;
}


lli combi(lli n, lli r) {
    return (fact[n] * invv[r] % mod) * invv[n-r] % mod;
}

lli modexp(lli x, int k) {
    if(k == 0) return 1;
    lli v = modexp(x, k/2);
    if(k % 2) {
        return (v * v % mod) * x % mod;
    }
    else return v * v % mod;
}

int main() {
    int n, k;
    scd(n);
    scd(k);

    fact = vll(n+1);
    fact[0] = 1;
    forr(i, 1, n+1) fact[i] = (fact[i-1] * i) % mod;

    invv = vll(n+1);

    frange(i, n+1) {
        invv[i] = inv(fact[i]);
    }

    // vll pov(n+1);
    // pov[0] = 1;

    // forr(i, 1, n+1) pov[i] = (pov[i-1] * k) % mod;

    lli tot = 0;

    frange(i, k+1) {
        lli v = combi(k, i) * modexp(k-i, n) % mod; 
        if(i % 2 == 0) {
            tot += v;
            tot %= mod;
        }
        else {
            tot -= v;
            tot += mod;
            tot %= mod;
        }
    }
    printf("%lld", tot);

}