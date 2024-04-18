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

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int n, m;

bool check(pii p) {
    return p.f < n && p.s < m && p.f >= 0 && p.s >= 0;
}


int main() {
    // usaco();
    fastio();

    
    string str;
    cin >> n >> m >> str;

    vii dir;

    for(auto c : str) {
        if(c == 'L') dir.pb(mp(0, -1));
        if(c == 'R') dir.pb(mp(0, 1));
        if(c == 'D') dir.pb(mp(1, 0));
        if(c == 'U') dir.pb(mp(-1, 0));
    }

    vvi grid(n, vi(m));
    frange(i, n) {
        frange(j, m) cin >> grid[i][j];
    }

    vector<vector<map<int, lli>>> dist(n, vector<map<int, lli>>(m));
    vector<vector<map<int, bool>>> vis(n, vector<map<int, bool>>(m));

    priority_queue<pair<lli, pair<pii, int>>> pq;
    pq.push(mp(0, mp(mp(0, 0), grid[0][0])));
    dist[0][0][grid[0][0]] = 0;

    while(pq.size()) {
        auto p = pq.top();
        pq.pop();
        if(vis[p.s.f.f][p.s.f.s][p.s.s]) continue;
        vis[p.s.f.f][p.s.f.s][p.s.s] = true;
        p.f = -p.f;
        pii po = p.s.f;
        int h = p.s.s;
        for(auto p1 : dir) {
            pii pot = po;
            pot.f += p1.f;
            pot.s += p1.s;
            if(!check(pot)) continue;
            int h2 = grid[pot.f][pot.s];
            if(h2 >= h) {
                lli c = h2 - h + h2 + p.f;
                if(dist[pot.f][pot.s].find(h2) == dist[pot.f][pot.s].end() || dist[pot.f][pot.s][h2] > c) {
                    dist[pot.f][pot.s][h2] = c;
                    pq.push(mp(-c, mp(pot, h2)));
                }
            }
            else {
                int ht = max(grid[pot.f][pot.s], min(h, grid[po.f][po.s]));
                lli c = p.f + ht;
                if(dist[pot.f][pot.s].find(ht) == dist[pot.f][pot.s].end() || dist[pot.f][pot.s][ht] > c) {
                    dist[pot.f][pot.s][ht] = c;
                    pq.push(mp(-c, mp(pot, ht)));
                }
            }
        }

    }
    lli mi = 1e18;
    for(auto p : dist[n-1][m-1]) mi = min(mi, p.s);
    cout << mi;

}