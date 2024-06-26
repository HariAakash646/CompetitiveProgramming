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

struct Segtree {
	int n, size;
	vi vec, tree;

	void init(int l) {
		n = l;
		size = 1;
		while(size < n) size *= 2;
		vec = vi(size, 1e9);
		tree = vi(2*size, 1e9);
	}

	void set(int id, int x) {
		vec[id] = x;
	}

	int operation(int x, int y) {
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
		if(rx < l || lx > r) return 1e9;
		if(lx <= l && r <= rx) return tree[x];
		int mid = (l+r)/2;
		int v1 = query(2*x+1, l, mid, lx, rx);
		int v2 = query(2*x+2, mid+1, r, lx, rx);
		return operation(v1, v2);
	}

	int query(int lx, int rx) {
		if(lx > rx) return 1e9;
		return query(0, 0, size-1, lx, rx);
	}
};

int main() {
	// usaco();
	int n, m;
	scd(n);
	scd(m);

	vii vec(n);
	vi val(n);
	frange(i, n) {
		scd(vec[i].f);
		val[i] = vec[i].f;
		vec[i].s = i;
	}
	Segtree segtree;
	segtree.init(n);
	sort(all(vec));
	vi pos(n);
	frange(i, n) {
		segtree.set(i, vec[i].s);
		pos[vec[i].s] = i;
	}
	segtree.build();

	frange(i, m) {
		int t;
		scd(t);
		if(t == 0) {
			int x, y;
			scd(x);
			scd(y);
			int l = lower_bound(all(vec), mp(x, 0))-vec.begin();
			int r = lower_bound(all(vec), mp(y+1, 0))-vec.begin();
			r--;
			int v = segtree.query(l, r);
			if(v < 1e9) printf("%d\n", v);
			else printf("-1\n");
			
		}
		else {
			int x, y;
			scd(x);
			scd(y);
			segtree.update(pos[x], y);
			segtree.update(pos[y], x);
			swap(vec[x].s, vec[y].s);
			swap(val[x], val[y]);
			swap(pos[x], pos[y]);
		}
	}
	// printf("5");
}