#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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


void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

typedef tree<
int,
null_type,
less_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

struct SegTree
{
    int size = 1, n;
    vector<ordered_set> segtree;
    vector<int> vec;


    void init(int l)
    {
        n = l;

        while (size < n)
            size *= 2;

        segtree = vector<ordered_set>(2 * size);
        vec = vector<int>(size);
    }

    ordered_set operation(ordered_set &x, ordered_set &y)
    {
        
        // for(auto e : y) out.insert(e);
        // vi v2(x.size()+y.size());
        // merge(all(x), all(y), v2.begin());
        ordered_set out;
        set_union(all(x), all(y), inserter(out, out.begin()));
        return out; // Any required operation
    }

    void recalculate(int x)
    {
        segtree[x] = operation(segtree[2 * x + 1], segtree[2 * x + 2]);
    }

    void build(int x, int l, int r)
    {
        if (l == r)
        {
            segtree[x].insert(vec[l]);
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

    void set(int id, int val)
    {
        vec[id] = val;
    }

    void update(int x, int l, int r, int id, int val)
    {
        if (l == r)
        {
            segtree[x]={};
            segtree[x].insert(val);
            return;
        }
        segtree[x].erase(segtree[x].upper_bound(vec[id]));
        segtree[x].insert(val);
        int mid = (l + r) / 2;
        if (id <= mid)
        {
            update(2 * x + 1, l, mid, id, val);
        }
        else
        {
            update(2 * x + 2, mid + 1, r, id, val);
        }
        
        // recalculate(x);
    }

    void update(int id, int val)
    {
        update(0, 0, size - 1, id, val);
        vec[id] = val;
        // for(auto e : segtree[0]) printf("%d ", e);
    }

    int query(int x, int l, int r, int lx, int rx, int v)
    {
        if (lx > r || rx < l)
        {
            return 0;
        }
        if (lx <= l && r <= rx)
        {
            return segtree[x].order_of_key(v+1);
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

int main() {
    // usaco();
    int n, q;
    scd(n);
    scd(q);

    SegTree segtree;
    segtree.init(n);

    frange(i, n) {
        int a;
        scd(a);
        segtree.set(i, a);
    }
    segtree.build();

    frange(_, q) {
        int t, l, r;
        scd(t);
        scd(l);
        scd(r);
        l--;
        // r--;
        if(t == 1) {
            r--;
            int v;
            scd(v);
            printf("%d\n", segtree.query(l, r, v));
        }
        else {
            segtree.update(l, r);
        }
    }
}