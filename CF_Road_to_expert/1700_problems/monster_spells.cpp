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

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vll sec(n + 1);
        vll hea(n + 1);
        forr(i, 1, n + 1)
        {
            sclld(sec[i]);
        }
        forr(i, 1, n + 1)
        {
            sclld(hea[i]);
        }
        lli tot = 0;
        lli prev = 0;
        set<pair<lli, int>> curr;
        set<pair<lli, int>> avail;
        forr(i, 1, n + 1)
        {
            curr.insert({sec[i] - hea[i] + 1, i});
        }
        lli st = (*curr.begin()).f;
        int idx = (*curr.begin()).s;
        curr.erase(curr.begin());
        avail.insert({st, idx});
        map<lli, lli> stend;
        forr(i, 1, n + 1)
        {
            // printf("%lld ", st);
            lli ti = sec[i];
            stend[st] = ti;
            for (auto itr = curr.begin(); itr != curr.end();)
            {

                auto tmp = itr;
                itr++;
                if ((*tmp).s <= i)
                {
                    curr.erase(tmp);
                }
            }
            if (i == idx)
            {
                tot += (ti - st + 1) * (ti -st + 2)/2;
                st = (*curr.begin()).f;
                idx = (*curr.begin()).s;
                while()
            }
        }
        // for (auto p : stend)
        // {
        //     tot += (p.s - p.f + 1) * (p.s - p.f + 2) / 2;
        // }
        printf("%lld\n", tot);
    }
}