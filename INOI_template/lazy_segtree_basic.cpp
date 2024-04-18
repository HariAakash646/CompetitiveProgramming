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

// Checked CSES 1651

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

 
int main()
{
	// usaco();
    int n, q;
    scd(n);
    scd(q);
	LazySegTree<lli> segtree;
	segtree.init(n);
    frange(i, n)
    {
        lli v;
        sclld(v);
        segtree.set(i, v);
    }
    segtree.build();
 
    frange(i, q)
    {
        int t;
        scd(t);
        if (t == 1)
        {
            int l, r;
            lli v;
            scd(l);
            scd(r);
            sclld(v);
            l--;
            r--;
            segtree.update(l, r, v);
        }
        else
        {
            int k;
            scd(k);
            k--;
            printf("%lld\n", segtree.query(k, k));
        }
    }
}