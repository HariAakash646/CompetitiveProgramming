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
typedef pair<int, pii> piii;

int main()
{
    int n;
    scd(n);
    map<int, lli> row;
    map<int, lli> col;
    map<pii, int> val;
    frange(i, n)
    {
        int r, c, x;
        scd(r);
        scd(c);
        scd(x);
        val[{r, c}] = x;
        row[r] += x;
        col[c] += x;
    }
    vector<pair<lli, int>> colv;
    for (auto p : col)
    {
        colv.pb(mp(p.s, p.f));
    }
    sort(all(colv), greater<>());
    lli ma = 0;
    for (auto p : row)
    {
        lli x = p.s;
        for (auto e : colv)
        {
            ma = max(ma, x + e.f - val[{p.f, e.s}]);
            if (!val[{p.f, e.s}])
                break;
        }
    }
    printf("%lld", ma);
}