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
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int main()
{
    int v, e, q;
    scd(v);
    scd(e);
    scd(q);
    vvii graph(v + 1);
    frange(i, e)
    {
        int a, b, c;
        scd(a);
        scd(b);
        scd(c);
        graph[a].pb({b, c});
        graph[b].pb({a, c});
    }
    vi dist(v + 1, 0);
    priority_queue<pii> pq;
    vb vis(v + 1);
    dist[1] = 1e6;
    pq.push({1e6, 1});

    while (pq.size())
    {
        pii p = pq.top();
        pq.pop();
        if (vis[p.s])
            continue;
        vis[p.s] = true;
        for (auto e : graph[p.s])
        {
            if (min(e.s, dist[p.s]) > dist[e.f])
            {
                dist[e.f] = min(e.s, dist[p.s]);
                pq.push({dist[e.f], e.f});
            }
        }
    }

    frange(i, q)
    {
        int x;
        scd(x);
        printf("%d\n", dist[x]);
    }
}