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

vvi graph;
vi nodes;

bool dfs1(int x, int p, int b) {
	if(x == b) return true;
	for(auto e : graph[x]) {
		if(e != p) {
			bool out = dfs1(e, x, b);
			if(out) {
				nodes.pb(e);
				return true;
			}
		}
	}
	return false;
}

int dfs(int x, int p1, int p2) {
	int out = 0;
	vi vec;
	for(auto e : graph[x]) {
		if(e != p1 && e != p2) {
			int v = dfs(e, x, p2);
			v++;
			vec.pb(v);
		}
	}
	sort(all(vec), greater<>());
	frange(i, vec.size()) vec[i] += i;
	if(vec.size()) return *max_element(all(vec));
	else return 0;
}

int main() {
	// usaco();
	int n, k;
	scd(n);
	scd(k);

	if(k == 2) {
		int a, b;
		scd(a);
		scd(b);
		graph = vvi(n+1);
	
		frange(i, n-1) {
			int u, v;
			scd(u);
			scd(v);
			graph[u].pb(v);
			graph[v].pb(u);
		}
		dfs1(a, 0, b);
		
		nodes.pb(a);
	
		reverse(all(nodes));
	
		
		int ma = 1e9;
		// vi v1(nodes.size());
		// v1[1] = dfs(nodes[1], nodes[0], nodes[2]);
		// v1[(int)nodes.size()-2] = dfs(nodes[(int)nodes.size()-2], nodes[(int)nodes.size()-3], nodes[(int)nodes.size()-1]);
		// ma = max(v1[(int)nodes.size()-2], v1[1]);
		int l = 1;
		int r = nodes.size()-1;
	    while (r-l>=3) {
	        int m1 = l + (r - l) / 3;
	        int m2 = r - (r - l) / 3;
	        int f1 = max(dfs(a, 0, nodes[m1]), dfs(b, 0, nodes[m1-1]));
	        int f2 = max(dfs(a, 0, nodes[m2]), dfs(b, 0, nodes[m2-1]));
	        if (f1 >= f2)
	            l = m1;
	        else
	            r = m2;
	    }
		forr(i, l, r+1) {
			ma = min(ma, max(dfs(a, 0, nodes[i]), dfs(b, 0, nodes[i-1])));
		}
		printf("%d", ma);
	}
	else {
		int rt;
		scd(rt);

		graph = vvi(n+1);

		frange(i, n-1) {
			int a, b;
			scd(a);
			scd(b);
			graph[a].pb(b);
			graph[b].pb(a);
		}

		int out = dfs(rt, 0, 0);
		printf("%d", out);
	}
}