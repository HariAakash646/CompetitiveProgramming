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

vi pos, spd;
int n;

bool check(long double t)
{
    long double r = pos[0] + spd[0] * t;
    long double l = pos[0] - spd[0] * t;
    long double rm, lm;
    frange(i, n)
    {
        rm = pos[i] + spd[i] * t;
        lm = pos[i] - spd[i] * t;
        if (pos[i] <= r && rm >= l)
        {
            r = min(r, rm);
        }
        else if (pos[i] >= l && lm <= r)
        {
            l = max(l, lm);
        }
        else
            return false;
    }
    return true;
}

int main()
{

    scd(n);
    pos = vi(n);
    spd = vi(n);
    frange(i, n)
    {
        scd(pos[i]);
    }
    frange(i, n)
    {
        scd(spd[i]);
    }
    long double l = 0.0;
    long double h = *max_element(all(pos));
    while (abs(l - h) >= 1e-6)
    {
        long double mid = (l + h) / 2;
        bool out = check(mid);
        if (out)
            h = mid;
        else
            l = mid;
        if (l > h)
        {
            printf("-1");
            return 0;
        }
    }
    cout << setprecision(1000) << l;
}