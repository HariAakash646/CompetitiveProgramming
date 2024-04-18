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

int k;
vector<vii> graph;
vvi lift;
vi depth;

void dfs(int x, int p) {
    lift[0][x] = p;
    depth[x] = depth[p] + 1;
    for(auto e : graph[x]) {
        if(e.f != p) {
            dfs(e.f, x);
        }
    }
}

int binlift(int x, int c) {
    frange(i, 20) {
        if(c & (1<<i)) x = lift[i][x];
    }
    return x;
}

int lca(int u, int v) {
    if(depth[v] > depth[u]) swap(u, v);
    u = binlift(u, depth[u] - depth[v]);
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

vb pres;
vvi edg;

bool dfs2(int x, int y, int p, int id) {
    if(x == y) return true;
    for(auto e : graph[x]) {
        if(e.f != p) {
            bool out = dfs2(e.f, y, x, id);
            if(out) {
                edg[e.s].pb(id);
                return true;
            }
        }
    }
    return false;
}

vector<vector<pair<int, vi>>> tree;
vi vid;
vi cnt;

void dfs3(int x, int y, int p) {
    if(pres[x]) {
        vid[x] = tree.size();
        tree.pb(vector<pair<int, vi>>(0));
        if(y != 0) {
            tree[vid[y]].pb(mp(vid[x], cnt));
            
            tree[vid[x]].pb(mp(vid[y], cnt));
        }
        y = x;
    }

    for(auto e : graph[x]) {
        if(e.f != p) {
            for(auto id : edg[e.s]) cnt[id]++;
            dfs3(e.f, y, x);
            for(auto id : edg[e.s]) cnt[id]--;
        }
    }
}

const int MAXS = 1e6 + 5;

int dp[60][MAXS];

void dfs4(int x, int p) {
    dp[x][0] = 0;
    for(auto e : tree[x]) {
        if(e.f != p) {
            int v = 0;
            frange(i, k) {
                if(e.s[i]) v = v | (1<<i);
            }
            dfs4(e.f, x);
            // printf("%d %d\n", e.f, v);
            frange(i, 1<<k) {
                dp[x][i|v] = min(dp[x][i|v], dp[e.f][i]+1);
                
                printf("%d %d %d\n", x, i|v, dp[x][i|v]);
            }
        }
    }
}

int main() {
    usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);
        graph = vector<vii>(n+1);

        frange(i, n-1) {
            int a, b;
            scd(a);
            scd(b);
            graph[a].pb(mp(b, i));
            graph[b].pb(mp(a, i));
        }
        
        lift = vvi(20, vi(n+1));
        depth = vi(n+1);
        dfs(1, 0);

        forr(i, 1, 20) {
            forr(j, 1, n+1) lift[i][j] = lift[i-1][lift[i-1][j]];
        }

        pres = vb(n+1);
        scd(k);

        edg = vvi(n+1);

        frange(i, k) {
            int a, b;
            scd(a);
            scd(b);
            dfs2(a, b, 0, i);
            pres[a] = true;
            pres[b] = true;
            pres[lca(a, b)] = true;
        }

        vid = vi(n+1);
        tree = vector<vector<pair<int, vi>>>(0);
        cnt = vi(k);

        dfs3(1, 0, 0);

        int m = tree.size();

        frange(i, m) {
            frange(j, 1<<k) dp[i][j] = 1e9;
        }

        dfs4(0, 0);

        printf("%d\n", dp[0][(1<<k)-1]);

    }
}