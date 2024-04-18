#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

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


typedef tree<
lli,
null_type,
less_equal<lli>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

vll djikstra(int u, int n, vector<vector<pair<int, lli>>>& graph) {
	vll dist(n+1, 1e18);
	vb vis(n+1);
	priority_queue<pair<lli, int>> pq;
	dist[u] = 0;
	pq.push(mp(0, u));

	while(pq.size()) {
		auto p = pq.top();
		pq.pop();
		if(vis[p.s]) continue;
		vis[p.s] = true;
		for(auto e : graph[p.s]) {
			if(e.s - p.f < dist[e.f]) {
				dist[e.f] = e.s - p.f;
				pq.push(mp(-dist[e.f], e.f));
			}
		}
	}
	return dist;
}

int main() {
	// usaco();
	int n, m;
	int s1, t;
	scd(n);
	scd(m);
	scd(s1);
	scd(t);
	lli l, k;
	sclld(l);
	sclld(k);

	vector<vector<pair<int, lli>>> graph(n+1);

	frange(i, m) {
		int a, b;
		lli c;
		scd(a);
		scd(b);
		sclld(c);
		graph[a].pb(mp(b, c));
		graph[b].pb(mp(a, c));
	}

	vll dist1 = djikstra(s1, n, graph);
	vll dist2 = djikstra(t, n, graph);

	ordered_set st, st2;

	if(dist1[t] <= k) {
		printf("%lld", (lli(n) * (n-1))/2);
		return 0;
	}
	lli out = 0;
	forr(i, 1, n+1) {
		lli v = dist2[i] + l;
		out += st.order_of_key(k - v + 1);
		// printf("%lld %lld ", dist1[i], dist2[i]);
		
		st.insert(dist1[i]);
		v = dist1[i] + l;
		out += st2.order_of_key(k - v+1);
		st2.insert(dist2[i]);
		// printf("%d %lld\n", i, out);
	}

	printf("%lld", out);
}