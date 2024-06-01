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

vector<vii> graph;
int n;
int n2;

void build1(int x, int l, int r) {
    while(graph.size()<=n+x) graph.pb({});
    if(l==r) {
        graph[n+x].pb(mp(l, 0));
        // graph[l].pb(mp(n+x, 0));
        return;
    }
    int mid = (l+r)/2;
    graph[n+x].pb(mp(n+2*x, 0));
    graph[n+x].pb(mp(n+2*x+1, 0));
    build1(2*x, l, mid);
    build1(2*x+1, mid+1, r);
}

void build2(int x, int l, int r) {
    while(graph.size()<=n2+x) graph.pb({});

    if(l==r) {
        graph[l].pb(mp(n2+x, 0));
        // graph[n2+x].pb(mp(l, 0));
        return;
    }
    int mid = (l+r)/2;
    while(graph.size()<=n2+2*x+1) graph.pb({});
    graph[n2+2*x].pb(mp(n2+x, 0));
    graph[n2+2*x+1].pb(mp(n2+x, 0));
    build2(2*x, l, mid);
    build2(2*x+1, mid+1, r);
}

void upd1(int x, int l, int r, int lx, int rx, int v, int c) {
    if(lx > r || rx < l) {
        return;
    }
    if(lx <= l && r <= rx) {
        // printf("%d %d\n", n+x, v);
        graph[v].pb(mp(n+x, c));
        return;
    }
    int mid = (l+r)/2;
    upd1(2*x, l, mid, lx, rx, v, c);
    upd1(2*x+1, mid+1, r, lx, rx, v, c);
}

void upd2(int x, int l, int r, int lx, int rx, int v, int c) {
    if(lx > r || rx < l) {
        return;
    }
    if(lx <= l && r <= rx) {
        // printf("%d %d\n", n2+x, v);
        graph[n2+x].pb(mp(v, c));
        return;
    }
    int mid = (l+r)/2;
    upd2(2*x, l, mid, lx, rx, v, c);
    upd2(2*x+1, mid+1, r, lx, rx, v, c);
}


int main() {
    // usaco();
    int q, st;
    scd(n);
    scd(q);
    scd(st);
    graph = vector<vii>(n+1);
    build1(1, 1, n);
    n2 = (int)graph.size()-1;
    build2(1, 1, n);
    frange(_, q) {
        int t;
        scd(t);
        if(t == 1) {
            int v, u, c;
            scd(v);
            scd(u);
            scd(c);
            graph[v].pb(mp(u, c));
        }
        else {
            int v, l, r, c;
            scd(v);

            scd(l);
            scd(r);
            scd(c);
            if(t==2) upd1(1, 1, n, l, r, v, c);
            else upd2(1, 1, n, l, r, v, c);
        }
    }

    int sz = graph.size();
    vll dist(sz, 1e18);
    vb vis(sz);
    priority_queue<pair<lli, int>> pq;
    pq.push(mp(0, st));
    dist[st] = 0;

    while(pq.size()) {
        auto p = pq.top();
        pq.pop();
        if(vis[p.s]) continue;
        vis[p.s] = true;

        for(auto e : graph[p.s]) {
            // printf("%d %d %d\n", p.s, e.f, e.s);
            if(dist[e.f]>-p.f+e.s) {
                dist[e.f] = -p.f + e.s;
                pq.push(mp(-dist[e.f], e.f));
            }
        }
    }
    forr(i, 1, n+1) {
        if(dist[i]==1e18) printf("-1 ");
        else printf("%lld ", dist[i]);
    }

}