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

bool cmp(pii x, pii y) {
    return max(x.f, x.s) > max(y.f, y.s);
}

int main() {
    // usaco();
    int n, k;
    scd(n);
    scd(k);
    vii vec(n);
    seti st;

    frange(i, n) {
        scd(vec[i].f);
        scd(vec[i].s);
        st.insert(vec[i].f);
        st.insert(vec[i].s);
    }

    vi val(k+1);
    vii val2;
    forr(i, 1, k+1) {
        scd(val[i]);
        st.insert(val[i]);
        val2.pb(mp(val[i], i));
    }
    sort(all(val2));
    mpii mv1, mv2;

    int id = 0;
    for(auto e : st) {
        mv2[id] = e;
        mv1[e] = id++;
    }

    SegTree<int> tree;
    tree.init(id, 0);
    forr(i, 1, k+1) {
        tree.set(mv1[val[i]], i);
    }
    tree.build();

    BIT<int> bit(k+1);

    sort(all(vec), cmp);

    lli tot = 0;
    id =val2.size();
    for(auto p : vec) {
        int a = max(p.f, p.s);
        int b = min(p.f, p.s);
        if(a == b) {
            tot += a;
            continue;
        }
        // printf("%d %d\n", id, val2[id-1].f);
        while(id > 0 && val2[id-1].f >= a) {
            id--;
            // printf("%d\n", id);
            bit.add(val2[id].s, 1);
        }
        int id1 = tree.query(mv1[b], mv1[a]-1);
        // printf("%d ", id1);
        if(id1 == 0) {
            int x = bit.query(k);
            // printf("%d %d %d\n", x, p.f, p.s);
            if(x % 2 == 0) tot += p.f;
            else tot += p.s;
        }
        else {
            int x = bit.query(k) - bit.query(id1);
            // printf("%d %d %d\n", x, p.f, p.s);
            if(x % 2 == 0) tot += a;
            else tot += b;
        }
    }
    printf("%lld", tot);

}