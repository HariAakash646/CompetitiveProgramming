// TODO: Not working for all cases. Partially correct.

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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define PB push_back
#define f first
#define s second

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
    // freopen("split.in", "r", stdin);
    // freopen("split.out", "w", stdout);
    int n;
    scd(n);
    vii vec(n);

    int min_x = 1e9 + 5;
    int min_y = 1e9 + 5;
    int max_x = 0;
    int max_y = 0;
    frange(i, n)
    {
        scd(vec[i].f);
        scd(vec[i].s);
        min_x = min(min_x, vec[i].f);
        min_y = min(min_y, vec[i].s);
        max_x = max(max_x, vec[i].f);
        max_y = max(max_y, vec[i].s);
    }
    lli tot_area = (max_x - min_x) * (max_y - min_y);
    pii min_p, max_p;
    int min_dist = 2e9 + 5;
    int max_dist = 2e9 + 5;
    sort(vec.begin(), vec.end());
    for (auto e : vec)
    {
        if (abs(e.f - min_x) + abs(e.s - min_y) < min_dist)
        {
            min_dist = abs(e.f - min_x) + abs(e.s - min_y);
            min_p = e;
        }
        if (abs(e.f - max_x) + abs(e.s - max_y) < max_dist)
        {
            max_dist = abs(e.f - max_x) + abs(e.s - max_y);
            max_p = e;
        }
    }
    pii min_p2 = min_p;
    pii max_p2 = max_p;
    lli curr_area1 = 0;
    lli curr_area2 = 0;

    for (auto e : vec)
    {
        if (((max(e.f, min_p2.f) - min_p.f) * (max(e.s, min_p2.s) - min_p.s) - curr_area1) < ((max_p.f - min(e.f, max_p2.f)) * (max_p.s - min(e.s, max_p2.s)) - curr_area2))
        {

            if (e.f < min_p.f || e.s < min_p.s)
            {
                min_p2 = {max(e.f, min_p2.f), max(e.s, min_p2.s)};
                min_p = {min(e.f, min_p.f), min(e.s, min_p.s)};
                curr_area1 = (min_p2.f - min_p.f) * (min_p2.s - min_p.s);
            }
            else
            {
                min_p2 = {max(e.f, min_p2.f), max(e.s, min_p2.s)};
                curr_area1 = ((max(e.f, min_p2.f) - min_p.f) * (max(e.s, min_p2.s) - min_p.s));
            }
        }
        else // if (((max(e.f, min_p2.f) - min_p.f) * (max(e.s, min_p2.s) - min_p.s) - curr_area1) >= ((max_p.f - min(e.f, max_p2.f)) * (max_p.s - min(e.s, max_p2.s)) - curr_area2))
        {

            if (e.f > max_p.f || e.s > max_p.s)
            {
                max_p2 = {min(e.f, max_p2.f), min(e.s, max_p2.s)};
                max_p = {max(e.f, max_p.f), max(e.s, max_p.s)};
                curr_area2 = ((max_p.f - max_p2.f) * (max_p.s - max_p2.s));
            }
            else
            {
                max_p2 = {min(e.f, max_p2.f), min(e.s, max_p2.s)};
                curr_area2 = ((max_p.f - min(e.f, max_p2.f)) * (max_p.s - min(e.s, max_p2.s)));
            }
        }
    }
    printf("%lld", tot_area - curr_area1 - curr_area2);
}