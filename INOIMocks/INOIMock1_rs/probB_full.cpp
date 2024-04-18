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
 
 
void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}
 
struct Edge {
    int u, v, c, d;
};
 
int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);
 
    vector<Edge> vec(m);
 
    vector<seti> graph(n+1);
 
    vector<vll> dist(n+1, vll(n+1, 1e17));
 
    forr(i, 1, n+1) dist[i][i] = 0;
 
    frange(i, m) {
        int u, v, c, d;
        scd(u);
        scd(v);
        scd(c);
        scd(d);
        vec[i].u = u;
        vec[i].v = v;
        vec[i].c = c;
        vec[i].d = d;
 
        dist[u][v] = min(dist[u][v], (lli)c);
        graph[u].insert(i);
    }
 
    forr(k, 1, n+1) {
        forr(i, 1, n+1) {
            forr(j, 1, n+1) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
 
    // vb inpath(m);
 
    // queue<pii> q;
    // q.push(mp(1, -10));
    // vi par(n+1, -1);
    // if(dist[1][n] < 1e16)
    // {
    //     while(q.size()) {
    //         auto p = q.front();
    //         q.pop();
    //         if(par[p.f] != -1) continue;
    //         par[p.f] = p.s;
 
    //         if(p.f == n) {
    //             int curr = n;
    //             while(curr != 1) {
    //                 // printf("%d ", curr);
    //                 inpath[par[curr]] = true;
    //                 curr = vec[par[curr]].u;
    //             }
    //         }
 
    //         for(auto e : graph[p.f]) {
    //             if(dist[1][vec[e].u] + vec[e].c + dist[vec[e].v][n] == dist[1][n]) {
    //                 q.push(mp(vec[e].v, e));
    //             }
    //         }
    //     }
        
    // }
 
    lli mi = dist[1][n] + dist[n][1];
 
    // frange(i, m) {
    //     auto p = vec[i];
    //     lli v = dist[n][p.v] + dist[p.u][1] + p.c + p.d;
 
    //     if(v + dist[1][n] < mi) {
    //         graph[p.u].erase(i);
    //         graph[p.v].insert(i);
 
    //         swap(vec[i].u, vec[i].v);
    
    //         vll dist2(n+1, 1e16);
    //         priority_queue<pair<lli, int>> pq;
    //         pq.push(mp(0, 1));
    //         dist2[1] = 0;
    //         vb vis(n+1);
    //         while(pq.size()) {
    //             auto p = pq.top();
    //             pq.pop();
    
    //             if(vis[p.s]) continue;
    //             vis[p.s] = true;
    
    //             for(auto j : graph[p.s]) {
    //                 auto e = vec[j];
    //                 if(dist2[p.s] + e.c < dist2[e.v]) {
    //                     dist2[e.v] = dist2[p.s] + e.c;
    //                     pq.push(mp(-dist2[e.v], e.v));
    //                 }
    //             }
    //         }
    //         v += dist2[n];
    //         graph[p.v].erase(i);
    //         graph[p.u].insert(i);
    //         mi = min(mi, v);
    //         swap(vec[i].u, vec[i].v);
    //     }
    //     // else {
    //     //     v += dist[1][n];
    //     // }
    //     // mi = min(mi, v);
    // }
 
    // inpath = vb(m);
 
    // q = {};
    // q.push(mp(n, -10));
    // par = vi(n+1, -1);
    // if(dist[n][1] < 1e16)
    // {
    //     while(q.size()) {
    //         auto p = q.front();
    //         q.pop();
    //         if(par[p.f] != -1) continue;
    //         par[p.f] = p.s;
 
    //         if(p.f == 1) {
    //             int curr = 1;
    //             while(curr != n) {
    //                 // printf("%d ", curr);
    //                 inpath[par[curr]] = true;
    //                 curr = vec[par[curr]].u;
    //             }
    //         }
 
    //         for(auto e : graph[p.f]) {
    //             if(dist[n][vec[e].u] + vec[e].c + dist[vec[e].v][1] == dist[n][1]) {
    //                 q.push(mp(vec[e].v, e));
    //             }
    //         }
    //     }
        
    // }
 
    frange(i, m) {
        auto p = vec[i];
        // lli v = min(dist[1][n], dist[1][p.v] + dist[p.u][n] + p.c) + p.d;
 
        lli d1 = min(dist[1][n], dist[1][p.v] + dist[p.u][n] + p.c);
        lli d2 = min(dist[n][1], dist[n][p.v] + dist[p.u][1] + p.c);
 
        if(d1 + d2 + p.d < mi) {
            lli v = p.d;
            graph[p.u].erase(i);
            graph[p.v].insert(i);
 
            swap(vec[i].u, vec[i].v);
    
            vll dist2(n+1, 1e16);
            priority_queue<pair<lli, int>> pq;
            pq.push(mp(0, n));
            dist2[n] = 0;
            vb vis(n+1);
            while(pq.size()) {
                auto p = pq.top();
                pq.pop();
    
                if(vis[p.s]) continue;
                vis[p.s] = true;
    
                for(auto j : graph[p.s]) {
                    auto e = vec[j];
                    if(dist2[p.s] + e.c < dist2[e.v]) {
                        dist2[e.v] = dist2[p.s] + e.c;
                        pq.push(mp(-dist2[e.v], e.v));
                    }
                }
            }
            v += dist2[1];
 
            dist2 = vll(n+1, 1e16);
            pq.push(mp(0, 1));
            dist2[1] = 0;
            vis=vb(n+1);
            while(pq.size()) {
                auto p = pq.top();
                pq.pop();
    
                if(vis[p.s]) continue;
                vis[p.s] = true;
    
                for(auto j : graph[p.s]) {
                    auto e = vec[j];
                    if(dist2[p.s] + e.c < dist2[e.v]) {
                        dist2[e.v] = dist2[p.s] + e.c;
                        pq.push(mp(-dist2[e.v], e.v));
                    }
                }
            }
            v += dist2[n];
 
            graph[p.v].erase(i);
            graph[p.u].insert(i);
            mi = min(mi, v);
            swap(vec[i].u, vec[i].v);
        }
        // else {
        //     v += dist[n][1];
        // }
        // mi = min(mi, v);
    }
 
    // frange(i, m) {
    //     auto p = vec[i];
    //     lli v = dist[1][p.v] + dist[p.u][n] + p.c + p.d + dist[n][p.v] + dist[p.u][1] + p.c;
    //     mi = min(mi, v);
    // }
 
    if(mi < 1e16) printf("%lld", mi);
    else printf("-1");
 
}