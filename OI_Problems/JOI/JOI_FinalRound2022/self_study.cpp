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

lli n, m;
bool check(lli x, vll &v1, vll &v2)
{
    lli tot = 0;
    frange(i, n)
    {
        lli e1 = v1[i];
        lli e2 = v2[i];

        lli tmp = x;
        lli v = (tmp + e1 - 1) / e1;
        tmp -= e1 * min(m, v);
        tot += min(m, v);
        if (tmp > 0)
        {
            v = (tmp + e2 - 1) / e2;
            tot += v;
        }
        if (tot > n * m)
            return false;
    }
    return tot <= n * m;
}

int main()
{

    sclld(n);
    sclld(m);
    vll vec1(n);
    vll vec2(n);
    frange(i, n)
    {
        sclld(vec1[i]);
    }
    frange(i, n)
    {
        lli a;
        sclld(a);
        vec2[i] = a;
        vec1[i] = max(vec1[i], a);
    }
    // mi = *min_element(all(vec));
    lli hi = 1e18;
    lli lo = 0;
    while (hi != lo)
    {
        lli mid = (hi + lo + 1) / 2;
        if (check(mid, vec1, vec2))
        {
            lo = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }
    printf("%lld", lo);
}