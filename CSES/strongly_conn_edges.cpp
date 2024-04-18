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
int c = 0;

void dfs(int x, int d) {
    vis[x] = true;
    depth[x] = d;
    for(auto e : graph[x]) {
        if(!vis[e.f]) {
            tree[e.s] = true;
            dfs(e.f, d+1);
        }
    }
}

void dfs2(int x) {
    vis[x] = true;
    for(auto e : graph[x]) {
        if(tree[e.s]) {
            if(!vis[e.f]) {
                dfs2(e.f);
                dp[x] += dp[e.f];
            }
        }
        else {
            if(depth[e.f] > depth[x]) dp[x]--;
            else dp[x]++;
        }
    }
    if(x != 1 && dp[x] == 0) c++;
}

int main() {
    // usaco();
    int n, m;
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
    dfs(1, 0);
    vis = vb(n+1);
    dfs2(1);

    forr(i, 1, n+1) {
        if(!vis[i]) c = 100;
    }

    if(c > 0) printf("IMPOSSIBLE");
    else {
        frange(i, m) {
            int a = edges[i].f;
            int b = edges[i].s;
            if(depth[a] > depth[b]) swap(a, b);
            if(tree[i]) {
                printf("%d %d\n", a, b);
            }
            else printf("%d %d\n", b, a);
        }
    }
}
