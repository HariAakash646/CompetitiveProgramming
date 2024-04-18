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

int main()
{
    int n, k;
    scd(n);
    scd(k);
    vi brak(n + 1);
    vll val(n + 1);
    forr(i, 1, n + 1) sclld(val[i]);
    forr(i, 1, n + 1)
    {
        scd(brak[i]);
    }
    vector<vll> dp(n + 1, vll(n + 1));
    forr(l, 1, n + 1)
    {
        for (int i = 1; i + l <= n; i++)
        {
            int j = i + l;
            if (brak[i] == brak[j] - k)
            {
                dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + val[i] + val[j]);
            }
            forr(k, i, j)
            {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }
    printf("%lld", dp[1][n]);
}