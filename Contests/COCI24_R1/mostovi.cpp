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

vvi graph;
vb vis;

// void dfs(int x, int a, int b) {
//     if(x == a || x == b) return;
//     vis[x] = true;

//     for(auto e : graph[x]) if(!vis[e]) dfs(e, a, b);
// }

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);
    vii edges(m);
    graph = vvi(n+1);
    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        edges[i] = mp(a, b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    int c = 0;
    for(auto p : edges) {
        vis = vb(n+1);
        queue<int> q;
        if(1 != p.f && 1 != p.s) q.push(1);
        else if(2 != p.f && 2 != p.s) q.push(2);
        else q.push(3);
        while(q.size()) {
            int x = q.front();
            q.pop();
            if(x == p.f || x == p.s || vis[x]) continue;
            vis[x] = true;
            for(auto e : graph[x]) {
                if(e != p.f && e != p.s && !vis[e]) q.push(e);
            } 
        }
        bool done = true;
        forr(i, 1, n+1) {
            if(i != p.f && i != p.s) {
                if(!vis[i]) {
                    c++;
                    break;
                }
            }
        }
    }
    printf("%d", c);
}