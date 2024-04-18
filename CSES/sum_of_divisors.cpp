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

lli sum(lli l, lli r) {
    if(r < l) return 0;
    l %= mod;
    r %= mod;
    return ((r * (r+1)/2 % mod) - (l * (l-1)/2 % mod) + mod) % mod;
}

int main() {
    lli n;
    sclld(n);

    lli sq;

    for(lli i=1; i*i<=n; i++) {
        sq = i;
    }

    lli tot = 0;

    forr(i, 1, sq+1) {
        tot += n / i * i;
        tot %= mod;
        if(n / i == i) tot += sum(n/(i+1)+1, n/i-1);
        else
        tot += sum(n/(i+1)+1, n/i)*i;
        tot %= mod;
    }

    // tot += n / sq * sq;
    // tot += sum(n/(sq+1)+1, n/sq) - sq + mod;
    tot %= mod;

    printf("%lld", tot);

}