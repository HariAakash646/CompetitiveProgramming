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

vll fact(1e6+1, 1), pow2v(1e6+1, 1);

lli combi(int n, int r) {
    if(r<0||r>n) return 0;
    return (fact[n] * inv(fact[r]) % mod) * inv(fact[n-r]) % mod; 
}

int main() {
    // usaco();
    int t;
    scd(t);

    forr(i, 1, 1e6+1) {
        fact[i] = (fact[i-1] * i) % mod;
        pow2v[i] = pow2v[i-1] * 2 % mod;
    }

    frange(_, t) {
        int n, m;
        lli k;
        scd(n);
        scd(m);
        sclld(k);
        lli tot = 0;
        forr(i, 1, n+1) {
            lli v = k*i%mod;
            v = v * combi(n-i-1, m-i) % mod;
            v = v * inv(pow2v[n-i]) % mod;
            tot += v;
            tot %= mod;
        }
        if(n==m) tot = k*n%mod;
        printf("%lld\n", tot);
    }
}