#include "cyberland.h"
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


vector<vii> graph;
vb vis;

void dfs(int x) {
    if(vis[x]) return;
    vis[x] = true;
    for(auto e : graph[x]) dfs(e.f);
}

double solve(int n, int m, int k, int h, std::vector<int> x, std::vector<int> y, std::vector<int> c, std::vector<int> arr) {
    graph = vector<vii>(n);
    frange(i, m) {
        int a=x[i];int b = y[i];
        if(a != h) graph[a].pb(mp(b, c[i]));
        if(b != h) graph[b].pb(mp(a, c[i]));
    }
    vis = vb(n);
    dfs(0);
    vector<vector<ld>> dist(k+1, vector<ld>(n, 1e15));
    vector<vb> vis2(k+1, vb(n));
    dist[0][0] = 0;
    priority_queue<pair<int, pair<ld, int>>> pq;
    pq.push(mp(0, mp(0, 0)));
    forr(i, 1, n) {
        if(vis[i] && arr[i] == 0) {
            dist[0][i] = 0;
            pq.push(mp(0, mp(0, i)));
        }
    }

    while(pq.size()) {
        auto p = pq.top();
        pq.pop();
        int x = p.s.s;
        int c = -p.f;
        ld w = -p.s.f;
        if(vis2[c][x]) continue;
        vis2[c][x] = true;

        for(auto e : graph[x]) {
            if(dist[c][e.f] > w + e.s) {
                dist[c][e.f] = w + e.s;
                pq.push(mp(-c, mp(-dist[c][e.f], e.f)));
            }
            if(c<k && arr[e.f]==2 && dist[c+1][e.f] > ld(w+e.s)/2) {
                dist[c+1][e.f] = ld(w+e.s)/2;
                pq.push(mp(-c-1, mp(-dist[c+1][e.f], e.f)));
            }
        }
    }

    ld mi = 1e15;
    frange(i, k+1) mi = min(mi, dist[i][h]);
    if(abs(mi-1e15)<=1) return -1;
    else
    return mi;


}