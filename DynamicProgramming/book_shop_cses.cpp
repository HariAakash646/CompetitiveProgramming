// TLE for some reason. Time complexity is fine.

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
#define frange(i, j) forr(i, 0, j, 1)
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
    int n, x;
    scd(n);
    scd(x);
    vi price(n + 1);
    vi page(n + 1);
    forr(i, 1, n + 1)
    {
        scd(price[i]);
    }
    forr(i, 1, n + 1)
    {
        scd(page[i]);
    }
    vvi dp(x + 1, vi(n + 1, 0));
    forr(i, 1, x + 1)
    {
        forr(j, 1, n + 1)
        {
            int p = price[j];
            if (i - p >= 0)
            {
                int a = dp[i - p][j - 1] + page[j];
                int b = dp[i][j - 1];
                if (a > b)
                    dp[i][j] = a;
                else
                    dp[i][j] = b;
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    printf("%d", dp[x][n]);
}