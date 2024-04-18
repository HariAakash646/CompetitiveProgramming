#include <bits/stdc++.h>

using namespace std;

#define scd(x) scanf("%d", &x)
#define sclld(x) scanf("%lld", &x)
#define frange(i, n) for(int i=0; i<n; i++)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define all(vec) vec.begin(), vec.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second

typedef long long lli;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<lli> vll;
typedef vector<vi> vvi;
typedef vector<bool> vb;

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

int main() {
	// usaco();
	int n, m;
	scd(n);
	scd(m);
	vector<pair<pii, pair<lli, lli>>> vec(m);

	vector<set<int>> graph(n+1);

	frange(i, m) {
		int u, v;
		scd(u);
		scd(v);
		lli c, d;
		sclld(c);
		sclld(d);
		graph[u].insert(i);
		vec[i] = mp(mp(u, v), mp(c, d));
	}

	vll dist(n+1, 1e18);

	priority_queue<pair<lli, int>> pq;
	vb vis(n+1);

	pq.push(mp(0, 1));
	dist[1] = 0;

	while(pq.size()) {
		auto p = pq.top();
		pq.pop();
		if(vis[p.s]) continue;
		vis[p.s] = true;

		for(auto i : graph[p.s]) {
			auto e = vec[i];
			if(dist[p.s] + e.s.f < dist[e.f.s]) {
				dist[e.f.s] = dist[p.s] + e.s.f;
				pq.push(mp(-dist[e.f.s], e.f.s));
			}
		}
	}

	lli v = dist[n];

	dist = vll(n+1, 1e18);
	vis = vb(n+1);

	pq.push(mp(0, n));
	dist[n] = 0;

	while(pq.size()) {
		auto p = pq.top();
		pq.pop();
		if(vis[p.s]) continue;
		vis[p.s] = true;

		for(auto i : graph[p.s]) {
			auto e = vec[i];
			if(dist[p.s] + e.s.f < dist[e.f.s]) {
				dist[e.f.s] = dist[p.s] + e.s.f;
				pq.push(mp(-dist[e.f.s], e.f.s));
			}
		}
	}

	v += dist[1];

	lli mi = v;

	frange(i, m) {
		auto p = vec[i];
		graph[p.f.f].erase(i);
		graph[p.f.s].insert(i);

		swap(vec[i].f.f, vec[i].f.s);

		vll dist(n+1, 1e18);

		priority_queue<pair<lli, int>> pq;
		vb vis(n+1);

		pq.push(mp(0, 1));
		dist[1] = 0;

		while(pq.size()) {
			auto p = pq.top();
			pq.pop();
			if(vis[p.s]) continue;
			vis[p.s] = true;

			for(auto i : graph[p.s]) {
				auto e = vec[i];
				if(dist[p.s] + e.s.f < dist[e.f.s]) {
					dist[e.f.s] = dist[p.s] + e.s.f;
					pq.push(mp(-dist[e.f.s], e.f.s));
				}
			}
		}

		lli v = dist[n];

		dist = vll(n+1, 1e18);
		vis = vb(n+1);

		pq.push(mp(0, n));
		dist[n] = 0;

		while(pq.size()) {
			auto p = pq.top();
			pq.pop();
			if(vis[p.s]) continue;
			vis[p.s] = true;

			for(auto i : graph[p.s]) {
				auto e = vec[i];
				if(dist[p.s] + e.s.f < dist[e.f.s]) {
					dist[e.f.s] = dist[p.s] + e.s.f;
					pq.push(mp(-dist[e.f.s], e.f.s));
				}
			}
		}
		v += dist[1];
		mi = min(mi, v+vec[i].s.s);

		p = vec[i];
		graph[p.f.f].erase(i);
		graph[p.f.s].insert(i);

		swap(vec[i].f.f, vec[i].f.s);
	}

	if(mi < 1e17) printf("%lld", mi);
	else printf("-1");
}