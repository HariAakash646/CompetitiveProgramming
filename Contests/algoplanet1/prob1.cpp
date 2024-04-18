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
    int t;
    scd(t);
    frange(_, t)
    {
        int r, g, b;
        scd(r);
        scd(g);
        scd(b);
        vll red(r);
        frange(i, r)
        {
            sclld(red[i]);
        }
        vll green(g);
        frange(i, g)
        {
            sclld(green[i]);
        }
        vll blue(b);
        frange(i, b)
        {
            sclld(blue[i]);
        }
        sort(all(red));
        sort(all(green));
        sort(all(blue));
        lli mi = 3e18 + 10;
        for (auto r1 : red)
        {
            auto b1 = upper_bound(all(blue), r1);
            auto g1 = lower_bound(all(green), r1);
            if (b1 != blue.begin() && g1 != green.end())
            {
                lli num = pow(r1 - *(b1 - 1), 2) + pow(r1 - *g1, 2) + pow(*g1 - *(b1 - 1), 2);
                mi = min(mi, num);
            }
            b1 = lower_bound(all(blue), r1);
            g1 = upper_bound(all(green), r1);
            if (b1 != blue.end() && g1 != green.begin())
            {
                lli num = pow(r1 - *b1, 2) + pow(r1 - *(g1 - 1), 2) + pow(*(g1 - 1) - *b1, 2);
                mi = min(mi, num);
            }
        }
        for (auto r1 : blue)
        {
            auto b1 = upper_bound(all(red), r1);
            auto g1 = lower_bound(all(green), r1);
            if (b1 != red.begin() && g1 != green.end())
            {
                lli num = pow(r1 - *(b1 - 1), 2) + pow(r1 - *g1, 2) + pow(*g1 - *(b1 - 1), 2);
                mi = min(mi, num);
            }
            b1 = lower_bound(all(red), r1);
            g1 = upper_bound(all(green), r1);
            if (b1 != red.end() && g1 != green.begin())
            {
                lli num = pow(r1 - *b1, 2) + pow(r1 - *(g1 - 1), 2) + pow(*(g1 - 1) - *b1, 2);
                mi = min(mi, num);
            }
        }
        for (auto r1 : green)
        {
            auto b1 = upper_bound(all(blue), r1);
            auto g1 = lower_bound(all(red), r1);
            if (b1 != blue.begin() && g1 != red.end())
            {
                lli num = pow(r1 - *(b1 - 1), 2) + pow(r1 - *g1, 2) + pow(*g1 - *(b1 - 1), 2);
                mi = min(mi, num);
            }
            b1 = lower_bound(all(blue), r1);
            g1 = upper_bound(all(red), r1);
            if (b1 != blue.end() && g1 != red.begin())
            {
                lli num = pow(r1 - *b1, 2) + pow(r1 - *(g1 - 1), 2) + pow(*(g1 - 1) - *b1, 2);
                mi = min(mi, num);
            }
        }
        printf("%lld\n", mi);
    }
}