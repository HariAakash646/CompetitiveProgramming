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
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);

    if(n == 1) {
        printf("0");
        return 0;
    }
    if(n == 2) {
        printf("1");
        return 0;
    }

    vll vec(n+1);

    forr(i, 1, n+1) sclld(vec[i]);

    vvi graph(n+1);
    vii edg(m);

    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
        edg[i] = mp(a, b);
    }

    priority_queue<pair<lli, pair<int, pii>>> pq;
    vll dist(n+1, 1e18);
    vb vis(n+1);
    dist[1] = 0;
    vii val1(n+1), val2(n+1);
    pq.push(mp(0, mp(1, mp(0, 0))));

    while(pq.size()) {
        auto p = pq.top();
        pq.pop();
        if(vis[p.s.f]) continue;
        vis[p.s.f] = true;
        val1[p.s.f] = p.s.s;

        for(auto e : graph[p.s.f]) {
            lli v = 0;
            if(vec[e] > p.s.s.s) {
                if(-p.f + vec[e] - p.s.s.s < dist[e]) {
                    dist[e] = -p.f + vec[e] - p.s.s.s;
                    pq.push(mp(-dist[e], mp(e, mp(vec[e], vec[e]))));
                }
            }
            else if(vec[e] <= p.s.s.s) {
                if(-p.f + 1 < dist[e]) {
                    dist[e] = -p.f + 1;
                    pq.push(mp(-dist[e], mp(e, mp(p.s.s.s, p.s.s.s+1))));
                }
            }
        }
    }

    vll dist2(n+1, 1e18);
    vis = vb(n+1);
    pq.push(mp(0, mp(n, mp(0, 0))));
    dist2[n] = 0;

    while(pq.size()) {
        auto p = pq.top();
        pq.pop();
        if(vis[p.s.f]) continue;
        vis[p.s.f] = true;
        val2[p.s.f] = p.s.s;

        for(auto e : graph[p.s.f]) {
            lli v = 0;
            if(vec[e] > p.s.s.s) {
                if(-p.f + vec[e] - p.s.s.s < dist2[e]) {
                    dist2[e] = -p.f + vec[e] - p.s.s.s;
                    pq.push(mp(-dist2[e], mp(e, mp(vec[e], vec[e]))));
                }
            }
            else if(vec[e] <= p.s.s.s) {
                if(-p.f + 1 < dist2[e]) {
                    dist2[e] = -p.f + 1;
                    pq.push(mp(-dist2[e], mp(e, mp(p.s.s.s, p.s.s.s+1))));
                }
            }
        }
    }


    lli mi = 1e18;

    forr(i, 1, n+1) {
        // if(val1[i].f == val2[i].f)
        mi = min(mi, max(dist[i], dist2[i])*2);
    }

    for(auto p : edg) {
        mi = min(mi, max(dist[p.f], dist2[p.s])*2+1);
        mi = min(mi, max(dist2[p.f], dist[p.s])*2+1);
    }

    printf("%lld", mi);


}