#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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

lli mod = 998244353;

lli exp(lli x, lli y, lli mod)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 1)
    {
        lli out = exp(x, y / 2, mod);
        return (x * (out * out % mod)) % mod;
    }
    else
    {
        lli out = exp(x, y / 2, mod) % mod;
        return (out * out);
    }
}

int main()
{
    lli n, x;
    sclld(n);
    sclld(x);
    lli prev = 0;
    lli prev1 = 0;
    lli tot = 0;
    forr(i, 1, x + 1)
    {
        lli curr = (exp(i, n, mod) - exp(i - 1, n, mod) - (n * exp(i - 1, n - 1, mod) % mod) + (n + 1) * mod) % mod;
        tot += curr;
        tot %= mod;
    }
    printf("%lld", tot);
}