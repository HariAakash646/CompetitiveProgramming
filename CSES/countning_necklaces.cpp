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

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

lli inv(lli a) {
  return a <= 1 ? a : mod - (mod/a) * inv(mod % a) % mod;
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);

    vll pom(n+1);
    pom[0] = 1;
    forr(i, 1, n+1) pom[i] = (pom[i-1] * m) % mod;

    lli tot = 0;

    lli invn = inv(n);

    frange(i, n) {
        tot += pom[gcd(i, n)] * invn % mod;
        tot %= mod;
    }

    printf("%lld", tot);
}