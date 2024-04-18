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

int main()
{
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k;
    scd(n);
    scd(k);
    vi vec(n);
    frange(i, n)
    {
        scd(vec[i]);
    }
    // if (n == 1)
    // {
    //     printf("1\n");
    //     return 0;
    // }
    sort(all(vec));
    auto itr1 = vec.begin();
    auto itr2 = vec.begin();
    vii out;
    while (itr2 != vec.end())
    {
        itr2++;
        if (itr2 == prev(vec.end()))
        {
            while (*itr2 - *itr1 > k)
                itr1++;
            out.pb({itr1 - vec.begin(), itr2 - vec.begin()});
            break;
        }
        if (*itr2 - *itr1 > k)
        {
            out.pb({itr1 - vec.begin(), itr2 - vec.begin() - 1});
            while (*itr2 - *itr1 > k)
                itr1++;
        }
    }
    vi suf(out.size() + 1);
    for (int i = out.size() - 1; i >= 0; i--)
    {
        suf[i] = max(suf[i + 1], out[i].s - out[i].f);
    }
    int ma = 0;
    frange(i, out.size())
    {
        auto p = out[i];
        auto it = upper_bound(all(out), mp(p.s, 0));
        if (it == out.end())
        {
            it--;
            ma = max(ma, (*it).s - p.f);
            continue;
        }
        ma = max(ma, p.s - p.f + 1 + suf[it - out.begin()]);
        it--;
        ma = max(ma, (*it).s - p.f);
    }
    printf("%d", ma + 1);
}
