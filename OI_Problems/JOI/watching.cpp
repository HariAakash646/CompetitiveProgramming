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

vi vec;
int n, p, q;

bool check(int w)
{
    vvi dp(n + 1, vi(p + 1));
    vi pre1(n + 1), pre2(n + 1);
    forr(i, 1, n + 1)
    {
        auto it = lower_bound(all(vec), vec[i] - 2 * w + 1);
        if (it != vec.begin())
        {
            it--;
            pre2[i] = it - vec.begin();
        }
        else
            pre2[i] = 0;

        it = lower_bound(all(vec), vec[i] - w + 1);
        if (it != vec.begin())
        {
            it--;
            pre1[i] = it - vec.begin();
        }
        else
            pre1[i] = 0;
    }
    frange(i, p + 1) dp[0][i] = 0;
    forr(i, 1, n + 1)
    {
        frange(j, p + 1)
        {
            int v = dp[pre2[i]][j];
            dp[i][j] = v + 1;
            if (j > 0)
            {
                v = dp[pre1[i]][j - 1];
                dp[i][j] = min(dp[i][j], v);
            }
        }
    }
    return dp[n][p] <= q;
}

int main()
{
    scd(n);
    scd(p);
    scd(q);
    if (p + q >= n)
    {
        printf("1");
        return 0;
    }
    vec = vi(n + 1);
    forr(i, 1, n + 1) scd(vec[i]);
    sort(all(vec));
    int lo = 1;
    int hi = 1e9;

    while (lo != hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
        {
            hi = mid;
        }
        else
            lo = mid + 1;
    }
    printf("%d", lo);
}