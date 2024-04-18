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
vvi graph, flow, cost;

int main() {
    usaco();
    int n, m;
    scd(n);
    scd(m);

    graph = vvi(n+m+2);

    cost = vvi(n+m+2, vi(n+m+2));
    flow = vvi(n+m+2, vi(n+m+2));

    vector<vi> grid(n+1, vi(m+1));

    forr(r, 1, n+1) {
        forr(c, 1, m+1) {
            int a;
            scd(a);
            grid[r][c] = a;
            graph[r].pb(n+c);
            graph[n+c].pb(r);
            // if(a == 0) cost[r][n+c]++;
            // else cost[n+c][r]++;
            cost[r][n+c]++;
        }
    }

    vi cntr(n+1), cntc(m+1);
    vi valr(n+1), valc(m+1);

    forr(i, 1, n+1) {
        forr(j, 1, m+1) {
            if(grid[i][j]) {
                cntr[i]++;
                cntc[j]++;
            }
        }
    }

    forr(r, 1, n+1) {
        graph[0].pb(r);
        graph[r].pb(0);
    }

    forr(c, 1, m+1) {
        graph[n+c].pb(n+m+1);
        graph[n+m+1].pb(n+c);
    }

    forr(i, 1, n+1) {
        int a;
        scd(a);
        valr[i] = a;
        // if(a > cntr[i])
            cost[0][i] = abs(a-cntr[i]);
        // else cost[i][0] = cntr[i]-a;
    }

    forr(i, 1, m+1) {
        int a;
        scd(a);
        valc[i] = a;
        // if(a > cntc[i])
            cost[n+i][n+m+1] = abs(a-cntc[i]);
        // else cost[n+m+1][n+i] = cntc[i] - a;
    }

    vvi og = cost;

    while(true) {
        queue<pair<pii, int>> q;
        q.push(mp(mp(0, 0), inf));
        bool done = false;
        vb vis(n+m+2);
        vi par(n+m+2);

        while(q.size()) {
            auto p = q.front();
            q.pop();
            if(vis[p.f.f]) continue;
            par[p.f.f] = p.f.s;
            vis[p.f.f] = true;
            // printf("%d\n", p.f.f);
            if(p.f.f == n+m+1) {
                // printf("%d\n", p.s);
                int pa = n+m+1;
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
                    q.push(mp(mp(e, p.f.f), min(p.s, cost[p.f.f][e] - flow[p.f.f][e])));
                }
            }
        }
        if(!done) break;
    }

    // cost = og;

    // while(true) {
    //     queue<pair<pii, int>> q;
    //     q.push(mp(mp(n+m+1, n+m+1), inf));
    //     bool done = false;
    //     vb vis(n+m+2);
    //     vi par(n+m+2);

    //     while(q.size()) {
    //         auto p = q.front();
    //         q.pop();
    //         if(vis[p.f.f]) continue;
    //         par[p.f.f] = p.f.s;
    //         vis[p.f.f] = true;
    //         // printf("%d\n", p.f.f);
    //         if(p.f.f == 0) {
    //             // printf("%d\n", p.s);
    //             int pa = 0;
    //             while(pa != n+m+1) {
    //                 int p2 = par[pa];
    //                 flow[p2][pa] += p.s;
    //                 cost[pa][p2] += p.s;
    //                 pa = p2;
    //             }
    //             done = true;
    //             break;
    //         }
    //         for(auto e : graph[p.f.f]) {
    //             if(cost[p.f.f][e] != flow[p.f.f][e]) {
    //                 q.push(mp(mp(e, p.f.f), min(p.s, cost[p.f.f][e] - flow[p.f.f][e])));
    //             }
    //         }
    //     }
    //     if(!done) break;
    // }

    // int c = 0;

    int c = 0;
    forr(i, 1, n+1) {
        forr(j, n+1, n+m+1) {
            // printf("%d %d %d %d\n", i, j, cost[i][j], flow[i][j]);
            if(cost[i][j] == flow[i][j] && grid[i][j-n] == 0) {
                c++;
                grid[i][j-n] = 1;
            }
        }
    }

    forr(j, n+1, n+m+1) {
        forr(i, 1, n+1) {
            // printf("%d %d %d %d\n", i, j, cost[j][i], flow[j][i]);
            if(cost[j][i] == flow[j][i] && grid[i][j-n] != 0) {
                c++;
                grid[i][j-n] = 0;
            }
        }
    }

    cntr = vi(n+1);
    cntc = vi(m+1);

    forr(i, 1, n+1) {
        forr(j, 1, m+1) {
            if(grid[i][j]) {
                cntr[i]++;
                cntc[j]++;
            }
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    // forr(i, 1, n+1) printf("%d %d\n", valr[i], cntr[i]);
    // forr(j, 1, m+1) printf("%d %d\n", valc[j], cntc[j]);
    if(valc != cntc || valr != cntr) printf("-1");
    else
    printf("%d", c);
}