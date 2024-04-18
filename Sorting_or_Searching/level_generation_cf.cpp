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

lli n;

bool check(lli x)
{
    return x * (x - 1) / 2 <= n - x;
}

int main()
{
    int q;
    scd(q);
    frange(_, q)
    {
        sclld(n);
        lli hi = n;
        lli lo = 1;
        while (hi != lo)
        {
            lli mid = (hi + lo + 1) / 2;
            if (check(mid))
            {
                lo = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }
        lli v1 = lo * (lo - 1) / 2;
        lli v2 = n - lo;
        if (v1 + 1 <= v2 - 1)
        {
            v1++;
            v2--;
            printf("%lld\n", v1 + v2 + max(0LL, (v2 - v1)));
        }
        else
            printf("%lld\n", v1 + v2);
    }
}