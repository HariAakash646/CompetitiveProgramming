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

// Checked with: https://judge.yosupo.jp/problem/biconnected_components

vvi graph;
stack<pii> stk;
vi num, lowpt;
vector<seti> comps;

int timer = 0;

void dfs(int x, int p) {
	num[x] = timer++;
	lowpt[x] = num[x];

	for(auto e : graph[x]) {
		if(e != p) {
			if(num[e]) {
				lowpt[x] = min(lowpt[x], num[e]);
				if(num[e] < num[x])
					stk.push(mp(x, e));
			}
			else {
				stk.push(mp(x, e));
				dfs(e, x);
				lowpt[x] = min(lowpt[x], lowpt[e]);
			}
		}
	}
	if(p && lowpt[x] >= num[p]) {
		auto pa = stk.top();
		comps.pb({});

		do {
			pa = stk.top();
			stk.pop();
			comps.back().insert(pa.f);
			comps.back().insert(pa.s);
		}
		while(pa != mp(p, x) && stk.size());
	}
	if(!p) {
		if(graph[x].empty()) comps.pb({x});
	}
}

int main() {
	// usaco();
	int n, m;
	scd(n);
	scd(m);
	graph = vvi(n+1);

	frange(i, m) {
		int a, b;
		scd(a);
		scd(b);
		a++;
		b++;
		graph[a].pb(b);
		graph[b].pb(a);
	}

	num = lowpt = vi(n+1);

	forr(i, 1, n+1) {
		if(!num[i]) dfs(i, 0);
	}

	printf("%d\n", (int)comps.size());
	for(auto st : comps) {
		printf("%d ", (int)st.size());
		for(auto e : st) printf("%d ", e-1);
		printf("\n");
	}
}