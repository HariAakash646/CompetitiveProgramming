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


void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

template <class T>
struct LazySegTree
{
    int size = 1, n;
    vector<pair<T, int>> segtree;
    vector<T> lazy;
    vector<T> vec;

    T def1; // Assign a value

    void init(int l, T d1)
    {
        n = l;
        def1 = d1;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, mp(def1, -1));
        vec.assign(size, def1);
        lazy.assign(2*size, 0);
    }

    pair<T, int> operation(pair<T, int> x, pair<T, int> y)
    {
        return min(x, y); // Any required operation
    }

    void recalculate(int x)
    {
        segtree[x] = operation(segtree[2 * x + 1], segtree[2 * x + 2]);
    }

    void build(int x, int l, int r)
    {
        if (l == r)
        {
            segtree[x] = mp(vec[l], l);
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

    void propagate(int x, int l, int r)
    {
        segtree[x].f += lazy[x];
        if (l < r)
        {
            lazy[2 * x + 1] += lazy[x];
            lazy[2 * x + 2] += lazy[x];
        }
        lazy[x] = 0;
    }

    void update(int x, int l, int r, int lx, int rx, T val)
    {
        propagate(x, l, r);
        if (lx <= l && r <= rx)
        {
            lazy[x] += val;
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

    void update(int lx, int rx, T val)
    {
        update(0, 0, size - 1, lx, rx, val);
    }

    pair<T, int> query(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            return mp(def1, -1);
        }
        propagate(x, l, r);
        if (lx <= l && r <= rx)
        {
            return segtree[x];
        }
        int mid = (l + r) / 2;
        auto v1 = query(2 * x + 1, l, mid, lx, rx);
        auto v2 = query(2 * x + 2, mid + 1, r, lx, rx);
        return operation(v1, v2);
    }

    pair<T, int> query(int lx, int rx)
    {
        return query(0, 0, size - 1, lx, rx);
    }
};

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);
    vii edg(m);
    vvi graph(n+1);
    vi indeg(n+1);
    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        indeg[b]++;
        edg[i] = mp(a, b);
    }

    queue<int> q;
    forr(i, 1, n+1) {
        if(indeg[i] == 0) q.push(i);
    }

    vi topo;
    while(q.size()) {
        auto x = q.front();
        q.pop();
        topo.pb(x);
        // printf("%d\n", x);
        for(auto e : graph[x]) {
            indeg[e]--;
            if(indeg[e] == 0) q.push(e);
        }
    }
    vi idp(n+1);

    frange(i, n) {
        idp[topo[i]] = i;
    }

    LazySegTree<int> segtree;
    segtree.init(n, n-1);
    segtree.build();

    vi out(n+1, -1);
    vi mi(n, n), ma(n, -1);

    frange(i, m) {
        auto p = edg[i];
        if(idp[p.s] < mi[idp[p.f]]) {
            segtree.update(idp[p.s], mi[idp[p.f]]-1, -1);
            mi[idp[p.f]] = idp[p.s];
        }
        if(idp[p.f] > ma[idp[p.s]]) {
            segtree.update(ma[idp[p.s]]+1, idp[p.f], -1);
            ma[idp[p.s]] = idp[p.f];
        }
        

        while(true) {
            auto x = segtree.query(0, n-1);
            if(x.f != 0) break;
            out[topo[x.s]] = i+1;
            segtree.update(x.s, x.s, 1e9);
        }
    }

    forr(i, 1, n+1) printf("%d ", out[i]);


}