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
vi depth, back;
 
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
 
seti out;
 
void dfs2(int x, int id) {
    vis[x] = true;
    int c1 = 0;
    bool art = false;
    back[x] = depth[x];
    for(auto e : graph[x]) {
        if(tree[e.s]) {
            if(!vis[e.f]) {
                dfs2(e.f, e.s);
                back[x] = min(back[x], back[e.f]);
                c1++;
                if(back[e.f] >= depth[x]) art = true; 
            }
        }
        else {
            back[x] = min(back[x], depth[e.f]);
        }
    }
    if(x != 1 && c1 > 0 && art) out.insert(x);
    if(x == 1 && c1 > 1) out.insert(x);
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
    depth = vi(n+1);
    back = vi(n+1, 1e9);
    dfs(1, 0);
 
    vis = vb(n+1);
    dfs2(1, 0);
 
    printf("%d\n", (int)out.size());
    for(auto i : out) {
        printf("%d ", i);
    }
    
}