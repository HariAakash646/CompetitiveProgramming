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

int n, k;
vi vec;

bool check(int x)
{
    int les = 0;
    int grt = 0;
    int tml = 0;
    int tmg = 0;

    frange(i, k)
    {
        if (vec[i] < x)
            les++;
        else
            grt++;
    }
    if (les < grt)
        return true;
    forr(i, k, n)
    {
        if (vec[i] < x)
            les++;
        else
            grt++;
        if (vec[i - k] < x)
            tml++;
        else
            tmg++;
        if (tml >= tmg)
        {
            les -= tml;
            grt -= tmg;
            tml = 0;
            tmg = 0;
        }
        if (les < grt)
            return true;
    }
    return false;
}

int main()
{
    scd(n);
    scd(k);
    vec = vi(n);
    frange(i, n) scd(vec[i]);
    int hi = n;
    int lo = 1;
    while (lo != hi)
    {
        int mid = (hi + lo + 1) / 2;
        if (check(mid))
        {
            lo = mid;
        }
        else
            hi = mid - 1;
    }
    printf("%d", lo);
}