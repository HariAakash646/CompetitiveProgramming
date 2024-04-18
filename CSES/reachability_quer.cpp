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
vb vis;

vi order;

void dfs(int x) {
    vis[x] = true;
    for(auto e : graph[x]) {
        if(!vis[e]) dfs(e);
    }
    order.pb(x);
}

int id = 0;
vi pos;

void dfs2(int x) {
    vis[x] = true;
    for(auto e : gr2[x]) {
        if(!vis[e]) dfs2(e);
    }
    pos[x] = id;
}


int main() {
    // usaco();
    int n, m, q;
    scd(n);
    scd(m);
    scd(q);

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

    reverse(all(order));

    pos = vi(n+1);
    vis = vb(n+1, false);

    for(auto e : order) {
        if(!vis[e]) {
            dfs2(e);
            id++;
        }
    }

    vvi comps(id);

    forr(i, 1, n+1) {
        comps[pos[i]].pb(i);
    }

    vector<seti> cong(id);
    frange(i, id) {
        for(auto e : comps[i]) {
            for(auto x : graph[e]) {
                if(pos[x] != i) cong[i].insert(pos[x]);
            }
        }
    }

    vector<bitset<int(5e4+1)>> dp(id);

    for(int i=id-1; i>=0; i--) {
        dp[i][i] = 1;
        for(auto e : cong[i]) {
            dp[i] |= dp[e];
        }
    }

    frange(_, q) {
        int a, b;
        scd(a);
        scd(b);
        if(dp[pos[a]][pos[b]]) printf("YES\n");
        else printf("NO\n");
    }
}