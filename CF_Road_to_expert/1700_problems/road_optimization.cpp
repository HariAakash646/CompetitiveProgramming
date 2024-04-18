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
    int n, l, k;
    scd(n);
    scd(l);
    scd(k);
    vi coord(n + 2);
    forr(i, 1, n + 1)
    {
        scd(coord[i]);
    }
    coord[n + 1] = l;
    vi speed(n + 1);
    forr(i, 1, n + 1)
    {
        scd(speed[i]);
    }
    vvi dp(n + 1, vi(k + 1, 2e9));
    dp[0][0] = 0;
    forr(i, 1, n + 1)
    {
        dp[i][0] = dp[i - 1][0] + speed[i] * (coord[i + 1] - coord[i]);
    }
    forr(i, 1, n + 1)
    {
        forr(j, 1, k + 1)
        {
            dp[i][j] = dp[i][j - 1];
            forr(l, 1, min(i, j + 2))
            {
                dp[i][j] = min(dp[i - l][j - (l - 1)] + speed[i - l] * (coord[i] - coord[i - l + 1]) + speed[i] * (coord[i + 1] - coord[i]), dp[i][j]);
            }
        }
    }
    int mi = 1e9 + 5;
    forr(i, 0, min(n, k + 1))
    {
        mi = min(dp[n - i][k - i] + speed[n - i] * (coord[n + 1] - coord[n - i + 1]), mi);
    }
    printf("%d", mi);
}