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
typedef vector<char> vc;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

lli mod = 998244353;
lli MOD = mod;

int xGCD(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1, gcd = xGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (long long)(a / b) * y1;
    return gcd;
}

// factorial of n modulo MOD
int modfact(int n)
{
    int result = 1;
    while (n > 1)
    {
        result = (long long)result * n % MOD;
        n -= 1;
    }
    return result;
}

// multiply a and b modulo MOD
int modmult(int a, int b)
{
    return (long long)a * b % MOD;
}

// inverse of a modulo MOD
int inverse(int a)
{
    int x, y;
    xGCD(a, MOD, x, y);
    return x;
}

// binomial coefficient nCk modulo MOD
int bc(int n, int k)
{
    return modmult(modmult(modfact(n), inverse(modfact(k))), inverse(modfact(n - k)));
}

int main()
{
    int n;
    scd(n);
    lli ans = 1;

    frange(i, n / 3)
    {
        int a, b, c;
        scd(a);
        scd(b);
        scd(c);
        if (a == b && b == c)
        {
            ans *= 3;
            ans %= mod;
        }
        else if ((c > a && a == b) || (a > b && b == c) || (b > a && a == c))
        {
            ans *= 2;
            ans %= mod;
        }
    }
    ans = (ans * bc(n / 3, n / 6)) % mod;
    printf("%lld", ans);
}