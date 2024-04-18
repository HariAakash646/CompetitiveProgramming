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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define PB push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
    int n;
    scd(n);
    vi vec(n);
    vi odd;
    vi even;
    frange(i, n)
    {
        scd(vec[i]);
        if (vec[i] % 2 == 0)
            even.PB(vec[i]);
        else
            odd.PB(vec[i]);
    }
    auto eitr = even.begin();
    auto oitr = odd.begin();
    int l = 0;
    while (true)
    {
        if (l % 2 == 0)
        {
            if (eitr != even.end())
            {
                l++;
                eitr++;
            }
            else if (oitr != odd.end() && oitr != odd.end() - 1)
            {
                l++;
                oitr++;
                oitr++;
            }
            else if (oitr == odd.end() - 1)
            {
                l--;
                break;
            }
            else
                break;
        }
        else
        {
            if (oitr != odd.end())
            {
                l++;
                oitr++;
            }
            else
                break;
        }
    }
    printf("%d", l);
}