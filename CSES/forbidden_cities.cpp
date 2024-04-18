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
vb vis;
vb tree;
vi depth, back;
vvi lift;
 
void dfs(int x, int d) {
    vis[x] = true;
    depth[x] = d;
    for(auto e : graph[x]) {
        if(!vis[e.f]) {
            tree[e.s] = true;
            lift[0][e.f] = x;
            dfs(e.f, d+1);
        }
    }
}
 
 
void dfs2(int x, int id) {
    vis[x] = true;
    back[x] = depth[x];
    for(auto e : graph[x]) {
        if(tree[e.s]) {
            if(!vis[e.f]) {
                dfs2(e.f, e.s);
                back[x] = min(back[x], back[e.f]);
            }
        }
        else {
            back[x] = min(back[x], depth[e.f]);
        }
    }
}


int binlift(int x, int c) {
    for(int i=19; i>=0; i--) {
        if(c & (1<< i)) x = lift[i][x];
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
    int n, m, q;
    scd(n);
    scd(m);
    scd(q);
 
    graph = vector<vii>(n+1);
    vii edges(m);
    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(mp(b, i));
        graph[b].pb(mp(a, i));
        edges[i] = mp(a, b);
    }
 
    vis = vb(n+1);
    tree = vb(m);
    depth = vi(n+1);
    back = vi(n+1, 1e9);
    lift = vvi(20, vi(n+1));
    dfs(1, 0);
 
    vis = vb(n+1);
    dfs2(1, 0);

    forr(i, 1, 20) {
        forr(j, 1, n+1) lift[i][j] = lift[i-1][lift[i-1][j]];
    }
    
    frange(_, q) {
        int a, b, c;
        scd(a);
        scd(b);
        scd(c);

        int l = lca(a, b);
        // printf("%d ", l);

        bool d1 = false;
        bool d2 = false;
        if(depth[c] < depth[l] || depth[c] > depth[a]) {
            d1 = true;
        }
        else {   
            int c1 = binlift(a, depth[a] - depth[c]);
            if(c1 != c) {
                d1 = true;
            }
            else {
                int a1 = binlift(a, depth[a] - depth[c] - 1);
                if(back[a1] < depth[c]) d1 = true;
            }
        }
        if(depth[c] < depth[l] || depth[c] > depth[b]) {
            d2 = true;
        }
        else {   
            int c1 = binlift(b, depth[b] - depth[c]);
            if(c1 != c) {
                d2 = true;
            }
            else {
                int b1 = binlift(b, depth[b] - depth[c] - 1);
                if(back[b1] < depth[c]) d2 = true;
            }
        }
        if(d1 && d2) printf("YES\n");
        else printf("NO\n");
    }    
}