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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vvi lift, lifti, lifta, liftv;
vvi lfgi, lfga, lfsi, lfsa;
vvi graph;
vi depth;
// vi dist;

void dfs(int x, int d) {
    depth[x] = d;
    for(auto e : graph[x]) dfs(e, d+1);
}

int binlift(int x, int c) {
    frange(i, 20) {
        if(c & (1<<i)) x = lift[i][x];
    }
    return x;
}

int lca(int u, int v) {
    if(depth[u] > depth[v]) swap(u, v);
    v = binlift(v, depth[v]-depth[u]);
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

pii binliftv(int x, int c) {
    int tot = 0;
    int mi = 0;
    int ma = 0;
    frange(i, 20) {
        if(c & (1<<i)) {
            mi = min(mi, tot + lifti[i][x]);
            ma = max(ma, tot + lifta[i][x]);
            tot += liftv[i][x];
            x = lift[i][x];
        }
    }

    return mp(tot-ma, tot-mi);
}

pii binlift2(int x, int c) {
    int smi = 0;
    int sma = 0;
    int mi = 0;
    int ma = 0;
    frange(i, 20) {
        if(c & (1<<i)) {
            mi = min(mi, lfgi[i][x]);
            mi = min(mi, smi + lifti[i][x]);
            ma = max(ma, lfga[i][x]);
            ma = max(ma, sma + lifta[i][x]);
            smi = min(smi+liftv[i][x], lfsi[i][x]);
            sma = max(sma + liftv[i][x], lfsa[i][x]);
            x = lift[i][x];
        }
    }
    return mp(mi, ma);
}

int main() {
    // usaco();
    fastio();
    int t;
    cin >> t;

    frange(_, t) {
        int q;
        cin >> q;
        vii upd;
        vector<pair<pii, int>> quer;

        frange(i, q) {
            char c;
            cin >> c;
            if(c == '+') {
                int p, v;
                cin >> p >> v;
                upd.pb(mp(p, v));
            }
            else {
                int x, y, v;
                cin >> x >> y >> v;
                quer.pb(mp(mp(x, y), v));
            }
        }

        int n = upd.size()+1;

        lfsi = lfsa = lfgi = lfga = liftv = lifti = lifta = lift = vvi(20, vi(n+1));
        graph = vvi(n+1);
        vi val(n+1);
        val[1] = 1;
        liftv[0][1] = 1;
        lifti[0][1] = min(0, 1);
        lifta[0][1] = max(0, 1);
        lfsi[0][1] = min(0, 1);
        lfsa[0][1] = max(0, 1);
        lfgi[0][1] = min(0, 1);
        lfga[0][1] = max(0, 1);

        int id = 2;
        for(auto p : upd) {
            graph[p.f].pb(id);
            lift[0][id] = p.f;
            liftv[0][id] = p.s;
            lifti[0][id] = min(0, p.s);
            lifta[0][id] = max(0, p.s);
            lfsi[0][id] = min(0, p.s);
            lfsa[0][id] = max(0, p.s);
            lfgi[0][id] = min(0, p.s);
            lfga[0][id] = max(0, p.s);
            val[id] = p.s;
            id++;
        }

        forr(i, 1, 20) {
            forr(j, 1, n+1) {
                lift[i][j] = lift[i-1][lift[i-1][j]];
                liftv[i][j] = liftv[i-1][j] + liftv[i-1][lift[i-1][j]];
                lifti[i][j] = min(lifti[i-1][j], liftv[i-1][j] + lifti[i-1][lift[i-1][j]]);
                lifta[i][j] = max(lifta[i-1][j], liftv[i-1][j] + lifta[i-1][lift[i-1][j]]);
                lfsi[i][j] = min(lfsi[i-1][lift[i-1][j]], liftv[i-1][lift[i-1][j]] + lfsi[i-1][j]);
                lfsa[i][j] = max(lfsa[i-1][lift[i-1][j]], liftv[i-1][lift[i-1][j]] + lfsa[i-1][j]);
                lfgi[i][j] = min({lfgi[i-1][j], lfgi[i-1][lift[i-1][j]], lfsi[i-1][j] + lifti[i-1][lift[i-1][j]]});
                lfga[i][j] = max({lfga[i-1][j], lfga[i-1][lift[i-1][j]], lfsa[i-1][j] + lifta[i-1][lift[i-1][j]]});

            }
        }

        depth = vi(n+1);
        dfs(1, 0);

        for(auto p : quer) {
            int l = lca(p.f.f, p.f.s);
            if(depth[p.f.f] > depth[p.f.s]) swap(p.f.f, p.f.s);
            pii pt = binlift2(p.f.f, depth[p.f.f] - depth[l]+1);
            if(pt.f <= p.s && p.s <= pt.s) {
                cout << "YES\n";
                continue;
            }
            pt = binlift2(p.f.s, depth[p.f.s] - depth[l]+1);
            if(pt.f <= p.s && p.s <= pt.s) {
                cout << "YES\n";
                continue;
            }
            pii p1 = binliftv(p.f.f, depth[p.f.f] - depth[l]+1);
            pii p2 = binliftv(p.f.s, depth[p.f.s] - depth[l]);
            // p1.f = min(0, p1.f + val[l]);
            // p1.s = max(0, p1.s + val[l]);
            // printf("%d %d %d ", l, p1.f, p1.s);
            p1.f += p2.f;
            p1.s += p2.s;
            // printf("%d %d ", p1.f, p1.s);
            if(p1.f <= p.s && p.s <= p1.s) cout<<("YES\n");
            else cout<<("NO\n");
        }
    }
}