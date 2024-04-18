// Not wokring. Read sol.
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
    scd(n);
    scd(m);
    int st, en;
    scd(st);
    scd(en);
    int u, v;
    scd(u);
    scd(v);

    vector<vector<pair<int, lli>>> graph(n + 1);

    frange(i, m)
    {
        int a, b, c;
        scd(a);
        scd(b);
        scd(c);
        graph[a].pb(mp(b, c));
        graph[b].pb(mp(a, c));
    }

    priority_queue<pair<lli, int>> pq;
    vll dist(n + 1, 1e18);
    dist[st] = 0;
    vvi con(n + 1);
    pq.push(mp(0, st));
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
                con[e.f] = {p.s};
                pq.push(mp(-dist[e.f], e.f));
            }
            else if (dist[p.s] + e.s == dist[e.f])
            {
                con[e.f].pb(p.s);
            }
        }
    }
    set<pii> edges;
    queue<int> q;

    q.push(en);

    while (q.size())
    {
        auto x = q.front();
        q.pop();
        for (auto e : con[x])
        {
            edges.insert(mp(x, e));
            q.push(e);
        }
    }
    printf("%lld\n", dist[en]);
    for (auto p : edges)
        printf("%d %d\n", p.f, p.s);

    vector<vii> graph2(n + 1);

    forr(i, 1, n + 1)
    {
        for (auto e : graph[i])
        {
            if (edges.count(mp(e.f, i)) || edges.count(mp(i, e.f)))
            {
                graph2[i].pb(mp(e.f, 0));
            }
            else
            {
                graph2[i].pb(e);
            }
        }
    }

    dist = vll(n + 1, 1e18);
    dist[u] = 0;
    pq.push(mp(0, u));
    vis = vb(n + 1);

    while (pq.size())
    {
        auto p = pq.top();
        pq.pop();
        if (vis[p.s])
            continue;
        vis[p.s] = true;
        for (auto e : graph2[p.s])
        {
            if (dist[p.s] + e.s < dist[e.f])
            {
                dist[e.f] = dist[p.s] + e.s;
                pq.push(mp(-dist[e.f], e.f));
            }
        }
    }
    printf("%lld", dist[v]);
}