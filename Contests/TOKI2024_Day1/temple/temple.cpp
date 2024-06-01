#include "temple.h"
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

int n, m;
vector<vector<pair<int, lli>>> graph;

vi disset, sze, pos;

int findf(int x) {
    if(x == disset[x]) return x;
    disset[x] = findf(disset[x]);
    return disset[x];
}

void unionf(int u, int v) {
    u = findf(u);
    v = findf(v);
    if(u==v) return;
    if(sze[u] < sze[v]) swap(u, v);
    disset[v] = u;
    sze[u] = max(sze[u], sze[v]+1); 
    
    graph.pb({mp(pos[u], 0LL), mp(pos[v], 0LL)});
    // printf("%d: %d %d\n", (int)graph.size()-1, pos[u], pos[v]);
    pos[u] = (int)graph.size() - 1;
}

long long min_weight(int N, int M, int K,
                     std::vector<int> U, std::vector<int> V, std::vector<int> W,
                     std::vector<int> P) {
    n = N;
    m = M;

    vector<pair<lli, pii>> edg(m);

    frange(i, m) {
        edg[i].f = W[i];
        edg[i].s = mp(U[i], V[i]);
    }
    sort(all(edg));
    int id = 0;

    disset = vi(n);
    sze = vi(n);
    pos = vi(n);

    frange(i, n) {disset[i] = i;pos[i] = i;}

    graph = vector<vector<pair<int, lli>>>(n);

    for(auto p : edg) {
        while(id < m && edg[id].f <= p.f) {
            // printf("%d %d\n", edg[id].s.f, edg[id].s.s);
            unionf(edg[id].s.f, edg[id].s.s);
            id++;
        }
        int v = pos[findf(p.s.f)];
        graph[p.s.f].pb(mp(v, p.f));
        v = pos[findf(p.s.s)];
        graph[p.s.s].pb(mp(v, p.f));
    }
    int sz = graph.size();
    vll dist(sz, 1e18);
    priority_queue<pair<lli, int>> pq;

    for(auto e : P) {
        dist[e] = 0;
        pq.push(mp(0, e));
    }
    vb vis(sz);
    while(pq.size()) {
        auto p = pq.top();
        pq.pop();
        if(vis[p.s]) continue;
        vis[p.s] = true;

        // printf("%d %lld\n", p.s, -p.f);

        for(auto e : graph[p.s]) {
            if(dist[e.f] > -p.f + e.s) {
                dist[e.f] = -p.f + e.s;
                pq.push(mp(-dist[e.f], e.f));
            }
        }
    }

    return dist[0];
}
