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
    int n, m;
    scd(n);
    scd(m);
    vi v1(n);
    vi v2(m);
    frange(i, n) scd(v1[i]);
    frange(i, m) scd(v2[i]);

    vvi val(1001);
    frange(i, 1 << m)
    {
        int tot = 0;
        frange(j, m)
        {
            if (i & (1 << j))
                tot += v2[j];
        }
        if (tot <= 1000)
            val[tot].pb(i);
    }
    vector<vb> dp(1 << m, vb(n));
    for (auto e : val[v1[0]])
        dp[e][0] = true;
    frange(j, n - 1)
    {
        frange(i, 1 << m)
        {
            if (!dp[i][j])
                continue;
            for (auto v : val[v1[j + 1]])
            {
                if ((v & i) == 0)
                    dp[v | i][j + 1] = true;
            }
        }
    }
    bool out = false;
    frange(i, 1 << m)
    {
        if (dp[i][n - 1])
        {
            // printf("%d\n", i);
            out = true;
        }
    }
    if (out)
        printf("YES");
    else
        printf("NO");
}