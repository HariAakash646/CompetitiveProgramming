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

struct Edge {
    int a, b, c, d;
    int st, en;
    bool operator<(Edge other) const {
        return a < other.a;
    }
};

lli wgt(Edge x, Edge y) {
    if(x.d > y.a) return 1e18;
    else return y.b - x.c;
}

int main() {
    // usaco();
    int n, m, p, t;
    scd(n);
    scd(m);
    scd(p);
    scd(t);

    vector<Edge> edges(m);

    frange(i, m) {
        scd(edges[i].st);
        scd(edges[i].en);
        scd(edges[i].a);
        scd(edges[i].b);
        scd(edges[i].c);
        scd(edges[i].d);
    }
    sort(all(edges));
    vll dist(n+1, 1e18);
    dist[1] = 0;
    priority_queue<pair<lli, pair<lli, int>>> pq;

    for(auto p : edges) {
        // if(p.b > t) break;
        while(pq.size() && p.a >= -pq.top().f) {
            auto e = pq.top();
            pq.pop();
            dist[e.s.s] = min(dist[e.s.s], e.s.f);
        }
        lli v = dist[p.st] + p.b - p.c;
        if(p.d <= t)
            pq.push(mp(-p.d, mp(v, p.en)));
        // forr(i, 1, n+1) printf("%lld ", dist[i]);
        // printf("\n");
    }
    while(pq.size() && t >= -pq.top().f) {
        auto e = pq.top();
        pq.pop();
        dist[e.s.s] = min(dist[e.s.s], e.s.f);
    }
    if(dist[p] + t < 1e18) printf("%lld", dist[p] + t);
    else printf("-1");
}