#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();
    int t;
    cin >> t;

    frange(_, t)
    {
        int n;
        cin >> n;
        vvi grid(n + 1, vi(n + 1));

        frange(i, n)
        {
            string str;
            cin >> str;
            frange(j, n)
            {
                grid[i][j] = str[j] - '0';
            }
        }

        vvi dp(n + 1, vi(n + 1)), lb(n + 1, vi(n + 1)), rb(n + 1, vi(n + 1));
        int c = 0;
        frange(i, n)
        {
            frange(j, n)
            {
                if ((grid[i][j] + dp[i][j]) & 1)
                {
                    c++;
                    dp[i][j]++;
                    lb[i][j]++;
                    rb[i][j]++;
                }
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j + 1] += rb[i][j];
                rb[i + 1][j + 1] += rb[i][j];
                if (j - 1 >= 0)
                {
                    dp[i + 1][j - 1] += lb[i][j];
                    lb[i + 1][j - 1] += lb[i][j];
                }
            }
        }
        cout << c << "\n";
    }
}