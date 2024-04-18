#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;
typedef multiset<int> mseti;

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);
    vii vec(m);

    vvi pos(n);

    frange(i, m) {
        scd(vec[i].f);
        scd(vec[i].s);
        pos[vec[i].f].pb(i);
    }

    priority_queue<pair<lli, int>> pq;
    vll dist(n, 1e18);
    dist[vec[0].f] = 0;
    for(auto e : pos[vec[0].f])
        pq.push(mp(0, e));
    vb vis(m);

    
    

    while(pq.size()) {
        auto p = pq.top();
        pq.pop();
        if(vis[p.s]) continue;
        vis[p.s] = true;

        int id = vec[p.s].f;
        int pow = vec[p.s].s;

        for(int i=1; id+i*pow<n; i++) {
            if(-p.f + i < dist[id+i*pow]) {
                dist[id+i*pow] = -p.f+i;
                for(auto e : pos[id+i*pow]) pq.push(mp(-dist[id+i*pow], e));
            }
        }

        for(int i=-1; id+i*pow>=0; i--) {
            if(-p.f - i < dist[id+i*pow]) {
                dist[id+i*pow] = -p.f-i;
                for(auto e : pos[id+i*pow]) pq.push(mp(-dist[id+i*pow], e));
            }
        }
    }

    if(dist[vec[1].f] == 1e18) printf("-1");
    else printf("%lld", dist[vec[1].f]);
}