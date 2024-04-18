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

int n, m, st, en;
vector<vector<pair<pii, int>>> graph;

int timer = 0;
int vert = 0;
vi tin, low;
vi cnt, dp;
vector<vi> rem;
vi par;
vb path;

void dfs(pair<pii, int> ele, int prev)
{
    int x = ele.f.f;
    if ((x == st || x == en) && vert == 0)
        vert = x;
    tin[x] = low[x] = ++timer;
    if (vert)
    {
        path[x] = true;
        dp[x] += ele.f.s;
        par[x] = ele.s;
    }
    for (auto p : graph[x])
    {
        int e = p.f.f;
        if (e == prev)
            continue;

        if (tin[e])
        {
            if (vert && tin[e] <= tin[vert])
            {
                cnt[x]++;
                dp[x] += p.f.s;
                rem[x].pb(p.s);
            }
            low[x] = min(low[x], tin[e]);
        }
        else
        {
            dfs(p, x);
            if (vert && low[e] <= tin[vert])
            {
                if (cnt[e] <= 1)
                {
                    if (dp[e] - p.f.s < p.f.s)
                    {
                        dp[x] += dp[e] - p.f.s;
                        rem[x].pb(rem[e][0]);
                    }
                    else
                    {
                        dp[x] += p.f.s;
                        rem[x].pb(p.s);
                    }
                }
                else
                {
                    dp[x] += p.f.s;
                    rem[x].pb(p.s);
                }
                cnt[x]++;
            }
            low[x] = min(low[x], low[e]);
        }
    }
}

int main()
{
    cin >> n >> m >> st >> en;
    graph = vector<vector<pair<pii, int>>>(n + 1);
    vii edges(m + 1);
    frange(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].pb(mp(mp(b, c), i + 1));
        graph[b].pb(mp(mp(a, c), i + 1));
        edges[i + 1] = {a, b};
    }

    tin = low = cnt = dp = par = vi(n + 1);
    rem = vvi(n + 1);
    path = vb(n + 1);

    dfs(mp(mp(1, 0), 0), 0);

    lli mi = 1e18;
    int mid = -1;

    forr(i, 1, n + 1)
    {
        if (i != st && i != en && path[i] && cnt[i] <= 1)
        {
            if (dp[i] < mi)
            {
                mi = dp[i];
                mid = i;
            }
        }
    }
    if (mid == -1)
        cout << -1;
    else
    {
        cout << dp[mid] << "\n";
        cout << cnt[mid] + 1 << "\n";
        cout << par[mid] << " ";
        if (cnt[mid])
            cout << rem[mid][0];
    }
}