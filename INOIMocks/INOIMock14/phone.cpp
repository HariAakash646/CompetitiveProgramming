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

int main()
{
    int n;
    scd(n);
    vll avec(n);
    vll bvec(n);
    frange(i, n)
    {
        sclld(avec[i]);
        sclld(bvec[i]);
    }
    // st 1 & 2
    // lli ma = 0;
    // for (auto e1 : avec)
    // {
    //     for (auto e2 : bvec)
    //     {
    //         lli tot = 0;
    //         frange(i, n)
    //         {
    //             if (avec[i] >= e1)
    //             {
    //                 tot += e1;
    //             }
    //             else if (bvec[i] >= e2)
    //             {
    //                 tot += e2;
    //             }
    //         }
    //         ma = max(ma, tot);
    //     }
    // }
    // printf("%lld", ma);
    // st 4
    // sort(all(avec), greater<lli>());
    // lli ma = 0;
    // forr(i, 1, n + 1)
    // {
    //     ma = max(ma, avec[i - 1] * i);
    // }
    // printf("%lld", ma);
    sort(all(avec), greater<lli>());
    vll fvec(n + 2);
    forr(i, 1, n + 1)
    {
        fvec[i] = max(fvec[i - 1], avec[i - 1] * i);
    }
    vll rvec(n + 2);
    for (int i = n; i >= 1; i--)
    {
        rvec[i] = max(rvec[i + 1], avec[i - 1] * (n - i + 1));
    }
    lli ma = fvec[1];
    forr(i, 1, n)
    {
        ma = max(ma, rvec[i + 1] + fvec[i]);
    }
    for (auto e : fvec)
        printf("%lld ", e);
    printf("\n");
    for (auto e : rvec)
        printf("%lld ", e);
    printf("\n");
    printf("%lld", ma);
}