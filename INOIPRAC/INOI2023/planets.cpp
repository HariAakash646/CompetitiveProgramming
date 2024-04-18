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

lli inf = 1e18;

int main()
{
    int n, k;
    scd(n);
    scd(k);
    vll vec(n + 1), wgt(n + 1);

    frange(i, n) sclld(vec[i + 1]);
    frange(i, n) sclld(wgt[i + 1]);

    vector<vll> dp(n + 1, vll(k + 1, inf)), mdp(n + 1, vll(n + 1));
    vll pref(n + 1);

    forr(i, 1, n + 1) mdp[i][i] = wgt[i];
    forr(i, 1, n + 1)
    {
        for (int j = 1; j + i <= n; j++)
        {
            mdp[j][i + j] = max(mdp[j + 1][i + j], mdp[j][i + j - 1]);
        }
    }
    forr(i, 1, n + 1) pref[i] = pref[i - 1] + vec[i];
    dp[0][0] = 0;
    forr(i, 1, n + 1)
    {
        dp[i][0] = pref[i] * mdp[1][i];
    }
    forr(i, 1, n + 1)
    {
        forr(j, 1, k + 1)
        {
            frange(l, i)
            {
                dp[i][j] = min(dp[i][j], dp[l][j - 1] + (pref[i] - pref[l]) * mdp[l + 1][i]);
            }
        }
    }
    printf("%lld", dp[n][k]);
}