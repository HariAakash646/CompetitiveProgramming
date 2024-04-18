#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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
    freopen("input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

template <class T>
struct LazySegTree
{
    int size = 1, n;
    vector<pair<T, T>> segtree;
    vector<T> vec;

    T def1; // Assign a value

    void init(int l, T d1)
    {
        n = l;
        def1 = d1;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, mp(def1, 0));
        vec.assign(size, def1);
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
            segtree[x].f = vec[l];
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
        segtree[x].f += segtree[x].s;
        if (l < r)
        {
            segtree[2 * x + 1].s += segtree[x].s;
            segtree[2 * x + 2].s += segtree[x].s;
        }
        segtree[x].s = 0;
    }

    void update(int x, int l, int r, int lx, int rx, T val)
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

    void update(int lx, int rx, T val)
    {
        update(0, 0, size - 1, lx, rx, val);
    }

    T query(int x, int l, int r, T val)
    {
        propagate(x, l, r);
        if (l == r)
        {
            return l;
        }
        int mid = (l + r) / 2;
        propagate(2*x+2, mid+1, r);
        if(segtree[2*x+2].f <= val) {
            return query(2*x+2, mid+1, r, val);
        }
        else return query(2 * x + 1, l, mid, val);
    }

    T query(T val)
    {
        return query(0, 0, size - 1, val);
    }

    T query_min(int x, int l, int r, int pos) {
        propagate(x, l, r);
        if(l == r) {
            return segtree[x].f;
        }
        int mid = (l + r)/2;
        if(pos <= mid)
            return query_min(2*x+1, l, mid, pos);
        else 
            return query_min(2*x+2, mid+1, r, pos);
    }

    T query_min(int pos) {
        return query_min(0, 0, size-1, pos);
    }
};

int mod = 1e5 + 1;

int main() {
    // usaco();
    int n;
    scd(n);

    LazySegTree<int> segtree;
    segtree.init(1e5+2, 1e9);

    forr(i, 0, 1e5+2) {
        segtree.set(i, i);
    }
    segtree.build();
    int ans = 0;
    frange(i, n) {
        int t;
        scd(t);
        int id = segtree.query(t);
        int val = segtree.query_min(id);
        if(val == t) {
            int id2 = segtree.query(t-1);
            if(segtree.query_min(id2) < t) segtree.update(0, id2, 1);
        }
        else if(val < t) {
            segtree.update(0, id, 1);
        }
        else {
            segtree.update(id, id, -1);
        }
        segtree.update(id+1, 1e5+1, -1);
        // printf("id: %d %d\n", id, segtree.segtree[id].f);
        // frange(i, 20) printf("%d ", segtree.query_min(i));
        // printf("\n");
        int k;
        scd(k);
        frange(_, k) {
            int x;
            scd(x);
            x = (x + ans) % mod;
            ans = segtree.query_min(x);
            printf("%d\n", ans);
        }
    }
}