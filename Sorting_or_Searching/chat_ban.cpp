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

lli x, k;

bool check(lli n)
{
    lli tot = 0;
    if (n > k)
    {
        tot += (k * (k + 1)) / 2;
        n -= k;
        tot += (((k - 1) * k) / 2) - (((k - 1 - n) * (k - n)) / 2);
    }
    else
    {
        tot += n * (n + 1) / 2;
    }
    return tot < x;
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        sclld(k);
        sclld(x);
        lli h = 2 * k - 1;
        lli l = 0;
        while (l != h)
        {
            lli mid = (l + h + 1) / 2;
            if (check(mid))
            {
                l = mid;
            }
            else
            {
                h = mid - 1;
            }
        }
        lli n = l + 1;
        lli tot = 0;

        printf("%lld\n", min(2 * k - 1, n));
    }
}