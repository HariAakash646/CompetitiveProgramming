#include "sequence.h"
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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less_equal<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

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
        T out;
        int i1 = 0;
        int i2 = 0;
        frange(i, int(x.size()+y.size())) {
        	if(i1 == (int)x.size()) {
        		out.pb(y[i2++]);
        	}
        	else if(i2 == (int)y.size()) {
        		out.pb(x[i1++]);
        	}
        	else if(x[i1] <= y[i2]) {
        		out.pb(x[i1++]);
        	}
        	else {
        		out.pb(y[i2++]);
        	}
        }
        return out;
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

    int query(int x, int l, int r, int lx, int rx, int v)
    {
        if (lx > r || rx < l)
        {
            return 0;
        }
        if (lx <= l && r <= rx)
        {
            return upper_bound(all(segtree[x]), v) - segtree[x].begin();
        }
        int mid = (l + r) / 2;
        int v1 = query(2 * x + 1, l, mid, lx, rx, v);
        int v2 = query(2 * x + 2, mid + 1, r, lx, rx, v);
        return v1+v2;
    }

    int query(int lx, int rx, int v)
    {
        return query(0, 0, size - 1, lx, rx, v);
    }
};



int sequence(int n, std::vector<int> vec) {
    vi cnt(n+1);
    vi ma(n+1, -1);
    vi mi(n+1, 1e9);
    frange(i, n) {
    	cnt[vec[i]]++;
    	ma[vec[i]] = max(ma[vec[i]], i);
    	mi[vec[i]] = min(mi[vec[i]], i);
    }
    int v = 0;
    frange(i, n) {
    	int c = 1;
    	int x = vec[i];
    	while(i < n-1 && vec[i+1] == x) {
    		c++;
    		i++;
    	}
    	int l = ma[x]-mi[x]+1;
    	int g = l - cnt[x];
    	int tot = cnt[x];
    	tot += mi[x] + n-1-ma[x];
    	if(g > tot) {
    		v = max({v, c, cnt[x]-c});
    	}
    	else {
    		v = max(v, cnt[x]);
    	}
    }
    return v;
}

