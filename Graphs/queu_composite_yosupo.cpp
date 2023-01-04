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
#define mp make_pair
#define pb push_back
#define f first
#define s second

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

int mod = 998244353;

int main()
{
    int q;
    scd(q);
    deque<pii> func;
    int m;
    frange(i, q)
    {
        scd(m);
        if (m == 0)
        {
            int a, b;
            scd(a);
            scd(b);
            func.pb(pii{a, b});
        }
        else if (m == 1)
        {
            func.pop_front();
        }
        else
        {
            int x;
            scd(x);
            if (func.size() == 0)
            {
                printf("%d\n", x);
            }
            else
            {
                for (auto p : func)
                {

                    x = (((p.f * x) % mod) + p.s) % mod;
                }
                printf("%d\n", x);
            }
        }
    }
    return 0;
}