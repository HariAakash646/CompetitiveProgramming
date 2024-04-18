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
    int n, k;
    scd(n);
    scd(k);
    vector<pair<pii, int>> vec(n + 1);
    vec[0] = (mp(mp(-1e9, -1e9), 0));
    forr(i, 1, n + 1)
    {
        scd(vec[i].f.s);
        scd(vec[i].f.f);
        scd(vec[i].s);
    }
    sort(all(vec));

    vvi dp(n + 1, vi(k + 1, -1));

    forr(i, 0, n + 1)
    {
        dp[i][0] = 1e9;
    }

    forr(i, 1, n + 1)
    {
        forr(j, 1, k + 1)
        {
            dp[i][j] = dp[i - 1][j];
            forr(l, 0, i)
            {
                dp[i][j] = max(dp[i][j], min(dp[l][max(0, j - vec[i].s)], vec[i].f.s - vec[l].f.f));
            }
        }
        for (int j = k - 1; j >= 0; j--)
        {
            dp[i][j] = max(dp[i][j], dp[i][j + 1]);
        }
    }
    int inf = 1e9;
    if (dp[n][k] >= inf)
        printf("%d", inf);
    else if (dp[n][k] < 0)
        printf("-1");
    else
        printf("%d", dp[n][k]);
}