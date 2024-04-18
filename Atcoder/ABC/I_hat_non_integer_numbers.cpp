// Not working
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
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int mod = 998244353;

int main()
{
    int n;
    scd(n);
    vi vec(n + 1);
    frange(i, n) scd(vec[i + 1]);
    vvvi dp(n + 1, vvi(n + 1, vi(n + 1)));
    forr(i, 1, n + 1)
    {
        dp[0][i][0] = 1;
    }
    int tot = 0;
    forr(i, 1, n + 1)
    {
        forr(j, 1, i + 1)
        {
            forr(k, 0, j)
            {
                dp[i][j][k] = (dp[i - 1][j][k] + dp[i - 1][j][(j - ((vec[i] - k) % j)) % j]) % mod;
                if (k == 0)
                {
                    tot = (tot + dp[i][j][k]) % mod;
                }
            }
        }
    }
    printf("%d", tot);
}