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
            return 1e9;
        }
        if (lx <= l && r <= rx)
        {
            return segtree[x];
        }
        int mid = (l + r) / 2;
        T v1 = query(2 * x + 1, l, mid, lx, rx);
        T v2 = query(2 * x + 2, mid + 1, r, lx, rx);
        // printf()
        return operation(v1, v2);
    }

    T query(int lx, int rx)
    {
        return query(0, 0, size - 1, lx, rx);
    }
};

struct Query {
    int id, t, b, l, r;
};

bool cmp1(Query &x, Query &y) {
    return x.b < y.b;
}

bool cmp2(Query &x, Query &y) {
    return x.r < y.r;
} 


int main() {
    // usaco();
    int r, c, k, q;
    scd(r);
    scd(c);
    scd(k);
    scd(q);

    vii hori, vert;

    frange(i, k) {
        int d, r, c;
        
        scd(r);
        scd(c);
        scd(d);
        if(d) vert.pb(mp(r, c));
        else hori.pb(mp(c, r));
    }
    sort(all(vert));
    sort(all(hori));
    vector<Query> quer(q);
    frange(i, q) {
        scd(quer[i].t);
        scd(quer[i].b);
        scd(quer[i].l);
        scd(quer[i].r);
        quer[i].id = i;
    }

    sort(all(quer), cmp1);
    SegTree<int> seg1;
    seg1.init(c+1, -1e9);
    seg1.build();
    vi vec(c+1, -1e9);

    int id = 0;
    vb out(q);

    for(auto p : quer) {
        while(id < vert.size() && vert[id].f <= p.b) {
            if(vert[id].f > vec[vert[id].s]) {
                vec[vert[id].s] = vert[id].f;
                seg1.update(vert[id].s, vert[id].f);
                // printf("%d %d\n", vert[id].s, vert[id].f);
            }
            id++;
        }
        int v = seg1.query(p.l, p.r);
        // printf("%d %d %d %d\n", v, p.l, p.r, p.id);
        if(v >= p.t) out[p.id] = true;
    }

    sort(all(quer), cmp2);
    SegTree<int> seg2;
    seg2.init(r+1, -1e9);
    seg2.build();
    vec = vi(r+1, -1e9);
    id = 0;

    for(auto p : quer) {
        while(id < hori.size() && hori[id].f <= p.r) {
            if(hori[id].f > vec[hori[id].s]) {
                vec[hori[id].s] = hori[id].f;
                seg2.update(hori[id].s, hori[id].f);
            }
            id++;
        }
        int v = seg2.query(p.t, p.b);
        if(v >= p.l) out[p.id] = true;
    }

    frange(i, q) {
        if(out[i]) printf("YES\n");
        else printf("NO\n");
    }

}