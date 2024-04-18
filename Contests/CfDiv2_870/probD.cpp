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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
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
        int n;
        scd(n);
        vi vec(n);
        set<pii> st, st2;
        frange(i, n)
        {
            scd(vec[i]);
            st.insert({vec[i] - i, i});
            st2.insert({vec[i], i});
        }
        int ma = 0;
        frange(i, n - 2)
        {
            st.erase({vec[i] - i, i});
            st2.erase({vec[i], i});
            auto it = prev(st.end());
            auto it1 = prev(st2.end());
            int v1 = vec[i] + ((*it).f + (*it).s) + ((*prev(it)).f + (*prev(it)).s) - (max((*it).s, (*prev(it)).s) - i);
            int v2 = vec[i] + ((*it1).f) + ((*prev(it1)).f) - (max((*it1).s, (*prev(it1)).s) - i);
            int v3;
            if v3
                = vec[i] + ((*it).f + (*it).s) + ((*(it1)).f) - (max((*it).s, (*(it1)).s) - i);
            ma = max(ma, v);
        }
        printf("%d\n", ma);
    }
}