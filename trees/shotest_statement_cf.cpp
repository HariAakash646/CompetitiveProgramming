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

vector<vii> tree;
vi disset, sze;

int findf(int x)
{
    while (x != disset[x])
    {
        x = disset[x];
    }
    return x;
}

void unionf(int x, int y)
{
    x = findf(x);
    y = findf(y);
    if (x == y)
        return;
    if (sze[x] < sze[y])
    {
        swap(x, y);
    }
    disset[y] = x;
    sze[x] = max(sze[x], sze[y] + 1);
}

vll dp;
vi depth;
vvi lift;

void dfs(int x, int p, int d) {
    depth[x] = d;
    lift[0][x] = p;
    for(auto e : tree[x]) {
        if(e.f != p) {
            dp[e.f] = dp[x] + e.s;
            dfs(e.f, x, d+1);
        }
    }
}

int binlift(int x, int c) {
    frange(i, 20) {
        if(c & (1<<i)) {
            x = lift[i][x];
        }
    }
    return x;
}

int lca(int u, int v) {
    if(depth[u] > depth[v]) swap(u, v);
    v = binlift(v, depth[v] - depth[u]);

    if(u == v) return u;

    for(int i=19; i>=0; i--) {
        int ut = lift[i][u];
        int vt = lift[i][v];
        if(ut != vt) {
            u = ut;
            v = vt;
        }
    }
    return lift[0][u];
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);

    vector<vii> graph(n+1);
    vector<pair<int, pii>> edges(m);

    tree = vector<vii>(n+1);

    frange(i, m) {
        int a, b, c;
        scd(a);
        scd(b);
        scd(c);
        graph[a].pb(mp(b, c));
        graph[b].pb(mp(a, c));
        edges[i] = mp(c, mp(a, b));
    }

    sort(all(edges));

    disset = vi(n+1);
    sze = vi(n+1);

    forr(i, 1, n+1) disset[i] = i;

    vi djk;
    for(auto p : edges) {
        if(findf(p.s.f) != findf(p.s.s)) {
            unionf(p.s.f, p.s.s);
            tree[p.s.f].pb(mp(p.s.s, p.f));
            tree[p.s.s].pb(mp(p.s.f, p.f));
        }
        else {djk.pb(p.s.s);}
    }
    int x = djk.size();
    vector<vll> dist(x, vll(n+1, 1e18));
    frange(i, x) {
        int e = djk[i];
        vb vis(n+1);
        priority_queue<pair<lli, int>> pq;
        dist[i][e] = 0;
        pq.push(mp(0, e));

        while(pq.size()) {
            auto p = pq.top();
            pq.pop();
            if(vis[p.s]) continue;
            vis[p.s] = true;
            for(auto e : graph[p.s]) {
                if(-p.f + e.s < dist[i][e.f]) {
                    dist[i][e.f] = -p.f + e.s;
                    pq.push(mp(-dist[i][e.f], e.f));
                }
            }
        }
        // printf("%d: ", e);
        // forr(j, 1, n+1) printf("%lld ", dist[i][j]);
        // printf("\n");
    }

    dp = vll(n+1);
    depth = vi(n+1);
    lift = vvi(20, vi(n+1));

    dfs(1, 0, 0);

    forr(i, 1, 20) {
        forr(j, 1, n+1) {
            lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }

    int q;
    scd(q);
    frange(_, q) {
        int u, v;
        scd(u);
        scd(v);
        int l = lca(u, v);
        lli d = dp[u] + dp[v] - 2 * dp[l];
        // printf("%lld ", d);
        frange(i, x) {
            d = min(d, dist[i][u] + dist[i][v]);
        }
        printf("%lld\n", d);
    }

}