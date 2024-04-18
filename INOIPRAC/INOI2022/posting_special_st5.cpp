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

int main()
{
    int n, m;
    scd(n);
    scd(m);

    vll v1(n);
    vector<lli> v2(m);

    forr(i, 0, n) sclld(v1[i]);
    lli mv = 0;
    lli mav = 0;
    forr(i, 0, m)
    {
        int a, b;
        sclld(v2[i]);
        scd(a);
        scd(b);
        mv += a;
        mav += b;
    }

    sort(all(v1));
    sort(all(v2));

    lli tot = 0;
    for (auto e : v1)
    {
        auto it1 = upper_bound(all(v2), e);
        lli v = abs(e - *it1);
        if (it1 != v2.begin())
        {
            it1--;
            v = min(v, abs(e - *it1));
        }
        tot += v;
    }
    printf("%lld", tot);
}