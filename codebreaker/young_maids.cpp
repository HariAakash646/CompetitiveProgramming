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

struct Data {
    int a, b;
    int l, r, lx, rx;

    bool operator<(const Data &other) const {
        return a > other.a;
    } 
};

SegTree<pii> sege, sego;

Data process(int l, int r) {
    // printf("%d %d\n", l, r);
    if(l%2) swap(sege, sego);
    pii p1 = sege.query(l, r);
    pii p2 = sego.query(p1.s+1, r);
    Data tmp;
    tmp.a = p1.f;
    tmp.b = p2.f;
    tmp.l = l;
    tmp.r = r;
    tmp.lx = p1.s;
    tmp.rx = p2.s;
    if(l%2) swap(sege, sego);
    return tmp;
}

int main() {
    // usaco();
    int n;
    scd(n);

    vi vec(n);
    
    sege.init(n, mp(1e9, 0));
    sego.init(n, mp(1e9, 0));
    frange(i, n) {
        scd(vec[i]);
        if(i%2) sego.set(i, mp(vec[i], i));
        else sege.set(i, mp(vec[i], i));
    }

    sego.build();
    sege.build();

    priority_queue<Data> pq;
    
    Data tmp=process(0, n-1);
    pq.push(tmp);
    vi out;
    while(pq.size()) {  
        auto p = pq.top();
        pq.pop();
        out.pb(p.a);
        out.pb(p.b);
        if(p.l < p.lx-1) {
            Data tmp = process(p.l, p.lx-1);
            pq.push(tmp);
        }
        if(p.lx + 1 < p.rx - 1) {
            Data tmp = process(p.lx+1, p.rx-1);
            pq.push(tmp);
        }
        if(p.rx+1 < p.r) {
            Data tmp = process(p.rx+1, p.r);
            pq.push(tmp);
        }
    }

    for(auto e : out) printf("%d ", e);
}