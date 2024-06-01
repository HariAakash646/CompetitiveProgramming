#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
	int,
	null_type,
	less<int>,
	rb_tree_tag,
	tree_order_statistics_node_update> ordered_set;
	

template <class T>
struct LazySegtree {
	int n, size=1;
	vector<T> vec, tree, lazy;

	void init(int l) {
		n = l;
		while(size < n) size*=2;

		vec = vector<T>(size);
		tree = lazy = vector<T>(size);
	}

	void set(int id, T v) {
		vec[id] = v;
	}

	T operation(T x, T y) {
		return x + y;
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

	void propagate(int x, int l, int r) {
		tree[x] += lazy[x];
		if(l != r) {

		}
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
		update(2*x+1, l, mid, lx, rx, v);
		update(2*x+2, mid+1, r, lx, rx, v);
		propagate(2*x+1, l, mid);
		propagate(2*x+2, mid+1, r);
	}
};

template <class T>
struct BIT {
	int size;
	vector<T> vec, bit;

	BIT(int n) : size(n), vec(n+1), bit(n+1) {}

	void add(int id, T v) {
		vec[id] += v;
		while(id <= size) {
			bit[id] += v;
			id += lsb(id);
		}
	}

	T query(int id) {
		T tot = 0;
		while(id >= 1) {
			tot += bit[id];
			id -= lsb(id);
		} 
		return tot;
	}
}

vvi minv;
vi vec;

void init(int n) {
	frange(i, n) minv[0][i] = vec[i];

	forr(i, 1, 20) {
		frange(j, n) {
			minv[i][j] = min(minv[i-1][j], minvi-1][min(n-1, j+(1<<(i-1)))]);
		}
	}
}

int query(int l, int r) {
	int len = r - l + 1;
	int msb = 31 - __builtin_clz(len);

	return min(minv[msb][l], minv[msb][r-(1<<msb) + 1]);
}

vvi graph;
vi num, lowpt;
int timer = 0;

void dfs(int x, int p) {
	num[x] = ++timer;
	lowpt[x] = num[x];

	for(auto e : graph[x]) {
		if(e != p) {
			if(num[e]) {
				lowpt[x] = min(lowpt[x], num[e]);
			}
			else {
				dfs(e, x);
				lowpt[x] = min(lowpt[x], lowpt[e]);
			}
		}
	}

	if(lowpt[x] >= num[x]) {
		bridg.pb(mp(p, x));
	}
}

void dfs(int x, int p) {
	num[x] = ++timer;
	lowpt[x] = num[x];

	int comps = (p!=0);

	for(auto e : graph[x]) {
		if(e != p) {
			if(num[e]) {
				lowpt[x] = min(lowpt[x], num[e]);
			}
			else {
				dfs(e, x);
				lowpt[x] = min(lowpt[x], lowpt[e]);
				if(lowpt[e] >= num[x])
					comps++;
			}
		}
	}

	if(comps > 1) {
		artic.pb(x);
	}
}

stack<pii> stk;

void dfs(int x, int p) {
	num[x] = ++timer;
	lowpt[x] = num[x];

	for(auto e : graph[x]) {
		if(e != p) {
			if(num[e]) {
				if(num[e] < num[x]) stk.push(mp(e, x));
				lowpt[x] = min(lowpt[x], num[e]);
			}
			else {
				stk.push(mp(e, x));
				dfs(e, x);
				lowpt[x] = min(lowpt[x], lowpt[e]);
			}
		}
	}

	if(p && lowpt[x] >= num[p]) {
		bridg.pb(mp(p, x));
	}
}

void dfs_size(int x, int p) {
	sze;
	heavy;
	depth;
	par;
}


void decompose(int x, int h, int p) {
	head;
	pos;
	seg.set();


}

vi sze;
vb vis;

int dfs_sze(int x, int p) {
	sze[x] = 1;
	for(auto e : graph[x]) {
		if(e != p && !vis[e]) {
			sze[x] += dfs_sze(e, x);
		}
	}
}

int get_cent(int x, int sz, int p) {
	for(auto e : graph[x]) {
		if( e != p && !vis[e] && 2*sze[e] > sze[x]) {
			return get_cent(e, sz, x);
		}
	}
	return x;
}

void decompose(int x) {
	int sz = get_sze(x, 0);
	x = get_centroid(x, sz, 0);
	vis[x] = true;

	for(auto e : graph[x]) {
		if(!vis[e]) decompose(e);
	}
}

struct line {
	lli m, c;

	lli eval(lli x) {
		return m * x + c;
	}

	ld intersect(line y) {
		return ld(c - y.c) / ld(y.m - m);
	}
};

struct Data {
	line ln;
	int rc=-1, lc = -1;
};

void add(int x, int l, int r, Data data) {
	if(l > r) return;
	int mid = (l+r)/2;
	bool mb = data.ln.eval(mid) < tree[x].ln.eval(mid);

	if(mb) {
		swap(data.ln, tree[x].ln);
	} 

	bool lb = data.ln.eval(mid) < tree[x].ln.eval(mid);
	if(lb) {
		if(tree[x].lc != -1) {
			add(tree[x].lc, l, mid-1, data);
		}
		else {
			tree[x].lc = tree.size();
			tree.pb(data);
		}
	}
}

void query(int x, int l, int r, int val) {
	int mid = (l+r)/2;
	if(val == mid) return
	else if(val < mid)
}

int main(int argc, char *argv[]) {
	srand(atoi(argv[1]));

}