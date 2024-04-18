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

lli modexp(lli x, lli k) {
    if(k == 0) return 1;
    lli v = modexp(x, k/2);
    v *= v;
    v %= mod;
    if(k % 2) return v * x % mod;
    else return v;
}

int main() {
    lli n;
    sclld(n);
    if(n % 2 == 0) 
    {lli tot = modexp(2, n*n);
        tot += modexp(2, n*n/2);
        tot += 2 * modexp(2, n/2*n/2);
        tot %= mod;
        tot *= modexp(4, mod-2);
        tot %= mod;
        printf("%lld", tot);}
    else {
        lli tot = modexp(2, n*n);
        tot += 2*modexp(2, (n+1)*(n-1)/4 + 1);
        tot += modexp(2, (n+1) * (n-1) / 2 + 1);
        tot %= mod;
        tot *= modexp(4, mod-2);
        tot %= mod;
        printf("%lld", tot);
    }
}