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

vvi cp, fl, graph;


int main() {
    // usaco();
    int n, m, k;
    scd(n);
    scd(m);
    scd(k);

    int t = n + m + 1;
    graph = vvi(t+1);

    cp = fl = vvi(t+1, vi(t+1));

    set<pii> ed;

    frange(i, k) {
        int a, b;
        scd(a);
        scd(b);
        if(ed.find(mp(a, b)) != ed.end()) continue;
        graph[a].pb(n+b);
        graph[n+b].pb(a);
        cp[a][n+b]++;
        ed.insert(mp(a, b));
    }

    forr(i, 1, n+1) {
        graph[0].pb(i);
        cp[0][i]++;
    }

    forr(i, 1, m+1) {
        graph[n+i].pb(n+m+1);
        cp[n+i][n+m+1]++;
    }

    while(true) {
        bool done = false;
        vb vis(t+1);
        vi par(t+1);

        queue<pair<pii, int>> q;
        q.push(mp(mp(0, 0), 1e9+5));

        while(q.size()) {
            auto p = q.front();
            q.pop();
            if(vis[p.f.f]) continue;
            vis[p.f.f] = true;
            par[p.f.f] = p.f.s;
            if(p.f.f == n+m+1) {
                int pr = p.f.f;
                while(pr != 0) {
                    int p1 = par[pr];
                    fl[p1][pr] += p.s;
                    cp[pr][p1] += p.s;
                    pr = p1;
                }
                done = true;
                break;
            }
            for(auto e : graph[p.f.f]) {
                if(fl[p.f.f][e] < cp[p.f.f][e]) {
                    q.push(mp(mp(e, p.f.f), min(cp[p.f.f][e]-fl[p.f.f][e], p.s)));
                }
            }
        }
        if(!done) break;
    }
    vii out;
    for(auto p : ed) {
        if(cp[p.f][p.s+n] == fl[p.f][p.s+n]) out.pb(p);
    }
    printf("%d\n", (int)out.size());
    for(auto p : out) printf("%d %d\n", p.f, p.s);

}