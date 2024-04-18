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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define PB push_back
#define f first
#define s second

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int mod = 1e9 + 7;

lli exp(int x, int y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 1)
    {
        return (x * exp(x, y - 1)) % mod;
    }
    else
    {
        lli out = exp(x, y / 2);
        return (out * out) % mod;
    }
}

int main()
{
    mpii prime_fac;
    int n;
    scd(n);
    lli number = 1;
    frange(i, n)
    {
        int x, k;
        scd(x);
        scd(k);
        prime_fac[x] = k;
        number = (number * exp(x, k)) % mod;
    }
    lli num = 1;
    lli sum = 1;
    for (auto p : prime_fac)
    {
        num = (num * (p.s + 1));
        sum = (sum * ((exp(p.f, p.s + 1) - 1) / (p.f - 1))) % mod;
    }
    int prod = exp(number, num / 2);
    int numout = num % mod;

    printf("%d %d %d", numout, sum, prod);

    return 0;
}