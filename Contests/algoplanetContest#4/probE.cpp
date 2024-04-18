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

bool cmp1(pair<pii, int> v1, pair<pii, int> v2)
{
    pii x = v1.f;
    pii y = v2.f;
    if (x.s > y.f)
    {
        return false;
    }
    else
    {
        if (y.s < x.f)
        {
            if (x.s > y.s)
            {
                return true;
            }
            else
                return false;
        }
        return true;
    }
}

bool cmp2(pair<pii, int> v1, pair<pii, int> v2)
{
    pii x = v1.f;
    pii y = v2.f;
    if (x.s < y.f)
    {
        return false;
    }
    else
    {
        if (y.s > x.f)
        {
            if (x.s < y.s)
            {
                return true;
            }
            else
                return false;
        }
        return true;
    }
}

int main()
{
    int n;
    scd(n);
    vector<pair<pii, int>> asc;
    vector<pair<pii, int>> dsc;
    frange(i, n)
    {
        int a, b;
        scd(a);
        scd(b);
        if (a > b)
        {
            asc.pb({{a, b}, i + 1});
        }
        if (b > a)
        {
            dsc.pb({{a, b}, i + 1});
        }
    }
    sort(all(asc), cmp1);
    sort(all(dsc), cmp2);
    printf("%d\n", max(asc.size(), dsc.size()));
    if (asc.size() >= dsc.size())
    {
        for (auto e : asc)
        {
            printf("%d ", e.s);
        }
    }
    else
    {
        for (auto e : dsc)
        {
            printf("%d ", e.s);
        }
    }
}