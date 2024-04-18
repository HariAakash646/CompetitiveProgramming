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
    int n, m, k;
    scd(n);
    scd(m);
    scd(k);
    k++;
    vvi vec(n + 1, vi(m + 1));
    forr(i, 1, n + 1)
    {
        string row;
        cin >> row;
        forr(j, 1, m + 1)
        {
            vec[i][j] = row[j - 1] - '0';
        }
    }
    vector<vector<vi>> dp(n + 1, vector<vi>(m + 2, vi(k, -1e9)));
    forr(i, 1, m + 1)
    {
        dp[1][i][vec[1][i] % k] = vec[1][i];
    }
    forr(i, 2, n + 1)
    {
        forr(j, 1, m + 1)
        {
            frange(l, k)
            {
                dp[i][j][l] = max(dp[i - 1][j - 1][(l - vec[i][j] + 10 * k) % k] + vec[i][j], dp[i - 1][j + 1][(l - vec[i][j] + 10 * k) % k] + vec[i][j]);
            }
        }
    }
    int ma = -1e9;
    int id = 0;
    forr(j, 1, m + 1)
    {
        if (dp[n][j][0] > ma)
        {
            ma = dp[n][j][0];
            id = j;
        }
    }
    if (ma >= 0)
    {
        printf("%d\n%d\n", ma, id);
        int l = 0;
        for (int i = n; i >= 2; i--)
        {
            if (dp[i][id][l] - vec[i][id] == dp[i - 1][id - 1][(l - vec[i][id] + 10 * k) % k])
            {
                printf("L");

                l = (l - vec[i][id] + 10 * k) % k;
                id = id - 1;
            }
            else
            {
                printf("R");

                l = (l - vec[i][id] + 10 * k) % k;
                id = id + 1;
            }
        }
    }
    else
        printf("-1");
}