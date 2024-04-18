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
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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

lli mod = 1e9 + 9;

int main()
{
    int n, d;
    scd(n);
    scd(d);
    vi vec(n);
    frange(i, n) scd(vec[i]);
    vector<vll> dp(1 << n, vll(n));
    frange(i, n)
    {
        dp[1 << i][i] = 1;
    }
    lli tot = 0;
    frange(i, 1 << n)
    {
        frange(j, n)
        {
            if (i & (1 << j))
            {
                frange(k, n)
                {
                    if (j == k)
                        continue;
                    if (i & (1 << k) && vec[k] - vec[j] <= d)
                    {
                        dp[i][j] = (dp[i][j] + dp[i ^ (1 << j)][k]) % mod;
                    }
                }
            }
        }
    }
    frange(i, n)
    {
        tot += dp[(1 << n) - 1][i];
        tot %= mod;
    }
    printf("%lld", tot);
}