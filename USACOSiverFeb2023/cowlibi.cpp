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

int main()
{
    int g, n;
    scd(g);
    scd(n);

    vector<pair<int, pii>> graze(g);
    frange(i, g)
    {
        scd(graze[i].s.f);
        scd(graze[i].s.s);
        scd(graze[i].f);
    }
    sort(all(graze));

    vector<pair<int, pii>> cow(n);
    frange(i, n)
    {
        scd(cow[i].s.f);
        scd(cow[i].s.s);
        scd(cow[i].f);
    }

    int inno = 0;
    for (auto e : cow)
    {
        bool innoc = true;
        bool inn1 = true, inn2 = true;
        auto itr = lower_bound(all(graze), mp(e.f, mp(0, 0)));
        if (itr != graze.end())
        {
            auto p = *itr;
            lli dist = lli(e.s.f - p.s.f) * lli(e.s.f - p.s.f) + lli(e.s.s - p.s.s) * lli(e.s.s - p.s.s);
            lli time = lli(e.f - p.f) * lli(e.f - p.f);
            // printf("%lld %lld\n", dist, time);
            if (dist <= time)
                inn1 = false;
        }
        else
            inn1 = false;
        auto itr1 = upper_bound(all(graze), mp(e.f, mp(0, 0)));
        if (itr1 != graze.begin())
        {
            itr1--;
            auto p = *itr1;
            lli dist = lli(e.s.f - p.s.f) * lli(e.s.f - p.s.f) + lli(e.s.s - p.s.s) * lli(e.s.s - p.s.s);
            lli time = lli(e.f - p.f) * lli(e.f - p.f);
            // printf("%lld %lld\n", dist, time);
            if (dist <= time)
                inn2 = false;
        }
        else
            inn2 = false;
        if (!inn1 && !inn2)
            innoc = false;
        if (innoc)
            inno++;
    }
    printf("%d", inno);
}