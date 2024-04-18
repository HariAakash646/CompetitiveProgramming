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

vvi graph;
vi dp1, dp2, dp3;
vi vec;

void dfs(int x, int p) {
	int sw = 1e9;
	int nsw = 0;
	int s2 = 1e9;
	int ns2 = 0;
	vi val, val2;
	for(auto e: graph[x]) {
		if(e != p) {
			dfs(e, x);
			nsw += dp1[e];
			ns2 += dp2[e];
			val2.pb(dp3[e] - dp2[e] + 1);
			val.pb(dp2[e] - dp1[e] + 1);
		}
	}
	// if(graph[x].size())
	sort(all(val));
	int v = nsw;
	frange(i, val.size()) {
		v += val[i];
		if(i % 2) nsw = min(nsw, v);
		else sw = min(sw, v);
	}
	v = ns2;
	frange(i, val2.size()) {
		v += val2[i];
		if(i % 2) ns2 = min(ns2, v);
		else s2 = min(s2, v);
	}
	if(vec[x]) {
		dp1[x] = sw;
		dp2[x] = nsw;
		dp3[x] = s2;
	}
	else {
		dp1[x] = nsw;
		dp2[x] = sw;
		dp3[x] = ns2;
	}
}

int main() {
	usaco();
	int n;
	scd(n);

	graph = vvi(n+1);
	frange(i, n-1) {
		int a, b;
		scd(a);
		scd(b);
		graph[a].pb(b);
		graph[b].pb(a);
	}
	vec = vi(n+1);
	forr(i, 1, n+1) scd(vec[i]);
	dp3 = dp1 = dp2 = vi(n+1, 1e9);
	dfs(1, 0);
	// forr(i, 1, n+1) printf("%d %d\n", dp1[i], dp2[i]);
	int mi = dp1[1];
	int tot = 0;
	vi val;
	for(auto e : graph[1]) {
		tot += dp2[e];
		val.pb(dp3[e] - dp2[e] + 1);
	}
	if(vec[1]) mi = min(mi, tot+1);
	sort(all(val));

	frange(i, val.size()) {
		tot += val[i];
		if(i % 2 == vec[i]) mi = min(mi, tot+1);
	}
	
	if(mi < 1e9)
	printf("%d", mi);
	else printf("impossible");

}