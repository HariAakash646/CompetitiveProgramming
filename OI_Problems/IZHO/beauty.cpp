#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
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

int main()
{
    int n;
    scd(n);
    vi vec(n);
    vi cnt2(n), cnt3(n);

    frange(i, n)
    {
        int a;
        scd(a);
        vec[i] = a;
        int v1 = a;
        int v2 = a;
        while (v1 > 0)
        {
            if (v1 % 2 == 1)
                cnt2[i]++;
            v1 /= 2;
        }
        while (v2 > 0)
        {
            if (v2 % 3 == 1)
                cnt3[i]++;
            v2 /= 3;
        }
    }

    vector<vll> dp(1 << n, vll(n));

    frange(i, n)
    {
        dp[1 << i][i] = 1;
    }

    frange(i, 1 << n)
    {
        frange(j, n)
        {
            if (i & (1 << j))
            {
                frange(k, n)
                {
                    if (cnt2[j] == cnt2[k] || cnt3[k] == cnt3[j])
                    {
                        dp[i][j] += dp[i ^ (1 << j)][k];
                        // printf("%d %d %lld\n", k, j, dp[i][j]);
                    }
                }
            }
        }
    }
    lli tot = 0;
    frange(i, n)
    {
        tot += dp[(1 << n) - 1][i];
    }
    // lli fac = 1;
    // forr(i, 1, n + 1) fac *= i;
    printf("%lld", tot);
}