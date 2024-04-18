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

lli mod = 998244353;

lli inv(lli n)
{
    return (n <= 1) ? n : mod - (lli(mod / n) * inv(mod % n)) % mod;
}

int main()
{
    int n;
    scd(n);
    vb isprime(1e6 + 1, true);
    isprime[0] = false;
    isprime[1] = false;
    for (int i = 2; i * i <= 1e6; i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j <= 1e6; j += i)
            {
                isprime[j] = false;
            }
        }
    }
    vll fac(2 * n + 5);
    fac[0] = 1;
    forr(i, 1, 2 * n + 5)
    {
        fac[i] = (fac[i - 1] * i) % mod;
    }
    vi v1(2 * n);
    frange(i, 2 * n)
    {
        scd(v1[i]);
    }
    seti prim;
    mpii vec;
    int c = 0;
    for (auto e : v1)
    {
        if (isprime[e] && prim.find(e) == prim.end())
        {
            prim.insert(e);
        }
        else
        {
            vec[e] += 1;
            c++;
        }
    }
    int sz = prim.size();
    if (sz < n)
    {
        printf("0");
        return 0;
    }
    if (sz == n)
    {
        lli out = fac[n];
        lli prod = 1;
        for (auto p : vec)
        {
            prod = (prod * p.s) % mod;
        }
        out = (out * inv(prod)) % mod;
        printf("%lld", out);
    }
    else
    {
        lli out = (fac[sz] * inv((fac[n - c] * fac[sz - (n - c)]) % mod)) % mod;
        out = (out * fac[n]) % mod;
        lli prod = 1;
        for (pii p : vec)
        {
            prod = (prod * p.s) % mod;
        }
        out = (out * inv(prod)) % mod;
        lli og = (fac[n] * inv(prod)) % mod;

        lli comb = (fac[sz - 1] * inv((fac[n - c - 1] * fac[(sz - 1) - (n - c - 1)]) % mod)) % mod;
        // printf("%lld %lld %lld\n", out, og, comb);
        for (auto e : prim)
        {
            // lli tmp = (og * fac[vec[e]]) % mod;
            lli tmp = ((og * fac[vec[e]]) % mod) * inv(fac[vec[e] + 1]) % mod;
            // printf("%lld %lld\n", tmp - og, inv(fac[vec[e] + 1]));
            // out -= ((((comb * (tmp * vec[e]) % mod) % mod) * inv(fac[vec[e] + 1])) % mod) % mod;
            out += comb * tmp;
            out -= comb * og;
            out = (out + mod) % mod;
        }
        printf("%lld", out);
    }
}