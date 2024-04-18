#include <bits/stdc++.h>

using namespace std;

#define forr(i, j, k) for(int i=j; i<k; i++)
#define frange(i, k) forr(i, 0, k)
#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(vec) vec.begin(), vec.end()

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long lli;
typedef vector<lli> vll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef set<int> seti;
typedef map<int, int> mpii;
typedef multiset<int> mseti;
typedef vector<bool> vb;

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

// Checked with: https://judge.yosupo.jp/problem/scc

vvi graph, revg;
vi order;
vb vis;

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
	for(auto e : revg[x]) {
		if(!vis[e]) dfs2(e);
	}
}

int main() {
	// usaco();
	int n, m;
	scd(n);
	scd(m);

	graph = revg = vvi(n+1);

	frange(i, m) {
		int a, b;
		scd(a);
		scd(b);
		a++;
		b++;
		graph[a].pb(b);
		revg[b].pb(a);
	}

	vvi comps;

	vis = vb(n+1);

	forr(i, 1, n+1) {
		if(!vis[i]) dfs(i);
	} 

	reverse(all(order));
	vis = vb(n+1);

	for(auto e : order) {
		if(!vis[e]) {
			comp = {};
			dfs2(e);
			comps.pb(comp);
		}
	}
	printf("%d\n", (int)comps.size());
	for(auto v : comps) {
		printf("%d ", (int)v.size());
		for(auto e : v) printf("%d ", e-1);
		printf("\n");
	}
}