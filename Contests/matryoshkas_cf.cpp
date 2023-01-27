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
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vector<lli> vec(n);
        frange(i, n)
        {
            sclld(vec[i]);
        }
        sort(all(vec));
        auto itr = vec.begin();
        lli tot = 0;
        lli curr = 0;
        lli prev = 0;
        while (itr != vec.end())
        {
            auto itr2 = upper_bound(all(vec), *itr);
            if (*itr == prev + 1)
            {
                lli dif = (itr2 - itr) - curr;
                tot += max(0LL, dif);
                curr = itr2 - itr;
                prev = *itr;
                itr = itr2;
            }
            else
            {
                tot += (itr2 - itr);
                curr = itr2 - itr;
                prev = *itr;
                itr = itr2;
            }
        }
        printf("%lld\n", tot);
    }
}