#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t);
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

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

struct Edge {
	int a, b;
	lli c, d;
};

int main() {
	// usaco();
	int n, m;
	scd(n);
	scd(m);

	vector<seti> graph(n+1);
	vector<Edge> edg(m);
	vector<vll> dist(n+1, vll(n+1, 1e17));
	forr(i, 1, n+1) dist[i][i] = 0;
	frange(i, m) {
		int a, b;
		lli c, d;
		scd(a);
		scd(b);
		sclld(c);
		sclld(d);
		graph[a].insert(i);
		edg[i].a = a;
		edg[i].b = b;
		edg[i].c = c;
		edg[i].d = d;
		dist[a][b] = min(dist[a][b], c);
	}

	forr(k, 1, n+1) {
		forr(i, 1, n+1) {
			forr(j, 1, n+1) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}

	lli mi = dist[1][n]+dist[n][1];

	frange(i, m) {
		auto p = edg[i];
		lli d1 = min(dist[1][n], dist[1][p.b] + dist[p.a][n] + p.c);
		lli d2 = min(dist[n][1], dist[n][p.b] + dist[p.a][1] + p.c);

		if(d1 + d2 + p.d < mi) {
			graph[edg[i].a].erase(i);
			graph[edg[i].b].insert(i);
			swap(edg[i].a, edg[i].b);

			priority_queue<pair<lli, int>> pq;
			vll dist(n+1, 1e17);
			dist[1] = 0;

			pq.push(mp(0, 1));
			vb vis(n+1);
			while(pq.size()) {
				auto p = pq.top();
				pq.pop();
				if(vis[p.s]) continue;
				vis[p.s] = true;

				for(auto x : graph[p.s]) {
					auto e = edg[x];
					if(dist[p.s] + e.c < dist[e.b]) {
						dist[e.b] = dist[p.s] + e.c;
						pq.push(mp(-dist[e.b], e.b));
					}
				}
			}
			lli dt1 = dist[n];
			dist = vll(n+1, 1e17);
			dist[n] = 0;

			pq.push(mp(0, n));
			vis = vb(n+1);
			while(pq.size()) {
				auto p = pq.top();
				pq.pop();
				if(vis[p.s]) continue;
				vis[p.s] = true;

				for(auto x : graph[p.s]) {
					auto e = edg[x];
					if(dist[p.s] + e.c < dist[e.b]) {
						dist[e.b] = dist[p.s] + e.c;
						pq.push(mp(-dist[e.b], e.b));
					}
				}
			}
			lli dt2 = dist[1];
			mi = min(mi, dt1+dt2+p.d);
			swap(edg[i].a, edg[i].b);
			graph[edg[i].a].insert(i);
			graph[edg[i].b].erase(i);
		}
	}
	if(mi < 1e17)
	printf("%lld", mi);
	else printf("-1");

}