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
    int t;
    scd(t);
    frange(_, t)
    {
        int n, m;
        scd(n);
        scd(m);
        seti st;
        int ty1 = 0;
        int ty2 = 0;
        frange(i, n)
        {
            int a;
            scd(a);
            if (a == -1)
                ty2++;
            else if (a == -2)
                ty1++;
            else
                st.insert(a);
        }
        int ma = min(m, max(ty1, ty2) + int(st.size()));
        int x = st.size();
        int x1 = x - 1;
        // st.insert(0);
        // st.insert(m + 1);
        for (auto e : st)
        {
            int v1 = min(ty1, m - e);
            int v2 = min(ty2, e - 1);
            int tot = (v1 + v2) + min(((m - e) - v1), x1) + min((e - 1) - v2, x - (x1 + 1)) + 1;
            tot = min(m, tot);
            // printf("%d %d %d %d %d\n", e, min(((m - e) - v1), x1), min((e - 1) - v2, x - (x1 + 1)), (v1 + v2), tot);
            ma = max(ma, tot);
            --x1;
        }
        printf("%d\n", ma);
    }
}