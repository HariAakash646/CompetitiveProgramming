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

const lli mod = 998244353;

//Checked with: https://judge.yosupo.jp/problem/range_affine_range_sum

template <class T>
struct LazySegTree {
	int n, size=1;
	vector<T> tree, vec;
	vector<pair<T, T>> lazy;

	void init(int l) {
		n = l;
		while(size<n) size*=2;
		tree = vector<T>(2*size);
		vec = vector<T>(size);
		lazy = vector<pair<T, T>>(2*size, mp(1, 0));
	}

	T operation(T x, T y) {
		return (x+ y)%mod;
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
		tree[x] = (tree[x] * lazy[x].f + (r-l+1)*lazy[x].s) % mod;

		if(l != r) {
			lazy[2*x+1] = mp(lazy[2*x+1].f * lazy[x].f % mod, (lazy[2*x+1].s*lazy[x].f + lazy[x].s)%mod);
			lazy[2*x+2] = mp(lazy[2*x+2].f * lazy[x].f % mod, (lazy[2*x+2].s*lazy[x].f + lazy[x].s)%mod);
		}

		lazy[x] = mp(1, 0);
	}

	void update(int x, int l, int r, int lx, int rx, pair<T, T> v) {
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

	void update(int lx, int rx, pair<T, T> v) {
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

int main() {
	// usaco();
	int n, q;
	scd(n);
	scd(q);

	LazySegTree<lli> tree;
	tree.init(n);

	frange(i, n) {
		lli a;
		sclld(a);
		tree.set(i, a);
	}

	tree.build();

	frange(_, q) {
		int t, l, r;
		scd(t);
		scd(l);
		scd(r);

		if(t) {
			printf("%lld\n", tree.query(l, r-1));
		}
		else {
			lli a, b;
			sclld(a);
			sclld(b);
			tree.update(l, r-1, mp(a, b));
		}
	}
}