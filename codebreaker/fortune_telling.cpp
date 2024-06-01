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

bool cmp(pii x, pii y) {
    return max(x.f, x.s) > max(y.f, y.s);
}

int main() {
    // usaco();
    int n, k;
    scd(n);
    scd(k);

    vii vec(n);
    frange(i, n) {
        scd(vec[i].f);
        scd(vec[i].s);
    }

    sort(all(vec), cmp);

    vii v2(k);
    vi val(k);
    frange(i, k) {scd(v2[i].f); v2[i].s = i; val[i] = v2[i].f;}
    sort(all(v2));
    sort(all(val));
    SegTree<int> tree;
    tree.init(k, 0);
    frange(i, k) {
        tree.set(i, v2[i].s+1);
    }
    tree.build();
    int id = k-1;
    lli tot = 0;
    BIT<int> bit(k);
    for(auto p : vec) {
        int a = p.f;
        int b = p.s;
        while(id >= 0 && v2[id].f >= max(a, b)) {
            bit.add(v2[id].s+1, 1);
            id--;
        }

        int i1 = lower_bound(all(val), min(a, b)) - val.begin();
        int i2 = prev(lower_bound(all(val), max(a, b))) - val.begin();
        // printf("%d %d %d %d ", a, b, i1, i2);
        if(i1 > i2) {
            int c = bit.query(k);
            // printf("%d ", c);
            if(c % 2) tot += b;
            else tot += a;
        }
        else {
            int idx = tree.query(i1, i2);
            
            int c = bit.query(k) - bit.query(idx);
            // printf("%d %d ", idx, c);
            if(a < b) swap(a, b);
            if(c % 2) tot += b;
            else tot += a;
        }
        // printf("\n");

    }
    printf("%lld", tot);
}