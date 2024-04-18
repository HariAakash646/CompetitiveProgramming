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
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

struct frac
{
    int num, den;
    bool operator<(const frac &y) const
    {
        return ld(num) / ld(den) < ld(y.num) / ld(y.den);
    }
};

bool sign(int x, int y)
{
    if ((x >= 0 && y >= 0) || (x <= 0 && y <= 0))
        return true;
    else
        return false;
}

int main()
{
    int n, m;
    scd(n);
    scd(m);
    vii vec(n);
    frange(i, n)
    {
        scd(vec[i].f);
        scd(vec[i].s);
    }

    vector<frac> out(n);

    frange(i, m)
    {
        int e;
        scd(e);
        frange(j, n)
        {
            auto p = vec[j];
            if (sign(p.s, e) && sign(p.s, p.s - e))
            {
                out[j].num = abs(e - p.f);
                out[j].den = abs(p.s - p.f);
            }
            else
            {
                out[j].num = 1;
                out[j].den = 1;
            }
        }
        sort(all(out));
        int g = gcd(out[0].num, out[0].den);
        printf("%d %d\n", out[0].num / g, out[0].den / g);
    }
}