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
    int n, mod;
    scd(n);
    scd(mod);
    seti s1, s2;
    vi v1((n + 1) / 2), v2(n / 2);
    frange(i, (n + 1) / 2) scd(v1[i]);
    frange(i, n / 2) scd(v2[i]);
    frange(i, 1 << ((n + 1) / 2))
    {
        int v = 0;
        frange(j, (n + 1) / 2)
        {
            if (i & (1 << j))
                v = (v + v1[j]) % mod;
        }
        s1.insert(v);
    }
    frange(i, 1 << (n / 2))
    {
        int v = 0;
        frange(j, n / 2)
        {
            if (i & (1 << j))
                v = (v + v2[j]) % mod;
        }
        s2.insert(v);
    }
    int ma = 0;
    for (auto e : s1)
    {
        auto it = prev(s2.lower_bound(mod - e));
        ma = max(ma, e + *it);
    }
    printf("%d", ma);
}