#include <bits/stdc++.h>

using namespace std;

#define scd(x) scanf("%d", &x)
#define sclld(x) scanf("%lld", &x)
#define frange(i, n) for(int i=0; i<n; i++)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define all(vec) vec.begin(), vec.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define int long long

// typedef long long lli;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
// typedef vector<lli> vll;
typedef vector<vi> vvi;

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

struct SegTree {
	int n, sze;
	vector<int> vec, tree;
	vi lazy;

	void init(int l) {
		n = l;
		sze = 1;
		while(sze < n) sze *= 2;

		vec = vi(sze);
		tree = vi(2*sze);
		lazy = vi(2*sze);
	}

	void set(int id, int v) {
		vec[id] = v;
	}

	int operation(int x, int y) {
		return x + y;
	}

	void recalculate(int x) {
		tree[x] = tree[2*x+1] + tree[2*x+2];
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
		build(0, 0, sze-1);
	}

	// void propogate(int x, int l, int r) {
	// 	tree[x] += lazy[x] * (r - l + 1);
	// 	if(l != r) {
	// 		lazy[2*x+1] = lazy[x];
	// 		lazy[2*x+2] = lazy[x];
	// 	}
	// 	lazy[x] = 0;
	// }

	void update(int x, int l, int r, int id, int v) {
		if(l == r) {
			tree[x] = v;
			return;
		}
		int mid = (l+r)/2;
		if(id <= mid) {
			update(2*x+1, l, mid, id, v);
		}
		else {
			update(2*x+2, mid+1, r, id, v);
		}
		recalculate(x);
	}

	int query(int x, int l, int r, int lx, int rx) {
		if(lx <= l && r <= rx) {
			return tree[x];
		}
		if(lx > r || rx < l) {
			return 0;
		}
		int mid = (l + r)/2;
		return query(2*x+1, l, mid, lx, rx) + query(2*x+2, mid+1, r, lx, rx);
	}

	void update(int id, int v) {
		update(0, 0, sze-1, id, v);
	}

	int query(int l, int r) {
		return query(0, 0, sze-1, l, r);
	}
};

__int32_t main() {
	// usaco();
	int n, m;
    sclld(n);
    sclld(m);
    
    SegTree segtree;

    segtree.init(n);

    frange(i, n)
    {
    	int a;
        sclld(a);
        segtree.set(i, a);
    }
    segtree.build();
    int q, b, c;
    frange(i, m)
    {
        sclld(q);
        sclld(b);
        sclld(c);
        if (q == 1)
        {
            b--;
            segtree.update(b, c);
        }
        else
        {
            b--;
            c--;
            printf("%lld\n", segtree.query(b, c));
        }
    }
}

struct BIT {
	int size;
	vi vec;
	vi bit;

	BIT(int n) : size(n), vec(n+1), bit(n+1);

	int lsb(int x) {
		return x & (-x);
	}

	void set(int id, int x) {
		add(id, x-vec[id]);
	}

	void add(int id, int x) {
		vec[id] += x;
		for(int i=id; i<=size; i+=lsb(i)) {
			bit[id] += x;
		}
	}

	void query(int id) {
		if(id == 0) return 0;
		int tot = 0;
		for(int id=size; id>=1; id-=lsb(id)) {
			tot += bit[id];
		}
		return tot;
	}
}

template <class T> 
struct LazySegTree {
	int size=1;
	int n;
	vector<T> vec, segtree, lazy;

	T def;

	void init(int l) {
		size = 1;
		n = l;
		def = 0;
		while(size<n) size*=2;
		segtree = vector<T>(2*size, def);
		vec = vector<T>(size, def);
		lazy = vector<T>(size, -1);
	}

	void set(int id, T v) {
		vec[id] = v;
	}

	void operation(T x, T y) {
		return x + y;
	}

	void recalculate(int x) {
		segtree[x] = operation(segtree[2*x+1], segtree[2*x+2]);
	}
	
	void propagate(int x, int l, int r) {
		if(lazy[x] == -1) return;
		segtree[x] = (r-l+1) * lazy[x];
		if(l != r) {
			lazy[2*x+1] = lazy[x];
			lazy[2*x+2] = lazy[x];
		}
		lazy[x] = -1;
	}

	void build(int x, int l, int r) {
		if(l == r) {
			segtree[x] = vec[x];
			return;
		}
		int mid =(l+r)/2;
		build(2*x+1, l, mid);
		build(2*x+2, mid+1, r);
		recalculate(x);
	}

	void update(int x, int l, int r, int lx, int rx, T v) {
		if(lx > r || rx < l) {
			return;
		}
		propagate(x, l, r);
		if(lx <= l && r <= rx) {
			lazy[x] = v;
			return;
		}
		int mid = (l+r)/2;
		if(lx <= mid) {
			update(2*x+1, l, mid, lx, rx, v);
		}
		if(rx > mid) {
			update(2*x+2, mid+1, r, lx, rx, v);
		}
		propagate(2*x+1, l, mid);
		propagate(2*x+2, mid+1, r);
	}

	T query(int x, int l, int r, int lx, int rx) {
		if(lx > r || rx < l) {
			return def;
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

}