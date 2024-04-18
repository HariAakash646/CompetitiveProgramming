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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

bool cmp(pair<pii, int> x, pair<pii, int> y)
{
    if (x.f.s < y.f.s)
        return true;
    else
        return false;
}

int main()
{
    int n;
    scd(n);
    vector<pair<pii, int>> vec(n);
    frange(i, n)
    {
        scd(vec[i].f.f);
        scd(vec[i].f.s);
        scd(vec[i].s);
    }
    sort(all(vec));
    int idx = 1;
    int prev = vec[0].f.f;
    vec[0].f.f = idx;

    forr(i, 1, n)
    {
        if (vec[i].f.f != prev)
            idx++;
        vec[i].f.f = idx;
    }
    sort(all(vec), cmp);
    idx = 1;
    prev = vec[0].f.s;
    vec[0].f.s = idx;

    forr(i, 1, n)
    {
        if (vec[i].f.s != prev)
            idx++;
        vec[i].f.s = idx;
    }

    vvi grid(n + 1, vi(n + 1));
    for (auto e : vec)
    {
        grid[e.f.f][e.f.s] = e.s;
    }
    vector<vector<lli>> pref(n + 1, vector<lli>(n + 1));
    forr(i, 1, n + 1)
    {
        forr(j, 1, n + 1)
        {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + grid[i][j];
        }
    }

    lli m = 0;
    for (auto e : vec)
    {
        for (auto p : vec)
        {
            int mx = max(e.f.f, p.f.f);
            int mix = min(e.f.f, p.f.f);
            int my = max(e.f.s, p.f.s);
            int miy = min(e.f.s, p.f.s);
            mix = min(mix, miy);
            miy = mix;
            mx = max(mx, my);
            my = mx;
            lli val = pref[mx][my] - pref[mix - 1][my] - pref[mx][miy - 1] + pref[mix - 1][miy - 1];
            m = max(val, m);
        }
    }
    printf("%lld", m);
}