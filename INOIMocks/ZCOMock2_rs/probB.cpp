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

struct SegTree {

	vll vec, tree;
	int n, size = 1;
	void init(int l) {
		n = l;
		while(size < n) size *= 2;

		vec = vll(size);
		tree = vll(2*size);
	}

	void set(int id, lli x) {
		vec[id] = x;
	}

	lli operation(lli x, lli y) {
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

	lli query(int x, int l, int r, int lx, int rx) {
		if(rx < l || lx > r) {
			return 0;
		}
		if(lx <= l && r <= rx) {
			return tree[x];
		}

		int mid = (l+r)/2;

		lli v1 = query(2*x+1, l, mid, lx, rx);
		lli v2 = query(2*x+2, mid+1, r, lx, rx);
		return operation(v1, v2);
	}

	lli query(int lx, int rx) {
		return query(0, 0, size-1, lx, rx);
	}

	void update(int x, int l, int r, int id, lli v) {
		if(l == r) {
			tree[x] = v;
			return;
		}
		int mid = (l+r)/2;
		if(id <= mid) update(2*x+1, l, mid, id, v);
		else update(2*x+2, mid+1, r, id, v);
		recalculate(x);
	}

	void update(int id, lli v) {
		update(0, 0, size-1, id, v);
	}
};

int main() {
	// usaco();
	int n, q;
	scd(n);
	scd(q);

	seti st;
	vll vec(n);

	SegTree segtree;

	segtree.init(n);

	frange(i, n) {
		sclld(vec[i]);
		if(vec[i]) st.insert(i);
		segtree.set(i, vec[i]);
	}

	segtree.build();

	frange(_, q) {
		int t;
		scd(t);
		if(t == 0) {
			int l, r;
			lli k;
			scd(l);
			scd(r);
			sclld(k);
			// l--;
			// r--;
			if(k == 1) continue;
			auto it = st.lower_bound(l);
			while(it != st.end() && *it <= r) {
				lli v = vec[*it];
				vec[*it] =  v / k;
				segtree.update(*it, vec[*it]);
				if(vec[*it] == 0) {
					int id = *it;
					st.erase(it);
					it = st.lower_bound(id);
				}
				else it++;
				
			}
		}
		else if(t == 1) {
			int id;
			lli v;
			scd(id);
			sclld(v);
			// id--;
			segtree.update(id, v);
			vec[id] = v;
			st.insert(id);
		}
		else {
			int l, r;
			scd(l);
			scd(r);
			// l--;
			// r--;
			printf("%lld\n", segtree.query(l, r));
		}
		// frange(i, n) printf("%lld ", vec[i]);
		// printf("\n");
	}
}