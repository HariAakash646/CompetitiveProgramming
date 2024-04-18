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

vi prim;

vi factor(int x)
{
    vi fac;
    for (auto e : prim)
    {
        if (x % e == 0)
        {
            fac.pb(e);
            x /= e;
        }
        while (x % e == 0)
            x /= e;
    }
    if (x >= 2)
    {
        fac.pb(x);
    }
    return fac;
}

int main()
{

    int n, m;
    scd(n);
    scd(m);
    int ma = max(sqrt(n), sqrt(m)) + 5;
    vb sieve(ma, true);
    sieve[0] = false;
    sieve[1] = false;
    forr(i, 2, ma)
    {
        if (sieve[i])
        {
            prim.pb(i);
            for (int j = i * i; j < ma; j += i)
            {
                sieve[j] = false;
            }
        }
    }
    vi vec(n);
    frange(i, n)
    {
        scd(vec[i]);
    }
    seti fac;
    for (auto e : vec)
    {
        vi out = factor(e);
        for (auto e : out)
        {
            fac.insert(e);
        }
    }
    vi ans;
    forr(i, 1, m + 1)
    {
        vi out = factor(i);
        bool done = false;
        for (auto e : out)
        {
            if (fac.find(e) != fac.end())
            {
                done = true;
                break;
            }
        }
        if (!done)
        {
            ans.pb(i);
        }
    }
    printf("%d\n", ans.size());
    for (auto e : ans)
    {
        printf("%d\n", e);
    }
}