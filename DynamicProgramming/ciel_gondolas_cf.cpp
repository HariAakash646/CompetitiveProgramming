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

int dp[801][4001];
int cost[4001][4001];
int val[4001][4001];
int pref[4001][4001];

void rec(int k, int l, int r, int st, int en)
{

    int mid = (l + r) >> 1;
    int optim = st;
    forr(i, st, min(mid, en) + 1)
    {
        if (dp[k - 1][i - 1] + cost[i][mid] < dp[k][mid])
        {
            dp[k][mid] = dp[k - 1][i - 1] + cost[i][mid];
            optim = i;
        }
    }
    if (mid - 1 >= l)
        rec(k, l, mid - 1, st, optim);
    if (mid + 1 <= r)
        rec(k, mid + 1, r, optim, en);
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();
    int n, k;
    cin >> n >> k;

    forr(i, 1, n + 1)
    {
        forr(j, 1, n + 1) cin >> val[i][j];
    }

    forr(i, 1, n + 1)
    {
        forr(j, 1, n + 1)
        {
            pref[i][j] += pref[i][j - 1] + val[i][j];
        }
    }

    forr(i, 0, n + 1)
    {
        forr(j, i + 1, n + 1)
        {
            cost[i][j] = cost[i][j - 1] + pref[j][j];
            if (i > 0)
                cost[i][j] -= pref[j][i - 1];
            // cout << cost[i][j] << " ";
        }
        // cout << "\n";
    }

    // forr(i, 0, k + 1)
    //     dp[i][0] = 0;
    forr(j, 0, k + 1)
    {
        forr(i, 0, n + 1)
        {
            dp[j][i] = 2e9 + 5;
        }
    }

    dp[0][0] = 0;
    forr(i, 1, n + 1) dp[1][i] = cost[0][i];
    forr(i, 2, k + 1)
    {
        rec(i, 1, n, 1, n);
    }
    cout << dp[k][n];
}