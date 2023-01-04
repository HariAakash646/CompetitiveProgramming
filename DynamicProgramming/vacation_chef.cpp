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
#define pb push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
    int m, n;
    scd(m);
    scd(n);
    vvi grid(m + 1, vi(n + 1));
    frange(i, m)
    {
        frange(j, n)
        {
            scd(grid[i + 1][j + 1]);
        }
    }
    int q;
    scd(q);
    vvi dp(m + 1, vi(n + 1));
    forr(i, 1, m + 1, 1)
    {
        forr(j, 1, n + 1, 1)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + grid[i][j];
        }
    }
    frange(i, q)
    {
        int a, b, c, d;
        scd(a);
        scd(b);
        scd(c);
        scd(d);
        int s = dp[c][d] - dp[c][b - 1] - dp[a - 1][d] + dp[a - 1][b - 1];
        int s1 = (c - a + 1) * (d - b + 1);
        if (s == s1)
        {
            printf("1\n");
        }
        else
            printf("0\n");
    }
    return 0;
}
