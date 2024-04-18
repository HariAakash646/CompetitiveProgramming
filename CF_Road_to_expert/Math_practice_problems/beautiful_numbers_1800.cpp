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

lli inv(lli n)
{
    return (n <= 1) ? n : mod - (lli(mod / n) * inv(mod % n)) % mod;
}

int main()
{
    int n, a, b;

    scd(a);
    scd(b);
    scd(n);
    vll fac(n + 1);
    fac[0] = 1;
    forr(i, 1, n + 1)
    {
        fac[i] = (fac[i - 1] * i) % mod;
    }
    int tot = 0;
    frange(i, n + 1)
    {
        int num = a * i + b * (n - i);
        bool done = true;
        while (num)
        {
            int x = num % 10;

            if (x != a && x != b)
            {
                done = false;
                break;
            }
            num /= 10;
        }
        if (done)
        {
            tot = (tot + (fac[n] * inv((fac[i] * fac[n - i]) % mod)) % mod) % mod;
        }
    }
    printf("%d", tot);
}