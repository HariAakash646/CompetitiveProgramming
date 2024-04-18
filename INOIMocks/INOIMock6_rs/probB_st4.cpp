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

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

int main() {
	// usaco();
	int n, m;
	scd(n);
	scd(m);

	vii vec(m); 

	frange(i, m) {
		scd(vec[i].f);

	}
	frange(i, m) scd(vec[i].s);

	sort(all(vec));

	vvi graph(2*m+2);
	vvi cost(2*m+2, vi(2*m+2)), flow(2*m+2, vi(2*m+2));

	frange(i, m) {
		auto p = vec[i];
		forr(j, i+1, m) {
			auto p2 = vec[j];
			if(abs(p2.s-p.s) <= p2.f-p.f) {
				cost[i][j+m]++;
				graph[i].pb(j+m);
				graph[j+m].pb(i);
			}
		}
		graph[2*m].pb(i);
		graph[i].pb(2*m);
		cost[2*m][i]++;
		graph[i+m].pb(2*m+1);
		graph[2*m+1].pb(i+m);
		cost[i+m][2*m+1]++;
	}

	while(true) {
		bool done = false;
		vb vis(2*m+2);
		vi par(2*m+2, -1);
		queue<pair<pii, int>> q;
		q.push(mp(mp(2*m, -1), 1e9));

		while(q.size()) {
			auto p = q.front();
			q.pop();
			if(vis[p.f.f]) continue;
			vis[p.f.f] = true;
			par[p.f.f] = p.f.s;
			if(p.f.f == 2*m+1) {
				int x = p.f.f;
				while(par[x] != -1) {
					int pa = par[x];
					flow[pa][x]+=p.s;
					cost[x][pa]+=p.s;
					// printf("%d %d\n", pa, x);
					x = pa;
				}
				done = true;
				break;
			}

			for(auto e : graph[p.f.f]) {
				if(flow[p.f.f][e] != cost[p.f.f][e]) {
					q.push(mp(mp(e, p.f.f), min(p.s, cost[p.f.f][e] - flow[p.f.f][e])));
				}
			}
		}
		if(!done) break;
	}

	int c = 0;

	frange(i, m) {
		bool done = false;
		frange(j, m) {
			if(cost[j][i+m] && cost[j][i+m] == flow[j][i+m]) done = true;
		}
		if(!done) c++;
	}
	printf("%d", c);
}