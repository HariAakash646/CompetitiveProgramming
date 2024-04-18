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
    int n;
    scd(n);
    vector<pair<pii, lli>> vec(n);
    frange(i, n)
    {
        scd(vec[i].f.s);
        scd(vec[i].f.f);
        sclld(vec[i].s);
    }
    sort(all(vec));
    vll dp(n);
    frange(i, n)
    {
        if (i > 0)
            dp[i] = dp[i - 1];
        auto it = lower_bound(all(vec), mp(mp(vec[i].f.s, 0), 0LL));
        if (it != vec.begin())
        {
            it--;
            dp[i] = max(dp[i], dp[it - vec.begin()] + vec[i].s);
        }
        else
            dp[i] = max(dp[i], vec[i].s);
    }
    printf("%lld", dp[n - 1]);
}