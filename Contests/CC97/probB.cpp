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
        lli n;
        int q;
        sclld(n);
        scd(q);
        vi vec(n);
        frange(i, n)
        {
            scd(vec[i]);
        }
        sort(all(vec));
        vll pref(n);
        pref[0] = (n - 1) * (n - 2) / 2;
        forr(i, 1, n)
        {
            pref[i] = pref[i - 1] + (n - 1 - i) * (n - 2 - i) / 2;
        }
        frange(_, q)
        {
            lli id;
            sclld(id);
            int it = lower_bound(all(pref), id) - pref.begin();
            printf("%d\n", vec[it]);
        }
    }
}