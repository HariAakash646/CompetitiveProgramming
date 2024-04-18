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
    freopen("input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

struct Edge {
    int v;
    int c;
    lli p;
};

int main()
{
    // usaco();
    int n, m;
    scd(n);
    scd(m);
    
    vector<vector<Edge>> graph(n+1);
    vector<map<int, lli>> val(n+1);
    frange(i, m) {
        int a, b;
        int c;
        lli p;
        scd(a);
        scd(b);
        scd(c);
        sclld(p);
        Edge ed;
        ed.v = b;
        ed.c = c;
        ed.p = p;
        graph[a].pb(ed);
        ed.v = a;
        graph[b].pb(ed);
        val[a][c] += p;
        val[b][c] += p;
    }

    vll dist(n+1, 1e18);
    vector<map<int, lli>> dp(n+1);

    priority_queue<pair<lli, pii>> pq;
    vb vis(n+1);
    vector<map<int, bool>> vis2(n+1);

    dist[1] = 0;
    pq.push(mp(0, mp(1, 0)));

    while(pq.size()) {
        auto p = pq.top();
        pq.pop();
        if(!p.s.s) 
        {
            if(vis[p.s.f]) continue;
            vis[p.s.f] = true;
            
            for(auto e : graph[p.s.f]) {
                lli v = dist[p.s.f] + min(e.p, val[p.s.f][e.c] - e.p);
                if(v < dist[e.v]) {
                    dist[e.v] = v;
                    pq.push(mp(-v, mp(e.v, 0)));
                }
                if(dp[e.v].find(p.s.f) == dp[e.v].end() || dist[p.s.f] < dp[e.v][p.s.f]) {
                    dp[e.v][p.s.f] = dist[p.s.f];
                    pq.push(mp(-dist[p.s.f], mp(e.v, p.s.f)));
                }
            }
        }
        else {
            if(vis2[p.s.f][p.s.s]) continue;
            vis2[p.s.f][p.s.s] = true;
            lli v = 0;
            int c = 0;
            // map<int, lli> val;
            for(auto e : graph[p.s.f]) {
                if(e.v == p.s.s) {
                    v = e.p;
                    c = e.c;
                    val[p.s.f][e.c] -= e.p;
                }
                
            }
            for(auto e : graph[p.s.f]) {
                if(e.v == p.s.s) continue;
                lli v1 = v + dp[p.s.f][p.s.s] + min(e.p, val[p.s.f][e.c] - e.p);
                if(v1 < dist[e.v]) {
                    dist[e.v] = v1;
                    pq.push(mp(-v1, mp(e.v, 0)));
                }
                v1 = v + dp[p.s.f][p.s.s];
                if(dp[e.v].find(p.s.f) == dp[e.v].end() || v1 < dp[e.v][p.s.f]) {
                    dp[e.v][p.s.f] = v1;
                    pq.push(mp(-v1, mp(e.v, p.s.f)));
                }
            }
            val[p.s.f][c] += v;
        }
    }
    if(dist[n] <= 1e15)
        printf("%lld\n", dist[n]);
    else printf("-1\n");
}