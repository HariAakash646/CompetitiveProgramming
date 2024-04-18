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
    int n, x, y;
    scd(n);
    scd(x);
    scd(y);
    vii con(n);
    frange(i, n)
    {
        scd(con[i].f);
        scd(con[i].s);
    }

    vi v1(x), v2(y);
    frange(i, x) scd(v1[i]);
    frange(i, y) scd(v2[i]);
    sort(all(v1));
    sort(all(v2));

    int mi = 1e9;

    for (auto p : con)
    {
        auto it1 = upper_bound(all(v1), p.f);
        auto it2 = lower_bound(all(v2), p.s);

        if (it1 == v1.begin() || it2 == v2.end())
            continue;

        --it1;
        mi = min(mi, *it2 - *it1 + 1);
    }
    printf("%d", mi);
}