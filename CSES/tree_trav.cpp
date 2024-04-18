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

vi v1, v2;
vb vis;
vvi graph;

void dfs(int x, int r, int i1) {
    if(vis[v2[i1]]) {
        vis[v2[i1]] = false;
        r = v2[i1];
        if(graph[r].size() == 0) {
            // printf("%d %d\n", x, r);
            graph[r].pb(0);
        }
        dfs(x, r, i1+1);
        return;
    }
    if(x == v1.size()) return;
    graph[r].pb(v1[x]);
    // printf("%d %d\n", r, v1[x]);
    vis[v1[x]] = true;
    dfs(x+1, v1[x], i1);
}

vi out;
void trav(int x) {
    if(x == 0) return;
    if(graph[x].size()) trav(graph[x][0]);
    if(graph[x].size() == 2) trav(graph[x][1]);
    out.pb(x);    
}

int main() {
    // usaco();
    int n;
    scd(n);

    v1 = v2 = vi(n);

    frange(i, n) scd(v1[i]);
    frange(i, n) scd(v2[i]);

    graph = vvi(n+1);
    vis = vb(n+1);
    vis[v1[0]] = true;
    dfs(1, v1[0], 0);

    trav(v1[0]);

    for(auto e : out) printf("%d ", e);
}