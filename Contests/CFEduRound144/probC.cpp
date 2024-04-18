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

seti primefac(int n)
{
    seti prim;
    while (n % 2 == 0)
    {
        n = n / 2;
        prim.insert(2);
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            n = n / i;
            prim.insert(i);
        }
    }
    if (n > 2)
        prim.insert(n);
    return prim;
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int l, r;
        scd(l);
        scd(r);
        vii vec(r + 1);
        forr(i, l, r + 1)
        {
            if (!vec[i].f)
            {
                vec[i].f = 1;
                vec[i].s = 1;
                for (int j = 2; i * j <= r; j++)
                {
                    if (vec[j].f == 1 && j < i)
                        continue;
                    seti prim = primefac(j);
                    for (auto e : prim)
                    {
                        if (vec[i * j].f < vec[i * j / e].f + 1)
                        {
                            vec[i * j].f = vec[i * j / e].f + 1;
                            vec[i * j].s = vec[i * j / e].s;
                        }
                        else if (vec[i * j].f == vec[i * j / e].f + 1)
                        {
                            if (vec[i * j / e].f == 1 && i != j)
                                continue;
                            vec[i * j].s += vec[i * j / e].s;
                            vec[i * j].s %= mod;
                        }
                    }
                }
            }
        }

        int ma = 0;
        int tot = 0;
        // for (auto p : vec)
        // {
        //     printf("%d ", p.f);
        // }
        // printf("\n");
        // for (auto p : vec)
        // {
        //     printf("%d ", p.s);
        // }
        // printf("\n");
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