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

vvi graph, gr2;
vi order;
vb vis;
vi comp;

void dfs(int x) {
    vis[x] = true;
    for(auto e : graph[x]) {
        if(!vis[e]) dfs(e);
    }
    order.pb(x);
}

void dfs2(int x) {
    vis[x] = true;
    comp.pb(x);
    for(auto e : gr2[x]) {
        if(!vis[e]) dfs2(e);
    }
}

int main() {
    usaco();
    int n, m;
    scd(n);
    scd(m);

    gr2 = graph = vvi(n+1);

    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        gr2[b].pb(a);
    }

    vis = vb(n+1);
    forr(i, 1, n+1) {
        if(!vis[i]) dfs(i);
    }

    vis = vb(n+1);
    vi pos(n+1);
    vi sze;
    int idx = 0;
    vi out;
    reverse(all(order));
    for(auto i : order) {
        if(!vis[i]) {
            comp = {};
            dfs2(i);
            for(auto e : comp) pos[e] = idx;

            for(auto e : comp) {
                if(e == 1) out = comp;
            }
            sze.pb(comp.size());
            idx++;
        }
    }

    int ma = sze[pos[1]];

    forr(i, 1, n+1) printf("%d ", sze[pos[i]]);

    for(auto e : out) {
        for(auto x : gr2[e]) {
            if(pos[x] != pos[1]) {
                ma = max(ma, sze[pos[1]] + sze[pos[x]]);
            }
        }
        for(auto x : graph[e]) {
            if(pos[x] != pos[1]) {
                ma = max(ma, sze[pos[1]] + sze[pos[x]]);
            }
        }
    }

    printf("%d", ma);



}