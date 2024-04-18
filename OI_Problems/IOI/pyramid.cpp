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

int main() {
    // usaco();
    int n, m, a, b, c, d;
    scd(m);
    scd(n);
    scd(b);
    scd(a);
    scd(d);
    scd(c);
    a--;
    b--;
    c--;
    d--;
    vvi grid(n, vi(m));
    vvi pref(n, vi(m));

    frange(i, n) {
        frange(j, m) {
            scd(grid[i][j]);
            pref[i][j] = grid[i][j];
            if(i - 1>=0) pref[i][j] += pref[i-1][j];
            if(j-1 >=0) pref[i][j] += pref[i][j-1];
            if(i-1>=0 && j-1>=0) pref[i][j] -= pref[i-1][j-1];
        }
    }

    vector<SegTree<pii>> minv(n);

    frange(i, n-c) {
        minv[i].init(m, {1e9, 1e9});
        frange(j, m-d) {
            int v= pref[i+c][j+d];
            if(i > 0) v -= pref[i-1][j+d];
            if(j > 0) v -= pref[i+c][j-1];
            if(i > 0 && j > 0) v += pref[i-1][j-1];
            minv[i].set(j, {v, j});
        }
        minv[i].build();
    }
    int ma = 0;
    pii p1, p2;
    frange(j, m-b) {
        deque<pair<int, pii>> q;
        forr(i, 1, a-c) {
            pii p = minv[i].query(j+1, j+b-d-1);
            int v = p.f;
            while(q.size() && q.back().f >= v) {
                q.pop_back();
            }
            q.pb(mp(v, mp(i, p.s)));
        }
        frange(i, n-a) {
            if(q.front().s.f == i) q.pop_front();
            int v = pref[i+a][j+b];
            if(j > 0) v -= pref[i+a][j-1];
            if(i > 0) v -= pref[i-1][j+b];
            if(i > 0 && j > 0) v += pref[i-1][j-1];
            v -= q.front().f;
            if(v >= ma) {
                ma = v;
                p1.f = j+1;
                p1.s = i+1;
                p2.f = q.front().s.s+1;
                p2.s = q.front().s.f+1;
            }
            pii p = minv[i+a-c].query(j+1, j+b-d-1);
            v = p.f;
            while(q.size() && q.back().f >= v) {
                q.pop_back();
            }
            q.pb(mp(v, mp(i+a-c, p.s)));
        }
    }
    // printf("%d\n", ma);
    printf("%d %d\n", p1.f, p1.s);
    printf("%d %d\n", p2.f, p2.s);
}