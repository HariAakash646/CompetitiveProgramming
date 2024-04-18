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

vll fact(2e6 + 10);

lli mod = 1e9 + 7;

lli modinv(lli i)
{
    return i <= 1 ? i : mod - (lli)(mod / i) * modinv(mod % i) % mod;
}

lli combination(lli n, lli r)
{
    return fact[n] * modinv((fact[r] * fact[n - r]) % mod) % mod;
}

int main()
{

    fact[0] = 1;
    forr(i, 1, 2e6 + 10)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    lli n, m;
    sclld(n);
    sclld(m);
    printf("%lld", combination(m + n - 1, n - 1));
}