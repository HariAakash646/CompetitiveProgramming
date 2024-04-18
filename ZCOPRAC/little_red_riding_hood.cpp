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
    int n, m;
    scd(n);
    scd(m);
    vvi vec(n + 1, vi(n + 1));
    forr(i, 1, n + 1)
    {
        forr(j, 1, n + 1)
        {
            scd(vec[i][j]);
        }
    }
    vvi safe(n + 1, vi(n + 1));

    frange(_, m)
    {
        int x, y, c;
        scd(x);
        scd(y);
        scd(c);
        forr(i, -c, c + 1)
        {
            forr(j, -c + abs(i), c - abs(i) + 1)
            {
                if (1 <= x + i && x + i <= n && 1 <= y + j && y + j <= n)
                {
                    safe[x + i][y + j] = 1;
                }
            }
        }
    }

    vvi dp(n + 1, vi(n + 1, -2e9));
    if (safe[1][1])
    {
        dp[1][1] = vec[1][1];
    }
    else
    {
        printf("NO");
        return 0;
    }
    forr(i, 1, n + 1)
    {
        forr(j, 1, n + 1)
        {
            if (i == 1 && j == 1)
                continue;
            if (!safe[i][j])
                continue;
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + vec[i][j];
        }
    }
    if (dp[n][n] <= -1e9)
    {
        printf("NO");
    }
    else
    {
        printf("YES\n");
        printf("%d", dp[n][n]);
    }
}