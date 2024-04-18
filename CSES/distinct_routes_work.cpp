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

int n, m;
vvi graph, dirg;
vvi cp, fl;
vi out;
vb vis;

bool dfs(int x) {
    if(n == x) {
        out.pb(x);
        return true;
    }
    if(vis[x]) return false;
    vis[x] = true;
    for(auto e : dirg[x]) {
        if(fl[x][e] == cp[x][e]) {
            bool ou = dfs(e);
            if(ou) {
                fl[x][e]--;
                out.pb(x);
                return true;
            }
        }

    }
    return false;
}

int main() {
    // usaco();
    scd(n);
    scd(m);

    dirg = graph = vvi(n+1);
    cp = fl = vvi(n+1, vi(n+1));

    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
        dirg[a].pb(b);
        cp[a][b]++;
    }

    while(true) {
        bool done = false;
        vb vis(n+1);
        vi par(n+1);

        queue<pair<pii, int>> q;
        q.push(mp(mp(1, 0), 1e9+5));

        while(q.size()) {
            auto p = q.front();
            q.pop();
            if(vis[p.f.f]) continue;
            vis[p.f.f] = true;
            par[p.f.f] = p.f.s;

            if(p.f.f == n) {
                int pa = p.f.f;
                while(pa != 1) {
                    int p1 = par[pa];
                    fl[p1][pa] += p.s;
                    cp[pa][p1] += p.s;
                    pa = p1;
                }
                done = true;
                break;
            }

            for(auto e : graph[p.f.f]) {
                if(fl[p.f.f][e] < cp[p.f.f][e]) q.push(mp(mp(e, p.f.f), min(p.s, cp[p.f.f][e] - fl[p.f.f][e])));
            }
        }

        if(!done) break;
    }

    vvi outs;

    while(true) {
        vis = vb(n+1);
        out = {};

        bool ou = dfs(1);
        if(!ou) break;

        outs.pb(out);
    }

    printf("%d\n",(int)outs.size());

    for(auto v : outs) {
        printf("%d\n", (int)v.size());
        reverse(all(v));
        for(auto e : v) printf("%d ", e);
        printf("\n");
    }




}