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
    int n;
    scd(n);
    vi vec(n + 1);
    forr(i, 1, n + 1)
    {
        scd(vec[i]);
    }
    vector<vector<lli>> dp(n + 1, vector<lli>(n + 1, -1e16));
    frange(j, 2)
    {
        dp[0][j] = 0;
    }
    forr(i, 1, n + 1)
    {
        forr(j, 0, i + 1)
        {
            lli a = 0, b = 0, c = 0;

            if (j == 0)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]);
            }
            else if (j == i)
                dp[i][j] = max({dp[i - 1][j], dp[i - 1][j - 1]}) + vec[i] * j;
            else
                dp[i][j] = max({dp[i - 1][j], dp[i - 1][j + 1], dp[i - 1][j - 1]}) + vec[i] * j;
        }
    }
    printf("%lld", max(dp[n][0], dp[n][1]));
}