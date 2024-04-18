#include <bits/stdc++.h>
#include <iostream>

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
typedef vector<string> vs;
typedef vector<bool> vb;
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
    int t;
    scd(t);
    frange(_, t)
    {
        int k, n;
        scd(k);
        scd(n);
        vector<vector<lli>> dp(k + 1, vector<lli>(n + 1, 0));
        frange(i, k + 1) dp[i][0] = 1;
        forr(i, 1, k + 1)
        {
            forr(j, 1, n + 1)
            {
                if (j >= 3)
                {
                    dp[i][j] += dp[i - 1][3] + dp[i][j - 3];
                }
                if (i >= 2 && j >= 3)
                {
                    dp[i][j] += dp[2][j - 2] + dp[i - 2][j - 3];
                }
                if (i >= 3)
                {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
        printf("%lld\n", dp[k][n]);
    }
}