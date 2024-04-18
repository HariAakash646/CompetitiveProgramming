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

lli mod = 1e9 + 7;
lli inv2 = 500000004;

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        lli n, m;
        int k;
        sclld(n);
        sclld(m);
        scd(k);
        lli ans = 0;
        if (n % 2 == 0)
        {
            ans += ((((n / 2) * (n - 1)) % mod) * (m * m % mod)) % mod;
        }
        else
        {
            ans += (((n * ((n - 1) / 2)) % mod) * (m * m % mod)) % mod;
        }
        if (m % 2 == 0)
        {
            ans += (((n * (m / 2)) % mod) * (m + 1)) % mod;
        }
        else
        {
            ans += (((n * m) % mod) * ((m + 1) / 2)) % mod;
        }
        ans %= mod;
        lli row = 0;
        lli col = 0;
        lli rk = 0;
        lli ck = 0;

        frange(i, k)
        {
            printf("%lld ", ans);
            int q;
            lli x, v;
            scd(q);
            sclld(x);
            sclld(v);
            if (q == 0)
            {
                ans += (v - 1) * ((x - 1) * (m * m % mod) % mod);
                ans += (v - 1) * row % mod;
                ans += ((v - 1) * rk % mod) * ((x - 1) * m % mod) % mod;
                ans += ((v - 1) * (m * (m + 1) % mod) * inv2 % mod) % mod;
                // if (m % 2)
                // {
                //     ans += ((v - 1) * (m * ((m + 1) / 2) % mod)) % mod;
                // }
                // else
                // {
                //     ans += ((v - 1) * ((m / 2) * (m + 1) % mod)) % mod;
                // }
                ck += v - 1;
                col += ((x - 1) * m % mod) * (v - 1) % mod;
                // col += ((v - 1) * rk % mod) * ((x - 1) % mod) % mod;
                // col += rk * row % mod;
            }
            else
            {
                ans += (v - 1) * ((((n * (n - 1) % mod) * m % mod) * inv2) % mod + (n * x % mod));
                ans %= mod;
                ans += (v - 1) * col % mod;
                ans %= mod;
                ans += ((ck * (v - 1) % mod) * x) % mod;
                rk += v - 1;
                row += (x * (v - 1)) % mod;
            }
        }
        printf("%lld\n", ans);
    }
}