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

int max_n = 300000;

lli mod = 1e9 + 7;

vll fact;

lli inv(lli a)
{
    return a <= 1 ? a : mod - (long long)(mod / a) * inv(mod % a) % mod;
}

lli combi(lli n, lli r)
{
    if (n < r)
        return 0;
    return ((fact[n] * inv(fact[n - r])) % mod * inv(fact[r])) % mod;
}

int main()
{
    int n;
    scd(n);
    fact = vll(max_n + 1);
    fact[0] = 1;

    forr(i, 1, n + 1) fact[i] = (fact[i - 1] * i) % mod;

    vi vec(n + 1), cnt(max_n + 1);

    forr(i, 1, n + 1)
    {
        scd(vec[i]);
        cnt[vec[i]]++;
    }

    vi div(max_n + 1);
    div[1] = n;
    forr(i, 2, max_n + 1)
    {
        for (int j = i; j <= max_n; j += i)
        {
            div[i] += cnt[j];
        }
    }

    vvi dp(max_n + 1, vi(8));

    forr(i, 1, 8)
    {
        for (int j = max_n; j >= 1; j--)
        {
            dp[j][i] = combi(div[j], i);
            for (int k = 2 * j; k <= max_n; k += j)
            {
                dp[j][i] -= dp[k][i];
                dp[j][i] += mod;
                dp[j][i] %= mod;
            }
        }
    }
    forr(i, 1, 8)
    {
        if (dp[1][i])
        {
            printf("%d", i);
            return 0;
        }
    }
    printf("-1");
}