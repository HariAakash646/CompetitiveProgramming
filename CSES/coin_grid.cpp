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

int inf = 1e9;

vvi cost, flow;
vvi graph;

vb vis;

void dfs(int x) {
    if(vis[x]) return;
    vis[x] = true;
    for(auto e : graph[x]) {
        if(flow[x][e] == cost[x][e]) continue;
        dfs(e);
    }
}

int main() {
    // usaco();
    int n;
    cin >> n;

    graph = vvi(2*n+2);

    cost = vvi(2*n+2, vi(2*n+2));
    flow = vvi(2*n+2, vi(2*n+2));

    forr(r, 1, n+1) {
        string row;
        cin >> row;
        forr(c, 1, n+1) {
            if(row[c-1] == 'o') {
                graph[r].pb(n+c);
                cost[r][n+c] = inf;
                graph[n+c].pb(r);
            }
        }
    }

    forr(r, 1, n+1) {
        graph[0].pb(r);
        graph[r].pb(0);
        cost[0][r] = 1;
    }

    forr(c, 1, n+1) {
        graph[n+c].pb(2*n+1);
        graph[2*n+1].pb(n+c);
        cost[n+c][2*n+1] = 1;
    }

    while(true) {
        queue<pair<pii, int>> q;
        q.push(mp(mp(0, 0), inf));
        bool done = false;
        vb vis(2*n+2);
        vi par(2*n+2);

        while(q.size()) {
            auto p = q.front();
            q.pop();
            if(vis[p.f.f]) continue;
            par[p.f.f] = p.f.s;
            vis[p.f.f] = true;
            if(p.f.f == 2*n+1) {
                int pa = 2*n+1;
                while(pa != 0) {
                    int p2 = par[pa];
                    flow[p2][pa] += p.s;
                    cost[pa][p2] += p.s;
                    pa = p2;
                }
                done = true;
                break;
            }
            for(auto e : graph[p.f.f]) {
                if(cost[p.f.f][e] != flow[p.f.f][e]) {
                    q.push(mp(mp(e, p.f.f), cost[p.f.f][e] - flow[p.f.f][e]));
                }
            }
        }
        if(!done) break;
    }

    vis = vb(2*n+2);
    dfs(0);
    int c = 0;
    forr(i, 1, n+1) {
        if(vis[0] && !vis[i]) {
            c++;
        }
    }

    forr(i, 1, n+1) {
        if(vis[n+i] && !vis[2*n+1]) {
            c++;
        }
    }

    printf("%d\n", c);


    forr(i, 1, n+1) {
        if(vis[0] && !vis[i]) {
            printf("1 %d\n", i);
        }
    }

    forr(i, 1, n+1) {
        if(vis[n+i] && !vis[2*n+1]) {
            printf("2 %d\n", i);
        }
    }


}