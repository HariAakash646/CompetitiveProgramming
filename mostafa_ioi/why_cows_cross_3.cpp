#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

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
    // freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
    freopen("friendcross.in", "r", stdin);
   freopen("friendcross.out", "w", stdout);
}

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

    void init(int l)
    {
        n = l;

        while (size < n)
            size *= 2;

        segtree = vector<T>(2 * size);
        vec = vector<T>(size);
    }

    T operation(T x, T y)
    {
        T s3;
        // set_union(all(x), all(y), inserter(s3, s3.begin()));
        for(auto e : x) s3.insert(e);
        for(auto e : y) s3.insert(e);

        return s3;
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

    void update(int x, int l, int r, int id, int val)
    {
        segtree[x].insert(val);
        if (l == r)
        {
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
        // recalculate(x);
    }

    void update(int id, int val)
    {
        update(0, 0, size - 1, id, val);
    }

    int query(int x, int l, int r, int lx, int rx, int id)
    {
        if (lx > r || rx < l)
        {
            return 0;
        }
        if (lx <= l && r <= rx)
        {
            return (int)segtree[x].size() - (int)segtree[x].order_of_key(id);
        }
        int mid = (l + r) / 2;
        int v1 = query(2 * x + 1, l, mid, lx, rx, id);
        int v2 = query(2 * x + 2, mid + 1, r, lx, rx, id);
        return v1 + v2;
    }

    int query(int lx, int rx, int id)
    {
        return query(0, 0, size - 1, lx, rx, id);
    }
};

int main() {
    usaco();
    int n, k;
    scd(n);
    scd(k);

    vii vec(n);
    vi p1(n+1), p2(n+1);
    frange(i, n) {
        scd(vec[i].f);
        p1[vec[i].f] = i;
        
    }
    frange(i, n) {
        scd(vec[i].s);
        p2[vec[i].s] = i;
    }

    vi vis(n+1, -1);
    lli tot=0;
    SegTree<ordered_set> segtree;
    segtree.init(n+1);
    vi out(n);
    forr(i, 1, n+1) {
        out[p1[i]] = p2[i];
    }

    frange(i, n) {
        segtree.update(vec[i].f, out[i]);
        int x = vec[i].f;
        if(x - k - 1 >= 0) tot += segtree.query(0, x-k-1, out[i]);
        if(x + k + 1 <= n) tot += segtree.query(x+k+1, n, out[i]);
    }
    // frange(i, n) {
    //     auto p = vec[i];
    //     if(vis[p.f] != -1) {
    //         out[p.f] = vis[p.f];
    //         segtree.update(p.f, vis[p.f]);
    //     }
    //     else vis[p.f] = i;
        
    //     if(vis[p.s] != -1) {
    //         out[p.s] = vis[p.s];
    //         segtree.update(p.s, vis[p.s]);
    //     }
    //     else vis[p.s] = i;
        
    //     if(vis[p.f] != i) {
    //         if(p.f-k-1 >= 0) tot += segtree.query(0, p.f-k-1, vis[p.f]);
    //         if(p.f+k+1 <= n) tot += segtree.query(p.f+k+1, n, vis[p.f]);
    //         if(vis[p.f] == vis[p.s] && abs(p.f - p.s) > k) tot--; 
    //     }
        
    //     if(vis[p.s] != i) {
    //         if(p.s-k-1 >= 0) tot += segtree.query(0, p.s-k-1, vis[p.s]);
    //         if(p.s+k+1 <= n) tot += segtree.query(p.s+k+1, n, vis[p.s]);

    //     }
        
        
    // }
    // forr(i, 1, n+1) printf("%d\n", out[i]);

    printf("%lld", tot);
}