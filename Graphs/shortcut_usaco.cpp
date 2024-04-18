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
typedef vector<vii> vvii;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

vvi path;
vi pre;
vb visd;

vi dfs(int x)
{
    // if (visd[x])
    // {
    //     return {x};
    // }
    // path[x].pb(x);
    // visd[x] = true;
    int e = pre[x];
    if (e == 0)
        return vi(1, x);
    vi out = dfs(e);
    out.pb(x);
    // for (auto p : path[e])
    //     printf("%d ", p);
    // printf("\n");
    // for (auto p : path[e])
    //     path[x].pb(p);
    return out;
}

int main()
{
    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout);
    int n, m, t;
    scd(n);
    scd(m);
    scd(t);
    vll vec(n + 1);
    forr(i, 1, n + 1) sclld(vec[i]);
    vector<vector<pair<int, lli>>> graph(n + 1);
    frange(i, m)
    {
        int a, b;
        lli c;
        scd(a);
        scd(b);
        sclld(c);
        graph[a].pb({b, c});
        graph[b].pb({a, c});
    }
    priority_queue<pair<lli, int>> pq;
    vll dist(n + 1, 1e18);
    dist[1] = 0;
    pq.push({0, 1});
    vb vis(n + 1);
    while (pq.size())
    {
        auto p = pq.top();
        pq.pop();
        if (vis[p.s])
            continue;
        vis[p.s] = true;
        for (auto e : graph[p.s])
        {
            if (dist[p.s] + e.s < dist[e.f])
            {
                dist[e.f] = dist[p.s] + e.s;
                pq.push({-dist[e.f], e.f});
            }
        }
    }
    // for (auto e : dist)
    //     printf("%d ", e);
    pre = vi(n + 1);
    forr(i, 2, n + 1)
    {
        int mi = 1e9;
        for (auto p : graph[i])
        {
            if (dist[p.f] + p.s == dist[i])
            {
                mi = min(mi, p.f);
            }
        }
        // if (mi != 1e9)
        pre[i] = mi;
    }
    path = vvi(n + 1);
    visd = vb(n + 1);
    vll cnt(n + 1);
    forr(i, 1, n + 1)
    {
        vi out = dfs(i);
        for (auto e : out)
        {
            cnt[e] += vec[i];
        }
    }

    // forr(i, 1, n + 1)
    // {
    //     for (auto e : path[i])
    //     {
    //         // printf("%d ", e);
    //         cnt[e] += vec[i];
    //     }
    //     // printf("\n");
    // }
    lli ma = 0;
    forr(i, 1, n + 1)
    {
        ma = max((dist[i] - t) * cnt[i], ma);
    }
    printf("%lld", ma);
}