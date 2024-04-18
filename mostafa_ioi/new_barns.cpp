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

vvi graph, tree, lift;
vi sze, par, dist;
vb vis;

void dfs(int x, int p) {
	dist[x] = dist[p] + 1;
	vis[x] =true;
	lift[0][x] = p;
	for(auto e : graph[x]) {
		if(e != p) dfs(e, x);
	}
}

int binlift(int x, int c) {
	frange(i, 20) {
		if(c & (1<<i)) x = lift[i][x];
	}
	return x;
}

int lca(int u, int v) {
	if(dist[u] > dist[v]) swap(u, v);
	v = binlift(v, dist[v] - dist[u]);
	if(u == v) return u;

	for(int i=19; i>=0; i--) {
		int ut = lift[i][u];
		int vt = lift[i][v];
		if(ut != vt) {
			u = ut;
			v = vt;
		}
	}
	return lift[0][u];
}

int get_size(int x, int p) {
	sze[x] = 1;
	for(auto e : graph[x]) {
		if(e != p && !vis[e]) {
			sze[x] += get_size(e, x);
		}
	}
	return sze[x];
}

int centroid(int x, int p, int sz) {
	for(auto e : graph[x]) {
		if(e != p && !vis[e] && sze[e] * 2 >= sz) {
			return centroid(e, x, sz);
		}
	}
	return x;
}

void decompose(int x, int p) {
	int sz = get_size(x, 0);
	x = centroid(x, 0, sz);
	if(p) {
		tree[p].pb(x);
		tree[x].pb(p);
		par[x] = p;
	}
	// else printf("%d\n", x);
	// printf("%d\n", x);
	vis[x] = true;

	for(auto e : graph[x]) {
		if(!vis[e]) decompose(e, x);
	}
}

int distance(int u, int v) {
	int l = lca(u, v);
	return dist[u] + dist[v] - 2*dist[l];
}

vb act;
vii ma, sma;

void upd(int x, int p, int st) {
	if(x == 0) return;
	int d = distance(x, st);
	if(d >= ma[x].f) {
		if(ma[x].s != p)
			sma[x] = ma[x];
		ma[x] = mp(d, p);
	}
	else if(d > sma[x].f) {
		if(ma[x].s != p)
			sma[x] = mp(d, p);
	}
	upd(par[x], x, st);
}

int query(int x, int p, int st) {
	if(x == 0) return -1e9;
	int d = distance(x, st);
	if(p != ma[x].s) d += ma[x].f;
	else d += sma[x].f;
	// printf("%d %d\n", x, d);
	// if(!act[x]) d = -1e9;
	return max(d, query(par[x], x, st));
}

int main() {
	// usaco();
	freopen("newbarn.in", "r", stdin);
	freopen("newbarn.out", "w", stdout);
	int q;
	cin >> q;

	vector<pii> quer(q);

	tree = graph = vvi(q+1);
	int id = 1;
	frange(i, q) {
		char c;
		cin >> c;
		if(c == 'B') {
			int p;
			cin >> p;
			if(p != -1)
			{
				graph[p].pb(id);
				graph[id].pb(p);
				// if(id == 15486) printf("%d\n",p);
			}
			quer[i] = mp(0, id);
			id++;
		}
		else {
			int x;
			cin >> x;
			quer[i] = mp(1, x);
		}
	}

	int n = id-1;

	lift = vvi(20, vi(n+1));
	dist = sze = par = vi(n+1);
	vis = vb(n+1);
	forr(i, 1, n+1) if(!vis[i]) dfs(i, 0);
	vis = vb(n+1);
	forr(i, 1, 20) {
		forr(j, 1, n+1) {
			lift[i][j] = lift[i-1][lift[i-1][j]];
		}
	}

	// decompose(1, 0);
	// printf("%d\n", par[15486]);
	forr(i, 1, n+1) {
		if(!vis[i]) decompose(i, 0);
	}

	ma = sma = vii(n+1, mp(-1e9, -1));
	act = vb(n+1);

	for(auto p : quer) {
		if(p.f) {
			int out = query(p.s, 0, p.s);
			out = max(out, ma[p.s].f);

			cout<< out << "\n";
		}
		else {
			act[p.s] = true;
			upd(p.s, 0, p.s);
		}
	}

}