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

const lli mod = 998244353;
vll fact(5e5+1, 1);

lli inv(lli a) {
  return a <= 1 ? a : mod - (mod/a) * inv(mod % a) % mod;
}

lli combi(int n, int r) {
    return (fact[n] * inv(fact[r]) % mod) * inv(fact[n-r]) % mod;
}

lli binexp(lli x, int c) {
    if(c == 0) return 1;
    lli v = binexp(x, c/2);
    v = (v*v) % mod;
    if(c % 2) return v * x % mod;
    else return v;
}

int main() {
    // usaco();
    forr(i, 1, 5e5+1) {
        fact[i] = (fact[i-1]*i) % mod;
    }
    int t;
    scd(t);

    frange(_, t) {
        int n, m;
        scd(n);
        scd(m);
        lli tot = 0;
        forr(i, 1, min(n, m)+1) {
            lli out = binexp(fact[i], n/i);
            int c = n%i;
            out = out * (fact[i] * inv(fact[i-c]) % mod) % mod;
            out = out * combi(m, i) % mod;
            tot = (tot + out) % mod;
        }
        printf("%lld\n", tot);
    }
}