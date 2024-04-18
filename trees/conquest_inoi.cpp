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

int n, q;
vvi graph;
vi depth;
vll val;

const int MAXN = 5e5+5;

int lift[MAXN][20];
lli lift2[MAXN][20][2][2];

void dfs(int x, int p, int d) {
    lift[x][0] = p;
    depth[x] = d;
    lift2[x][0][1][1] = 0;
    lift2[x][0][1][0] = val[x];
    lift2[x][0][0][1] = val[p];

    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x, d+1);
        }
    }
}

pair<int, pair<lli, lli>> binlift(int x, int c) {
    lli v0 = 0;
    lli v1 = val[x];
    frange(i, 20) {
        if(c & (1<<i)) {
            lli tv0 = max(v0 + lift2[x][i][0][0], v1 + lift2[x][i][1][0] - val[x]);
            v1 = max(v0 + lift2[x][i][0][1], v1 + lift2[x][i][1][1] - val[x]);
            v0 = tv0;
            x = lift[x][i];
        }
    }
    return mp(x, mp(v0, v1));
}

lli lca(int x, int y) {
    if(depth[x] > depth[y]) swap(x, y);
    lli xv0 = 0;
    lli xv1 = val[x];
    auto p = binlift(y, depth[y] - depth[x]);
    y = p.f;
    lli yv0 = p.s.f;
    lli yv1 = p.s.s;

    if(x == y) {
        lli out = xv0 + yv0;
        out = max(out, xv1 + yv1 - val[x]);
        return out; 
    }

    for(int i=19; i>=0; i--) {
        int xt = lift[x][i];
        int yt = lift[y][i];
        if(xt != yt) {
            lli txv0 = max(xv0 + lift2[x][i][0][0], xv1 + lift2[x][i][1][0] - val[x]);
            lli tyv0 = max(yv0 + lift2[y][i][0][0], yv1 + lift2[y][i][1][0] - val[y]);

            xv1 = max(xv0 + lift2[x][i][0][1], xv1 + lift2[x][i][1][1] - val[x]);
            yv1 = max(yv0 + lift2[y][i][0][1], yv1 + lift2[y][i][1][1] - val[y]);

            xv0 = txv0;
            yv0 = tyv0;
            x = lift[x][i];
            y = lift[y][i];
        }
    }
    lli txv0 = max(xv0 + lift2[x][0][0][0], xv1 + lift2[x][0][1][0] - val[x]);
    lli tyv0 = max(yv0 + lift2[y][0][0][0], yv1 + lift2[y][0][1][0] - val[y]);

    xv1 = max(xv0 + lift2[x][0][0][1], xv1 + lift2[x][0][1][1] - val[x]);
    yv1 = max(yv0 + lift2[y][0][0][1], yv1 + lift2[y][0][1][1] - val[y]);

    xv0 = txv0;
    yv0 = tyv0;

    x = lift[x][0];
    lli out = xv0 + yv0;
    out = max(out, xv1 + yv1 - val[x]);
    return out;
}

int main() {
    // usaco();
    scd(n);
    scd(q);

    graph = vvi(n+1);
    val = vll(n+1);

    forr(i, 1, n+1) sclld(val[i]);

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    depth = vi(n+1);
    dfs(1, 0, 0);

    forr(i, 1, 20) {
        forr(j, 1, n+1) {
            lift[j][i] = lift[lift[j][i-1]][i-1];
            frange(l1, 2) {
                frange(l2, 2) {
                    lift2[j][i][l1][l2] = lift2[j][i-1][l1][0] + lift2[lift[j][i-1]][i-1][0][l2];
                    lift2[j][i][l1][l2] = max(lift2[j][i][l1][l2], lift2[j][i-1][l1][1] + lift2[lift[j][i-1]][i-1][1][l2] - val[lift[j][i-1]]);
                }
            }
        }
    }


    frange(_, q) {
        int u, v;
        scd(u);
        scd(v);
        lli ans = lca(u, v);
        printf("%lld\n", ans);
    }
}