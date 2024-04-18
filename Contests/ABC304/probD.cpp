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
    int w, h;
    scd(w);
    scd(h);
    int n;
    scd(n);
    vii vec(n);
    frange(i, n)
    {
        scd(vec[i].f);
        scd(vec[i].s);
    }
    int a;
    scd(a);
    vi veca(a + 2);
    frange(i, a) scd(veca[i + 1]);
    veca[a + 1] = w;
    int b;
    scd(b);
    vi vecb(b + 2);
    frange(i, b) scd(vecb[i + 1]);
    vecb[b + 1] = h;
    map<pii, int> cnt;
    for (auto p : vec)
    {
        int x = upper_bound(all(veca), p.f) - veca.begin();
        int y = upper_bound(all(vecb), p.s) - vecb.begin();
        cnt[{x, y}]++;
    }
    int c = 0;
    int ma = 0;
    int mi = 1e9;
    for (auto p : cnt)
    {
        c++;
        ma = max(ma, p.s);
        mi = min(mi, p.s);
    }
    if (c < lli(a + 1) * lli(b + 1))
        mi = 0;
    printf("%d %d", mi, ma);
}