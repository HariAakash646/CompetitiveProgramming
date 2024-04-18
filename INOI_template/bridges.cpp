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

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

// Checked with CSES 2076

vvi graph;

vi num, lowpt;

vii bridg;
int timer = 0;

void dfs(int x, int p) {
	num[x] = ++timer;
	lowpt[x] = num[x];

	for(auto e : graph[x]) {
		if(e != p) {
			if(num[e]) lowpt[x] = min(lowpt[x], num[e]);
			else {
				dfs(e, x);
				lowpt[x] = min(lowpt[x], lowpt[e]);
			}
		}
	}

	if(p && lowpt[x] == num[x]) {
		bridg.pb(mp(p, x));
	}
}

int main() {
	// usaco();
	int n, m;
	scd(n);
	scd(m);
	graph = vvi(n+1);
	num = lowpt = vi(n+1);

	frange(i, m) {
		int a, b;
		scd(a);
		scd(b);
		graph[a].pb(b);
		graph[b].pb(a);
	}

	dfs(1, 0);

	printf("%d\n", (int)bridg.size());

	for(auto p : bridg) {
		printf("%d %d\n", p.f, p.s);
	}
}