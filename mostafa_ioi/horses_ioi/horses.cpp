#include "horses.h"
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


template <class T>
struct SegTree
{
    int size = 1, n;
    vector<T> segtree;
    vector<T> vec;

    T def; // Assign a value

    void init(int l, T defv)
    {
        n = l;
        def = defv;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, def);
        vec.assign(size, def);
    }

    T operation(T x, T y)
    {
        return max(x, y); // Any required operation
    }

    void recalculate(int x)
    {
        segtree[x] = operation(segtree[2 * x + 1], segtree[2 * x + 2]);
    }

    void build(int x, int l, int r)
    {
        if (l == r)
        {
            segtree[x] = vec[l];
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

    void set(int id, T val)
    {
        vec[id] = val;
    }

    void update(int x, int l, int r, int id, T val)
    {
        if (l == r)
        {
            segtree[x] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (id <= mid)
        {
            update(2 * x + 1, l, mid, id, val);
        }
        else
        {
            update(2 * x + 2, mid + 1, r, id, val);
        }
        recalculate(x);
    }

    void update(int id, T val)
    {
        update(0, 0, size - 1, id, val);
    }

    T query(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            return def;
        }
        if (lx <= l && r <= rx)
        {
            return segtree[x];
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

const lli mod = 1e9 + 7;

template <class T>
struct SegTreeMul
{
    int size = 1, n;
    vector<T> segtree;
    vector<T> vec;

    T def; // Assign a value

    void init(int l, T defv)
    {
        n = l;
        def = defv;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, def);
        vec.assign(size, def);
    }

    T operation(T x, T y)
    {
        return (x*y)%mod; // Any required operation
    }

    void recalculate(int x)
    {
        segtree[x] = operation(segtree[2 * x + 1], segtree[2 * x + 2]);
    }

    void build(int x, int l, int r)
    {
        if (l == r)
        {
            segtree[x] = vec[l];
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

    void set(int id, T val)
    {
        vec[id] = val;
    }

    void update(int x, int l, int r, int id, T val)
    {
        if (l == r)
        {
            segtree[x] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (id <= mid)
        {
            update(2 * x + 1, l, mid, id, val);
        }
        else
        {
            update(2 * x + 2, mid + 1, r, id, val);
        }
        recalculate(x);
    }

    void update(int id, T val)
    {
        update(0, 0, size - 1, id, val);
    }

    T query(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            return def;
        }
        if (lx <= l && r <= rx)
        {
            return segtree[x];
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

SegTree<lli> segtree;
SegTreeMul<lli> segmul;
seti act;
vll v1, v2;
int n;

int init(int N, int X[], int Y[]) {
	n = N;
	segtree.init(n, 0LL);
	segmul.init(n, 1);
	v1 = v2 = vll(n);

	frange(i, n) {
		if(X[i] != 1) act.insert(i);
		v1[i] = X[i];
		v2[i] = Y[i];
		segtree.set(i, v2[i]);
		segmul.set(i, v1[i]);
	}
	act.insert(0);
	segtree.build();
	segmul.build();

	auto it = act.end();
	frange(i, 30) {
		it--;
		if(it == act.begin()) break;
	}
	int ma = *it;
	lli v = segtree.query(ma, n-1);
	it++;
	lli curr = 1;
	while(it != act.end()) {
		int id = *it;
		curr *= v1[id];
		lli val = segtree.query(id, n-1);
		if(curr >= v || curr * val >= v) {
			ma = id;
			v = val;
			curr = 1;
		}
		it++;
	}

	lli out = segmul.query(0, ma) * segtree.query(ma, n-1) % mod;

	return out;
}

int updateX(int pos, int val) {	
	segmul.update(pos, val);
	if(v1[pos] != 1 && val == 1) act.erase(pos);
	if(val != 1) act.insert(pos);
	act.insert(0);
	v1[pos] = val;

	auto it = act.end();
	frange(i, 30) {
		it--;
		if(it == act.begin()) break;
	}
	int ma = *it;
	lli v = segtree.query(ma, n-1);
	it++;
	lli curr = 1;
	while(it != act.end()) {
		int id = *it;
		curr *= v1[id];
		lli val = segtree.query(id, n-1);
		if(curr >= v || curr * val >= v) {
			ma = id;
			v = val;
			curr = 1;
		}
		it++;
	}

	lli out = segmul.query(0, ma) * segtree.query(ma, n-1) % mod;

	return out;
}

int updateY(int pos, int val) {
	segtree.update(pos, val);
	v2[pos] = val;

	auto it = act.end();
	frange(i, 30) {
		it--;
		if(it == act.begin()) break;
	}
	int ma = *it;
	lli v = segtree.query(ma, n-1);
	it++;
	lli curr = 1;
	while(it != act.end()) {
		int id = *it;
		curr *= v1[id];
		lli val = segtree.query(id, n-1);
		if(curr >= v || curr * val >= v) {
			ma = id;
			v = val;
			curr = 1;
		}
		it++;
	}

	lli out = segmul.query(0, ma) * segtree.query(ma, n-1) % mod;

	return out;
}
