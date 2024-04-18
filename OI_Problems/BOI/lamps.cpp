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
    int n, m;
    cin >> n >> m;
    vvi grid(n + 3, vi(m + 3));
    forr(i, 1, n + 1)
    {
        string row;
        cin >> row;
        frange(j, m)
        {
            if (row[j] == '/')
                grid[i][j + 1] = 1;
        }
    }
    vvi dp(n + 3, vi(m + 3, 1e9));
    dp[1][1] = 0;
    deque<pair<pii, int>> dq;
    dq.push_back(mp(mp(1, 1), 0));
    vector<vb> vis(n + 3, vb(m + 3));

    while (dq.size())
    {
        auto p = dq.front();
        dq.pop_front();
        if (p.f.f < 1 || p.f.s < 1 || p.f.f > n + 1 || p.f.s > m + 1 || vis[p.f.f][p.f.s])
            continue;
        vis[p.f.f][p.f.s] = true;

        vector<pair<pii, int>> val = {mp(mp(1, 1), grid[p.f.f][p.f.s]), mp(mp(1, -1), !grid[p.f.f][p.f.s - 1]), mp(mp(-1, 1), !grid[p.f.f - 1][p.f.s]), mp(mp(-1, -1), grid[p.f.f - 1][p.f.s - 1])};

        for (auto e : val)
        {
            int x = p.f.f + e.f.f;
            int y = p.f.s + e.f.s;
            if (dp[p.f.f][p.f.s] + e.s < dp[x][y])
            {
                dp[x][y] = dp[p.f.f][p.f.s] + e.s;
                if (e.s)
                    dq.push_back(mp(mp(x, y), dp[x][y]));
                else
                    dq.push_front(mp(mp(x, y), dp[x][y]));
            }
        }
    }
    if (dp[n + 1][m + 1] <= n * m)
        printf("%d", dp[n + 1][m + 1]);
    else
        printf("NO SOLUTION");
}