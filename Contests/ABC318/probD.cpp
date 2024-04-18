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

    vvi val(n, vi(n));

    frange(i, n)
    {
        forr(j, n - (n - i - 1), n)
        {
            int a;
            scd(a);
            val[i][j] = a;
            val[j][i] = a;
        }
    }

    vll dp(1 << n);

    forr(i, 1, 1 << n)
    {
        frange(j, n)
        {
            frange(k, n)
            {
                if ((i & (1 << j)) && (i & (1 << k)))
                {
                    dp[i] = max(dp[i], dp[(i ^ (1 << j)) ^ (1 << k)] + val[j][k]);
                }
            }
        }
    }
    printf("%lld", dp[(1 << n) - 1]);
}