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

int n;
vvi lift;
vector<vector<pair<int, lli>>> graph;
vector<vll> liftv;
vi depth;

void dfs(int x, int p) {
    lift[0][x] = p;
    depth[x] = depth[p] + 1;
    for(auto e :graph[x]) {
        if(e.f != p) {
            liftv[0][e.f] = e.s;
            dfs(e.f, x);
        }
    }
}

pair<int, lli> binlift(int x, int c) {
    lli tot = 0;
    frange(i, 20) {
        if(c & (1<<i)) {
            tot += liftv[i][x];
            x = lift[i][x];
        }
    }
    return mp(x, tot);
}

pair<int, lli> lca(int u, int v) {
    if(depth[v] > depth[u]) swap(u, v);
    auto out = binlift(u, depth[u] - depth[v]);
    lli tot = out.s;
    u = out.f;

    if(u == v) return mp(u, tot);

    for(int i=19; i>=0; i--) {
        int ut = lift[i][u];
        int vt = lift[i][v];

        if(ut != vt) {
            tot += liftv[i][u];
            tot += liftv[i][v];
            u = ut;
            v = vt;
        }
    }

    int l = lift[0][u];
    tot += liftv[0][u] + liftv[0][v];
    return mp(l, tot);
}

lli bins(int x, int l, lli v) {
    lli tot = 0;
    for(int i=19; i>=0; i--) {
        int xt = lift[i][x];
        if(depth[xt] >= depth[l]) {
            lli v1 = liftv[i][x];
            if(tot + v1 <= v) {
                tot += v1;
                x = xt;
            }
        }
    }
    return tot;
}

lli bins2(int x, int l, lli v) {
    lli tot = 0;
    for(int i=19; i>=0; i--) {
        int xt = lift[i][x];
        if(depth[xt] > depth[l]) {
            lli v1 = liftv[i][x];
            if(tot + v1 < v) {
                tot += v1;
                x = xt;
            }
        }
    }
    tot += liftv[0][x];
    if(tot >= v) return tot;
    return 1e18;
}

int main() {
    // usaco();
    int n, q;
    scd(n);
    scd(q);
    depth = vi(n+1, -1);

    lift = vvi(20, vi(n+1));
    liftv = vector<vll>(20, vll(n+1));

    graph = vector<vector<pair<int, lli>>>(n+1);

    frange(i, n-1) {
        int a, b;
        lli c;
        scd(a);
        scd(b);
        sclld(c);

        graph[a].pb(mp(b, c));
        graph[b].pb(mp(a, c));
    }

    dfs(1, 0);
    forr(i, 1, 20) {
        forr(j, 1, n+1) {
            lift[i][j] = lift[i-1][lift[i-1][j]];
            liftv[i][j] = liftv[i-1][j] + liftv[i-1][lift[i-1][j]];
        }
    }

    frange(_, q) {
        int x, y;scd(x);
        scd(y);

        if(x == y) {
            printf("0\n");
            continue;
        }

        auto out = lca(x, y);
        int l = out.f;
        lli tot = out.s;
        // printf("%d ", l);
        printf("%lld\n", min(tot-max(bins(x, l, (tot)/2), bins(y, l, tot/2)), min(bins2(x, l, (tot+1)/2), bins2(y, l, (tot+1)/2))));
    }
}