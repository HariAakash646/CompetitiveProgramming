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

vvi graph;
vb black;
vi pos;

int dfs(int x, int p, int d, int v) {
	int ma = d+1;
	int mi = d+1;
	for(auto e : graph[x]) {
		if(e != p) {
			int v1 = dfs(e, x, d+1, v);
			printf("%d %d %d\n", x, e, v1);
			if(v1 == -1) return -1;
			mi = min(mi, v1);
			ma = max(ma, v1);
		}
	}
	if(black[x]) {
		printf("%d %d %d %d %d\n", x, d, v, ma, mi);
		if(mi <= d) return -1;
		
		if(d + v < ma) return d;
		else return d - v;
	}
	else {
		if(mi <= d) return mi;
		else return ma;
	}
}

bool check(int x) {
	int v = dfs(1, 0, 0, x);
	return v >= 0;
}

int dfs2(int x, int p, int d, int v, int po) {
	int ma = d+1;
	int mi = d+1;
	for(auto e : graph[x]) {
		if(e != p) {
			int v2 = dfs2(e, x, d+1, v, po);
			if(v2 == -1) return -1;
			mi = min(mi, v2);
			ma = max(ma, v2);
		}
	}
	// printf("%d %d %d %d %d %d\n", x, d, ma, mi, v, po);
	if(black[x]) {
		if(mi <= d) return -1;
		int v1 = v;
		if(pos[x] <= po) v1++;
		if(d + v1 < ma) return d;
		else return d - v1;
	}
	else {
		if(mi <= d) return mi;
		else return ma;
	}
}

bool check2(int x, int v) {
	int v1 = dfs2(1, 0, 0, v, x);
	return v1 >= 0;
}

int main() {
	usaco();
	int t;
	scd(t);

	frange(_, t) {
		int n, k;
		scd(n);


		graph = vvi(n+1);
		black = vb(n+1);

		frange(i, n-1) {
			int a, b;
			scd(a);
			scd(b);
			graph[a].pb(b);
			graph[b].pb(a);
		}
		scd(k);
		pos = vi(n+1);
		frange(i, k) {
			int v;
			scd(v);
			black[v] = true;
			pos[v] = i+1;
		}

		int lo = 0;
		int hi = n;

		// while(lo != hi) {
		// 	int mid = (lo+hi+1)/2;
		// 	if(check(mid)) {
		// 		lo = mid;
		// 	}
		// 	else hi = mid-1;
		// }
		check(2);
		// printf("%d ", lo);
		int v = lo;
		int cnt = lo * k;
		lo = 0;
		hi = k;


		while(lo != hi) {
			int mid = (lo+hi+1)/2;
			if(check2(mid, v)) {
				lo = mid;
			}
			else hi = mid-1;
		}
		cnt += lo;
		printf("%d\n", cnt);
	}
}