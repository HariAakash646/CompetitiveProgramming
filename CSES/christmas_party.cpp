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

vll fact(1e6+1);

lli combi(lli n, lli r) {
    return fact[n] * inv(fact[r]) % mod * inv(fact[n-r]) % mod;
}

int main() {

    fact[0] = 1;

    forr(i, 1, 1e6+1) fact[i] = (fact[i-1] * i) % mod;

    lli n;
    sclld(n);

    lli tot = fact[n];

    forr(i, 1, n+1) {
        int sg = 1;
        if(i % 2) sg = -1;
        tot += sg * (combi(n, i) * fact[n-i] % mod);
        tot += mod;
        tot %= mod;
    }

    printf("%lld", tot);
}