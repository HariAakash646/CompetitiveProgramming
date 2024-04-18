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

int main()
{
    int a, b;
    scd(a);
    scd(b);
    int n = 0;
    if (a < b)
        swap(a, b);
    vvi dp(b + 1, vi(a + 1, 0));
    forr(i, 1, b + 1)
    {
        forr(j, 1, a + 1)
        {
            int m = 1e9 + 10;
            if (i == j)
            {
                dp[i][j] = 0;
                continue;
            }
            forr(k, 1, j)
            {
                m = min(dp[i][k] + dp[i][j - k] + 1, m);
            }
            forr(k, 1, i)
            {
                m = min(dp[k][j] + dp[i - k][j] + 1, m);
            }
            dp[i][j] = m;
        }
    }
    printf("%d", dp[b][a]);
}