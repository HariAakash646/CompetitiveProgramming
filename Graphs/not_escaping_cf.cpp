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

int main() {
    usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n, m, k;
        scd(n);
        scd(m);
        scd(k);
        vll vec(n+1);
        forr(i, 1, n+1) sclld(vec[i]);
        vector<vector<pair<int, lli>>> graph(2*k+2);
        vector<vii> build(n+1);
        build[1].pb(mp(1, 0));
        build[n].pb(mp(m, 2*k+1));
        frange(i, k) {
            int a, b, c, d, h;
            scd(a);
            scd(b);
            scd(c);
            scd(d);
            scd(h);
            build[a].pb(mp(b, 2*i+1));
            build[c].pb(mp(d, 2*i+2));
            graph[2*i+1].pb(mp(2*i+2, h));
        }
        forr(i, 1, n+1) {
            sort(all(build[i]));
            forr(j, 1, build[i].size()) {
                pii a = build[i][j];
                pii b = build[i][j-1];
                graph[a.s].pb(mp(b.s, (b.f - a.f) * vec[i]));
                graph[b.s].pb(mp(a.s, (b.f - a.f) * vec[i]));
            }
        }

        vll dist(2*k+2, -1e18);
        dist[0] = 0;
        priority_queue<pair<lli, int>> pq;
        pq.push(mp(0, 0));
        vb vis(2*k+2);


        while(pq.size()) {
            auto p = pq.top();
            pq.pop();
            if(vis[p.s]) continue;
            vis[p.s] = true;
            for(auto e : graph[p.s]) {
                if(p.f + e.s > dist[e.f]) {
                    dist[e.f] = p.f + e.s;
                    pq.push(mp(dist[e.f], e.f));
                }
            }
        }
        if(dist[2*k+1] <= -1e18) printf("NO ESCAPE\n");
        else printf("%lld\n", -dist[2*k+1]);
    }
}