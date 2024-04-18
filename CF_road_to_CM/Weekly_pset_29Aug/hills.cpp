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

int main()
{
    int n;
    scd(n);

    vi vec(n + 2);
    forr(i, 1, n + 1) scd(vec[i]);
    vec[0] = 1e9;

    vvi dp1(n + 1, vi((n + 1) / 2 + 1, 1e9)), dp2(n + 1, vi((n + 1) / 2 + 1, 1e9));

    // dp1[0][0] = 0;
    forr(i, 0, n + 1)
    {
        dp2[i][0] = 0;
    }

    forr(j, 1, ((n + 1) / 2 + 1))
    {
        forr(i, 1, n + 1)
        {
            int v = 1e9;
            if (i - 2 >= 0)
            {
                v = min(v, dp1[i - 2][j - 1] + max(0, min(vec[i - 1], vec[i - 2] - 1) - (vec[i] - 1)) + max(0, vec[i + 1] - (vec[i] - 1)));
                v = min(v, dp2[i - 2][j - 1] + max(0, vec[i - 1] - (vec[i] - 1)) + max(0, vec[i + 1] - (vec[i] - 1)));
            }
            else
            {
                v = min(v, dp2[i - 1][j - 1] + max(0, vec[i + 1] - (vec[i] - 1)));
            }
            dp1[i][j] = v;
            v = 1e9;

            if (i - 2 >= 0)
            {
                v = min(v, dp1[i - 2][j]);
                v = min(v, dp2[i - 2][j]);
            }
            v = min(v, dp1[i - 1][j]);
            v = min(v, dp2[i - 1][j]);
            dp2[i][j] = v;
        }
    }

    forr(i, 1, (n + 1) / 2 + 1)
    {
        printf("%d ", min(dp1[n][i], dp2[n][i]));
    }
}