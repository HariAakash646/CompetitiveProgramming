#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t);
#define forr(i, j, k) for(int i=j; i<k; i++)
#define frange(i, j) forr(i, 0, j)
#define pb push_back
#define mp mak_pair
#define all(vec) vec.begin(), vec.end()

typedef long long lli;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<lli> vll;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef set<int> seti;
typedef map<int, int> mpii;
typedef vector<bool> vb;

void usaco() {
	freopen("", "r", stdin);
}

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

template <class T>
struct SegTree {
	int n, size=1;
	vector<T> tree, vec;
	T def;

	void init(int l, T defl) {
		n = l;
		while(size < n) size *= 2;
		def = defl;
		tree = vector<T>(2*size);
		vec = vector<T>(size, def);
	}

	void set(int id, T v) {
		vec[id] = v;
	}

	T operation(T x, T y) {
		return max(x, y);
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
		buidl(2*x+2, mid+1, r);
		recalculate(x);
	}

	void build() {
		build(0, 0, size-1);
	}

	void update(int x, int l, int r, int id, T v) {
		if(l==r) {
			tree[x] = v;
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
		if( lx > r || rx < l) {
			return def;
		}
		if(lx <= l && r <= rx) {
			return tree[x];
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
struct BIT {
	int n;
	vector<T> bit, vec;
	

	BIT(int n) : size(n), bit(n+1), vec(n+1) {}

	int lsb(int x) {
		return x & (-x);
	}

	void add(int id, T v) {
		vec[id] += v;
		while(id <= n) {
			bit[id] += v;
			id += lsb(id);
		}
	}

	void set(int id, T v) {
		add(id, v-vec[id]);
	}

	T query(int id) {
		T tot = 0;
		while(id > 0) {
			tot += bit[id];
			id -= lsb(id);
		}
		return tot;
	}
}

template <class T>
struct LazySegTree {
	int n, size=1;
	vector<T> tree, vec, lazy;
	T def;

	void init(int l, T defl) {
		n = l;
		while(size < n) size *= 2;
		def = defl;
		lazy = tree = vector<T>(2*size);
		vec = vector<T>(size, def);
	}

	void set(int id, T v) {
		vec[id] = v;
	}

	T operation(T x, T y) {
		return max(x, y);
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
		buidl(2*x+2, mid+1, r);
		recalculate(x);
	}

	void build() {
		build(0, 0, size-1);
	}

	void propogate(int x, int l, int r) {
		tree[x] += lazy[x];
		if(l != r) {
			lazy[2*x+1] += lazy[x];
			lazy[2*x+2] += lazy[x];
		}
		lazy[x] = 0;
	}

	void update(int x, int l, int r, int lx, int rx, T v) {
		if(lx > r || rx < l) return;
		propogate(x, l, r);
		if(lx <= l && r <= rx) {
			lazy[x] += v;
			return;
		}
		int mid = (l+r)/2;
		update(2*x+1, l, mid, lx, rx, v);
		update(2*x+2, mid+1, r, lx, rx, v);
		propogate(2*x+1, l, mid);
		propogate(2*x+2, mid+1, r);
		recalculate(x);
	}

	void update(int lx, int rx, T v) {
		update(0, 0, size-1, lx, rx, v);
	}

	T query(int x, int l, int r, int lx, int rx) {
		if( lx > r || rx < l) {
			return def;
		}
		propogate(x, l, r);
		if(lx <= l && r <= rx) {
			return tree[x];
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

SegTree<int> segtree;
vvi graph;
vi sze, par, head, heavy, depth, pos, val;
int timer = 0;

void dfs(int x, int p) {
	depth[x] = depth[p] + 1;
	par[x] = p;
	int ma = 0;
	sze[x] = 1;

	for(auto e : graph[x]) {
		if(e != p) {
			dfs(e, x);
			sze[x] += sze[e];
			if(sze[e] > ma) {
				ma = sze[e];
				heavy[x] = e;
			}
		}
	}
}

void decompose(int x, int h, int p) {
	head[x] = h;
	pos[x] = timer++;
	segtree.set(pos[x], val[x]);
	if(heavy[x]) {
		decmpose(heavy[x], h, x);
	}

	for(auto e : graph[x]) {
		if(e != heavy[x] && e != p) {
			decompose(e, e, x);
		}
	}
}

int query(int a, int b) {
	int ma = 0;
	while(head[a] != head[b]) {
		if(depth[head[b]] < depth[head[a]]) swap(a, b);
		ma = max(ma, segtree.query(pos[head[b]], pos[b]));
		b = par[head[b]];
	} 
	if(depth[b] < depth[a]) swap(a, b);
	ma = max(ma, segtree.query(pos[a], pos[b]));
	return ma;
}

int get_sze(int x, int p) {
	sze[x] = 1;
	for(auto e : graph[x]) {
		if(!vis[e] && e != p) {
			sze[x] += get_sze(e, x);
		}
	}
	return sze[x];
}

int get_cent(int x, int p, int sz) {
	for(auto e : graph[x]) {
		if(e != p && !vis[e]) {
			if(sze[e] * 2 > sz) return get_cent(e, x, sz);
		}
	}
	return x;
}

void decompose(int x) {
	sz = get_sze(x, 0);
	x = get_cent(x, 0, sz);
	vis[x] = true;
	for(auto e : graph[x]) {
		if(vis[e]) decompose(e);
	}
}

void init(int n) {
	minv = vvi(20, vi(n));
	frange(i, n) minv[0][i] = vec[i];

	forr(i, 1, 20) {
		frange(j, n) minv[i][j] = min(minv[i-1][j], minv[i-1][min(n-1, j+(1<<(i-1)))]);
	}
}

int query(int l, int r) {
	int len = r - l + 1;
	int msb = 31 - __builtin_clz(len);

	return min(minv[msb][l], minv[msb][r-(1<<msb)+1]);
}