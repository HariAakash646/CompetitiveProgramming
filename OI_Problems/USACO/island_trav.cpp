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
    // freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
    freopen("island.in", "r", stdin);
   freopen("island.out", "w", stdout);
}

int r, c;
vvi grid;
vvi reg;

void dfs(int x, int y, int v) {
    if(x < 0 || y < 0 || x >= r || y >= c) return;
    if(grid[x][y] != 0 || reg[x][y]) return;
    reg[x][y] = v;
    dfs(x+1, y, v);
    dfs(x-1, y, v);
    dfs(x, y+1, v);
    dfs(x, y-1, v);
}

int main() {
    usaco();
    
    cin >> r >> c;

    grid = vvi(r, vi(c));
    frange(i, r) {
        string row;
        cin >> row;
        frange(j, c) {
            if(row[j] == '.') {
                grid[i][j] = 2;
            }
            else if(row[j] == 'S') {
                grid[i][j] = 1;
            }
        }
    }

    reg = vvi(r, vi(c));
    int v = 1;
    frange(i, r) {
        frange(j, c) {
            if(!reg[i][j] && !grid[i][j]) {
                dfs(i, j, v);
                v++;
            }
        }
    }
    // frange(i, r) {
    //     frange(j, c) {
    //     printf("%d ", reg[i][j]);
    //     }
    //     printf("\n");
    // }
    vvi dist(v, vi(v, 1e9));
    forr(i, 0, v) dist[0][i] = 0;
    forr(i, 1, v) {
        deque<pair<pii, int>> dq;
        frange(j, r) {
            frange(k, c) {
                if(reg[j][k] == i)
                    dq.pb(mp(mp(j, k), 0));
            }
        }
        vector<vb> vis(r, vb(c));
        while(dq.size()) {
            auto p = dq.front();
            dq.pop_front();
            if(vis[p.f.f][p.f.s]) continue;
            vis[p.f.f][p.f.s] = true;
            dist[i][reg[p.f.f][p.f.s]] = min(dist[i][reg[p.f.f][p.f.s]], p.s);

            vii nxt;
            nxt.pb(mp(p.f.f, p.f.s+1));
            nxt.pb(mp(p.f.f, p.f.s-1));
            nxt.pb(mp(p.f.f+1, p.f.s));
            nxt.pb(mp(p.f.f-1, p.f.s));

            for(auto e : nxt) {
                if(e.f >= 0 && e.s >= 0 && e.f < r && e.s < c) {
                    if(grid[e.f][e.s] == 1) {
                        dq.push_back(mp(mp(e.f, e.s), p.s+1));
                    }
                    else if(grid[e.f][e.s] == 0) {
                        dq.push_front(mp(mp(e.f, e.s), p.s));
                    }
                }
            }
        }
    }
    v--;
    // forr(i, 1, v+1) printf("%d ", dist[1][i]);
    vvi dp(1<<v, vi(v, 1e9));
    frange(i, v)
    dp[0][i] = 0;

    forr(i, 1, 1<<v) {
        frange(j, v) {
            if(i & (1<<j)) {
                int k = i ^ (1<<j);
                if(k == 0) dp[i][j] = 0;
                frange(r, v) {
                    dp[i][j] = min(dp[i][j], dp[k][r] + dist[r+1][j+1]);
                }
            }
        }
    }
    printf("%d", *min_element(all(dp[(1<<v)-1])));

}