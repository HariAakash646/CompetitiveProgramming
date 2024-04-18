#include <bits/stdc++.h>

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
typedef long double ld;

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vii vec(n);
        mseti sec;
        frange(i, n)
        {
            scd(vec[i].f);
            scd(vec[i].s);
            sec.insert(vec[i].s);
        }
        sort(all(vec));

        int mi = 1e9;
        mseti oth;
        frange(i, n)
        {
            auto p = vec[i];
            if (sec.find(p.s) == sec.end())
            {
                printf("%d %d", p.f, p.s);
                break;
            }
            sec.erase(sec.find(p.s));
            int val;
            if (i == n - 1)
                val = 0;
            else
                val = *prev(sec.end());
            if (i != 0)
            {
                auto it = oth.lower_bound(p.f);
                int x1 = -1e9;
                int x2 = -1e9;
                if (it != oth.end())
                    x1 = *it;
                if (it != oth.begin())
                {
                    it--;
                    x2 = *it;
                }

                if (x1 >= val)
                {
                    mi = min(mi, abs(p.f - x1));
                }
                if (x2 >= val)
                {
                    mi = min(mi, abs(p.f - x2));
                }
            }
            if (i != n - 1)
                mi = min(mi, abs(p.f - val));
            oth.insert(p.s);
        }
        // int v = *prev(val.end());
        // int mi = abs(v - *prev(prev(val.end())));
        // auto itr = rem.lower_bound(v);
        // mi = min(mi, abs(v - *itr));
        // if (itr != rem.begin())
        // {
        //     itr--;
        //     mi = min(mi, abs(v - *itr));
        // }
        // for (auto it = rem.begin(); it != prev(rem.end()); it++)
        // {
        //     mi = min(mi, abs(*it - *next(it)));
        // }
        printf("%d\n", mi);
    }
}