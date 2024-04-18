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

const lli mod = 30013;

struct Data {
    int v = 0;
    lli cnt = 0;
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
    {   T out;
        if(x.v > y.v) {
            out = x;
        }
        else if(y.v > x.v) {
            out = y;
        }
        else {
            out = x;
            out.cnt += y.cnt;
            out.cnt %= mod;
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


int main() {
    // usaco();
    int n;
    scd(n);

    vector<pair<pii, pii>> vec(n);
    seti st;
    frange(i, n) {
        scd(vec[i].f.f);
        scd(vec[i].f.s);
        scd(vec[i].s.f);
        scd(vec[i].s.s);
        st.insert(vec[i].s.f);
        st.insert(vec[i].s.s);
    }   

    mpii mv;
    int id = 1;

    for(auto e : st) mv[e] = id++;

    sort(all(vec));
    priority_queue<pair<pii, pair<int, lli>>> pq;
    SegTree<Data> segtree;
    Data tmp;
    segtree.init(id, tmp);
    segtree.build();
    tmp.cnt = 1;
    segtree.update(0, tmp);

    for(auto p : vec) {
        while(pq.size() && -pq.top().f.f < p.f.f) {
            auto p1 = pq.top();
            pq.pop();
            tmp.v = p1.s.f;
            tmp.cnt = p1.s.s;
            segtree.update(p1.f.s, tmp);
        }
        Data out = segtree.query(0, mv[p.s.f]);
        out.v++;
        pq.push(mp(mp(-p.f.s, mv[p.s.s]), mp(out.v, out.cnt)));
    }

    while(pq.size()) {
        auto p1 = pq.top();
        pq.pop();
        tmp.v = p1.s.f;
        tmp.cnt = p1.s.s;
        segtree.update(p1.f.s, tmp);
    }

    Data out = segtree.query(0, id-1);

    printf("%d %lld\n", out.v, out.cnt % mod);



}