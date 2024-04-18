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
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

int main()
{
    int n, m, k;
    scd(n);
    scd(m);
    scd(k);
    vvi c1(n + 1, vi(m + 1, 1e9));
    vvi c2(n + 1, vi(m + 1, 1e9));
    forr(i, 1, n + 1)
    {
        forr(j, 1, m)
        {
            scd(c1[i][j]);
        }
    }
    forr(i, 1, n)
    {
        forr(j, 1, m + 1)
        {
            scd(c2[i][j]);
        }
    }
    if (k % 2)
    {
        frange(i, n)
        {
            frange(j, m)
            {
                printf("-1 ");
            }
            printf("\n");
        }
        return 0;
    }
    k /= 2;
    vector<vvll> dp(n + 2, vvll(m + 2, vll(k + 1, 1e9)));
    forr(i, 1, n + 1)
    {
        forr(j, 1, m + 1)
        {
            dp[i][j][0] = 0;
        }
    }
    forr(l, 1, k + 1)
    {
        forr(i, 1, n + 1)
        {
            forr(j, 1, m + 1)
            {
                dp[i][j][l] = min({dp[i + 1][j][l - 1] + c2[i][j], dp[i - 1][j][l - 1] + c2[i - 1][j], dp[i][j + 1][l - 1] + c1[i][j], dp[i][j - 1][l - 1] + c1[i][j - 1]});
            }
        }
    }
    forr(i, 1, n + 1)
    {
        forr(j, 1, m + 1)
        {
            printf("%lld ", 2 * dp[i][j][k]);
        }
        printf("\n");
    }
}