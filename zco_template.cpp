#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for(int i=j; i<k; i++)
#define frange(i, k) forr(i, 0, k)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(vec) vec.begin(), vec.end()

typedef vector<int> vi;
typedef long long lli;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

template <class T>
struct BIT {
	int size;
	vector<T> bit, vec;

	BIT(int n) : size(n), vec(n+1), bit(n+1) {}

	int lsb(int x) {
		return x & (-x);
	}

	void add(int id, T v) {
		vec[id] += v;
		while(id <= size) {
			bit[id] += v;
			id += lsb(id);
		}
	}

	void set(int id, T v) {
		add(id, v-vec[id]);
	}

	T query(int id) {
		T tot = 0;
		while(id >= 1) {
			tot += bit[id];
			id -= lsb(id);
		}
		return tot;
	}
};

template <class T>
struct SegTree {
	int n;
	int size = 1;
	vector<T> vec, segtree;

	void init(int l) {
		n = l;
		while(size < n) size *= 2;
		vec = vector<T>(size, 1e9+5);
		segtree = vector<T>(2*size, 1e9+5);
	}

	void set(int x, T v) {
		vec[x] = v;
	}

	T operation(T x, T y) {
		return min(x, y);
	}

	void recalculate(int x) {
		segtree[x] = operation(segtree[2*x+1], segtree[2*x+2]);
	}

	void build(int x, int l, int r) {
		if(l == r) {
			segtree[x] = vec[l];
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

	void update(int x, int l, int r, int id, T v) {
		if(l == r) {
			segtree[x] = v;
			return;
		}
		int mid = (l+r)/2;
		if(id <= mid) update(2*x+1, l, mid, id, v);
		else update(2*x+2, mid+1, r, id, v);
		recalculate(x);
	}

	void update(int id, T v) {
		update(0, 0, size-1, id, v);
	}

	T query(int x, int l, int r, int lx, int rx) {
		if(l > rx || r < lx) {
			return 1e9+5;
		}
		if(lx <= l && r <= rx) {
			return segtree[x];
		}
		int mid = (l+r)/2;
		T v1 = query(2*x+1, l, mid, lx, rx);
		T v2 = query(2*x+2, mid+1, r, lx, rx);
		return operation(v1, v2);
	}

	T query(int lx, int rx) {
		return query(0, 0, size-1, lx, rx);
	}
};

template <class T>
struct LazySegTree {
	int n;
	int size = 1;
	vector<T> vec, segtree, lazy;

	void init(int l) {
		n = l;
		while(size < n) size *= 2;
		vec = vector<T>(size);
		segtree = vector<T>(2*size);
		lazy = vector<T>(2*size);
	}

	void set(int x, T v) {
		vec[x] = v;
	}

	T operation(T x, T y) {
		return x+y;
	}

	void recalculate(int x) {
		segtree[x] = operation(segtree[2*x+1], segtree[2*x+2]);
	}

	void build(int x, int l, int r) {
		if(l == r) {
			segtree[x] = vec[l];
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
		segtree[x] += lazy[x] * (r - l + 1);
		if(l != r) {
			lazy[2*x+1] += lazy[x];
			lazy[2*x+2] += lazy[x];
		}
		lazy[x] = 0;
	} 

	void update(int x, int l, int r, int lx, int rx, T v) {
		if(l > rx || r < lx) {
			return;
		}
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

	void update(int lx, int rx, T v) {
		update(0, 0, size-1, lx, rx, v);
	}

	T query(int x, int l, int r, int lx, int rx) {
		if(l > rx || r < lx) {
			return 0;
		}
		propagate(x, l, r);
		if(lx <= l && r <= rx) {
			return segtree[x];
		}
		int mid = (l+r)/2;
		T v1 = query(2*x+1, l, mid, lx, rx);
		T v2 = query(2*x+2, mid+1, r, lx, rx);
		return operation(v1, v2);
	}

	T query(int lx, int rx) {
		return query(0, 0, size-1, lx, rx);
	}
};

// graph general
int n, m;
vvi graph;
vb vis;

vi num, lowpt;
// finding bridges

int timer = 0;
vii bridg;

void dfs(int x, int p) {
	num[x] = ++timer;
	lowpt[x] = num[x];
	for(auto e : graph[x]) {
		if(e == p) continue;
		if(num[e]) {
			if(num[e] < num[x]) lowpt[x] = min(lowpt[x], num[e]);
		}
		else {
			dfs(e, x);
			lowpt[x] = min(lowpt[x], lowpt[e]);
		}
	}
	if(p != 0 && lowpt[x] >= num[x]) {
		bridg.pb(mp(x, p));
	}
}

// finding articulation points

int timer = 0;
seti artic;

void dfs(int x, int p, int c) {
	num[x] = ++timer;
	lowpt[x] = num[x];
	int c1 = 0;
	for(auto e : graph[x]) {
		if(e == p) continue;
		if(num[e]) {
			if(num[e] < num[x]) {
				lowpt[x] = min(lowpt[x], num[e]);
			}
		}
		else {
			c1++;
			// stk.push(mp(e, x));
			dfs(e, x, c1);

			lowpt[x] = min(lowpt[x], lowpt[e]);
		}
	}
	if(p != 0 && lowpt[x] >= num[p]) {
		
		if(p != 1 || c > 1)
			artic.insert(p);
	}
}

// SCC finding
vvi comps;
vi comp;
vi order;
vvi revg;

void dfs(int x) {
	if(vis[x]) return;
	vis[x] = true;
	for(auto e : graph[x]) {
		dfs(e);
	}
	order.pb(x);
}

void dfs2(int x) {
	if(vis[x]) return;
	vis[x] = true;
	comp.pb(x);
	for(auto e : revg[x]) {
		dfs2(e);
	}
}

int n;

vvi minv;
vi vec;

void init() {
	minv = vvi(20, vi(n));
	frange(i, n) minv[0][i] = vec[i];

	forr(i, 1, 20) {
		frange(j, n) {
			minv[i][j] = min(minv[i-1][j], minv[i-1][min(n-1, j+(1<<(i-1)))]);
		}
	}
}

int query(int l, int r) {
	int len = r - l + 1;
	int msb = 31 - __builtin_clz(len);

	return min(minv[msb][l], minv[msb][r-(1<<msb)+1]);
}


// order_set

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<
    pii,
    null_type,
    less<pii>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;