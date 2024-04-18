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

int n;
lli k;
vll vec;

bool check(lli x)
{
    lli tot = 0;
    lli c1 = 1;
    lli c2 = 1;
    int i1 = 0;
    int i2 = n - 1;
    while (true)
    {
        if (vec[i2] - vec[i1] <= x)
        {
            break;
        }
        if (c1 <= c2)
        {
            tot += min(vec[i1 + 1] - vec[i1], (vec[i2] - vec[i1]) - x) * c1;
            c1++;
            i1++;
        }
        else
        {
            tot += min(vec[i2] - vec[i2 - 1], (vec[i2] - vec[i1]) - x) * c2;
            c2++;
            i2--;
        }
    }
    return tot <= k;
}

int main()
{
    scd(n);
    sclld(k);
    vec = vll(n);
    frange(i, n) sclld(vec[i]);
    sort(all(vec));
    lli hi = 1e9;
    lli lo = 0;
    while (hi != lo)
    {
        lli mid = (hi + lo) / 2;
        if (check(mid))
        {
            hi = mid;
        }
        else
            lo = mid + 1;
    }
    printf("%lld", lo);
}