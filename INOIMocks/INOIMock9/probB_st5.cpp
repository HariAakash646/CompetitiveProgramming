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

int main()
{
    int n, m, l, k;
    scd(n);
    scd(m);
    scd(l);
    scd(k);
    vll vec(5 * (n + 1) + 1);
    forr(i, 1, n + 1) sclld(vec[5 * i]);
    vvi graph(5 * (n + 1) + 1);

    frange(i, m)
    {
        int a, b, w;
        scd(a);
        scd(b);
        scd(w);
        int c = 0;
        for (; c < w - 1; c++)
        {
            graph[5 * a + c].pb(5 * a + c + 1);
        }
        graph[5 * a + c].pb(5 * b);
    }

    vector<map<int, lli>> major(5 * (n + 1) + 1);
    vi mt(k + 2);
    mt[k + 1] = l;

    frange(i, k)
    {
        int t, x;
        lli y;
        scd(t);
        scd(x);
        sclld(y);
        major[5 * x][t] = y;
        mt[i + 1] = t;
    }
    sort(all(mt));
    auto it = unique(all(mt));
    mt.resize(distance(mt.begin(), it));
    vector<vector<vll>> floyd(5 * (n + 1) + 1, vector<vll>(5 * (n + 1) + 1, vll(32, -1e18)));

    forr(i, 5, 5 * (n + 1) + 1)
    {
        for (auto e : graph[i])
        {
            floyd[i][e][0] = vec[i];
        }
    }

    forr(k, 1, 32)
    {
        forr(i, 5, 5 * (n + 1) + 1)
        {
            forr(j, 5, 5 * (n + 1) + 1)
            {
                forr(e, 5, 5 * (n + 1) + 1)
                {
                    floyd[i][j][k] = max(floyd[i][j][k], floyd[i][e][k - 1] + floyd[e][j][k - 1]);
                }
                // if (floyd[i][j][k] >= 0)
                //     printf("%d ", floyd[i][j][k]);
            }
            // printf("\n");
        }
        // printf("\n");
    }

    vector<vll> dp1(mt.size(), vll(5 * (n + 1) + 1, -1e18));
    dp1[0][5] = vec[5];

    forr(r, 1, mt.size())
    {
        vi val;
        int curr = 0;
        int l = mt[r] - mt[r - 1];
        frange(i, 32)
        {
            if (l & (1 << i))
            {
                curr = curr | (1 << i);
                val.pb(curr);
            }
        }

        vector<vector<vll>> dp(5 * (n + 1) + 1, vector<vll>(5 * (n + 1) + 1, vll(val.size(), -1e18)));
        forr(i, 5, 5 * (n + 1) + 1)
        {
            forr(j, 5, 5 * (n + 1) + 1)
            {
                dp[i][j][0] = floyd[i][j][32 - __builtin_clz(val[0]) - 1];
            }
        }

        forr(k, 1, val.size())
        {
            forr(i, 5, 5 * (n + 1) + 1)
            {
                forr(j, 5, 5 * (n + 1) + 1)
                {
                    forr(e, 5, 5 * (n + 1) + 1)
                    {
                        dp[i][j][k] = max(dp[i][j][k], dp[i][e][k - 1] + floyd[e][j][32 - __builtin_clz(val[k] ^ val[k - 1]) - 1]);
                    }
                    // printf("%lld ", dp[i][j][k]);
                }
                // printf("\n");
            }
            // printf("\n");
        }
        forr(i, 5, 5 * (n + 1) + 1)
        {
            forr(j, 5, 5 * (n + 1) + 1)
            {
                dp1[r][i] = max(dp1[r][i], dp1[r - 1][j] + dp[j][i][val.size() - 1] + major[i][mt[r]]);
            }
        }
    }

    if (dp1[k + 1][5] >= 0)
    {
        printf("%lld", dp1[k + 1][5]);
    }
    else
        printf("-1");
}