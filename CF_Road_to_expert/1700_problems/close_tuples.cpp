#include <bits/stdc++.h>
#include <iostream>

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
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

lli mod = 1e9 + 7;

lli modinv(lli i)
{
    return i <= 1 ? i : mod - (mod / i) * modinv(mod % i) % mod;
}

int main()
{
    vll fac(2e5 + 1);
    fac[0] = 1;
    forr(i, 1, 2e5 + 1)
    {
        fac[i] = (i * fac[i - 1]) % mod;
    }
    int t;
    scd(t);
    frange(_, t)
    {
        lli n, m, k;
        sclld(n);
        sclld(m);
        sclld(k);
        m--;
        vll vec(n);
        frange(i, n) sclld(vec[i]);
        sort(all(vec));
        lli tot = 0;
        frange(i, n)
        {
            int id = upper_bound(all(vec), vec[i] + k) - vec.begin() - 1 - i;

            if (m <= id)
            {
                tot += (fac[id] * (modinv((fac[m] * fac[id - m]) % mod) % mod)) % mod;
                tot %= mod;
            }
        }
        printf("%lld\n", tot);
    }
}