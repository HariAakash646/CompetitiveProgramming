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

int main() {
	// usaco();
	int n, m;
	scd(n);
	scd(m);

	vector<vll> cost(n+1, vll(n+1, 1e15)), chn(n+1, vll(n+1, 1e15)), dist(n+1, vll(n+1, 1e15));

	forr(i, 1, n+1) cost[i][i] = dist[i][i] = 0;
	vii edg;

	frange(i, m) {
		int u, v;
		lli c, d;
		scd(u);
		scd(v);
		sclld(c);
		sclld(d);
		// if(i%2==0)
		edg.pb(mp(u, v));

		dist[u][v] = cost[u][v] = min(c, cost[u][v]);
		chn[u][v] = min(chn[u][v], d);
	}

	frange(_, 3) {forr(k, 1, n+1) {
			forr(i, 1, n+1) {
				forr(j, 1, n+1) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}}

	lli mi = dist[1][n] + dist[n][1];
	// printf("%lld\n", mi);

	for(auto p : edg) {
		// printf("%d %d ", p.f, p.s);
		lli v = 0;
		v = dist[1][n] + dist[n][p.s] + dist[p.f][1] + min(dist[p.s][p.f], cost[p.f][p.s] + chn[p.f][p.s]);
		// printf("%lld ", v);
		mi = min(mi, v);
		v = dist[1][p.s] + dist[p.f][n] + dist[n][p.s] + dist[p.f][1] + min(2*dist[p.s][p.f], 2*cost[p.f][p.s] + chn[p.f][p.s]);
		// printf("%lld ", v);
		mi = min(mi, v);
		v = dist[1][p.s] + dist[p.f][n] + dist[n][1] + min(dist[p.s][p.f], cost[p.f][p.s] + chn[p.f][p.s]);
		// printf("%lld\n", v);
		mi = min(mi, v);
	}
	if(mi < 1e15)
	printf("%lld", mi);
	else printf("-1");
}