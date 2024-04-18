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
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

void usaco()
{
    freopen("problem.in", "r", stdin);
    freopen("problem.out", "w", stdout);
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

lli mod = 1e9 + 7;

// lli binexp(lli x, lli p)
// {
//     if (p == 0)
//         return 1;
//     lli v = binexp(x, p / 2);
//     if (p % 2)
//     {
//         return (((v * v) % mod) * x) % mod;
//     }
//     else
//     {
//         return (v * v) % mod;
//     }
// }

int main()
{
    vector<vll> binom(501, vll(501));
    binom[0][0] = 1;
    forr(i, 1, 501)
    {
        forr(j, 0, i + 1)
        {
            if (j == 0)
                binom[i][j] = binom[i - 1][j];
            else
                binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % mod;
        }
    }
    string str;
    cin >> str;
    int n = str.size();

    vector<vll> dp(n, vll(n));

    frange(i, n - 1)
    {
        if (str[i] == str[i + 1])
        {
            dp[i + 1][i] = 1;
        }
    }

    for (int k = 1; k < n; k += 2)
    {
        for (int l = 0; l + k < n; l++)
        {
            int r = l + k;
            forr(i, l + 1, r)
            {
                if (str[l] == str[i])
                {
                    dp[l][r] += (binom[(r - l + 1) / 2][(i - l + 1) / 2] * ((dp[l + 1][i - 1] * dp[i + 1][r]) % mod)) % mod;
                    dp[l][r] %= mod;
                }
            }
            if (str[l] == str[r])
            {
                dp[l][r] += dp[l + 1][r - 1];
            }
            dp[l][r] %= mod;
        }
    }
    printf("%lld", dp[0][n - 1]);
}