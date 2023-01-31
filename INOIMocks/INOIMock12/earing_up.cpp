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
    int r, c, q;
    scd(r);
    scd(c);
    scd(q);
    vector<vii> vec(r, vii(c));
    frange(i, r)
    {
        frange(j, c)
        {
            scd(vec[i][j].f);
        }
    }
    frange(i, r)
    {
        frange(j, c)
        {
            scd(vec[i][j].s);
        }
    }
    vector<lli> pref(c + 1);
    pref[0] = 1;
    seti wep;
    wep.insert(vec[0][0].s);
    forr(i, 1, c)
    {
        wep.insert(vec[0][i].s);
        pref[i] = wep.size();
    }
    frange(_, q)
    {
        int t, x, y, a;
        scd(t);
        scd(x);
        scd(y);
        scd(a);
        x--;
        y--;
        if (t == 1)
        {
            vec[y][x].s = a;
            pref[0] = 1;
            seti wep;
            wep.insert(vec[0][0].s);
            forr(i, 1, c)
            {
                wep.insert(vec[0][i].s);
                pref[i] = wep.size();
            }
        }
        else
        {
            if (x <= a - 1)
            {
                printf("%lld\n", pref[min(a - 1, c - 1)]);
            }
            else
            {
                printf("0\n");
            }
        }
    }
    // frange(_, q)
    // {
    //     int t, x, y, a;
    //     scd(t);
    //     scd(x);
    //     scd(y);
    //     scd(a);
    //     if (t == 1)
    //     {
    //         vec[x - 1][y - 1].s = a;
    //     }
    //     else
    //     {
    //         vector<int> weap;
    //         frange(i, r)
    //         {
    //             frange(j, c)
    //             {
    //                 if (vec[i][j].f <= a)
    //                 {
    //                     weap.pb(vec[i][j].s);
    //                 }
    //             }
    //         }
    //         seti wepset(all(weap));
    //         printf("%d\n", wepset.size());
    //     }
    // }
}