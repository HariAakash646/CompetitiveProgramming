#include <bits/stdc++.h>
 
using namespace std;
 
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

template <class T>
struct SegTree {
	int n;
	int size = 1;
	vector<T> vec, segtree, lazy;

	void init(int l) {
		n = l;
		while(size < n) size *= 2;
		vec = vector<T>(size);
		segtree = vector<T>(2*size);
		lazy = vector<T>(2*size, -1e9);
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
	void propagate(int x, int l, int r) {
		segtree[x] = max(lazy[x], segtree[x]);
		if(l != r) {
			lazy[2*x+1] = max(lazy[2*x+1], lazy[x]);
			lazy[2*x+2] = max(lazy[2*x+1], lazy[x]);
		}
		lazy[x] = -1e9;
	} 

	void update(int x, int l, int r, int lx, int rx, T v) {
		if(l > rx || r < lx) {
			return;
		}
		propagate(x, l, r);
		if(lx <= l && r <= rx) {
			lazy[x] = v;
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
			return 2e9;
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

vvi graph;
vi sze;
vi val;
vi heavy, head, pos, depth, par;

SegTree<int> segtree;

int dfs_sze(int x, int p) {
    sze[x] = 1;
    depth[x] = depth[p] + 1;
    par[x] = p;
    int ma = 0;

    for(auto e : graph[x]) {
        if(e != p) {
            int sz = dfs_sze(e, x);
            sze[x] += sz;
            if(sz > ma) {
                ma = sz;
                heavy[x] = e;
            }
        }
    }

    return sze[x];
}

int id = 0;

void decompose(int x, int h, int p) {
    head[x] = h;
    pos[x] = id++;
    segtree.set(pos[x], val[x]);
    if(heavy[x])
        decompose(heavy[x], h, x);

    for(auto e : graph[x]) {
        if(e != p && e != heavy[x]) {
            decompose(e, e, x);
        } 
    }

}

void init(int n) {
    segtree.init(n);
    par = depth = head = pos = heavy = sze = vi(n+1);
    dfs_sze(1, 0);
    decompose(1, 1, 0);
    segtree.build();
}

void update(int a, int b, int v) {
    while(head[a] != head[b]) {
        if(depth[head[a]] > depth[head[b]]) swap(a, b);
        segtree.update(pos[head[b]], pos[b], v);
        b = par[head[b]];
    }
    if(pos[a] > pos[b]) swap(a, b);
    segtree.update(pos[a]+1, pos[b], v);
}


int main() {
	// usaco();
	int n, m;
	scd(n);
	scd(m);
	val = vi(n+1, -1);
	graph = vvi(n+1);

	frange(i, n-1) {
		int a, b;
		scd(a);
		scd(b);
		graph[a].pb(b);
		graph[b].pb(a);
	}

	init(n);

	frange(i, m-(n-1)) {
		int a, b, v;
		scd(a);
		scd(b);
		scd(v);
		// printf("%d %d %d\n", a, b, v);
		update(a, b, v);
	}

	printf("%d\n", segtree.query(1, n-1));

	int q;
	scd(q);
	// printf("%d", q);

	frange(_, q) {
		int a, b, v;
		scd(a);
		scd(b);
		scd(v);
		update(a, b, v);
		printf("%d\n", segtree.query(1, n-1));
	}
}	