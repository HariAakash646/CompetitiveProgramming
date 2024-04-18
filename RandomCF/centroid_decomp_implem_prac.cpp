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

int n, k;

vvi graph;
vb vis;
vi par, sze;
vi depth;
vvi lift;

void dfs1(int x, int p, int d) {
    depth[x] = d;
    lift[0][x] = p;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs1(e, x, d+1);
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

int lca(int a, int b) {
    if(depth[a] > depth[b]) swap(a, b);
    b = binlift(b, depth[b]-depth[a]);
    if(a == b) return a;

    for(int i=19; i>=0; i--) {
        int at = lift[i][a];
        int bt = lift[i][b];
        if(at != bt) {
            a = at;
            b = bt;
        }
    }
    return lift[0][a];
}

int dist(int a, int b) {
    int l = lca(a, b);
    return depth[a] + depth[b] - 2 * depth[l];
}

int find_sz(int x, int p) {
    if(vis[x]) return 0;
    sze[x] = 1;
    for(auto e : graph[x]) {
        if(e != p) {
            sze[x] += find_sz(e, x);
        }
    }
    return sze[x];
}

int find_cent(int x, int p, int n) {
    for(auto e : graph[x]) {
        if(e != p && !vis[e] && sze[e] > n/2) {
            return find_cent(e, x, n);
        }
    }
    return x;
}

int init_cent(int x, int p) {
    find_sz(x, p);
    int c = find_cent(x, -1, sze[x]);
    vis[c] = true;
    par[c] = p;

    for(auto e : graph[c]) {
        if(!vis[e]) init_cent(e, c);
    }
    return c;
}

vi cnt;
vvi centg;

lli tot = 0;

int query(int x) {
    int mi = cnt[x];
    int og = x;
    while(par[x] != 0) {
        int v = cnt[par[x]] + dist(og, par[x]);
        mi = min(mi, v);
        x = par[x];
    }
    return mi;
}

void update(int x) {
    cnt[x] = 0;
    int og = x;
    while(par[x] != 0) {
        int v = dist(og, par[x]);
        cnt[par[x]] = min(cnt[par[x]], v);
        x = par[x];
    }
}


int main() {
    // usaco();
    scd(n);
    scd(k);
    graph = vvi(n+1);

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    depth = vi(n+1);
    lift = vvi(20, vi(n+1));
    
    par = sze = vi(n+1);
    vis = vb(n+1);
    int c = init_cent(1, 0);
    dfs1(1, 0, 0);

    forr(i, 1, 20) {
        forr(j, 1, n+1) lift[i][j] = lift[i-1][lift[i-1][j]];
    }
    centg = vvi(n+1);

    // forr(i, 1, n+1) {
    //     int b = par[i];
    //     if(b) {
    //         centg[b].pb(i);
    //         centg[i].pb(b);
    //     }
    //     // printf("%d ", b);
    // }

    cnt = vi(n+1, 1e9);
    update(1);

    frange(_, k) {
        int t, u;

        scd(t);
        scd(u);

        if(t == 1) {
            update(u);
        }
        else printf("%d\n", query(u));
    }

}