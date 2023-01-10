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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
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

int main()
{
    int n, m;
    scd(n);
    scd(m);
    vector<vii> graph(n + 1);
    vvi dist(n + 1);
    graph[1].pb({1, 0});
    dist[1].pb(0);
    int a, b, c;
    frange(i, m)
    {
        scd(a);
        scd(b);
        scd(c);
        graph[a].pb({b, c});
        graph[b].pb({a, c});
        dist[a].pb(c);
        dist[b].pb(c);
    }
    vb vis(n + 1, false);
    priority_queue<pii> pq;
    pq.push({0, 1});
    vi vec(n + 1, 1e9);
    while (pq.size())
    {
        pii ele = pq.top();
        pq.pop();
        if (vis[ele.s])
            continue;
        vis[ele.s] = true;
        forr(i, 0, graph[ele.s].size(), 1)
        {
            vec[graph[ele.s][i].f] = min(vec[graph[ele.s][i].f], dist[ele.s][i] - ele.f);
            pq.push({-vec[graph[ele.s][i].f], graph[ele.s][i].f});
            // cout << graph[ele.s][i].f << " " << vec[graph[ele.s][i].f] << "\n";
        }
    }
    forr(i, 1, n + 1, 1)
    {
        printf("%d ", vec[i]);
    }
}