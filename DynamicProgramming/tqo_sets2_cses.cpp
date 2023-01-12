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
#define PB push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

lli mod = 1e9 + 7;

int main()
{
    int n;
    scd(n);
    lli tot = (n * (n + 1)) / 2;
    if (tot % 2 != 0)
    {
        printf("0");
        return 0;
    }
    tot /= 2;
    vector<vector<lli>> dp(tot + 1, vector<lli>(n + 1, 0));
    frange(i, n + 1)
    {
        dp[0][i] = 1;
    }
    forr(i, 1, tot + 1)
    {
        forr(j, 1, n + 1)
        {
            if (i - j >= 0)
            {
                dp[i][j] = ((dp[i - j][j - 1] + dp[i][j - 1]) % mod);
            }
            else
                dp[i][j] = dp[i][j - 1];
        }
    }
    printf("%lld", dp[tot][n - 1]);
}