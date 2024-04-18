// Incomplete
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

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n, k;
        scd(n);
        scd(k);

        vll left(k + 1);
        vector<pair<lli, lli>> lefd(k + 1);
        vll lefma(k + 1);
        for (int i = k - 1; i >= 1; i--)
        {
            sclld(left[i]);
        }
        forr(i, 1, k)
        {
            lefd[i].s = lefd[i - 1].s + left[i];
            lefma[i] = max(lefd[i].s, lefma[i - 1]);
            lefd[i].f = max(lefd[i - 1].s - left[i], lefd[i - 1].f);
        }
        lli ak;
        sclld(ak);
        vll right(n - k + 1);
        vector<pair<lli, lli>> rigd(n - k + 1);
        vll rigma(n - k + 1);
        forr(i, 1, n - k + 1)
        {
            sclld(right[i]);
            rigd[i].s = rigd[i - 1].s + right[i];
            rigma[i] = max(rigd[i].s, rigma[i - 1]);
            rigd[i].f = max(rigd[i].s - right[i], rigd[i - 1].f);
        }
        lli tot = ak;
        lli rig = 0;
        lli lef = 0;
        frange(i, 2 * n)
        {
            if (i % 2 ==)
        }
    }
}