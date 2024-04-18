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


bool con[1001][1001];

vi disset;

int findf(int x) {
    if(x == disset[x]) return x;
    disset[x] = findf(disset[x]);
    return disset[x];
}

bool unionf(int u, int v) {
    u = findf(u);
    v = findf(v);
    if(u == v) return false;
    disset[u] = v;
    return true;
}

vector<vii> graph;
vvi lift, liftv;
vi depth;

void dfs(int x, int p) {
    lift[0][x] = p;
    depth[x] = depth[p]+1;

    for(auto e : graph[x]) {
        if(e.f != p) {
            liftv[0][e.f] = e.s;
            dfs(e.f, x);
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
    v = binlift(v, depth[v]-depth[u]);

    if(u == v) return v;

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

int binliftv(int x, int c) {
    int ma = 0;
    frange(i, 20) {
        if(c & (1<<i)) {
            ma = max(ma, liftv[i][x]);
            x = lift[i][x];
        }
    }
    return ma;
}

int main() {
    // usaco();
    int t, g;
    scd(t);
    scd(g);

    frange(_, t) {
        int n, m;
        scd(n);
        scd(m);

        forr(i, 1, n+1) {
            forr(j, 1, n+1) con[i][j] = false;
        }

        vector<pair<int, pii>> edg(m);
        vii quer;
        // vector<vb> con(n+1, vb(n+1));
        frange(i, m) {
            scd(edg[i].s.f);
            scd(edg[i].s.s);
            scd(edg[i].f);
            quer.pb(mp(edg[i].s.f, edg[i].s.s));
            con[edg[i].s.f][edg[i].s.s] = true;
            con[edg[i].s.s][edg[i].s.f] = true;
        }
        sort(all(edg));

        disset = vi(n+1);
        forr(i, 1, n+1) disset[i] = i;
        graph = vector<vii>(n+1);

        vector<pair<int, pii>> edg2;

        for(auto p : edg) {
            // bool out = unionf(p.s.f, p.s.s);
            int u = findf(p.s.f);
            int v = findf(p.s.s);
            if(u != v) {

                forr(i, 1, n+1) {
                    forr(j, 1, n+1) {
                        if(findf(i) == u && findf(j) == v) {
                            if(!con[i][j]) {
                                // printf("%d %d")
                                edg2.pb(mp(p.f, mp(i, j)));
                            }
                        }
                    }
                }
                unionf(u, v);
            }
        }

        forr(i, 1, n+1) disset[i] = i;

        sort(all(edg2));
        for(auto p : edg2) {
            if(unionf(p.s.f, p.s.s)) {
                // printf("%d %d\n", p.s.f, p.s.s);
                graph[p.s.f].pb(mp(p.s.s, p.f));
                graph[p.s.s].pb(mp(p.s.f, p.f));
            }
        }

        lift = liftv = vvi(20, vi(n+1));
        depth = vi(n+1);
        dfs(1, 0);

        forr(i, 1, 20) {
            forr(j, 1, n+1) {
                lift[i][j] = lift[i-1][lift[i-1][j]];
                liftv[i][j] = max(liftv[i-1][j], liftv[i-1][lift[i-1][j]]);
            }
        }

        for(auto p : quer) {
            int l = lca(p.f, p.s);
            int ma = binliftv(p.f, depth[p.f] - depth[l]);
            ma = max(ma, binliftv(p.s, depth[p.s] - depth[l]));
            printf("%d ", ma);
        }
        printf("\n");
    }
}