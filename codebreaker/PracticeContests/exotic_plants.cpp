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
    int n, m, k;
    scd(n);
    scd(m);
    scd(k);
    int st, t;
    scd(st);
    scd(t);
    k++;
    vector<vii> graph(n*k);

    frange(i, m) {
        int a, b, c;
        scd(a);
        scd(b);
        scd(c);
        frange(i, k) {
            graph[a*k+i].pb(mp(b*k+i, c));
            graph[b*k+i].pb(mp(a*k+i, c));
        }
        frange(i, k-1) {
            graph[a*k+i].pb(mp(b*k+i+1, 0));
            graph[b*k+i].pb(mp(a*k+i+1, 0));
        }
    }

    vll dist(n*k, 1e18);
    vb vis(n*k);
    priority_queue<pair<lli, int>> pq;
    dist[st*k] = 0;
    pq.push(mp(0, st*k));

    while(pq.size()) {
        auto p = pq.top();
        pq.pop();
        if(vis[p.s]) continue;
        vis[p.s] = true;
        for(auto e : graph[p.s]) {
            if(-p.f + e.s < dist[e.f]) {
                dist[e.f] = -p.f + e.s;
                pq.push(mp(-dist[e.f], e.f));  
            }
        }
    }

    lli mi = 1e18;
    frange(i, k) {
        mi = min(mi, dist[t*k+i]);
    }
    printf("%lld", mi);
}