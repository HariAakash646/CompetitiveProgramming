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

int main() {
    // usaco();
    int n;
    scd(n);
    vi v1(n);
    map<int, pair<seti, seti>> pos;
    SegTree<int> seg1, seg2;
    seg1.init(n, 0);
    seg2.init(n, 0);
    frange(i, n) 
    {
        scd(v1[i]);
        pos[v1[i]].f.insert(i);
        seg1.set(i, v1[i]);
    }
    vi v2(n);
    frange(i, n) {
        scd(v2[i]);
        pos[v2[i]].s.insert(i);
        seg2.set(i, v2[i]);
    }
    seg1.build();
    seg2.build();

    int mi = 0;
    for(auto p : pos) {
        seti st1 = p.s.f;
        seti st2 = p.s.s;
        if((st1.size() + st2.size()) % 2 == 1) {
            mi = -1;
            break;
        }
        if(st1.size() % 2 == 1 || st2.size() % 2 == 1) {
            mi = max(mi, p.f);
            continue;
        }
        auto it = st1.begin();
        while(it != st1.end()) {
            int i1 = *it;
            it++;
            int i2 = *it;
            it++;

            mi = max(mi, min(p.f, seg1.query(i1+1, i2-1)));
        }

        it = st2.begin();
        while(it != st2.end()) {
            int i1 = *it;
            it++;
            int i2 = *it;
            it++;

            mi = max(mi, min(p.f, seg2.query(i1+1, i2-1)));
        }
    }

    printf("%d", mi);

}