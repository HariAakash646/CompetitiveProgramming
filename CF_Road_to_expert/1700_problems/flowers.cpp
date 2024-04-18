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

lli mod = 1e9 + 7;

int main()
{
    int t, k;
    scd(t);
    scd(k);
    vll dp(1e5 + 1);
    dp[0] = 1;
    forr(i, 1, 1e5 + 1)
    {
        dp[i] = dp[i - 1];
        if (i >= k)
        {
            dp[i] += dp[i - k];
        }
        dp[i] %= mod;
    }
    vll pref(1e5 + 1);
    pref[0] = dp[0];
    forr(i, 1, 1e5 + 1)
    {
        pref[i] = pref[i - 1] + dp[i];
        pref[i] %= mod;
    }
    frange(_, t)
    {
        int a, b;
        scd(a);
        scd(b);
        printf("%lld\n", (pref[b] - pref[a - 1] + mod) % mod);
    }
}