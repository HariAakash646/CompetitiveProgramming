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
typedef set<int> seti;

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

int n, m;

vector<multiset<int>> graph, gr2;
vb vis;
vi order;

void dfs(int x) {
	vis[x] = true;
	for(auto e : graph[x]) {
		if(!vis[e]) dfs(e);
	}
	order.pb(x);
}

vi comp;
void dfs2(int x) {
	vis[x] = true;
	comp.pb(x);

	for(auto e : gr2[x]) {
		if(!vis[e]) {
			dfs2(e);
		}
	}
}

vi pos;
vvi comps;

bool findscc() {
	order = {};
	vis = vb(n+1);

	forr(i, 1, n+1) {
		if(!vis[i]) dfs(i);
	}

	reverse(all(order));
	pos = vi(n+1);
	vis = vb(n+1);
	int id = 0;
	for(auto e : order) {
		if(!vis[e]) {
			comp = {};
			dfs2(e);
			for(auto x : comp) {
				pos[x] = id; 
				// printf("%d ", x);
			}
			comps.pb(comp);
			// printf("\n");
			id++;
		}
	}

	return pos[1] == pos[n];

}

vector<seti> gr3;

void dfs3(int x) {
	vis[x] = true;
	for(auto e : gr3[x]) {
		if(!vis[e]) dfs3(e);
	}
}

int main() {
	usaco();
	scd(n);
	scd(m);
	vector<pair<pii, int>> vec(m);

	gr2 = graph = vector<multiset<int>>(n+1);
	vvi val(n+1, vi(n+1, 2e9));

	frange(i, m) {
		int u, v, c, d;
		scd(u);
		scd(v);
		scd(c);
		scd(d);
		graph[u].insert(v);
		vec[i] = mp(mp(u, v), d);
		val[u][v] = min(val[u][v], d);

		gr2[v].insert(u);
	}

	bool out = findscc();

	int mi = 1e9;

	if(out) mi = 0;
	else {
		int i1 = pos[1];
		int i2 = pos[n];
		if(i1 > i2) swap(i1, i2);
		int cnt = comps.size();
		
		gr3 = vector<seti>(cnt);

		vis = vb(cnt);

		frange(i, cnt) {
			auto v = comps[i];
			for(auto e : v) {
				for(auto x : gr2[e]) gr3[i].insert(pos[x]);
			}
		}

		dfs3(i1);

		vb rech1 = vis;

		gr3 = vector<seti>(cnt);

		vis = vb(cnt);

		frange(i, cnt) {
			auto v = comps[i];
			for(auto e : v) {
				for(auto x : graph[e]) gr3[i].insert(pos[x]);
			}
		}

		dfs3(i2);

		vb rech2 = vis;

		forr(i, 0, cnt) {
			forr(j, 0, cnt) {
				if(rech1[i] && rech2[j]) {
					for(auto v : comps[i]) {
						for(auto e : comps[j]) mi = min(mi, val[v][e]);
					}
				}
			}
		}

	}

	// for(auto p : vec) {
	// 	// printf("**********\n");
	// 	graph[p.f.f].erase(graph[p.f.f].find(p.f.s));
	// 	gr2[p.f.s].erase(gr2[p.f.s].find(p.f.f));
	// 	graph[p.f.s].insert(p.f.f);
	// 	gr2[p.f.f].insert(p.f.s);
	// 	// forr(i, 1, n+1) {
	// 	// 	for(auto e : graph[i]) printf("%d ", e);
	// 	// 	printf("\n");
	// 	// }
	// 	if(findscc()) {
	// 		mi = min(mi, (lli)p.s);
	// 	}
	// 	gr2[p.f.f].erase(gr2[p.f.f].find(p.f.s));
	// 	graph[p.f.s].erase(graph[p.f.s].find(p.f.f));
	// 	graph[p.f.f].insert(p.f.s);
	// 	gr2[p.f.s].insert(p.f.f);
	// }

	if(mi <= 1e9) printf("%d", mi);
	else printf("-1");




}