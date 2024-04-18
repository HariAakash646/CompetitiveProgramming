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

struct Edge
{
    int a, b, flow, cost;
};

bool cmp(Edge x, Edge y)
{
    return x.flow > y.flow;
}

int main()
{
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);
    int n, m;
    scd(n);
    scd(m);
    vector<Edge> edges(m);
    frange(i, m)
    {
        scd(edges[i].a);
        scd(edges[i].b);
        scd(edges[i].cost);
        scd(edges[i].flow);
    }
    int ma = 0;
    sort(all(edges), cmp);
    vector<vii> graph(n + 1);
    for (auto e : edges)
    {
        graph[e.a].pb({e.b, e.cost});
        graph[e.b].pb({e.a, e.cost});
        vi dist(n + 1, 1e9);
        priority_queue<pii> pq;
        vb proc(n + 1);
        dist[1] = 0;
        pq.push({0, 1});
        while (pq.size())
        {
            auto p = pq.top();
            pq.pop();
            if (proc[p.s])
                continue;
            proc[p.s] = true;
            for (auto e : graph[p.s])
            {
                if (dist[p.s] + e.s < dist[e.f])
                {
                    dist[e.f] = dist[p.s] + e.s;
                    pq.push({-dist[e.f], e.f});
                }
            }
        }

        ma = max(ma, int((lli(e.flow) * 1e6) / dist[n]));
    }
    printf("%d", ma);
}