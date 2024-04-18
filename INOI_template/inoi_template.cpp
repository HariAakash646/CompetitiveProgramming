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

	void init(int l) {
		n = l;
		while(size < n) size *= 2;
		tree = vector<T>(2*size, 1e9);
		vec = vector<T>(size, 1e9);
	}

	void set(int id, T v) {
		vec[id] = v;
	}

	T operation(T x, T y) {
		return min(x, y);
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

	void update(int x, int l, int r, int id, T v) {
		if(l == r) {
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
		if(l > rx || r < lx) {
			return 2e9;
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
struct LazySegTree {
	int n, size=1;
	vector<T> lazy, tree, vec;

	void init(int l) {
		n = l;
		while(size<n) size*=2;
		tree = vector<T>(2*size);
		vec = vector<T>(size);
		lazy = vector<T>(2*size);
	}

	T operation(T x, T y) {
		return x+ y;
	}

	void recalculate(int x) {
		tree[x] = operation(tree[2*x+1], tree[2*x+2]);
	}

	void set(int id, T v) {
		vec[id] = v;
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

	void propagate(int x, int l, int r) {
		tree[x] += (r-l+1) * lazy[x];
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
	int size;
	vector<T> vec, bit;

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
		add(id, v - vec[id]);
	}

	T query(int id) {
		T tot = 0;
		if(id == 0) return tot;

		while(id >= 1) {
			tot += bit[id];
			id -= lsb(id);
		}
		return tot;
	}
};

vi vec;
vvi minv;

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

vvi graph;
vb vis;

vi num, lowpt;

vii bridg;
int timer = 0;

void dfs(int x, int p) {
	num[x] = ++timer;
	lowpt[x] = num[x];

	for(auto e : graph[x]) {
		if(e != p) {
			if(num[e]) lowpt[x] = min(lowpt[x], num[e]);
			else {
				dfs(e, x);
				lowpt[x] = min(lowpt[x], lowpt[e]);
			}
		}
	}

	if(p && lowpt[x] == num[x]) {
		bridg.pb(mp(p, x));
	}
}

vi artic;
vi num, lowpt;

int timer = 0;

void dfs(int x, int p) {
	num[x] = ++timer;
	lowpt[x] = num[x];
	int comp = (p!=0);
	for(auto e : graph[x]) {
		if(e != p) {
			if(num[e]) {
				lowpt[x] = min(lowpt[x], num[e]);
			}
			else {
				dfs(e, x);
				if(lowpt[e] >= num[x]) {
					comp++;
				}
				lowpt[x] = min(lowpt[x], lowpt[e]);
			}
		}
	}
	if(comp > 1) artic.pb(x);
}

stack<pii> stk;
vi num, lowpt;
vector<seti> comps;

int timer = 0;

void dfs(int x, int p) {
	num[x] = timer++;
	lowpt[x] = num[x];

	for(auto e : graph[x]) {
		if(e != p) {
			if(num[e]) {
				lowpt[x] = min(lowpt[x], num[e]);
				if(num[e] < num[x])
					stk.push(mp(x, e));
			}
			else {
				stk.push(mp(x, e));
				dfs(e, x);
				lowpt[x] = min(lowpt[x], lowpt[e]);
			}
		}
	}
	if(p && lowpt[x] >= num[p]) {
		auto pa = stk.top();
		comps.pb({});

		do {
			pa = stk.top();
			stk.pop();
			comps.back().insert(pa.f);
			comps.back().insert(pa.s);
		}
		while(pa != mp(p, x) && stk.size());
	}
	if(!p) {
		if(graph[x].empty()) comps.pb({x});
	}
}

vvi graph, revg;
vi order;
vb vis;

void dfs(int x) {
	vis[x] = true;
	for(auto e : graph[x]) {
		if(!vis[e]) dfs(e);
	}
	order.pb(x);
}

vi comp;

void dfs2(int x) {
	vis[x] = true;
	comp.pb(x);
	for(auto e : revg[x]) {
		if(!vis[e]) dfs2(e);
	}
}

SegTree<int> tree;
vi sze, par, head, heavy, depth, pos, val;
vvi graph;
int timer = 0;

int dfs_size(int x, int p) {
	sze[x] = 1;
	depth[x] = depth[p]+1;
	par[x] = p;
	int ma = 0;
	for(auto e : graph[x]) {
		if(e != p) {
			sze[x] += dfs_size(e, x);
			if(sze[e] > ma) {
				ma = sze[e];
				heavy[x] = e;
			}
		}
	}
	return sze[x];
}

void decompose(int x, int h, int p) {
	head[x] = h;
	pos[x] = timer++;
	tree.set(pos[x], val[x]);

	if(heavy[x]) decompose(heavy[x], h, x);

	for(auto e : graph[x]) {
		if(heavy[x] != e && e != p) {
			decompose(e, e, x);
		}
	}
}

int query(int a, int b) {
	int ma = 0;
	while(head[a] != head[b]) {
		if(depth[head[b]] < depth[head[a]]) swap(a, b);
		ma = max(ma, tree.query(pos[head[b]], pos[b]));
		b = par[head[b]];
	}
	if(depth[a] > depth[b]) swap(a, b);
	ma = max(ma, tree.query(pos[a], pos[b]));
	return ma;
}

void init(int n) {
	sze = pos = head = heavy = depth = par = vi(n+1);
	tree.init(n);
	dfs_size(1, 0);
	decompose(1, 1, 0);
	tree.build();
}

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

void decompose(int x, int p) {
	int sz = get_sze(x, 0);
	x = get_centroid(x, 0, sz);
	vis[x] = true;
	par[x] = p;

	for(auto e : graph[x]) {
		if(!vis[e]) decompose(e, x);
	}
}

struct line {
	lli m, c;

	lli eval(lli x) {
		return m * x + c;
	}

	ld intersect(line &y) {
		return ld(c - y.c) / ld(y.m - m);
	}
};

struct Data {
	line ln;
	int lc=-1, rc=-1;
};

vector<Data> tree;

void add(int x, int l, int r, line data) {
	if(l > r) return;
	int mid = (l+r)/2;
	bool lb = data.ln.eval(l) < tree[x].ln.eval(l);
	bool mb = data.ln.eval(mid) < tree[x].ln.eval(mid);

	if(mb) {
		swap(data.ln, tree[x].ln);
	}
	if(lb != mb) {
		if(tree[x].lc == -1) {
			tree[x].lc = tree.size();
			tree.pb(data);
		}
		else {
			add(tree[x].lc, l, mid-1, data);
		}
	}
	else {
		if(tree[x].rc == -1) {
			tree[x].rc = tree.size();
			tree.pb(data);
		}
		else {
			add(tree[x].rc, mid+1, r, data);
		}
	}
} 

lli query(int x, int l, int r, lli v) {

	int mid = (l+r)/2;

	if(v == mid) return tree[x].eval(v);
	else if(v < mid) {
		if(tree[x].lc != -1) 
			return min(tree[x].ln.eval(v), query(tree[x].lc, l, mid-1, v));
		else return tree[x].ln.eval(v);
	}
	else {
		if(tree[x].rc != -1) {
			return min(tree[x].ln.eval(v), query(tree[x].rc, mid+1, r, v));
		}
		else return tree[x].ln.eval(v);
	}
}

const int MAXN = 1e6+1;

int cnt[MAXN];
int trie[MAXN][26];
int id = 0;

void add(string str) {
	int x = 0;
	frange(i, str.size()) {
		int v = str[i] - 'a';
		if(trie[x][v] != -1) {
			x = trie[x][v];
		}
		else {
			trie[x][v] = ++id;
			x = id;
		}
	}
	cnt[x]++;
}
