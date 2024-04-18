#pragma GCC optimize("O3","unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define all(vec) vec.begin(), vec.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second

typedef long long lli;
typedef vector<int> vi;
typedef vector<lli> vll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef set<int> seti;
typedef vector<vi> vvi;
typedef map<int, int> mpii;

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

struct Data {
	int pos = 0;
	int neg = 0;
};



template<class T>
struct SegTree {
	int n, sze;
	vector<T> tree;

	void init(int l) {
		n = l;
		sze = 1;
		while(sze < n) sze *= 2;
		Data tmp;
		tree = vector<T>(2*sze, tmp);
	}

	T operation(T x, T y)
    {
        T out;
        out.pos = y.pos;
        out.neg = x.neg;
        int v = x.pos + y.neg;
        if(v > 0) out.pos += v;
        else out.neg += v;
        return out;
    }

    void recalculate(int x)
    {
        tree[x] = operation(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void update(int x, int l, int r, int id, T val) {
    	if(l == r) {
    		tree[x] = val;
    		return;
    	}
    	int mid = (l+r)/2;
    	if(id <= mid) update(2*x+1, l, mid, id, val);
    	else update(2*x+2, mid+1, r, id, val);
    	recalculate(x);
    }

    void update(int id, T val) {
    	update(0, 0, sze-1, id, val);
    }

    T query(int x, int l, int r, int lx, int rx) {
    	if(lx > r || rx < l) {
    		Data tmp;
    		return tmp;
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
    	// return query(0, 0, sze-1, lx, rx);
    	return tree[0];
    }
};

int main() {
	// usaco();
	int n;
	scd(n);
	vi v1(n);
	SegTree<Data> segtree;
	
	seti st;
	frange(i, n) {
		scd(v1[i]);
		st.insert(v1[i]);
	}
	vi v2(n);
	frange(i, n) {
		scd(v2[i]);
		st.insert(v2[i]);
	}


	int q;
	scd(q);

	vii quer(q);

	frange(i, q) {
		scd(quer[i].f);
		scd(quer[i].s);
		quer[i].f--;
		st.insert(quer[i].s);
	}

	map<int, int> mv;
	int id = 0;

	for(auto e : st) mv[e] = id++;

	segtree.init(st.size()+1);
	Data tmp;
	vector<Data> val(st.size()+1, tmp);

	frange(i, n) {
		v1[i] = mv[v1[i]];
		v2[i] = mv[v2[i]];
		Data out = val[v1[i]];
		if(out.neg) out.neg++;
		else out.pos++;
		val[v1[i]] = out;
		segtree.update(v1[i], out);
		out = val[v2[i]];
		if(out.pos) out.pos--;
		else out.neg--;
		val[v2[i]] = out; 
		segtree.update(v2[i], out);
	}


	// printf("%d\n", n-segtree.query(0, st.size()).pos);

	frange(i, q) {
		int x, v;

		x = quer[i].f;
		v = mv[quer[i].s];
		
		Data out = val[v1[x]];
		if(out.pos == 0) out.neg--;
		else
		out.pos--;
		val[v1[x]] = out;
		segtree.update(v1[x], out);
		v1[x] = v;
		out = val[v1[x]];
		if(out.neg) out.neg++;
		else
			out.pos++;
		val[v1[x]] = out;
		segtree.update(v1[x], out);
		out = segtree.query(0, st.size());
		printf("%d\n", n-out.pos);
	}
}