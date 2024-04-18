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

int main() {
    // usaco();
    int n, m, k;
    scd(n);
    scd(m);
    scd(k);

    graph = vvi(n+1);

    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    vb stop(n+1), stop2(n+1);

    string str;
    cin >> str;
    int c=0;
    forr(i, 1, n+1) {
        if(str[i-1] == '1') {
            c++;
            stop[i] = true;
        }
    }

    forr(i, 1, n+1) {
        if(stop[i]) {
            for(auto e : graph[i]) {
                if(stop[e]) stop2[i] = true;
            }
        }
    }

    vi pos(k);
    frange(i, k) scd(pos[i]);

    int id = 0;
    forr(i, 1, n+1) {
        if(stop[i]) id = i;
    }

    if(c == 0 || (c==1 && id == pos[0])) {
        queue<pii> q;
        q.push(mp(pos[0], 0));
        vb vis(n+1);
        vi dist(n+1, 1e9);
        while(q.size()) {
            auto p = q.front();
            int x = p.f;
            q.pop();
            if(vis[x]) continue;
            vis[x] = true;
            dist[x] = p.s;
            for(auto e : graph[x]) q.push(mp(e, p.s+1));
        }
        forr(i, 1, n+1) printf("%d\n", dist[i]);
    }
    else if(c == 1) {
        
        queue<pii> q;
        q.push(mp(id, 0));
        vi dist(n+1, 1e9);
        vb vis(n+1);

        while(q.size()) {
            auto p = q.front();
            q.pop();
            int x = p.f;
            if(vis[x]) continue;
            vis[x] = true;
            dist[x] = p.s;
            for(auto e : graph[x]) {
                q.push(mp(e, p.s+1));
            }
        }
        dist[id] = 2;
        lli tot = 0;
        forr(i, 1, k) {
            tot += dist[pos[i]];
        }

        q.push(mp(pos[0], 0));
        vis = vb(n+1);
        vi dist2(n+1, 1e9);
        while(q.size()) {
            auto p = q.front();
            int x = p.f;
            q.pop();
            
            if(vis[x]) continue;
            vis[x] = true;
            dist2[x] = p.s;
            if(x == id) continue;
            for(auto e : graph[x]) q.push(mp(e, p.s+1));
        }
        
        
        forr(i, 1, n+1) {
            lli mi = min((lli)dist2[i], dist[pos[0]] + dist[i] + tot);
            printf("%lld\n", mi);
        }

    }
    else if(c == 2) {
        vi stv;
        forr(i, 1, n+1) {
            if(stop[i]) stv.pb(i);
        }
        vvi dist(2, vi(n+1, 1e9));

        frange(i, 2) {
            queue<pii> q;
            id = stv[i];
            q.push(mp(id, 0));
            vb vis(n+1);

            while(q.size()) {
                auto p = q.front();
                q.pop();
                int x = p.f;
                if(vis[x]) continue;
                vis[x] = true;
                dist[i][x] = p.s;
                if(x == stv[!i]) continue;
                for(auto e : graph[x]) {
                    q.push(mp(e, p.s+1));
                }
            }
            dist[i][id] = 2;
        }

        queue<pii> q;

        q.push(mp(pos[0], 0));
        vb vis(n+1);
        vi dist2(n+1, 1e9);
        while(q.size()) {
            auto p = q.front();
            int x = p.f;
            q.pop();
            
            if(vis[x]) continue;
            vis[x] = true;
            dist2[x] = p.s;
            if(stop[x] && p.s) continue;
            for(auto e : graph[x]) q.push(mp(e, p.s+1));
        }
        lli tot = 0;
        forr(i, 1, k) {
            tot += min(dist[0][pos[i]], dist[1][pos[i]]);
        }

        int v = 2;
        if(stop2[stv[0]]) v = 1;
        forr(i, 1, n+1) {
            lli mi = min({(lli)dist2[i], dist[0][pos[0]] + dist[0][i] + tot, dist[1][pos[0]] + dist[1][i] + tot, 
                dist[1][pos[0]] + dist[1][stv[0]] + dist[0][i] + tot + v * (k-1), dist[0][pos[0]] + dist[0][stv[1]] + dist[1][i] + tot + v * (k-1)});
            printf("%lld\n", mi);
        }
    }
    else {
        vvi moves(k, vi(c+1));
        forr(l, 1, k) {
            // queue<pair<pii, int>> q;
            // q.push(mp(mp(pos[l], 0), 0));
            priority_queue<pair<pii, int>> q;
            q.push(mp(mp(0, 0), pos[l]));
            vb vis(n+1);
            vii dist(n+1, mp(1e9, 0));
            // vi dist2(n+1, 1e9);
            // vb vis2(n+1);
            while(q.size()) {
                auto p = q.top();
                int x = p.s;
                q.pop();
                
                if(vis[x]) continue;
                vis[x] = true;
                dist[x] = mp(-p.f.f, p.f.s);
                if(stop[x] && p.f.f) p.f.s++;
                for(auto e : graph[x]) q.push(mp(mp(p.f.f-1, p.f.s), e));
            }
            dist[pos[l]] = mp(2, 0);
            int m1 = 1e9;
            pii m2 = mp(1e9, 0);
            
            forr(i, 1, n+1) {
                if(stop[i]) {
                    if(dist[i].f<m1) {
                        // v1 = {};
                        // v1.pb(i);
                        m1 = dist[i].f;
                    }
                    
                }
                if(stop2[i]) {
                    if(dist[i].f < m2.f) {
                        m2 = dist[i];
                    }
                    else if(dist[i].f == m2.f && dist[i].s > m2.s) {
                        m2.s = dist[i].s;
                    }
                }
            }
            
            
            
            moves[l][1] = m1;

            forr(j, 2, m2.s+1) moves[l][j] = m1 + 2 * (j-1); 
            
            forr(j, m2.s+1, c+1) {
                moves[l][j] = min(m1 + 2 * (j-1), m2.f + (j-m2.s-1));
                // if(j == 2) printf("%d, ", moves[l][j]);
            }

            

        }
        vll tot(c+1);
        forr(i, 1, c+1) {
            forr(j, 1, k) tot[i] += moves[j][i];
        }

        queue<pair<int, pii>> q;
        vector<vll> dist(n+1, vll(c+1, 1e18));
        vector<vb> vis(n+1, vb(c+1));

        q.push(mp(pos[0], mp(0, 0)));

        while(q.size()) {
            auto p = q.front();
            q.pop();
            int x = p.f;
            if(p.s.s > c || vis[x][p.s.s]) continue;
            vis[x][p.s.s] = true;
            dist[x][p.s.s] = p.s.f;

            if(stop[x] && p.s.f) p.s.s++; 

            for(auto e : graph[x]) q.push(mp(e, mp(p.s.f+1, p.s.s)));
        }

        forr(i, 1, n+1) {
            lli mi = 1e18;
            // printf("%d:\n", i);
            forr(j, 0, c+1) {
                // printf("%d %lld\n", dist[i][j], tot[j]);
                mi = min(mi, dist[i][j] + tot[j]);
            }
            printf("%lld\n", mi);
        }



    }
}