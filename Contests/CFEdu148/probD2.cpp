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
    int n, q;
    scd(n);
    scd(q);
    vll vec(n);
    frange(i, n)
    {
        sclld(vec[i]);
    }
    sort(all(vec));
    vll v1 = vec;
    lli mi = vec[0];
    int mid = 0;
    frange(i, n)
    {
        if (vec[i] == mi)
            mid = i;
        else
            break;
    }
    lli diff = 0;
    forr(i, mid + 1, n)
    {
        diff += vec[i] - vec[mid];
    }
    frange(i, q)
    {
        lli k;
        sclld(k);
        lli v = mi + (k - mid);
        if (k < n)
        {
            printf("%lld ", min(vec[k], mi + (k - mid)));
        }

        else
        {
            k -= (n - 1);

            k -= 2 * (((mid * (mid + 1)) / 2) - ((n - mid) * (n - mid - 1)) / 2 + diff);
            if (k > 0)
            {
                printf("%lld ", v - ((k + n - 1) / n));
            }
            else
                printf("%lld ", v);
        }
    }
}