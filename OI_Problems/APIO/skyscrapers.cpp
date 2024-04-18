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

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);

    int sq = 250;

    vector<vii> graph(n);
    vector<vb> con(n, vb(sq));
    vector<vi> consq(n+1);

    int st;
    int en;
    
    frange(i, m) {
        int b, p;
        scd(b);
        scd(p);
        if(i == 0) st = b;
        if(i == 1) en = b;
        if(p >= sq) {
            for(int i=1; b+i*p<n; i++) {
                graph[b].pb(mp(b+i*p, i));
                // printf("%d %d %d\n", b, b+i*p, i);
            }
            for(int i=1; b-i*p>=0; i++) {
                graph[b].pb(mp(b-i*p, i));
                // printf("%d %d %d\n", b, b-i*p, i);
            }
        }
        else {
            con[b][p] = true;
            consq[b].pb(p);
        }
    }

    // forr(p, 1, sq) {
    //     vb vis(n);
    //     queue<int> q;
    //     frange(i, n) {
    //         if(con[i][p]) q.push(i);
    //     }
    //     while(q.size()) {
    //         auto x = q.front();
    //         q.pop();
    //         if(vis[x]) continue;
    //         vis[x] = true;
    //         if(x + p < n) {
    //             graph[x].pb(mp(x+p, 1));
    //             q.push(x+p);
    //             printf("%d %d %d\n", x, x+p, 1);
    //         }
    //         if(x - p >= 0) {
    //             graph[x].pb(mp(x-p, 1));
    //             q.push(x-p);
    //             printf("%d %d %d\n", x, x-p, 1);
    //         }
    //     }
    // }

    vector<vb> vis(n, vb(sq));
    vvi dist(n, vi(sq, 2e9));
    dist[st][0] = 0;
    forr(i, 1, sq) {
        if(con[st][i]) dist[st][i] = 0;
    }
    priority_queue<pair<int, pii>> pq;
    pq.push(mp(0, mp(st, 0)));

    while(pq.size()) {
        auto p = pq.top();
        pq.pop();
        if(vis[p.s.f][p.s.s]) continue;
        vis[p.s.f][p.s.s] = true;
        dist[p.s.f][0] = min(dist[p.s.f][0], -p.f);
        for(auto e : graph[p.s.f]) {
            if(-p.f + e.s < dist[e.f][0]) {
                dist[e.f][0] = -p.f + e.s;
                // printf("%d %d\n", e.f, 0);
                pq.push(mp(-dist[e.f][0], mp(e.f, 0)));
            }
        }
        
        if(p.s.s) {
            if(p.s.f + p.s.s < n && -p.f + 1 < dist[p.s.f + p.s.s][p.s.s]) {
                dist[p.s.f + p.s.s][p.s.s] = -p.f + 1;
                pq.push(mp(-dist[p.s.f + p.s.s][p.s.s], mp(p.s.f + p.s.s, p.s.s)));
                // printf("%d %d\n", p.s.f + p.s.s, p.s.s);
            }
            if(p.s.f - p.s.s >= 0 && -p.f + 1 < dist[p.s.f - p.s.s][p.s.s]) {
                dist[p.s.f - p.s.s][p.s.s] = -p.f + 1;
                pq.push(mp(-dist[p.s.f - p.s.s][p.s.s], mp(p.s.f - p.s.s, p.s.s)));
                // printf("%d %d\n", p.s.f - p.s.s, p.s.s);
            }
        }
        for(auto i : consq[p.s.f]) {
            dist[p.s.f][i] = min(dist[p.s.f][i], dist[p.s.f][0]);
            if(p.s.f + i < n && -p.f + 1 < dist[p.s.f + i][i]) {
                dist[p.s.f + i][i] = -p.f + 1;
                pq.push(mp(-dist[p.s.f + i][i], mp(p.s.f + i, i)));
                // printf("%d %d\n", p.s.f+i, i);
            }
            if(p.s.f - i >= 0 && -p.f + 1 < dist[p.s.f - i][i]) {
                dist[p.s.f - i][i] = -p.f + 1;
                pq.push(mp(-dist[p.s.f - i][i], mp(p.s.f - i, i)));
                // printf("%d %d\n", p.s.f-i, i);
            }
        }
        
    }
    int mi = 2e9;
    frange(i, sq) mi = min(mi, dist[en][i]);
    if(mi < 2e9) printf("%d", mi);
    else printf("-1");


}