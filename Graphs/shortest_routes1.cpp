#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define scd(t) scanf("%lld", &t)
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
#define int_ long long

typedef pair<int_, int_> pii;
typedef vector<int_> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int_, int_> mpii;
typedef set<int_> seti;
typedef multiset<int_> mseti;
// typedef long int_ li;
// typedef unsigned long int_ uli;
// typedef long long int_ lli;
// typedef unsigned long long int_ ulli;

int main()
{
    int_ n, m;
    scd(n);
    scd(m);
    vector<vii> graph(n + 1);
    vvi dist(n + 1);
    graph[1].pb({1, 0});
    dist[1].pb(0);
    int_ a, b, c;
    frange(i, m)
    {
        scd(a);
        scd(b);
        scd(c);
        graph[a].pb({b, c});
        dist[a].pb(c);
    }
    vb vis(n + 1, false);
    priority_queue<pii> pq;
    pq.push({0, 1});
    vi vec(n + 1, 1e15);
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
        printf("%lld ", vec[i]);
    }
}