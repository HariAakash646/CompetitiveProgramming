// Incorrect for test case:
// 3 1 2
// 3 2 0
// 2 3 2
// Output: 17
// Correct: 16
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

int main()
{
    int n, m;
    scd(n);
    scd(m);
    vvi grid(n + 1, vi(m + 1));
    forr(i, 1, n + 1)
    {
        forr(j, 1, m + 1)
        {
            scd(grid[i][j]);
        }
    }

    vvi dp1(n + 2, vi(m + 2));
    vvi dp2(n + 2, vi(m + 2));
    vvi dp3(n + 2, vi(m + 2));
    vvi dp4(n + 2, vi(m + 2));
    forr(i, 1, n + 1)
    {
        forr(j, 1, m + 1)
        {
            dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]) + grid[i][j];
        }
    }
    for (int i = n; i > 0; i--)
    {
        for (int j = m; j > 0; j--)
        {
            dp2[i][j] = max(dp2[i + 1][j], dp2[i][j + 1]) + grid[i][j];
        }
    }
    for (int i = n; i > 0; i--)
    {
        forr(j, 1, m + 1)
        {
            dp3[i][j] = max(dp3[i + 1][j], dp3[i][j - 1]) + grid[i][j];
        }
    }
    forr(i, 1, n + 1)
    {
        for (int j = m; j > 0; j--)
        {
            dp4[i][j] = max(dp4[i - 1][j], dp4[i][j + 1]) + grid[i][j];
        }
    }
    int ma = 0;
    forr(i, 1, n + 1)
    {
        forr(j, 1, m + 1)
        {
            ma = max({ma, dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1], dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] + dp4[i - 1][j]});
        }
    }
    printf("%d", ma);
}