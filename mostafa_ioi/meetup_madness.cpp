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
vvi lift;
vector<vll> liftv;
vi depth;

void dfs(int x, int p) {
	depth[x] = depth[p] + 1;
	for(auto e : graph[x]) {
		if(e.f != p) {
			lift[0][e.f] = x;
			liftv[0][e.f] = e.s;
			dfs(e.f, x);
		}
	}
}

int binlift(int x, int c) {
	frange(i, 20) {
		if(c & (1<<i)) x = lift[i][x];
	}
	return x;
}

lli binliftv(int x, int c) {
	lli tot = 0;
	frange(i, 20) {
		if(c & (1<<i)) {
			tot += liftv[i][x];
			x = lift[i][x];
		}
	}
	return tot;
}

lli binlift2(int x, int d, lli v) {
	lli tot = 0;
	for(int i=19; i>=0; i--) {
		int xt = lift[i][x];
		lli tott = tot + liftv[i][x];
		if(depth[xt] > d && tott < v) {
			x = xt;
			tot = tott;
		}
	}
	return tot + liftv[0][x];
}

lli binlift3(int x, int d, lli v) {
	lli tot = 0;
	for(int i=19; i>=0; i--) {
		int xt = lift[i][x];
		lli tott = tot + liftv[i][x];
		if(depth[xt] >= d && tott <= v) {
			x = xt;
			tot = tott;
		}
	}
	return tot;
}

int lca(int u, int v) {
	if(depth[v] > depth[u]) {
		swap(u, v);
	}
	u = binlift(u, depth[u]-depth[v]);
	if(u == v) return v;

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

int main() {
	// usaco();
	int n, q;
	scd(n);
	scd(q);

	graph = vector<vii>(n+1);

	frange(i, n-1) {
		int a, b, c;
		scd(a);
		scd(b);
		scd(c);
		graph[a].pb(mp(b, c));
		graph[b].pb(mp(a, c));
	}

	lift = vvi(20, vi(n+1));
	liftv = vector<vll>(20, vll(n+1));
	depth = vi(n+1);

	dfs(1, 0);
	liftv[0][1] = 1e17;

	forr(i, 1, 20) {
		forr(j, 1, n+1) {
			lift[i][j] = lift[i-1][lift[i-1][j]];
			liftv[i][j] = liftv[i-1][j] + liftv[i-1][lift[i-1][j]];
		}
	}

	frange(_, q) {
		int u, v;
		scd(u);
		scd(v);
		int l = lca(u, v);

		lli val = binliftv(u, depth[u]-depth[l]) + binliftv(v, depth[v]-depth[l]);
		lli d = binlift2(u, depth[l], (val+1)/2);
		lli out = max(d, val-d);
		d = binlift2(v, depth[l], (val+1)/2);
		out = min(out, max(d, val-d));
		d = binlift3(u, depth[l], (val)/2);
		out = min(out, max(d, val-d));
		d = binlift3(v, depth[l], (val)/2);
		out = min(out, max(d, val-d));
		printf("%lld\n", out);
	}


}