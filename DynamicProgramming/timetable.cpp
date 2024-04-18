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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int inf = 1e8;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vs vec(n);
    vvi prefvec(n, vi(m));
    frange(i, n)
    {
        cin >> vec[i];
    }
    vvi dayhr(n + 1, vi(m + 1));
    forr(i, 1, n + 1)
    {
        forr(j, 1, m + 1)
        {
            int mi = inf;
            int curr = vec[i - 1][0] - '0';
            int i1 = 0, i2 = 0;
            while (i2 < m)
            {
                if (curr >= j)
                {
                    mi = min(i2 - i1 + 1, mi);
                    if (vec[i - 1][i1] == '1')
                        curr--;
                    i1++;
                }
                else
                {
                    i2++;
                    if (i2 == m)
                        continue;
                    if (vec[i - 1][i2] == '1')
                        curr++;
                }
                // if (i1 > i2)
                //     printf("ERROR");
            }
            dayhr[i][j] = mi;
        }
    }
    vvi dp(n + 1, vi(m - k + 1));
    forr(i, 1, m - k + 1)
    {
        dp[0][i] = inf;
    }
    forr(i, 1, n + 1)
    {
        forr(j, 1, m - k + 1)
        {
            dp[i][j] = inf;
            forr(l, 0, j + 1)
            {
                dp[i][j] = min(dp[i][j], dayhr[i][l] + dp[i - 1][j - l]);
            }
            // printf("%d ", dp[i][j]);
        }
    }
    if (dp[n][m - k] == inf)
        printf("0");
    else
        printf("%d", dp[n][m - k]);
}