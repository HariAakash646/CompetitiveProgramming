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

lli mod = 1e9 + 7;

lli exp(lli x, lli y, lli mod)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 1)
    {
        return ((x % mod) * (exp(x, y - 1, mod) % mod));
    }
    else
    {
        lli out = exp(x, y / 2, mod) % mod;
        return (out * out);
    }
}

int main()
{
    int n;
    scd(n);
    frange(i, n)
    {
        lli a, b, c;
        sclld(a);
        sclld(b);
        sclld(c);
        printf("%lld\n", exp(a, exp(b, c, (mod - 1)) % (mod - 1), mod) % mod);
    }
}