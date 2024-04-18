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

bool cmp(pii a, pii b)
{
    return min(a.f, a.s) > min(b.f, b.s);
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vii vec(n);
        frange(i, n)
        {
            scd(vec[i].f);
            scd(vec[i].s);
        }
        sort(all(vec), cmp);
        vi st;
        for (auto p : vec)
        {
            if (max(p.f, p.s) >= min(vec[0].f, vec[0].s))
            {
                st.pb(max(p.f, p.s));
            }
        }
        sort(all(st));
        int mi = 1e9;
        // for (auto it = st.begin(); it != prev(st.end()); it++)
        // {
        //     mi = min(mi, *next(it) - *it);
        // }
        frange(i, st.size() - 1)
        {
            mi = min(mi, st[i + 1] - st[i]);
        }
        if (n >= 2)
        {
            mi = min(mi, min(vec[0].f, vec[0].s) - min(vec[1].f, vec[1].s));
            mi = min(mi, abs(min(vec[0].f, vec[0].s) - max(vec[1].f, vec[1].s)));
            mi = min(mi, abs(max(vec[0].f, vec[0].s) - max(vec[1].f, vec[1].s)));
        }
        st = {};
        for (auto p : vec)
        {
            if (max(p.f, p.s) >= min(vec[1].f, vec[1].s))
            {
                st.pb(max(p.f, p.s));
            }
        }
        st.erase(find(all(st), max(vec[0].f, vec[0].s)));
        sort(all(st));
        auto it = upper_bound(all(st), min(vec[0].f, vec[0].s));
        if (it != st.end())
            mi = min(mi, *it - min(vec[0].f, vec[0].s));
        if (it != st.begin())
            mi = min(mi, min(vec[0].f, vec[0].s) - *prev(it));
        printf("%d\n", mi);
    }
}