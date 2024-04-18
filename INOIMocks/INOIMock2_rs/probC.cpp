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
typedef set<int> seti;


void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

vvi graph;
vii edg;
map<pii, int> med;
seti curr;

bool dfs(int x, int p, int tar) {
	if(x == tar) {
		return true;
	}
	for(auto e : graph[x]) {
		if(e != p) {
			bool out = dfs(e, x, tar);
			if(out) {
				curr.insert(med[mp(e, x)]);
				return true;
			}
		}
	}
	return false;
}

int main() {
	// usaco();
	int n, m;

	scd(n);
	scd(m);

	graph = vvi(n+1);

	edg = vii(m);

	frange(i, m) {
		scd(edg[i].f);
		scd(edg[i].s);
		if(edg[i].s < edg[i].f) swap(edg[i].f, edg[i].s);
		med[edg[i]] = i;
		med[mp(edg[i].s, edg[i].f)] = i;
	}

	vb tree(m);

	frange(i, n-1) {
		int id;
		scd(id);
		id--;
		graph[edg[id].f].pb(edg[id].s);
		graph[edg[id].s].pb(edg[id].f);
		tree[id] = true;
	}

	int cent = 0;

	forr(i, 1, n+1) {
		if(graph[i].size() > 1) cent = i;
	}

	med[mp(cent, cent)] = m;

	vi pos(m+1, -1);
	pos[m] = 0;
	seti st, active;

	forr(i, 1, n+1) active.insert(i);

	forr(i, 1, m+1) st.insert(i);
	frange(i, m) {
		if(tree[i]) {
			if(pos[i] != -1) continue;
			pos[i] = *st.begin();
			st.erase(st.begin());
		}
		else {
			if(pos[i] != -1) continue;
			curr = {};
			auto it = active.lower_bound(edg[i].f);
			for(; it != active.end() && *it<edg[i].s; it++) {

				int id = med[mp(*it, *it + 1)];
				curr.insert(id);
			} 
			it = active.lower_bound(edg[i].f);
			while(it != active.end() && *it < edg[i].s) {
				active.erase(it);
				it = active.lower_bound(edg[i].f);
			}
			for(auto e : curr) {
				if(pos[e] != -1) continue;
				pos[e] = *st.begin();
				st.erase(*st.begin());
			}
			pos[i] = *st.begin();
			st.erase(st.begin());
		}
	}

	frange(i, m) printf("%d ", pos[i]);



}