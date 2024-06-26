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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define PB push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

int mod = 1e9 + 7;
int main()
{
    int n;
    scd(n);
    vvi grid(n, vi(n));
    vvi dp(n, vi(n));
    string a;
    frange(i, n)
    {
        cin >> a;
        frange(j, n)
        {

            grid[i][j] = (a[j] == '*') ? 0 : 1;
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j];
            else if (i == 0)
                dp[i][j] = dp[i][j - 1] * grid[i][j];
            else if (j == 0)
                dp[i][j] = dp[i - 1][j] * grid[i][j];
            else
                dp[i][j] = ((dp[i - 1][j] % mod + dp[i][j - 1] % mod) % mod) * grid[i][j];
        }
    }
    printf("%d", dp[n - 1][n - 1]);
    return 0;
}