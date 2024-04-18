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
    vector<vi> vec(n + 1, vi(100));
    vector<vi> dp(n + 1, vi(101));

    forr(i, 1, n + 1)
    {
        int c;
        scd(c);
        frange(j, c)
        {
            scd(vec[i][j]);
        }
        forr(k, 1, c + 1)
        {
            vvi range(c, vi(c));
            forr(j, c - k, c)
            {
                for (int l = 0; l + j < c; l++)
                {
                    int r = l + j;
                    if (l == r)
                        range[l][r] = vec[i][l];
                    else
                        range[l][r] = max(range[l + 1][r] + vec[i][l], range[l][r - 1] + vec[i][r]);
                }
            }
            dp[i][k] = range[0][c - 1];
        }
    }
    vector<vi> dp1(n + 1, vi(m + 1));
    forr(i, 1, n + 1)
    {
        forr(j, 1, m + 1)
        {
            forr(k, 0, 101)
            {
                if (j - k >= 0)
                    dp1[i][j] = max(dp1[i][j], dp1[i - 1][j - k] + dp[i][k]);
            }
        }
    }
    printf("%d", dp1[n][m]);
}