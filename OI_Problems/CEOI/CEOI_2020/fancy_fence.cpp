// Not working
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

lli mod = 1e9 + 7;

int main()
{
    int n;
    scd(n);

    vector<pair<lli, lli>> vec(n);
    frange(i, n) sclld(vec[i].f);
    frange(i, n) sclld(vec[i].s);

    stack<pair<lli, lli>> stk;

    stk.push(vec[0]);
    lli tot = 0;
    forr(i, 1, n)
    {
        auto p = vec[i];
        vector<pair<lli, lli>> val;
        lli r = 0;
        while (stk.size() && stk.top().f > p.f)
        {
            auto e = stk.top();
            // tot += ((((e.f - p.f - 1 + mod) * (e.f - p.f + mod)) % mod) * (((e.s - 1 + mod) * e.s) % mod)) % mod;
            val.pb({(e.f - p.f + mod) % mod, e.s});
            r += e.s;
            r %= mod;
            tot %= mod;
            stk.pop();
            p.s += e.s;
            p.s %= mod;
        }
        stk.push(p);
        reverse(all(val));
        for (auto e : val)
        {
            tot += (((((e.f + 1) * e.f) / 2) % mod) * ((((r + 1) * r) / 2) % mod)) % mod;
            tot %= mod;
            r -= e.s;
            r += mod;
            r %= mod;
        }
    }
    vector<pair<lli, lli>> val;
    lli r = 0;
    while (stk.size())
    {
        val.pb(stk.top());
        r += stk.top().s;
        r %= mod;
        stk.pop();
    }
    reverse(all(val));
    for (auto p : val)
    {
        r -= p.s;
        tot += (((((p.f + 1) * p.f) / 2) % mod) * ((((r + 1) * (p.s + 1))) % mod)) % mod;
        tot %= mod;

        r += mod;
        r %= mod;
    }
    for (auto p : val)
        printf("%lld %lld\n", p.f, p.s);
    printf("%lld", tot);
}