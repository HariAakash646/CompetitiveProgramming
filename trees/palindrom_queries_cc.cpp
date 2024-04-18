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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

int n;
string str;

vvi graph;
vvi lift;
vector<vvi> lift2;
vi depth;


void dfs(int x, int p, int d) {
    depth[x] = d;
    lift[0][x] = p;
    lift2[0][x][str[x-1]-'a']++;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x, d+1);
        }
    }
}

pair<int, vi> binlift(int x, int c) {
    vi out(26);
    frange(i, 20) {
        if(c & (1<<i)) {
            frange(j, 26) {
                out[j] += lift2[i][x][j];
            }
            x = lift[i][x];
        }
    }
    return mp(x, out);
}

pair<vi, vi> lca(int x, int y) {
    if(depth[x] > depth[y]) swap(x, y);
    auto p = binlift(y, depth[y] - depth[x]);
    y = p.f;
    vi yv = p.s;
    vi xvv(26);

    if(x == y) {
        return mp(xvv, yv);
    }
    for(int i=19; i>=0; i--) {
        int xt = lift[i][x];
        int yt = lift[i][y];
        if(xt != yt) {
            frange(j, 26) {
                yv[j] += lift2[i][y][j];
                xvv[j] += lift2[i][x][j];
            }
            x = xt;
            y = yt;
        }
    }
    frange(i, 26) {
        xvv[i] += lift2[0][x][i];
        yv[i] += lift2[0][y][i];
    }
    return mp(xvv, yv);

}

int main() {
    // usaco();
    fastio();
    int t;
    cin >> t;
    frange(_, t) {
        
        cin >> n;
        
        cin >> str;
        graph = vvi(n+1);
        depth = vi(n+1);
        frange(i, n-1) {
            int a, b;
            cin >>a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
        }

        lift = vvi(20, vi(n+1));
        lift2 = vector<vvi>(20, vvi(n+1, vi(26)));
        dfs(1, 0, 0);
        forr(i, 1, 20) {
            forr(j, 1, n+1) {
                lift[i][j] = lift[i-1][lift[i-1][j]];
                frange(k, 26) {
                    lift2[i][j][k] = lift2[i-1][j][k] + lift2[i-1][lift[i-1][j]][k];
                }
            }
        }
        int q;
        cin >> q;
        frange(_, q) {
            int u, v;
            cin >> u >> v;
            pair<vi, vi> out = lca(u, v);
            bool done = false;
            frange(i, 26) {
                if(out.f[i] && out.s[i]) done = true;
            }
            if(done) cout << "YES\n";
            else cout << "NO\n";
        }

    }
}