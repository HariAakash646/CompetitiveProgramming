#include <bits/stdc++.h>
#include <iostream>

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
#define MP make_pair
#define pb push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

#define f first
#define s second

lli inf = 1e16;

vector<vii> graph;

int main()
{
    int n, m, k, st, en;
    scd(n);
    scd(m);
    scd(k);
    scd(st);
    scd(en);
    graph = vector<vii>(n + 1);
    frange(i, m)
    {
        int a, b, w;
        scd(a);
        scd(b);
        scd(w);
        graph[a].pb({b, w});
        graph[b].pb({a, w});
    }
    vi spec(n + 1);
    frange(i, k)
    {
        int a;
        scd(a);
        spec[a] = 1;
    }
    priority_queue<pair<lli, int>> pq;
    pq.push({0, st});
    vector<lli> dist(n + 1, inf);
    vb processed(n + 1, false);
    dist[st] = 0;
    while (pq.size())
    {
        auto p = pq.top();
        pq.pop();
        if (processed[p.s])
            continue;
        processed[p.s] = true;
        for (auto e : graph[p.s])
        {
            if (dist[e.f] > -p.f + e.s)
            {
                dist[e.f] = -p.f + e.s;
                pq.push({-dist[e.f], e.f});
            }
        }
    }
    vi path(n + 1);
    int node = en;
    path[en] = 1;
    int spc = 0;
    if (spec[en])
        spc++;
    if (dist[en] == inf)
    {
        forr(i, 1, n + 1)
        {

            printf("-1 ");
        }
        return 0;
    }
    while (node != st)
    {
        for (auto e : graph[node])
        {
            if (dist[e.f] == dist[node] - e.s)
            {
                path[e.f] = 1;
                node = e.f;
                if (spec[node])
                    spc++;
                break;
            }
        }
    }
    forr(i, 1, n + 1)
    {
        if (path[i])
        {
            printf("%d ", spc);
        }
        else
            printf("-1 ");
    }
}