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

lli inv(lli a) {
  return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

int main() {
    int n;
    scd(n);

    vll fact(1e6+1);
    fact[0] = 1;

    forr(i, 1, 1e6+1) {
        fact[i] = (fact[i-1] * i) % mod;
    }

    frange(_, n) {
        lli a, b;
        sclld(a);
        sclld(b);

        printf("%lld\n", (((fact[a] * inv(fact[b])) % mod) * inv(fact[a-b])) % mod);
    }
}