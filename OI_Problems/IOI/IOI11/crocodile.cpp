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

int travel_plan(int n, int m, int edge[][2], int time[], int k, int en[])
{
    vector<vector<pair<int, lli>>> graph(n);
    frange(i, m)
    {
        int a = edge[i][0];
        int b = edge[i][1];
        lli c = time[i];
        graph[a].pb({b, c});
        graph[b].pb({a, c});
    }
    priority_queue<pair<lli, int>> pq;
    vector<pair<lli, lli>> dist(n, mp(1e16, 1e16));
    vb vis(n);
    frange(i, k)
    {
        pq.push({0, en[i]});
        dist[en[i]] = {0, 0};
    }

    while (pq.size())
    {
        auto p = pq.top();
        pq.pop();
        if (vis[p.s])
            continue;
        vis[p.s] = true;
        for (auto e : graph[p.s])
        {
            if (e.s + dist[p.s].s < dist[e.f].f)
            {
                dist[e.f].s = dist[e.f].f;
                dist[e.f].f = e.s + dist[p.s].s;
                pq.push({-dist[e.f].s, e.f});
            }
            else if (e.s + dist[p.s].s < dist[e.f].s)
            {
                dist[e.f].s = e.s + dist[p.s].s;
                pq.push({-dist[e.f].s, e.f});
            }
        }
    }
    return int(dist[0].s);
}
