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
#define f first
#define s second
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
        set<pii> st;
        forr(i, 1, n + 1)
        {
            int a;
            scd(a);
            st.insert({a, i});
        }
        vi diff(n + 1);
        seti pos;
        int tot = 0;
        while (st.size())
        {
            auto p1 = *st.begin();
            auto p2 = *prev(st.end());
            if (p1 == p2)
                break;
            bool o1 = false;
            bool o2 = false;
            int d = 0;
            if (pos.upper_bound(p1.s) != pos.begin())
                d = diff[*prev(pos.upper_bound(p1.s))];
            if (p1.s - d != 1)
            {
                o1 = true;
            }
            if (p2.s < p2.f)
            {
                o2 = true;
            }
            diff[p1.s] += 1;
            diff[p2.s] += 1;
            pos.insert(p1.s);
            pos.insert(p2.s);
            if (o1 || o2)
                tot++;
            st.erase(st.begin());
            st.erase(prev(st.end()));
        }
        printf("%d\n", tot);
    }
}