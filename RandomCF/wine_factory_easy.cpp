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
typedef multiset<int> mseti;

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

struct Segtree {
	int n, size=1;
	vector<pair<lli, lli>> segtree, vec;

	void init(int l) {
		n = l;
		while(size < l) size *= 2;
		segtree = vector<pair<lli, lli>>(2*size);
		vec = vector<pair<lli, lli>>(size);
	}

	void set(int id, lli v) {
		if(v < 0) vec[id].f = -v;
		else vec[id].s = v;
	}

	pair<lli, lli> operation(pair<lli, lli> x, pair<lli, lli> y) {
		auto out = x;
		if(y.f > out.s) {
			out.f += y.f - out.s;
			out.s = 0;
		} 
		else {
			out.s -= y.f;
		}
		out.s += y.s;
		return out;
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

	void update(int x, int l, int r, int id, pair<lli, lli> v) {
		if(l == r) {
			segtree[x] = v;
			return;
		}
		int mid = (l+r)/2;
		if(id <= mid) 
			update(2*x+1, l, mid, id, v);
		else update(2*x+2, mid+1, r, id, v);
		recalculate(x);
	}

	void update(int id, pair<lli, lli> v) {
		update(0, 0, size-1, id, v);
	}

	pair<lli, lli> query(int x, int l, int r, int lx, int rx) {
		if(lx > r || rx < l) {
			return mp(0, 0);
		}
		if(lx <= l && r <= rx) {
			return segtree[x];
		}
		int mid = (l+r)/2;
		auto v1 = query(2*x+1, l, mid, lx, rx);
		auto v2 = query(2*x+2, mid+1, r, lx, rx);
		return operation(v1, v2);
	}

	pair<lli, lli> query(int lx, int rx) {
		return query(0, 0, size-1, lx, rx);
	}
};

int main() {
	// usaco();
	int n, q;
	scd(n);
	scd(q);
	vector<pair<lli, lli>> vec(n);
	Segtree segtree;
	segtree.init(n);
	lli tot = 0;
	frange(i, n) {
		sclld(vec[i].f);
		tot += vec[i].f;
	}

	frange(i, n) sclld(vec[i].s);

	frange(i, n-1) {
		lli v;
		sclld(v);
	}

	frange(i, n) {
		segtree.set(i, vec[i].f - vec[i].s);
	}
	segtree.build();

	frange(_, q) {
		int id;
		lli x, y, v;
		scd(id);
		sclld(x);
		sclld(y);
		sclld(v);

		id--;
		tot += x - vec[id].f;
		vec[id] = mp(x, y);
		auto val = mp(x, y);
		val.f = max(0LL, y-x);
		val.s = max(0LL, x-y);
		segtree.update(id, val);
		printf("%lld\n", tot - segtree.query(0, n-1).s);
	}	
}