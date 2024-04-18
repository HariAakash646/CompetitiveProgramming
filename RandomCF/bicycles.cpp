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
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n, m;
        scd(n);
        scd(m);

        vector<vector<pair<int, lli>>> graph(n+1);

        frange(i, m) {
            int a, b;
            lli w;
            scd(a);
            scd(b);
            sclld(w);
            graph[a].pb(mp(b, w));
            graph[b].pb(mp(a, w));
        }

        vll vec(n+1);
        forr(i, 1, n+1) sclld(vec[i]);

        vector<vll> dist(n+1, vll(1001, 1e18));
        priority_queue<pair<lli, pii>> pq;
        pq.push(mp(0, mp(1, vec[1])));

        dist[1][vec[1]] = 0;
        vector<vb> vis(n+1, vb(1001));

        while(pq.size()) {
            auto p = pq.top();
            pq.pop();
            if(vis[p.s.f][p.s.s]) continue;
            vis[p.s.f][p.s.s] = true;

            for(auto e : graph[p.s.f]) {
                lli mi = min((lli)p.s.s, vec[e.f]);
                if(dist[p.s.f][p.s.s] + e.s * p.s.s < dist[e.f][mi]) {
                    dist[e.f][mi] = dist[p.s.f][p.s.s] + e.s * p.s.s;
                    pq.push(mp(-dist[e.f][mi], mp(e.f, mi)));
                }
            }
        }   
        printf("%lld\n", *min_element(all(dist[n])));
    }
}