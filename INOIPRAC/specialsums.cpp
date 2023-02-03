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
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int main()
{
    int n;
    scd(n);
    vll vecb(n + 1);
    vll veca(n + 1);
    vll pref(n + 1);
    frange(i, n)
    {
        sclld(veca[i + 1]);
    }
    frange(i, n)
    {
        sclld(vecb[i + 1]);
    }
    forr(i, 1, n + 1)
    {
        pref[i] = pref[i - 1] + vecb[i];
    }
    lli m = -1e15;
    lli curr = 0;
    // forr(i, 1, n + 1)
    // {
    //     forr(j, 1, n + 1)
    //     {
    //         curr = veca[i] + veca[j];
    //         if (i < j)
    //         {
    //             curr += pref[j - 1] - pref[i];
    //         }
    //         else if (i > j)
    //         {
    //             curr += pref[n] - pref[i];
    //             curr += pref[j - 1];
    //         }
    //         else
    //             curr -= veca[i];
    //         m = max(curr, m);
    //     }
    // }
    int mi1 = min_element(all(pref)) - pref.begin();
    int ma1 = max_element(all(pref)) - pref.begin();
    lli out;
    if (mi1 > ma1)
    {
        out = pref[n] - pref[mi1] + pref[ma1];
    }
    else if (mi1 < ma1)
    {
        out = pref[ma1] - pref[mi1];
    }
    else
    {
        out = vecb[ma1];
    }
    printf("%lld", out);
}