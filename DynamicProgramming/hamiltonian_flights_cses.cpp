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

int mod = 1e9 + 7;

int main()
{
    int n, m;
    scd(n);
    scd(m);
    vvi ingraph(n + 1);
    frange(_, m)
    {
        int a, b;
        scd(a);
        scd(b);
        ingraph[b].pb(a);
    }
    vvi dp(1 << n, vi(n + 1));
    dp[1][1] = 1;
    for (int i = 2; i < (1 << n); i++)
    {
        if ((i & (1 << (n - 1))) && i != ((1 << n) - 1))
            continue;
        forr(k, 1, n + 1)
        {
            if (i & (1 << (k - 1)))
            {
                for (auto e : ingraph[k])
                {
                    if (i & (1 << (e - 1)))
                    {
                        dp[i][k] = (dp[i][k] + dp[i ^ (1 << (k - 1))][e]) % mod;
                    }
                }
            }
        }
    }
    printf("%d", dp[(1 << n) - 1][n]);
}