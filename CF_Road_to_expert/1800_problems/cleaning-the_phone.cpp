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

struct frac
{
    int num, den;
    bool operator<(const frac &y) const
    {
        return ld(num) / ld(den) < ld(y.num) / ld(y.den);
    }
    bool operator>(const frac &y) const
    {
        return ld(num) / ld(den) > ld(y.num) / ld(y.den);
        // if (ld(num) / ld(den) - 0.0001 > ld(y.num) / ld(y.den))
        // {
        //     return true;
        // }
        // else if (abs(ld(num) / ld(den) - ld(y.num) / ld(y.den)) <= 0.0001)
        // {
        //     return den < y.den;
        // }
        // else
        //     return false;
    }
};

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        lli m;
        sclld(m);
        vll a(n), b(n);
        vll v1, v2;
        frange(i, n)
        {
            sclld(a[i]);
        }
        frange(i, n)
        {
            sclld(b[i]);
            if (b[i] == 1)
                v1.pb(a[i]);
            else
                v2.pb(a[i]);
        }
        vll pref1(v1.size() + 1), pref2(v2.size() + 1);
        sort(all(v1), greater<>());
        sort(all(v2), greater<>());
        forr(i, 1, v1.size() + 1)
        {
            pref1[i] = pref1[i - 1] + v1[i - 1];
        }
        forr(i, 1, v2.size() + 1)
        {
            pref2[i] = pref2[i - 1] + v2[i - 1];
        }
        if (*prev(pref1.end()) + *prev(pref2.end()) < m)
        {
            printf("-1\n");
            continue;
        }
        int mi = 1e9;
        frange(i, pref1.size())
        {
            int v = i + 2 * (lower_bound(all(pref2), m - pref1[i]) - pref2.begin());
            if (lower_bound(all(pref2), m - pref1[i]) != pref2.end())
                mi = min(mi, v);
        }
        printf("%d\n", mi);
    }
}