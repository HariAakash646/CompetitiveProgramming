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

int inf = 1e9 + 5;

int main()
{
    string str;
    cin >> str;
    int n = str.size();
    int k;
    cin >> k;
    int m;
    cin >> m;
    vvi cost(26, vi(26));
    frange(i, m)
    {
        char a, b;
        int c;
        cin >> a >> b >> c;
        cost[a - 'a'][b - 'a'] = c;
    }
    vector<vvi> dp(k + 1, vvi(n, vi(26, -inf)));
    frange(i, n)
    {
        frange(j, 26)
        {
            if (j == str[i] - 'a')
            {
                if (i >= 1)
                {
                    dp[0][i][j] = dp[0][i - 1][str[i - 1] - 'a'] + cost[str[i - 1] - 'a'][j];
                    // printf("%d\n", cost[str[i - 1] - 'a'][j]);
                }
                else
                    dp[0][i][j] = 0;
            }
        }
    }
    forr(i, 1, k + 1)
    {
        frange(j, n)
        {
            frange(l, 26)
            {
                if (j == 0)
                    dp[i][j][l] = 0;
                else
                {
                    if (l == str[j] - 'a')
                    {
                        frange(e, 26)
                        {
                            dp[i][j][l] = max(dp[i][j][l], dp[i][j - 1][e] + cost[e][l]);
                        }
                    }
                    else
                    {
                        frange(e, 26)
                        {
                            dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j - 1][e] + cost[e][l]);
                        }
                    }
                }
            }
        }
    }
    int ma = -inf;
    forr(i, 0, k + 1)
    {

        frange(l, 26)
        {
            // printf("%d ", dp[0][i][l]);
            ma = max(ma, dp[i][n - 1][l]);
        }
        printf("\n");
    }
    printf("%d", ma);
}