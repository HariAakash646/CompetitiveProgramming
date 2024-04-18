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

vi graph;
vector<vii> swp;
vb vis;

void dfs(int x, int p, int d) {
    if(vis[x]) return;
    vis[x] = true;
    if(p == graph[x]) return;

    if(swp.size() < d+1) {
        swp.pb(vii());
        
    }
    swp[d].pb(mp(p+1, graph[x]+1));
    dfs(graph[x], p, d+1);
}

int main() {
    usaco();
    int n;
    scd(n);

    vi vec(n);
    vi pos(n+1);
    frange(i, n) {
        scd(vec[i]);
        pos[vec[i]] = i;
    }

    vi cnt(n);

    

    graph = vi(n);

    vi v2 = vec;
    forr(i, 1, n+1) {
        if(pos[i] != i-1) {
            graph[pos[i]] = i-1;
        }
        else graph[pos[i]] = -1;
    }
    frange(i, n) printf("%d ", graph[i]);
    printf("\n");
    vis = vb(n);
    forr(i, 0, n) {
        if(!vis[i] && graph[i] != -1) dfs(i, i, 0);
    }
    printf("%d\n", (int)swp.size());
    for(auto v : swp) {
        printf("%d\n", (int)v.size());
        for(auto p : v) printf("%d %d\n", p.f, p.s);
    }

}