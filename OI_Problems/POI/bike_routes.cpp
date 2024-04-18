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

void dfs(int x) {
    vis[x] = true;
    for(auto e : graph[x]) {
        if(!vis[e]) dfs(e);
    }
    order.pb(x);
}

vi comp;

void dfs2(int x) {
    vis[x] = true;
    comp.pb(x);

    for(auto e : gr2[x]) {
        if(!vis[e]) dfs2(e);
    }
}

int main() {
    // usaco();
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
    reverse(all(order));
    vvi comps;
    int c = 0;
    vi pos(n+1);

    vis = vb(n+1);
    vi val;
    for(auto e : order) {
        if(!vis[e]) {
            dfs2(e);
            comps.pb(comp);
            val.pb(comp.size());
            for(auto e : comp) pos[e] = c;
            c++;
            comp = {};
        }
    }
    vi dp(c);
    for(int i=c-1; i>=0; i--) {
        seti pv;
        for(auto e : comps[i]) {
            // printf("%d ", e);
            for(auto x : graph[e]) {
                pv.insert(pos[x]);
            }
        }
        // printf("\n");
        dp[i] = val[i];
        for(auto e : pv) {
            if(e != i)
            dp[i] += dp[e];
        }
    }

    forr(i, 1, n+1) {
        printf("%d\n", dp[pos[i]]-1);
    }
}