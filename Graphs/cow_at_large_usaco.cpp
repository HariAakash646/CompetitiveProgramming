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

vvi graph;
vi dist1, dist2;
int c = 0;

void dfs(int x, int prev)
{
    if (dist2[x] <= dist1[x])
    {
        c++;
        return;
    }
    for (auto e : graph[x])
    {
        if (e != prev)
        {
            dfs(e, x);
        }
    }
}

int main()
{
    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);
    int n, k;
    scd(n);
    scd(k);
    graph = vvi(n + 1);
    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dist1 = dist2 = vi(n + 1);
    vb vis(n + 1);
    queue<pii> q;
    q.push({k, 0});
    while (q.size())
    {
        auto p = q.front();
        q.pop();
        if (vis[p.f])
            continue;
        vis[p.f] = true;
        dist1[p.f] = p.s;
        for (auto e : graph[p.f])
        {
            q.push({e, p.s + 1});
        }
    }
    vis = vb(n + 1);
    forr(i, 1, n + 1)
    {
        if (graph[i].size() == 1)
            q.push({i, 0});
    }
    while (q.size())
    {
        auto p = q.front();
        q.pop();
        if (vis[p.f])
            continue;
        vis[p.f] = true;
        dist2[p.f] = p.s;
        for (auto e : graph[p.f])
        {
            q.push({e, p.s + 1});
        }
    }
    // forr(i, 1, n + 1)
    // {
    //     printf("%d %d\n", dist1[i], dist2[i]);
    // }
    dfs(k, 0);
    printf("%d", c);
}