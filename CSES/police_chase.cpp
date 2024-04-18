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
 
vector<vii> graph;
vb vis;
vb tree;
vi depth, dp;
vector<seti> val;
vii par;
int n, m;
int c = 0;
 
void dfs(int x, int d) {
    vis[x] = true;
    depth[x] = d;
    sort(all(graph[x]));
    // if(x == n) return;
    for(auto e : graph[x]) {
        if(!vis[e.f]) {
            par[e.f] = mp(x, e.s);
            tree[e.s] = true;
            dfs(e.f, d+1);
        }
    }
}
 
vi out;
 
void dfs2(int x, int id) {
    vis[x] = true;
    for(auto e : graph[x]) {
        if(tree[e.s]) {
            if(!vis[e.f]) {
 
                dfs2(e.f, e.s);
                dp[x] += dp[e.f];
                for(auto p : val[e.f]) val[x].insert(p);
            }
        }
        else {
            if(depth[e.f] > depth[x]) {
                dp[x]--;
                val[x].erase(e.s);
            }
            else {
                dp[x]++;
                val[x].insert(e.s);
            }
        }
    }
    
}
 
int main() {
    // usaco();
    
    scd(n);
    scd(m);
 
    graph = vector<vii>(n+1);
    vii edges(m);
    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(mp(b, i));
        graph[b].pb(mp(a, i));
        edges[i] = mp(a, b);
    }
 
    vis = vb(n+1);
    tree = vb(m);
    depth = dp = vi(n+1);
    par = vii(n+1);
    dfs(1, 0);
 
    vis = vb(n+1);
    val = vector<seti>(n+1);
    dfs2(1, 0);
 
    if(!vis[n]) {
        printf("0");
        return 0;
    }
 
    seti curr = val[n];
    int x = n;
 
    seti ms;
    int mi = m+1;
    
    while(x != 1) {
        for(auto e : graph[x]) {
            if(!tree[e.s]) {
                if(depth[e.f] > depth[x]) {
                    if(curr.find(e.s) != curr.end())
                        curr.erase(e.s);
                }
                else curr.insert(e.s);
            }
        }
        if(dp[x] + 1 < mi) {
            mi = dp[x] + 1;
            ms = curr;
            // printf("%d %d\n", x, mi);
            ms.insert(par[x].s);
        }
        x = par[x].f;
    }

    // frange(i, m) {
    //     if(tree[i]) printf("%d %d\n", edges[i].f, edges[i].s);
    // }
 
    printf("%d\n", mi);
    for(auto e : ms) {
        printf("%d %d\n", edges[e].f, edges[e].s);
    }

}
