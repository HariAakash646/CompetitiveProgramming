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

int mod = 998244353;

vi primefac(int n)
{
    vi prim;
    while (n % 2 == 0)
    {
        n = n / 2;
        prim.pb(2);
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            n = n / i;
            prim.pb(i);
        }
    }
    if (n > 2)
        prim.pb(n);
    sort(all(prim));
    prim.erase(unique(all(prim)), prim.end());
    return prim;
}

int main()
{
    int t;
    scd(t);
    // vi tmp(1e6 + 1);
    // vi prim;
    // forr(i, 2, 1e6 + 1)
    // {
    //     if (!tmp[i])
    //     {
    //         prim.pb(i);
    //         for (int j = 2; i * j <= 1e6; j++)
    //         {
    //             tmp[i * j] = i;
    //         }
    //     }
    // }

    // printf("%d ", prim.size());
    // printf("\n");
    frange(_, t)
    {
        int l, r;
        scd(l);
        scd(r);
        vii vec(r + 1);

        forr(i, l, r + 1)
        {
            vec[i].f = 1;
            vec[i].s = 1;
            vi prim = primefac(i);
            vi pref(r + 1);
            for (auto e : prim)
            {
                if (i / e >= l)
                {
                    if (vec[i].f < vec[i / e].f + 1)
                    {
                        vec[i].f = vec[i / e].f + 1;
                        vec[i].s = vec[i / e].s;
                    }
                    else if (vec[i].f == vec[i / e].f + 1)
                    {
                        vec[i].s += vec[i / e].s;
                        vec[i].s %= mod;
                    }
                    else if (pref[i / e] + 1 < vec[i].f)
                        break;
                }
                else
                    break;
            }
            pref[i] = max(pref[i - 1], vec[i].f);
        }

        int ma = 0;
        int tot = 0;

        for (auto p : vec)
        {
            if (p.f > ma)
            {
                ma = p.f;
                tot = p.s;
            }
            else if (p.f == ma)
            {
                tot += p.s;
                tot %= mod;
            }
        }
        printf("%d %d\n", ma, tot);
    }
}