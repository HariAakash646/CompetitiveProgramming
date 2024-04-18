#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
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

lli tot;
lli mod = 998244353;

lli inv(lli a)
{
    a %= mod;
    return a <= 1 ? a : mod - (lli)(mod / a) * inv(mod % a) % mod;
}

vvi val;

void rec(vi vec, lli vl)
{
    tot += vec.size() * vl;
    int c = 0;
    lli x = 0;
    for (auto e : vec)
    {
        // cout << e << " ";
        if (!e)
            x++;
    }
    // cout << "\n";
    frange(i, 31)
    {
        vi v;
        for (auto e : vec)
        {
            if (e)
            {
                if (31 - __builtin_clz(e) == i)
                {
                    v.pb(e ^ (1 << i));
                }
            }
        }
        x += v.size();
        tot %= mod;
        if (v.size())
            rec(v, x);
    }
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        lli n;
        sclld(n);
        vi vec(n);
        val = vvi(31);
        frange(i, n)
        {
            scd(vec[i]);
            val[30].pb(vec[i]);
        }
        tot = 0;
        rec(vec, n);

        tot = (tot * inv(n * n)) % mod;
        printf("%lld\n", tot);
    }
    // printf("%d", 31 - __builtin_clz(5));
}