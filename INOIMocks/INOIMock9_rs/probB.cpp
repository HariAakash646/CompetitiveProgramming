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
typedef set<int> seti;

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}


struct LazySegtree {
	int n, size;
	vll vec, lazy;
	vector<pair<lli, int>> tree;

	void init(int l) {
		n = l;
		size = 1;
		while(size < n) size *= 2;
		vec = vll(size, 1e9);
		tree = vector<pair<lli, int>>(2*size, mp(-1e18, -1));
		lazy = vll(2*size, 0);
	}

	void set(int id, lli x) {
		vec[id] = x;
	}

	pair<lli, int> operation(pair<lli, int> x, pair<lli, int> y) {
		return max(x, y);
	}

	void recalculate(int x) {
		tree[x] = operation(tree[2*x+1], tree[2*x+2]);
	}

	void build(int x, int l, int r) {
		if(l == r) {
			tree[x] = mp(vec[l], l);
			return;
		}
		int mid = (l+r)/2;
		build(2*x+1, l, mid);
		build(2*x+2, mid+1, r);
		recalculate(x);
	}

	void build() {
		build(0, 0, size-1);
	}

	void propagate(int x, int l, int r) {
		tree[x].f += lazy[x];
		if(l < r) {
			lazy[2*x+1] += lazy[x];
			lazy[2*x+2] += lazy[x];
		}
		lazy[x] = 0;
	}

	void update(int x, int l, int r, int lx, int rx, lli v) {
		if(rx < l || lx > r) return;
		propagate(x, l, r);
		if(lx <= l && r <= rx) {
			lazy[x] += v;
			return;
		}		
		int mid = (l+r)/2;
		update(2*x+1, l, mid, lx, rx, v);
		update(2*x+2, mid+1, r, lx, rx, v);
		propagate(2*x+1, l, mid);
		propagate(2*x+2, mid+1, r);
		recalculate(x);
	} 

	void update(int lx, int rx, lli v) {
		update(0, 0, size-1, lx, rx, v);
	}

	pair<lli, int> query(int x, int l, int r, int lx, int rx) {
		if(rx < l || lx > r) return mp(-1e18, -1);
		if(lx <= l && r <= rx) return tree[x];
		int mid = (l+r)/2;
		auto v1 = query(2*x+1, l, mid, lx, rx);
		auto v2 = query(2*x+2, mid+1, r, lx, rx);
		return operation(v1, v2);
	}

	pair<lli, int> query(int lx, int rx) {
		return query(0, 0, size-1, lx, rx);
	}
};

struct Segtree {
	int n, size;
	vi vec, tree;

	void init(int l) {
		n = l;
		size = 1;
		while(size < n) size *= 2;
		vec = vi(size, 0);
		tree = vi(2*size, 0);
	}

	void set(int id, int x) {
		vec[id] = x;
	}

	int operation(int x, int y) {
		return x+y;
	}

	void recalculate(int x) {
		tree[x] = operation(tree[2*x+1], tree[2*x+2]);
	}

	void build(int x, int l, int r) {
		if(l == r) {
			tree[x] = vec[l];
			return;
		}
		int mid = (l+r)/2;
		build(2*x+1, l, mid);
		build(2*x+2, mid+1, r);
		recalculate(x);
	}

	void build() {
		build(0, 0, size-1);
	}

	void update(int x, int l, int r, int id, int v) {
		if(l == r) {
			tree[x] = v;
			return;
		}
		int mid = (l+r)/2;
		if(id <= mid)
			update(2*x+1, l, mid, id, v);
		else update(2*x+2, mid+1, r, id, v);
		recalculate(x);
	} 

	void update(int id, int v) {
		update(0, 0, size-1, id, v);
	}

	int query(int x, int l, int r, int lx, int rx) {
		if(rx < l || lx > r) return 0;
		if(lx <= l && r <= rx) return tree[x];
		int mid = (l+r)/2;
		int v1 = query(2*x+1, l, mid, lx, rx);
		int v2 = query(2*x+2, mid+1, r, lx, rx);
		return operation(v1, v2);
	}

	int query(int lx, int rx) {
		if(lx > rx) return 0;
		return query(0, 0, size-1, lx, rx);
	}
};

vvi graph;

int timer = -1;
vi st, en;
void dfs(int x, int p) {
	st[x] = ++timer;
	for(auto e : graph[x]) {
		if(e != p) dfs(e, x);
	}
	en[x] = timer;
}

int main() {
	// usaco();
	int n;
	lli x;
	scd(n);
	sclld(x);

	vll val(n+1);
	forr(i, 1, n+1) sclld(val[i]);

	graph = vvi(n+1);
	st = en = vi(n+1);

	frange(i, n-1) {
		int a, b;
		scd(a);
		scd(b);
		graph[a].pb(b);
		graph[b].pb(a);
	}

	dfs(1, 0);

	LazySegtree seg1;
	seg1.init(n);
	Segtree seg2;
	seg2.init(n);

	forr(i, 1, n+1) {
		if(val[i] >= x) {
			seg1.set(st[i], -1e18);
			seg2.set(st[i], 1);
		}
		else {
			seg1.set(st[i], val[i]);
		}
	}

	seg2.build();
	seg1.build();

	int q;
	scd(q);
	frange(_, q) {
		int t;
		scd(t);

		if(t == 1) {
			int id;
			lli c;
			scd(id);
			sclld(c);
			seg1.update(st[id], en[id], c);
			while(true) {
				auto p = seg1.query(st[id], en[id]);
				// printf("%d %lld\n", p.s, p.f);
				if(p.f >= x) {
					seg2.update(p.s, 1);
					seg1.update(p.s, p.s, -1e18);
				}
				else break;
			}
		}
		else {
			int id;
			scd(id);
			lli v1 = seg2.query(st[id], en[id]);
			lli v2 = seg2.query(0, n-1) - v1;
			printf("%lld\n", v1*v2);
		}
	}
}