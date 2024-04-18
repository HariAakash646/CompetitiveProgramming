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
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

lli mod = 1e9 + 7;

int main()
{
    int n, k;
    scd(n);
    scd(k);
    vi vec(n + 1);
    frange(i, n)
    {
        scd(vec[i + 1]);
    }
    vvll dp(n + 1, vll(k + 1));
    dp[0][0] = 1;
    forr(i, 1, n + 1)
    {
        frange(j, k + 1)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = dp[i][j - 1];
            if (j - vec[i] - 1 >= 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j] - dp[i - 1][j - vec[i] - 1] + mod) % mod;
            else
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
        }
    }
    printf("%lld", (dp[n][k]) % mod);
}