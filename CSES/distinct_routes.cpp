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

struct Dat {
    int v, e, pe;
    lli x;
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);

    vector<vii> graph(n+1);
    vector<vll> cap(n+1, vll(n+1)), flow(n+1, vll(n+1));
    vii edges;
    vvi edgv(n+1, vi(n+1));
    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb({b, i});
        graph[b].pb({a, i});
        
        cap[a][b] += 1;
        edgv[a][b] = i;
        edges.pb(mp(a, b));
    }
    vb revg(m);
    vi par(m), nex(m);
    lli tot = 0;
    while(true) {
        queue<pair<pii, lli>> q;
        q.push(mp(mp(1, 0), 1e9+5));
        vb vis(n+1);
        vi par(n+1);
        bool done = false;
        while(q.size()) {
            auto p = q.front();
            q.pop();
            if(vis[p.f.f]) continue;
            par[p.f.f] = p.f.s;
            vis[p.f.f] = true;
            if(p.f.f == n) {
                tot += p.s;
                int pa = n;
                while(pa != 1) {
                    int p2 = par[pa];
                    wgt[p2][pa] -= p.s;
                    wgt[pa][p2] += p.s;
                    pa = p2;
                }
                done = true;
                break;
            } 
            for(auto e : graph[p.f.f]) {
                if(wgt[p.f.f][e]) {
                    q.push(mp(mp(e, p.f.f), min(wgt[p.f.f][e], p.s)));
                }
            }
        }
        if(!done) break;
    }
    printf("%lld\n", tot);
    vis = vb(n+1);
    dfs(1);
    for(auto p : edges) {
        if((vis[p.f] && !vis[p.s]) || (!vis[p.f] && vis[p.s])) printf("%d %d\n", p.f, p.s);
    }
    
}