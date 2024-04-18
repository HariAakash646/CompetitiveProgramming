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

struct tramp
{
    lli x, y;
    lli pow = 1;

    bool operator<(const tramp &e) const
    {
        if (x < e.x)
            return true;
        else if (x == e.x)
        {
            if (y < e.y)
                return true;
            else if (y == e.y)
            {
                return pow < e.pow;
            }
            else
                return false;
        }
        else
            return false;
    }
};

int main()
{
    int n;
    scd(n);
    vector<tramp> vec(n);
    frange(i, n)
    {
        sclld(vec[i].x);
        sclld(vec[i].y);
        sclld(vec[i].pow);
    }
    map<pair<tramp, tramp>, lli> dist;
    frange(i, n)
    {
        frange(j, n)
        {

            dist[mp(vec[i], vec[j])] = (abs(vec[i].x - vec[j].x) + abs(vec[i].y - vec[j].y) + vec[i].pow - 1) / vec[i].pow;
        }
    }
    for (auto k : vec)
    {
        for (auto i : vec)
        {
            for (auto j : vec)
            {
                dist[mp(i, j)] = min(dist[mp(i, j)], max(dist[mp(i, k)], dist[mp(k, j)]));
            }
        }
    }
    lli mi = 4e9;
    for (auto i : vec)
    {
        lli ma = 0;
        for (auto j : vec)
        {
            ma = max(ma, dist[mp(i, j)]);
        }
        mi = min(mi, ma);
    }
    printf("%lld", mi);
}