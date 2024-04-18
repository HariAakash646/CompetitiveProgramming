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

lli n;
vector<lli> gun, arm;

bool check(lli x)
{
    lli c = 0;
    for (auto e : gun)
    {
        c += upper_bound(all(arm), x - e) - arm.begin();
    }
    return c >= n;
}

int main()
{

        int g, a;
    scd(g);
    scd(a);
    sclld(n);
    gun = vll(g);
    arm = vll(a);

    frange(i, g) sclld(gun[i]);
    frange(i, a) sclld(arm[i]);
    sort(all(gun));
    sort(all(arm));
    lli lo = 1;
    lli hi = 4e6;

    while (lo != hi)
    {
        lli mid = (lo + hi) / 2;
        if (check(mid))
        {
            hi = mid;
        }
        else
            lo = mid + 1;
    }
    lli tot = 0;
    lli c = 0;
    vll pref(a);
    pref[0] = arm[0];
    forr(i, 1, a) pref[i] = pref[i - 1] + arm[i];
    for (auto e : gun)
    {
        int id = upper_bound(all(arm), lo - e - 1) - arm.begin();
        c += id;
        if (id > 0)
        {
            tot += pref[id - 1];
            tot += id * e;
        }
    }
    printf("%lld", tot + (n - c) * lo);
}