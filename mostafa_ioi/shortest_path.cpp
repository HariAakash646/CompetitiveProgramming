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

vector<vii> graph;
int n, m, a, b;
vvi tree;
vi st, en;
int timer = 0;

void dfs(int x, int p) {
    st[x] = ++timer;
    for(auto e : tree[x]) {
        if(e != p) dfs(e, x);
    }
    en[x] = timer;
}

int main() {
    // usaco();
    
    scd(n);
    scd(m);
    scd(a);
    scd(b);

    graph = vector<vii>(n+1);
    vvi edge(n+1, vi(n+1));
    vector<pair<pii, int>> edgs;

    frange(i, m) {
        int a, b, c;
        scd(a);
        scd(b);
        scd(c);
        edge[a][b] = edge[b][a] = c;
        graph[a].pb(mp(b, c));
        graph[b].pb(mp(a, c));
        edgs.pb(mp(mp(a, b), c));
    }

    int k;
    scd(k);
    vi vec(k+1);
    frange(i, k) scd(vec[i+1]);

    tree = vvi(n+1);
    vll dista(n+1, 1e18);
    priority_queue<pair<lli, pii>> pq;
    vb vis(n+1);

    lli tot = 0;
    forr(i, 1, k+1) {
        tot += edge[vec[i-1]][vec[i]];
        dista[vec[i]] = tot;
        pq.push(mp(-dista[vec[i]], mp(vec[i], vec[i-1])));
    }

    while(pq.size()) {
        auto p = pq.top();
        pq.pop();
        if(vis[p.s.f]) continue;
        vis[p.s.f] = true;
        tree[p.s.f].pb(p.s.s);
        tree[p.s.s].pb(p.s.f);

        for(auto e : graph[p.s.f]) {
            if(-p.f + e.s < dista[e.f]) {
                dista[e.f] = -p.f + e.s;
                pq.push(mp(-dista[e.f], mp(e.f, p.s.f)));
            }
        }
    }

    st = en = vi(n+1);
    dfs(a, 0);

    vll distb(n+1, 1e18);

    priority_queue<pair<lli, int>> pq2;
    pq2.push(mp(0, b));
    distb[b] = 0;
    vis = vb(n+1);

    while(pq2.size()) {
        auto p = pq2.top();
        pq2.pop();
        if(vis[p.s]) continue;
        vis[p.s] = true;

        for(auto e : graph[p.s]) {
            if(-p.f + e.s < distb[e.f]) {
                distb[e.f] = -p.f + e.s;
                pq2.push(mp(-distb[e.f], e.f));
            }
        }
    }

    forr(i, 2, k+1) {
        int id = vec[i]; 
        lli mi = 1e18;
        for(auto p : edgs) {
            int u = p.f.f;
            int v = p.f.s;
            if((u == vec[i-1] && v == vec[i]) || (u == vec[i] && v == vec[i-1])) continue;

            if((st[id] <= st[u] && st[u] <= en[id]) && !(st[id] <= st[v] && st[v] <= en[id])) {
                // printf("%d %d %lld\n", v, u, dista[v] + distb[u] + p.s);
                mi = min(mi, dista[v] + distb[u] + p.s);
            }
            if((st[id] <= st[v] && st[v] <= en[id]) && !(st[id] <= st[u] && st[u] <= en[id])) {
                // printf("%d %d %lld\n", u, v, dista[u] + distb[v] + p.s);
                mi = min(mi, dista[u] + distb[v] + p.s);
            }
        }
        if(mi == 1e18) mi = -1;
        printf("%lld\n", mi);
    }
}