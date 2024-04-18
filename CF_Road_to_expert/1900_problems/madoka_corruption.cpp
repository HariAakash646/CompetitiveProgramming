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

lli inv(lli i)
{
    return i <= 1 ? i : mod - (lli)(mod / i) * inv(mod % i) % mod;
}

int main()
{
    int n, k;
    scd(n);
    scd(k);
    vll pow2(n + 1);
    vll fact(n + 1);
    fact[0] = pow2[0] = 1;
    forr(i, 1, n + 1) fact[i] = fact[i - 1] * i % mod;
    forr(i, 1, n + 1) pow2[i] = (pow2[i - 1] * 2) % mod;
    lli tot = 0;
    forr(i, 0, min(n, k) + 1)
    {
        tot = (tot + ((fact[n] * inv(fact[i]) % mod) * inv(fact[n - i]) % mod)) % mod;
    }
    printf("%lld", tot);
}