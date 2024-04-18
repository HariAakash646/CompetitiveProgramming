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
    vi vec(n);
    frange(i, n) scd(vec[i]);
    vvi dp(n, vi(n, 1));

    forr(i, 1, n)
    {
        for (int j = 0; j + i < n; j++)
        {
            dp[j][j + i] = min(dp[j + 1][j + i], dp[j][j + i - 1]) + 1;
            forr(k, 1, i)
            {
                dp[j][j + i] = min(dp[j][j + i], dp[j][j + k] + dp[j + k + 1][j + i]);
            }
            if (vec[j] == vec[j + i] && dp[j + 1][j + i - 1] == 1)
            {
                dp[j][j + i] = 1;
            }
        }
    }
    printf("%d", dp[0][n - 1]);
}