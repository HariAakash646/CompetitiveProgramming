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

vector<pair<pii, lli>> vec;

bool check(int x)
{
    vll dp(n + 1);
    forr(i, 1, n + 1)
    {
        auto it = upper_bound(all(vec), mp(mp(vec[i].f.s - x, int(1e9 + 10)), lli(1e18)));
        lli v = 0;
        if (it != vec.begin())
        {
            it--;
            v = dp[it - vec.begin()];
        }
        dp[i] = max(dp[i - 1], v + vec[i].s);
    }
    return dp[n] >= k;
}

int main()
{

    scd(n);
    sclld(k);
    vec = vector<pair<pii, lli>>(n + 1);
    vec[0] = mp(mp(-1e9, -1e9), 0);

    forr(i, 1, n + 1)
    {
        scd(vec[i].f.s);
        scd(vec[i].f.f);
        sclld(vec[i].s);
    }
    sort(all(vec));
    int lo = 0;
    int hi = 1e9;
    while (lo != hi)
    {
        int mid = (lo + hi + 1) / 2;
        if (check(mid))
        {
            lo = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }
    if (check(lo))
        printf("%d\n", lo);
    else
        printf("-1");
}