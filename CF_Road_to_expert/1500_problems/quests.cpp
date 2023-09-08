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
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int n, d;
lli c;
multiset<lli, greater<lli>> rew;

bool check(lli v)
{
    v++;
    lli tot = 0;
    int cn = d / v;
    int rem = d % v;
    int co = 0;
    auto itr = rew.begin();
    while (itr != rew.end())
    {
        auto e = *itr;
        tot += min(d - co, cn) * e;
        co += cn;
        if (co < d && rem > 0)
        {
            tot += e;
            co++;
            rem--;
        }
        itr = next(itr);
        if (co >= d)
            break;
    }
    if (tot >= c)
        return true;
    else
        return false;
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {

        scd(n);
        sclld(c);
        scd(d);
        rew = {};
        lli tot = 0;
        forr(i, 1, n + 1)
        {
            lli a;
            sclld(a);
            rew.insert(a);
        }
        int dc = 0;
        auto itr = rew.begin();
        while (itr != rew.end())
        {
            auto e = *itr;
            dc++;
            tot += e;
            itr = next(itr);
            if (dc == d)
                break;
        }
        if (tot >= c)
        {
            printf("Infinity\n");
            continue;
        }
        tot = *rew.begin() * d;
        if (tot < c)
        {
            printf("Impossible\n");
            continue;
        }
        lli l = 0;
        lli h = d;
        while (l < h)
        {
            lli mid = l + (h - l + 1) / 2;
            if (check(mid))
            {
                l = mid;
            }
            else
            {
                h = mid - 1;
            }
        }
        printf("%lld\n", l);
    }
}