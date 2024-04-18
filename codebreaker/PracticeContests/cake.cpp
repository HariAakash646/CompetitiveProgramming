// TODO: Stress test
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
struct LSegTree
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

    int query_inc(int x, int l, int r, T v) {
        if(l == r) return l;
        int mid = (l + r)/2;

        if(segtree[2*x+2] >= v) {
            return query_inc(2*x+2, mid+1, r, v);
        }
        else if(segtree[2*x+1] >= v) {
            return query_inc(2*x+1, l, mid, v);
        }
        else return -1;
    }

    int query_inc(T v) {
        return query_inc(0, 0, size-1, v) + 1;
    }
};

template <class T>
struct RSegTree
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

    int query_dec(int x, int l, int r, T v) {
        if(l == r) return l;
        int mid = (l + r)/2;

        if(segtree[2*x+1] >= v) {
            return query_dec(2*x+1, l, mid, v);
        }
        else if(segtree[2*x+2] >= v) {
            return query_dec(2*x+2, mid+1, r, v);
        }
        else return n-1;
    }

    int query_dec(T v) {
        return query_dec(0, 0, size-1, v) - 1;
    }
};



int main() {
    // usaco();
    int n, a;
    cin >> n >> a;
    a--;

    vector<pair<lli, lli>> vec(n);
    frange(i, n) {
        sclld(vec[i].f);
        vec[i].s = i;
    }

    sort(all(vec), greater<>());

    LSegTree<lli> segl;
    segl.init(a, 0);

    RSegTree<lli> segr;
    segr.init(n-a, 0);

    frange(i, min(n, 10)) {
        vec[i].f = lli(10 - i) * 1e17;
    }

    // frange(i, a) {
    //     segl.set(i, vec[i].f);
    // }

    // forr(i, a+1, n) {
    //     segr.set(i-(a+1), vec[i].f);
    // }
    for(auto p : vec) {
        if(p.s < a) segl.set(p.s, p.f);
        else if(p.s > a) segr.set(p.s-(a+1), p.f);
    }

    segl.build();
    segr.build();

    int q;
    scd(q);

    frange(_, q) {
        char t;
        cin >> t;
        if(t == 'F') {
            int b;
            scd(b);
            b--;
            if(b == a) cout << "0\n";
            else if(b > a) {
                lli ma = segr.query(0, b-(a+1));
                int id = segl.query_inc(ma);
                // cout<< ma << " " << id << " " << b - id << "\n";
                cout  << b - id << "\n";
            }
            else {
                lli ma = segl.query(b, a-1);
                int id = segr.query_dec(ma);
                // cout<< ma << " "  << id + a + 1 << " " << id+a+1 - b << "\n";
                cout << id+a+1 - b << "\n";
            }
        }
        else {
            int i;
            scd(i);
            int e;
            scd(e);
            i--;
            e--;
            vec[e].f++;
            if(i < a) segl.update(i, vec[e].f);
            else if(i > a) segr.update(i-(a+1), vec[e].f);
        }
    }

}