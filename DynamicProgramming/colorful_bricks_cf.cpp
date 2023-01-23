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

lli mod = 998244353;

int main()
{
    lli n, m, k;
    sclld(n);
    sclld(m);
    sclld(k);
    vector<vector<lli>> dp(k + 2, vector<lli>(n + 1));
    dp[1][1] = m;

    forr(i, 1, k + 2)
    {
        forr(j, 1, n + 1)
        {
            if (i == 1 && j == 1)
                continue;
            dp[i][j] = ((dp[i - 1][j - 1] * (m - 1)) % mod + dp[i][j - 1]) % mod;
        }
    }
    printf("%lld", dp[k + 1][n]);
}