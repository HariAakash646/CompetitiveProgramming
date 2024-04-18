#include <bits/stdc++.h>
#include "artswap.h"

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
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

template <class T>
struct LazySegTree
{
    int size = 1, n;
    vector<pair<T, lli>> segtree;
    vector<lli> vec;

    T def1; // Assign a value

    void init(int l, T d1)
    {
        n = l;
        def1 = d1;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, mp(def1, 0));
        vec.assign(size, 1e9);
    }

    T operation(T x, T y)
    {
        return min(x, y); // Any required operation
    }

    void recalculate(int x)
    {
        segtree[x].f = operation(segtree[2 * x + 1].f, segtree[2 * x + 2].f);
    }

    void build(int x, int l, int r)
    {
        if (l == r)
        {
            segtree[x].f = mp(vec[l], l);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * x + 1, l, mid);
        build(2 * x + 2, mid + 1, r);
        recalculate(x);
    }

    void build()
    {
        build(0, 0, size - 1);
    }

    void set(int id, lli val)
    {
        vec[id] = val;
    }

    void propagate(int x, int l, int r)
    {
        segtree[x].f.f += segtree[x].s;
        if (l < r)
        {
            segtree[2 * x + 1].s += segtree[x].s;
            segtree[2 * x + 2].s += segtree[x].s;
        }
        segtree[x].s = 0;
    }

    void update(int x, int l, int r, int lx, int rx, lli val)
    {
        propagate(x, l, r);
        if (lx <= l && r <= rx)
        {
            segtree[x].s += val;
            return;
        }
        int mid = (l + r) / 2;
        if (lx <= mid)
        {
            update(2 * x + 1, l, mid, lx, rx, val);
        }
        if (rx >= mid + 1)
        {
            update(2 * x + 2, mid + 1, r, lx, rx, val);
        }
        propagate(2 * x + 1, l, mid);
        propagate(2 * x + 2, mid + 1, r);
        recalculate(x);
    }

    void update(int lx, int rx, lli val)
    {
        update(0, 0, size - 1, lx, rx, val);
    }

    T query(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            return def1;
        }
        propagate(x, l, r);
        if (lx <= l && r <= rx)
        {
            return segtree[x].f;
        }
        int mid = (l + r) / 2;
        T v1 = query(2 * x + 1, l, mid, lx, rx);
        T v2 = query(2 * x + 2, mid + 1, r, lx, rx);
        return operation(v1, v2);
    }

    T query(int lx, int rx)
    {
        return query(0, 0, size - 1, lx, rx);
    }
};

template <class T>
struct BIT
{
    int size;
    vector<T> bit;
    vector<T> vec;

    BIT(int n) : size(n), bit(n + 1), vec(n + 1) {}

    int lsb(int x)
    {
        return x & (-x);
    }

    void set(int id, T v)
    {
        add(id, v - vec[id]);
    }

    void add(int id, T v)
    {
        if (id == 0)
            return;
        vec[id] += v;
        while (id <= size)
        {
            bit[id] += v;
            id += lsb(id);
        }
    }

    T query(int id)
    {
        T tot = 0;
        if (id == 0)
            return tot;
        while (id >= 1)
        {
            tot += bit[id];
            id -= lsb(id);
        }
        return tot;
    }
};

void artswap(int n, long long d, int S, int Q) {

	// vi lv(n+1), rv(n+1);
	LazySegTree<pair<lli, int>> lv, rv;
	lv.init(n+1, mp(1e9, 1e9));
	rv.init(n+1, mp(1e9, 1e9));

	forr(i, 2, n) {
		lli v = swap_pieces(i, 1);
		swap_pieces(i, 1);
		if(v <= d) {
			int curr = 1;
			int x = (d-v-1)/2;
			lv.set(i, x);
			// printf("%d %d %d\n", i, curr, (d-v-1)/2);
		}
		else {
			int x = (v-d-1)/2;
			rv.set(i, x);
			// printf("%d %d %d\n", curr, i, (v-d-1)/2);
		}
	}

	lv.build();
	rv.build();

	int curr = 1;
	vi out;
	out.pb(1);
	priority_queue<int> pq;
	while(true) {
		auto p = lv.query(1, n);
		while(p.f == 0) {
			pq.push(p.s);
			lv.update(p.s, p.s, 1e9);
			p = lv.query(1, n);
		}
		if(pq.size() == 0) break;
		auto p1 = pq.top();
		pq.pop();

		out.pb(p1);
		lv.update(p1+1, n, -1);
	}
	reverse(all(out));

	while(true) {
		auto p = rv.query(1, n);
		while(p.f == 0) {
			pq.push(p.s);
			rv.update(p.s, p.s, 1e9);
			p = rv.query(1, n);
		}
		if(pq.size() == 0) break;
		auto p1 = pq.top();
		pq.pop();

		out.pb(p1);
		rv.update(p1+1, n, -1);
	}

	BIT<lli> bit(n+1);

	lli tot = 0;

	forr(i, 0, n-1) {
		tot += bit.query(n) - bit.query(out[i]);
		bit.add(out[i], 1);
	}

	lli x = d - tot;
	out.insert(out.begin() + n-x-1, n);

	forr(i, 1, n+1) answer(i, out[i-1]);
}