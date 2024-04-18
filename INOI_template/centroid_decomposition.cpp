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

int n, k;
vvi graph;

vi sze;
vi par;
vb vis;

int get_sze(int x, int p) {
	sze[x] = 1;
	for(auto e : graph[x]) {
		if(e != p && !vis[e]) {
			sze[x] += get_sze(e, x);
		}
	}
	return sze[x];
}

int get_centroid(int x, int p, int sz) {
	for(auto e : graph[x]) {
		if(!vis[e] && e != p && 2 * sze[e] > sz) {
			return get_centroid(e, x, sz);
		}
	}
	return x;
}

lli tot = 0;
vi cnt;
int mad = 0;

void val(int x, int p, int d, int v) {
	if(d > k) return;
	mad = max(mad, d);
	if(v)
		cnt[d]+=v;
	else if(d <= k) {
		tot += cnt[k-d];
	}
	for(auto e : graph[x]) {
		if(e != p && !vis[e]) {
			val(e, x, d+1, v);
		}
	}
}

void decompose(int x, int p) {
	int sz = get_sze(x, 0);
	x = get_centroid(x, 0, sz);
	vis[x] = true;
	par[x] = p;

	cnt[0]++;
	mad = 0;

	for(auto e : graph[x]) {
		if(!vis[e]) {
			val(e, x, 1, 0);
			val(e, x, 1, 1);
		}
	}

	frange(i, mad+1) cnt[i] = 0;

	for(auto e : graph[x]) {
		if(!vis[e]) decompose(e, x);
	}
}



int main() {
	// usaco();
	
	scd(n);
	scd(k);

	graph = vvi(n+1);
	sze = par = vi(n+1);
	vis = vb(n+1);

	frange(i, n-1) {
		int a, b;
		scd(a);
		scd(b);
		graph[a].pb(b);
		graph[b].pb(a);
	}

	cnt = vi(k+1);

	decompose(1, 0);

	printf("%lld", tot);
}