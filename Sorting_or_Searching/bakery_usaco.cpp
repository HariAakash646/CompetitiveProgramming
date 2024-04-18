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

struct Friend
{
    lli a, b, c;
};

vector<Friend> vec;

bool check(lli x)
{
    lli mia = 1;
    lli mib = 1;
    for (auto p : vec)
    {
        if (p.a > p.b)
        {
            lli v = p.a * x;
            lli d = (p.a - p.b);
            lli mi = (v - p.c + d - 1) / d;
            mia = max(mia, mi);
        }
        else if (p.a < p.b)
        {
            lli v = p.b * x;
            lli d = (p.b - p.a);
            lli mi = (v - p.c + d - 1) / d;
            mib = max(mib, mi);
        }
        else
        {
            lli v = p.b * x;
            if (v > p.c)
                return false;
        }
    }
    return mia + mib <= x;
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        lli tc, tm;
        sclld(tc);
        sclld(tm);
        vec = vector<Friend>(n);
        frange(i, n)
        {
            sclld(vec[i].a);
            sclld(vec[i].b);
            sclld(vec[i].c);
        }
        lli hi = tc + tm;
        lli lo = 2;
        while (hi != lo)
        {
            lli mid = (hi + lo + 1) / 2;
            if (check(mid))
            {
                lo = mid;
            }
            else
                hi = mid - 1;
        }
        printf("%lld %d\n", tc + tm - lo, int(check(5)));
    }
}