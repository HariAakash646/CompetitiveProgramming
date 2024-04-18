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

    freopen("248.in", "r", stdin);
    freopen("248.out", "w", stdout);
    int n;
    scd(n);
    vi vec(n);
    frange(i, n) scd(vec[i]);

    vvi dp(n, vi(n, -1));
    int ma = 0;
    frange(i, n)
    {
        dp[i][i] = vec[i];
        ma = max(ma, dp[i][i]);
    }

    forr(k, 1, n)
    {
        for (int l = 0; l + k < n; l++)
        {
            int r = l + k;
            forr(rr, l, r)
            {
                if (dp[l][rr] != -1 && dp[l][rr] == dp[rr + 1][r])
                {
                    dp[l][r] = max(dp[l][r], dp[l][rr] + 1);
                }
            }
            ma = max(ma, dp[l][r]);
        }
    }
    printf("%d", ma);
}