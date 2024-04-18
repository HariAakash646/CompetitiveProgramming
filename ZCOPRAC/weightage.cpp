#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
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
    int n, p;
    scd(n);
    scd(p);

    vii vec(n);
    frange(i, n)
    {
        scd(vec[i].f);
        scd(vec[i].s);
    }

    int c = 0;
    vi out;
    frange(i, n)
    {
        ld ma = 0;
        ld mi = 100;
        pii p = vec[i];
        frange(j, n)
        {
            pii p2 = vec[j];
            ld num = (p2.s - p.s) * 100;
            ld den = (p.f - p2.s + p2.s - p.s);
            if (den == 0)
                continue;
            if (p.s <= p2.s)
            {
                ma = max(ma, num / den);
            }
            else
            {
                mi = min(mi, num / den);
            }
            cout << i << " " << j << " " << num / den << "\n";
        }
        if (ma <= mi)
            out.pb(i + 1);
    }
    printf("%d\n", out.size());
    for (auto e : out)
        printf("%d ", e);
}