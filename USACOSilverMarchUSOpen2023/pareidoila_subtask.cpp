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
    string str;
    cin >> str;
    int n = str.size();
    vi vec(n, -1);
    vector<seti> posv(5);
    seti st;
    frange(i, n)
    {
        char e = str[i];
        if (e == 'b')
        {
            posv[0].insert(i);
        }
        if (e == 'e')
        {
            st = posv[0];
            for (auto l : st)
            {
                posv[1].insert(l);
                posv[0].erase(l);
            }
            st = posv[4];
            for (auto l : st)
            {
                vec[l] = i;
                posv[4].erase(l);
            }
        }
        if (e == 's')
        {
            st = posv[1];
            for (auto l : st)
            {
                posv[2].insert(l);
                posv[1].erase(l);
            }
            st = posv[2];
            for (auto l : st)
            {
                posv[3].insert(l);
                posv[2].erase(l);
            }
        }
        if (e == 'i')
        {
            st = posv[3];
            for (auto l : st)
            {
                posv[4].insert(l);
                posv[3].erase(l);
            }
        }
    }
    vii bes;
    frange(i, n)
    {
        if (vec[i] != -1)
        {
            // printf("%d %d\n", i, vec[i]);
            bes.pb({i, vec[i]});
        }
    }
    lli tot = 0;
    for (auto p : bes)
    {
        tot += lli(p.f + 1) * lli(n - p.s);
        // printf("%d\n", (p.f + 1) * (n - p.s));
    }
    sort(all(bes));
    frange(i, bes.size())
    {
        auto p = bes[i];
        auto it = upper_bound(all(bes), mp(p.s, 0));
        int id = it - bes.begin();
        forr(j, i + 1, id)
        {
            auto k = bes[j];
            tot -= lli(min(p.f, k.f) + 1) * lli(n - max(p.s, k.s));
            // printf("-%d\n", (min(p.f, k.f) + 1) * (n - max(p.s, k.s)));
        }
    }
    printf("%lld", tot);
}