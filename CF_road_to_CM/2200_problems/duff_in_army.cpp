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

vvi graph;
vi depth;
vvi binlift;
vector<vvi> binvec;

vi combine(vi &v1, vi &v2) {
    int i1 = 0;
    int i2 = 0;
    vi out(10, 1e9);

    frange(i, 10) {
        if(v1[i1] < v2[i2]) {
            out[i] = v1[i1];
            i1++;
        }
        else {
            out[i] = v2[i2];
            i2++;
        }
    }

    return out;
}

void dfs(int x, int p, int d) {
    depth[x] = d;
    binlift[0][x] = p;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x, d+1);
        }
    }
    // printf("%d %d\n", x, sze[x]);
} 

pair<int, vi> lift(int x, int c) {
    vi out(10, 1e9);
    frange(i, 20) {
        if(c & (1<<i)) {
            out = combine(out, binvec[i][x]);
            x = binlift[i][x];
        }
    }
    return mp(x, out);
}

pair<int, vi> lca(int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);
    auto va = lift(u, depth[u] - depth[v]);
    u = va.f;
    vi out = va.s;

    if(u == v) return mp(u, out);

    for(int i=19; i>=0; i--) {
        int ut = binlift[i][u];
        int vt = binlift[i][v];
        if(ut != vt) {
            out = combine(out, binvec[i][u]);
            out = combine(out, binvec[i][v]);
            u = ut;
            v = vt;
        }
    }
    out = combine(out, binvec[0][v]);
    return mp(binlift[0][u], combine(out, binvec[0][u]));
}

int main() {
    // usaco();
    int n, m, q;
    scd(n);
    scd(m);
    scd(q);

    graph = vvi(n+1);

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    binlift = vvi(20, vi(n+1));
    depth = vi(n+1);

    dfs(1, 0, 0);

    binvec = vector<vvi>(20, vvi(n+1, vi(10, 1e9)));


    vi curr(n+1);

    forr(i, 1, m+1) {
        int c;
        scd(c);
        if(curr[c] < 10) {
            binvec[0][c][curr[c]] = i;
            curr[c]++;
        }
    }

    forr(i, 1, 20) {
        forr(j, 1, n+1) {
            binlift[i][j] = binlift[i-1][binlift[i-1][j]];
            binvec[i][j] = combine(binvec[i-1][j], binvec[i-1][binlift[i-1][j]]);
        }
    }

    frange(i, q) {
        int u, v;
        scd(u);
        scd(v);
        int a;
        scd(a);

        auto out = lca(u, v);
        int l = out.f;
        vi vec = out.s;
        vec = combine(vec, binvec[0][l]);
        int c = 0;
        frange(i, a) {
            if(vec[i] != 1e9) c++;
            else break;
        }
        c = min(c, a);
        printf("%d ", c);
        frange(i, c) printf("%d ", vec[i]);
        printf("\n");
    }
}