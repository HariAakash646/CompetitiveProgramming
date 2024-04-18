#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
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
typedef long double ld;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;
typedef multiset<int> mseti;

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

lli tot = 0;
vector<vector<pair<int, lli>>> graph;
vll vec, val, dp;

vll cost, cnt;

void dfs(int x, int p) {
	cnt[x] = vec[x];
	for(auto e : graph[x]) {
		if(e.f != p) {
			dfs(e.f, x);
			cost[x] += cost[e.f];
			cost[x] += cnt[e.f] * e.s;
			cnt[x] += cnt[e.f];
			val[e.f] = e.s;
		}
	}
	// printf("%d %lld\n", x, cnt[x]);
}

void dfs2(int x, int p, lli v) {
	if(p != 0) {
		dp[x] = (cost[p] - (cost[x] + cnt[x] * v)) + dp[p] + (tot - cnt[x]) * v;
	}
	for(auto e : graph[x]) {
		if(e.f != p) {
			dfs2(e.f, x, e.s);
			
		}
	}
}

int main() {
	// usaco();
	int n;
	scd(n);

	graph = vector<vector<pair<int, lli>>>(n+1);
	vec = vll(n+1);

	forr(i, 1, n+1) {
		sclld(vec[i]);
		tot += vec[i];
	}

	frange(i, n-1) {
		int a, b;
		lli c;
		scd(a);
		scd(b);
		a++;
		b++;
		sclld(c);
		graph[a].pb(mp(b, c));
		graph[b].pb(mp(a, c));
	}

	dp = val = cost = cnt = vll(n+1);

	dfs(1, 0);
	dfs2(1, 0, 0);

	forr(i, 1, n+1) {
		printf("%lld ", cost[i] + dp[i]);
	}
}