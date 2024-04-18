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

void dfs(int x) {
    vis[x] = true;
    for(auto e : graph[x]) {
        if(!vis[e.f]) {
            tree[e.s] = true;
            dfs(e.f);
        }
    }
}

vi out;

int dfs2(int x) {
    out.pb(x);
    for(auto e : graph[x]) {
        if(!vis[e.s] && !tree[e.s]) {
            vis[e.s] = true;
            int v = dfs2(e.f);
            return v;
        } 
    }
    for(auto e : graph[x]) {
        if(!vis[e.s]) {
            vis[e.s] = true;
            return dfs2(e.f);
        }
    }
    return x;
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);

    graph = vector<vii>(n+1);

    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(mp(b, i));
        graph[b].pb(mp(a, i));
    }

    vis = vb(n+1);
    tree = vb(m);

    dfs(1);
    vis = vb(m);
    int v = dfs2(1);

    if(v != 1) printf("IMPOSSIBLE");
    else {
        bool done = true;
        frange(i, m) {
            if(!vis[i]) done = false;
        }
        if(!done) printf("IMPOSSIBLE");
        else {
            for(auto e : out) printf("%d ", e);
        }
    }


}