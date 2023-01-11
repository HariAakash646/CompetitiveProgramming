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
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int mod = 1e9 + 7;

int main()
{
    int n, m;
    scd(n);
    scd(m);
    vi vec(n);
    frange(i, n) scd(vec[i]);
    vector<vector<lli>> dp(n + 2, vector<lli>(m + 2, 0));
    forr(i, 1, n + 1)
    {
        int idx = vec[i - 1];
        if (idx != 0)
        {
            dp[i][idx] = (dp[i - 1][idx] + dp[i - 1][idx - 1] + dp[i - 1][idx + 1]) % mod;
            if (i == 1)
                dp[i][idx] = 1;
            continue;
        }
        forr(j, 1, m + 1)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
            if (i == 1)
                dp[i][j] = 1;
        }
    }
    int tot = 0;
    for (int e : dp[n])
    {
        tot = (tot + e) % mod;
    }
    printf("%d", tot);
}