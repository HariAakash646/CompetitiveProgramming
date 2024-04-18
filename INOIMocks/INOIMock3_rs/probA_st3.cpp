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

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

struct Edge {
	int a, b;
	lli v;
};

int main() {
	// usaco();
	int n, m, k;
	scd(n);
	scd(m);
	scd(k);

	vector<Edge> edg(m);
	vvi graph(n+1);

	frange(i, m) {
		int a, b;
		lli v;
		scd(a);
		scd(b);
		sclld(v);
		edg[i].a = a;
		edg[i].b = b;
		edg[i].v = v;
		graph[a].pb(i);
		graph[b].pb(i);
	}

	vi vec;
	vb spc(n+1);

	frange(i, k) {
		int id;
		scd(id);
		// if(id == 1 || id == 2) continue;
		vec.pb(id);
		spc[id] = true; 
	}

	vb vised(m);
	lli mi = 1e18;
	vector<pair<lli, pii>> st;
	for(auto e : vec) {
		map<int, lli> dist;
		map<int, bool> vis;
		priority_queue<pair<lli, int>> pq;
		pq.push(mp(0, e));

		dist[e] = 0;
		int c = 0;

		while(pq.size()) {
			auto p = pq.top();
			pq.pop();
			if(vis.find(p.s) != vis.end()) continue;
			vis[p.s] = true;
			if(spc[p.s] && p.s != e) {
				c++;
				st.pb(mp(dist[p.s], mp(min(e, p.s), max(e, p.s))));
				if(c == 2)
					break;
				continue;
			}
			for(auto e : graph[p.s]) {
				// if(!vised[e]) {
					int a = p.s;
					int b;
					if(edg[e].a == a) b = edg[e].b;
					else b = edg[e].a;
					if(dist.find(b) == dist.end() || (dist[a] + edg[e].v < dist[b])) {
						dist[b] = dist[a] + edg[e].v;
						vised[e] = true;
						pq.push(mp(-dist[b], b));
					}
				// }
			}
		}
	}
	sort(all(st));
	// for(auto p : st) printf("%d %d %lld\n", p.s.f, p.s.s, p.f);
	frange(i, min(12, (int)st.size())) {
		forr(j, i+1, min(12, (int)st.size())) {
			auto p1 = st[i].s;
			auto p2 = st[j].s;
			if(p1.f == p2.f || p1.s == p2.f || p1.f == p2.s || p1.s == p2.s) continue;
			// printf("%lld %lld %d %d\n", st[i].f, st[j].f, p1.f, p1.s);
			mi = min(mi, st[i].f + st[j].f);
		}
	}
	printf("%lld", mi);
}