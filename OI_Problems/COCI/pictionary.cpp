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

vi disset;
vector<vii> graph;

int findf(int x) {
    while(x != disset[x]) x = disset[x];
    return x;
}

void unionf(int x, int y) {
    int x2 = findf(x);
    int y2 = findf(y);
    disset[x2] = y2;
}

vii par;
vi depth;

void dfs(int x, int p, int d, int v) {
    par[x] = mp(p, v);
    depth[x] = d;
    for(auto e : graph[x]) {
        if(e.f != p) dfs(e.f, x, d+1, e.s);
    }
}

int main() {
    // usaco();
    int n, m, q;
    scd(n);
    scd(m);
    scd(q);

    graph = vector<vii>(n+1);
    disset = vi(n+1);

    frange(i, n+1) disset[i] = i;
    
    frange(i, m) {
        int v = m - i;
        for(int j=2*v; j<=n; j+=v) {
            if(findf(j) != findf(v)) {
                unionf(j, v);
                graph[j].pb(mp(v, i+1));
                graph[v].pb(mp(j, i+1));
            }
        }
    }

    depth = vi(n+1);
    par = vii(n+1);
    dfs(1, 0, 0, 0);
    frange(i, q) {
        int a, b;
        scd(a);
        scd(b);
        int ma = 0;
        if(depth[a] > depth[b]) swap(a, b);
        while(depth[b] > depth[a]) {
            ma = max(ma, par[b].s);
            b = par[b].f;
        }
        while(a != b) {
            ma = max(ma, par[b].s);
            ma = max(ma, par[a].s);
            a = par[a].f;
            b = par[b].f;
        }
        printf("%d\n", ma);

    }
}