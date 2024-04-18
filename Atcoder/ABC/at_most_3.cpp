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
    int w;
    scd(w);
    seti t1, t2, t3;

    forr(i, 1, w + 1)
    {
        if (t3.find(i) == t3.end())
        {
            if (t2.find(i) == t2.end())
            {
                if (t1.find(i) == t1.end())
                {
                    for (auto e : t2)
                        if (e + i <= 1e6)
                            t3.insert(e + i);
                    for (auto e : t1)
                        if (e + i <= 1e6)
                            t2.insert(e + i);
                    t1.insert(i);
                }
            }
        }
    }
    printf("%d\n", t1.size());
    for (auto e : t1)
        printf("%d ", e);
}