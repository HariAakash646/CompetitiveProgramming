#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
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
    int n, a;
    scd(n);
    scd(a);

    vi cnt(n + 1);

    set<pii> st;
    frange(i, n)
    {
        int x;
        scd(x);
        st.insert({x, 0});
    }

    set<pii> dif;
    for (auto it = st.begin(); it != prev(st.end()); it++)
    {
        dif.insert(mp((*next(it)).f - (*it).f, (*it).f));
    }

    int c = st.size();
    while (st.size() > 1)
    {
        auto it = dif.begin();
        int v = (*it).s;
        auto it1 = st.lower_bound({v, 0});
        pii p = *it1;
        int d = (*it).f;
        dif.erase(it);
        auto p1 = *next(it1);
        st.erase(next(it1));
        it1 = st.find(p);
        if (it1 != prev(st.end()))
        {
            dif.insert(mp((*next(it1)).s + (*next(it1)).f - (*it1).f, (*it1).f));
        }
        st.erase(p);
        st.insert(mp(p.f, d));
        cnt[st.size()] = d;
    }

    int q;
    scd(q);

    frange(_, q)
    {
        int x;
        scd(x);
        printf("%d\n", cnt[x]);
    }
}