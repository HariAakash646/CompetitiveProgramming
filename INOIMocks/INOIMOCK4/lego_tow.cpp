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
    int n;
    scd(n);
    vi vec(n);
    frange(i, n)
    {
        scd(vec[i]);
    }
    if (n == 1)
    {
        printf("1");
    }
    else if (n == 2)
    {
        if (vec[0] == vec[1])
        {
            printf("1");
        }
        else
        {
            printf("2");
        }
    }
    // vector<vector<lli>> dp(n + 1, vector<lli>(n + 1, 1));
    // forr(i, 1, n + 1)
    // {
    //     forr(j, i, n + 1)
    //     {
    //         if (i == j)
    //         {
    //             dp[i][j] = 1;
    //         }
    //         forr(k, i - 1, j + 1)
    //         {
    //             dp[i][j] += dp[i][k];
    //             dp[i][j] % mod;
    //         }
    //     }
    // }
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     forr(j, i, n)
    //     {
    //         if (i == j)
    //         {
    //             dp[i][j].f = 1;
    //             dp[i][j].s = vec[i];
    //         }
    //         forr(k, i, n - 1) {
    //         forr(l, k, n-1)
    //         {
    //             dp[i][j].f = max(dp[i][j].f, dp[i][k].f + dp[k + 1][j].f + (dp[i][k].s != dp[k + 1][j].s));
    //             dp[i][j].s = min(dp[i][k].s, dp[k + 1][j].s);
    //         }}
    //     }
    // }
    // printf("%d", dp[n][n]);
    ;
}