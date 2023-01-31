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

int main()
{
    int n, h;
    scd(n);
    scd(h);
    lli tot = 0;
    int e;
    bool x0 = true;
    vii vec(n + 1);
    vec[n] = {h + 1, 0};
    frange(i, n)
    {
        int x, y, se;
        scd(x);
        scd(y);
        scd(se);
        scd(e);
        if (x != 0)
            x0 = false;
        vec[i] = {y, se};
        tot += se;
    }
    if (x0)
    {
        sort(all(vec), greater<>());
        lli tot = 0;
        vec[0].f = vec[0].f - 1;
        vec.pb({0, 0});
        forr(i, 1, n)
        {
            if (vec[i - 1].f - vec[i].f <= e)
            {
                tot += vec[i].s;
            }
            else
                break;
        }
        printf("%lld", tot);
    }
    else
        printf("%lld", tot);
}