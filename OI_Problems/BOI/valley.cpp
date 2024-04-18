#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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

vector<vii> graph;
vector<pair<pii, int>> edges;
vvi lift;
vector<vll> liftmi;
vi depth;
vll dp;
vll dist;
vb shop;

void dfs(int x, int par, int dt, lli d) {
    if(shop[x]) dp[x] = 0;
    depth[x] = dt;
    dist[x] = d;
    lift[0][x] = par;

    for(auto p : graph[x]) {
        if(p.f != par) {
            dfs(p.f, x, dt+1, d+p.s);
            dp[x] = min(dp[x], dp[p.f] + p.s);
        }
    }
}

int binlift(int x, int c) {
    frange(i, 20) {
        if(c & (1<<i)) x = lift[i][x];
    }
    return x;
}

lli binval(int x, int c) {
    lli mi = 1e18;
    frange(i, 20) {
        if(c & (1<<i)) {
            mi = min(mi, liftmi[i][x]);
            x = lift[i][x];
            // printf("%lld %d\n", mi, x);
        }
    }
    // printf("%lld %d\n", dp[x] - dist[x], x);
    return min(dp[x] - dist[x], mi);
}

int main() {
    // usaco();
    int n, st, q, e;
    scd(n);
    scd(st);
    scd(q);
    scd(e);

    graph = vector<vii>(n+1);
    depth = vi(n+1, 1);
    dp = vll(n+1, 1e18);
    dist = vll(n+1, 1e18);

    frange(i, n-1) {
        int a, b, w;
        scd(a);
        scd(b);
        scd(w);
        edges.pb(mp(mp(a, b), w));
        graph[a].pb(mp(b, w));
        graph[b].pb(mp(a, w));
    }

    shop = vb(n+1);
    frange(i, st) {
        int a;
        scd(a);
        shop[a] = true;
    }

    lift = vvi(20, vi(n+1));
    liftmi = vector<vll>(20, vll(n+1, 1e18));

    dfs(e, 0, 0, 0);

    forr(i, 1, n+1) {
        liftmi[0][i] = dp[i] - dist[i];
    }

    forr(i, 1, 20) {
        forr(j, 1, n+1) {
            lift[i][j] = lift[i-1][lift[i-1][j]];
            liftmi[i][j] = min(liftmi[i-1][j], liftmi[i-1][lift[i-1][j]]);
        }
    }

    frange(i, q) {
        int ed, r;
        scd(ed);
        scd(r);
        ed--;
        int a = edges[ed].f.f;
        int b = edges[ed].f.s;
        if(depth[a] > depth[b]) swap(a, b);
        if(depth[r] >= depth[b] && binlift(r, depth[r]- depth[b]) == b) {
            // printf("%lld ", binval(r, depth[r] - depth[b]));
            lli mi = dist[r] + binval(r, depth[r] - depth[b]);
            if(mi <= 1e16) {
                printf("%lld\n", mi);
            }
            else {
                printf("oo\n");
            }
        }
        else {
            printf("escaped\n");
        }
    }
    // forr(i, 1, n+1) printf("%lld ", dp[i]);
    // printf("\n");
    // forr(i, 1, n+1) printf("%lld ", dist[i]);
}