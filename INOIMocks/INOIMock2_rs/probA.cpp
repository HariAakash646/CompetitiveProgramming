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
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<lli> vll;
typedef vector<bool> vb;


void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

int n, m, k;
vector<vii> graph;

bool check(int x) {
	vi dist(n+1, 1e9);
	deque<int> pq;
	dist[1] = 0;
	pq.push_back(1);
	vb vis(n+1);
	while(pq.size()) {
		auto p = pq.front();
		pq.pop_front();
		// printf("%d\n", p.s);
		if(vis[p]) continue;
		vis[p] = true;

		for(auto e : graph[p]) {
			int w = 0;
			if(e.s > x) w++;
			if(dist[p] + w < dist[e.f]) {
				dist[e.f] = dist[p] + w;
				if(w) pq.pb(e.f);
				else pq.push_front(e.f);
			}
		}
	}

	return dist[n] < k;
}

int main() {
	// usaco();
	scd(n);
	scd(m);
	scd(k);

	graph = vector<vii>(n+1);

	frange(i, m) {
		int a, b, d;
		scd(a);
		scd(b);
		scd(d);

		graph[a].pb(mp(b, d));
		graph[b].pb(mp(a, d));
	}

	int lo = 0;
	int hi = 1e9;

	while(lo != hi) {
		int mid = (lo + hi)/2;
		if(check(mid)) hi = mid;
		else lo = mid+1;
	}

	if(lo == 0) printf("-1");
	else printf("%d", lo); 




}