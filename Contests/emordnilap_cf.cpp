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
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

lli mod = 1e9 + 7;

vector<lli> facvec(1e5 + 5, 0);

lli fact(lli x)
{
    if (facvec[x])
        return facvec[x];
    if (x <= 1)
        return 1;
    facvec[x] = (fact(x - 1) * x) % mod;
    return facvec[x];
}

vector<lli> comp(1e5 + 5, 0);
lli ans(lli x)
{
    if (comp[x])
        return comp[x];
    comp[x] = (((((((x - 1) * x)) % mod) * fact(x - 1)) % mod) + (x * ans(x - 1)) % mod) % mod;
    return comp[x];
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        lli n;
        sclld(n);
        lli tot = ans(n);
        for (lli i = 0; i < n; i++)
        {
            tot = (tot + (i * fact(n)) % mod) % mod;
        }
        printf("%lld\n", tot);
    }
}