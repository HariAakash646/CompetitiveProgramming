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
typedef pair<int, pii> piii;

lli modinv(lli i, lli mod)
{
    return i <= 1 ? i : mod - (mod / i) * modinv(mod % i, mod) % mod;
}

lli binexp(lli x, lli pow, lli mod)
{
    if (pow == 0)
    {
        return 1;
    }
    lli res = binexp(x, pow / 2, mod);
    lli v = (res * res) % mod;
    if (pow % 2)
    {
        return (v * x) % mod;
    }
    else
    {
        return v;
    }
}

int main()
{
    lli a, x, m;
    sclld(a);
    sclld(x);
    sclld(m);
    printf("%lld", ((binexp(a, x, m) - 1) * modinv(a - 1, m)) % m);
}