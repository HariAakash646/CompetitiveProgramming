// Hard Implementation code. Work out if bored. Ad Hoc.
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
#define MP make_pair
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
    string str;
    cin >> str;
    int cb = 0;
    int cs = 0;
    int cc = 0;
    for (auto e : str)
    {
        if (e == 'B')
            cb++;
        else if (e == 'S')
            cs++;
        else if (e == 'C')
            cc++;
    }
    int nb, nc, ns;
    cin >> nb >> ns >> nc;
    int pb1, ps, pc;
    cin >> pb1 >> ps >> pc;
    int c = min(nb / cb, ns / cs, nc / cc);
    nb -= c * cb;
    ns -= c * cs;
    nc -= c * cc;
    int r;
    cin >> r;
    vi tmp = {nb / cb, ns / cs, nc / cc};
    sort(tmp, greater<int>());
    int p = pb1 * cb + ps * cs + pc * cc;
    int r1 = (p - ps * cs - pb1 * cb)
}