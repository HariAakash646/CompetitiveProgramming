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

const lli mod = 998244353;

template <class T>
struct LazySegTree
{
    int size = 1, n;
    vector<T> segtree;
    vector<pair<T, T>> lazy;
    vector<T> vec;
    vb upd;

    T def1; // Assign a value

    void init(int l, T d1)
    {
        n = l;
        def1 = d1;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, def1);
        vec.assign(size, def1);
        lazy = vector<pair<T, T>>(2*size, mp(mp(1LL, 0LL), mp(0LL, 1LL)));
        upd = vb(2*size);
        
    }

    T operation(T x, T y)
    {
        if(x.f!=-1)
        return x; // Any required operation
        else return y;
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

    void propagate(int x, int l, int r)
    {
        if(!upd[x]) return;
        
        if (l < r)
        {
            pair<T, T> tmp;
            if(upd[2*x+1])
            {tmp.f.f = (lazy[x].f.f * lazy[2*x+1].f.f + lazy[x].f.s * lazy[2*x+1].s.f) % mod;
                        tmp.f.s = (lazy[x].f.f * lazy[2*x+1].f.s + lazy[x].f.s * lazy[2*x+1].s.s) % mod;
                        tmp.s.f = (lazy[x].s.f * lazy[2*x+1].f.f + lazy[x].s.s * lazy[2*x+1].s.f) % mod;
                        tmp.s.s = (lazy[x].s.f * lazy[2*x+1].f.s + lazy[x].s.s * lazy[2*x+1].s.s) % mod;
                        lazy[2*x+1] = tmp;}
            else lazy[2*x+1] = lazy[x];
            if(upd[2*x+2]) {
            tmp.f.f = (lazy[x].f.f * lazy[2*x+2].f.f + lazy[x].f.s * lazy[2*x+2].s.f) % mod;
            tmp.f.s = (lazy[x].f.f * lazy[2*x+2].f.s + lazy[x].f.s * lazy[2*x+2].s.s) % mod;
            tmp.s.f = (lazy[x].s.f * lazy[2*x+2].f.f + lazy[x].s.s * lazy[2*x+2].s.f) % mod;
            tmp.s.s = (lazy[x].s.f * lazy[2*x+2].f.s + lazy[x].s.s * lazy[2*x+2].s.s) % mod;
            lazy[2*x+2] = tmp;
            }
            else lazy[2*x+2] = lazy[x];
            upd[2*x+1] = upd[2*x+2] = true;
            
        }
        else {
            T tmp;
            tmp.f = (segtree[x].f * lazy[x].f.f + segtree[x].s*lazy[x].f.s) % mod;
            tmp.s = (segtree[x].f * lazy[x].s.f + segtree[x].s*lazy[x].s.s) % mod;
            segtree[x] = tmp;
        }
        lazy[x].f.f = lazy[x].s.s = 0;
        lazy[x].f.s=lazy[x].s.f=0;
        upd[x] = false;
    }

    void update(int x, int l, int r, int lx, int rx, pair<T, T> val)
    {
        propagate(x, l, r);
        if (lx <= l && r <= rx)
        {
            lazy[x] = val;
            upd[x] = true;
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

    void update(int lx, int rx, pair<T, T> val)
    {
        update(0, 0, size - 1, lx, rx, val);
    }

    T query(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            return mp(-1LL, -1LL);
        }
        propagate(x, l, r);
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

int main() {
    // usaco();
    int n;
    scd(n);

    LazySegTree<pair<lli, lli>> tree;
    tree.init(3e5+1, mp(0LL, 1LL));
    // tree.build();

    int l, r;
    scd(l);
    scd(r);

    forr(i, l, r+1) tree.set(i, mp(1LL, 0LL));
    tree.build();


    frange(i, n-1) {
        int l, r;
        scd(l);
        scd(r);
        pair<pair<lli, lli>, pair<lli, lli>> p;
        p.f.f = 2;
        p.f.s = 2;
        p.s.f = 1;
        p.s.s = 1;
        tree.update(l, r, p);
        p.f.f = 2;
        p.f.s = 0;
        p.s.f = 1;
        p.s.s = 3;
        if(l > 0)
            tree.update(0, l-1, p);
        if(r < 3e5)
            tree.update(r+1, 3e5, p);
    }

    lli tot = 0;

    forr(i, 0, 3e5+1) {
        tot += tree.query(i, i).f;
        // printf("%d %lld\n", i, tree.query(i, i).f);
        tot %= mod;
    }
    printf("%lld\n", tot);
}