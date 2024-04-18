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
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}


template <class T>
struct SegTree {
	int n, size=1;
	vector<T> tree, vec;

	void init(int l) {
		n = l;
		while(size < n) size *= 2;
		tree = vector<T>(2*size, 0);
		vec = vector<T>(size, 0);
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
			return 0;
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

// Checked with CSES 2134

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

int main() {
    // usaco();
    int n, q;
    scd(n);
    scd(q);
    val = vi(n+1);
 
    forr(i, 1, n+1) scd(val[i]);
    graph = vvi(n+1);
 
    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
 
    init(n);
 
    frange(_, q) {
        int t;
        scd(t);
        int a, b;
        scd(a);
        scd(b);
        if(t == 1) {
            tree.update(pos[a], b);
        }
        else {
            printf("%d ", query(a, b));
        }
    }
}