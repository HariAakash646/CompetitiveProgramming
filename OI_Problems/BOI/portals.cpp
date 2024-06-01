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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    // usaco();
    fastio();
    int n, m;
    cin >> n >> m;

    vector<vb> grid(n+2, vb(m+2, true));
    pii st, en;
    frange(i, n) {
        string row;
        cin >> row;
        frange(j, m) {
            if(row[j] == 'S') st = mp(i+1, j+1);
            if(row[j] == 'C') en = mp(i+1, j+1);
            if(row[j] != '#') grid[i+1][j+1] = false;
        }
    }

    vector<vector<vii>> graph(n+2, vector<vii>(m+2));
    forr(i, 1, n+1) {
        int curr = -1;
        forr(j, 1, m+1) {
            if(grid[i][j]) {
                curr = -1;
                continue;
            }
            if(curr == -1) curr = j;
            graph[i][j].pb(mp(i, curr));
        } 
        curr = -1;
        for(int j=m; j>=1; j--) {
            if(grid[i][j]) {
                curr = -1;
                continue;
            }
            if(curr == -1) curr = j;
            graph[i][j].pb(mp(i, curr));
        } 
    }

    forr(j, 1, m+1) {
        int curr = -1;
        forr(i, 1, n+1) {
            if(grid[i][j]) {
                curr = -1;
                continue;
            }
            if(curr == -1) curr = i;
            graph[i][j].pb(mp(curr, j));
        } 
        curr = -1;
        for(int i=n; i>=1; i--) {
            if(grid[i][j]) {
                curr = -1;
                continue;
            }
            if(curr == -1) curr = i;
            graph[i][j].pb(mp(curr, j));
        } 
    }

    vvi distw(n+2, vi(m+2, 1e9));
    queue<pair<int, pii>> q;

    forr(i, 1, n+1) {
        forr(j, 1, m+1) {
            if(!grid[i][j] && (grid[i-1][j] || grid[i+1][j] || grid[i][j-1] || grid[i][j+1])) {
                q.push(mp(0, mp(i, j)));
            }
        }
    }

    while(q.size()) {
        auto p = q.front();
        q.pop();
        int x = p.s.f;
        int y = p.s.s;
        if(grid[x][y] || distw[x][y] <= p.f) continue;
        distw[x][y] = p.f;
        q.push(mp(p.f+1, mp(x+1, y)));
        q.push(mp(p.f+1, mp(x-1, y)));
        q.push(mp(p.f+1, mp(x, y+1)));
        q.push(mp(p.f+1, mp(x, y-1)));
    }

    priority_queue<pair<int, pii>> pq;
    vector<vb> vis(n+2, vb(m+2));
    vvi dist(n+2, vi(m+2, 1e9));
    pq.push(mp(0, st));

    while(pq.size()) {
        auto p = pq.top();
        pq.pop();
        if(vis[p.s.f][p.s.s] || grid[p.s.f][p.s.s]) continue;
        vis[p.s.f][p.s.s] = true;

        vii vec = {mp(0, 1), mp(0, -1), mp(1, 0), mp(-1, 0)};
        int x = p.s.f;
        int y = p.s.s;
        for(auto e : vec) {
            if(dist[x+e.f][y+e.s] > -p.f + 1) {
                dist[x+e.f][y+e.s] = -p.f + 1;
                pq.push(mp(-dist[x+e.f][y+e.s], mp(x+e.f, y+e.s)));
            }
        }
        
        for(auto e : graph[p.s.f][p.s.s]) {
            if(dist[e.f][e.s] > -p.f + distw[p.s.f][p.s.s]+1) {
                dist[e.f][e.s] = -p.f + distw[p.s.f][p.s.s]+1;
                pq.push(mp(-dist[e.f][e.s], mp(e.f, e.s)));
            }
        }
        
    }
    cout << dist[en.f][en.s];
}