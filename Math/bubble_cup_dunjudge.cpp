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

lli mod = 1e9 + 7;

lli modinv(lli i)
{
    return i <= 1 ? i : mod - (lli)(mod / i) * modinv(mod % i) % mod;
}

int main()
{
    lli n;
    sclld(n);
    vll fact(2 * n + 1);
    fact[0] = 1;
    forr(i, 1, 2 * n + 1) fact[i] = (i * fact[i - 1]) % mod;
    sclld(n);
    lli tot = 1;
    lli v = 1;
    frange(i, n)
    {
        v *= 2;
        v %= mod;
        tot += v;
    }
    frange(i, n)
    {
        lli val = (2 * (((fact[n + i] * modinv(fact[n]) % mod) * modinv(fact[i])) % mod)) % mod;
        v = 2 * (v - val + mod) + val;
        v %= mod;
        tot += v;
        tot %= mod;
    }
    printf("%lld", tot);
}