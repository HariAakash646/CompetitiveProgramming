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

lli mod = 998244353;

lli powf(lli x, lli k)
{
    lli v = 1;
    forr(i, 1, k + 1) v = (v * x) % mod;
    return v;
}

int main()
{
    lli n, m;
    sclld(n);
    sclld(m);

    vector<pair<lli, lli>> dp(n);
    dp[0].f = m;
    forr(i, 1, n)
    {
        dp[i].f = dp[i - 1].s;
        dp[i].s = (dp[i - 1].f * (m - 1) + dp[i - 1].s * (m - 2)) % mod;
    }

    printf("%lld", dp[n - 1].s);
}