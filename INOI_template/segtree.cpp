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

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

// Checked with CSES 1649

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

int main()
{
	// usaco();
    int n, m;
    scd(n);
    scd(m);
    SegTree<int> segtree;
    segtree.init(n);
    frange(i, n)
    {	int a;
        scd(a);
        segtree.set(i, a);
    }
    segtree.build();
    int q, b, c;
    frange(i, m)
    {
        scd(q);
        scd(b);
        scd(c);
        if (q == 1)
        {
        	
            segtree.update(b-1, c);
        }
        else
        {
            int out = segtree.query(b - 1, c - 1);
            printf("%d\n", out);
        }
    }
}