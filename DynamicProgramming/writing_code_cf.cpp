// Memory limit exceeded
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
    int n, m, b, mod;
    scd(n);
    scd(m);
    scd(b);
    scd(mod);
    vi vec(n + 1);
    frange(i, n)
    {
        scd(vec[i + 1]);
    }
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(b + 1)));
    dp[0][0][0] = 1;
    forr(i, 0, n + 1)
    {
        dp[i][0][0] = 1;
    }

    forr(i, 1, n + 1)
    {
        forr(j, 1, m + 1)
        {
            forr(k, 1, b + 1)
            {
                lli a = 0;
                if (k - vec[i] >= 0)
                {
                    a = dp[i][j - 1][k - vec[i]];
                }
                dp[i][j][k] = (dp[i - 1][j][k] + a) % mod;
            }
        }
    }
    lli out = 0;
    forr(i, 1, b + 1)
    {
        out = (out + dp[n][m][i]) % mod;
    }
    printf("%lld", out);
}