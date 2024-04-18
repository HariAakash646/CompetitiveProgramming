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
    int q;
    scd(q);
    map<lli, lli> val;
    map<lli, lli> pref;
    val[0] = 0;
    pref[0] = 0;
    lli curr = 0;
    frange(_, q)
    {
        int t;
        scd(t);
        if (t == 1)
        {
            lli x;
            lli c;
            sclld(x);
            sclld(c);
            pair<lli, lli> p = *prev(val.end());
            lli pre = p.f;
            val[pre + c] = x;
            pref[pre + c] = pref[pre] + c * x;
        }
        else
        {
            lli c;
            sclld(c);
            auto it = val.upper_bound(curr);
            lli sub = (*prev(pref.upper_bound(curr))).s + (*(it)).s * (curr - (*prev(it)).f);
            curr += c;
            auto it1 = val.upper_bound(curr);
            lli add = (*prev(pref.upper_bound(curr))).s + (*it1).s * (curr - (*prev(it1)).f);

            printf("%lld\n", add - sub);
        }
    }
}