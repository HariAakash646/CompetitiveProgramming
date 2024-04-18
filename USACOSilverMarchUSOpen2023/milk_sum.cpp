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
    int n;
    scd(n);
    vll vec(n + 1);
    vll pos(n + 1);
    frange(i, n)
    {
        sclld(vec[i + 1]);
        pos[i + 1] = vec[i + 1];
    }
    sort(all(vec));
    vll pref(n + 1);
    forr(i, 1, n + 1)
    {
        pref[i] = pref[i - 1] + vec[i];
    }
    lli tot = 0;
    forr(i, 1, n + 1)
    {
        tot += i * vec[i];
    }
    lli tmptot = tot;
    int q;
    scd(q);
    frange(_, q)
    {
        int i, j;
        scd(i);
        scd(j);
        lli a = pos[i];
        auto it = lower_bound(all(vec), a);
        tot -= (it - vec.begin()) * a;
        tot -= pref[n] - pref[it - vec.begin()];
        auto it2 = upper_bound(all(vec), j);
        if (it < it2)
            tot -= j;
        tot += j * (it2 - vec.begin());
        tot += pref[n] - pref[it2 - vec.begin() - 1];
        if (it >= it2)
            tot -= a;
        printf("%lld\n", tot);
        tot = tmptot;
    }
}