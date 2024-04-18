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

vector<vll> cost;
vector<vll> dp;

void dnc(int k, int l, int r, int st, int en)
{
    int mid = (l + r) / 2;
    int optim = mid;
    forr(i, st, min(en, mid) + 1)
    {
        if (dp[k - 1][i - 1] + cost[i][mid] < dp[k][mid])
        {
            dp[k][mid] = dp[k - 1][i - 1] + cost[i][mid];
            optim = i;
        }
    }
    if (mid - 1 >= l)
        dnc(k, l, mid - 1, st, optim);
    if (mid + 1 <= r)
        dnc(k, mid + 1, r, optim, en);
}

int main()
{
    int n, k;
    scd(n);
    scd(k);
    vll val(n + 1), wgt(n + 1);

    forr(i, 1, n + 1) sclld(val[i]);
    forr(i, 1, n + 1) sclld(wgt[i]);

    cost = vector<vll>(n + 1, vll(n + 1));

    forr(i, 1, n + 1)
    {
        lli ma = wgt[i];
        lli tot = 0;
        forr(j, i, n + 1)
        {
            ma = max(ma, wgt[j]);
            tot += val[j];
            cost[i][j] = ma * tot;
        }
    }

    dp = vector<vll>(k + 1, vll(n + 1, 2e18));
    forr(i, 0, n + 1)
    {
        dp[0][i] = cost[1][i];
    }
    forr(i, 1, k + 1)
        dnc(i, 1, n, 1, n);
    printf("%lld", dp[k][n]);
}