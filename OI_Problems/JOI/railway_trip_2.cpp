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
struct MinSegTree
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

vector<SegTree<int>> lift1(20);
vector<MinSegTree<int>> lift2(20);

int binlift(int st, int en) {
    int tot = 0;
    pii curr = mp(st, st);
    for(int i=19; i>=0; i--) {
        pii tmp = mp(lift2[i].query(curr.f, curr.s), lift1[i].query(curr.f, curr.s));
        
        if(!(tmp.f <= en && en <= tmp.s)) {
            curr = tmp;
            tot += (1<<i);
        }
    }
    // printf("%d %d\n", curr.f, curr.s);
    curr = mp(lift2[0].query(curr.f, curr.s), lift1[0].query(curr.f, curr.s));
    // printf("%d %d\n", curr.f, curr.s);
    if(curr.f <= en && en <= curr.s)
        return tot + 1;
    else return -1;
}

// bool check(int st, int en, int x) {
//     pii curr = mp(st, st);
//     frange(i, 20) {
//         if(x & (1<<i)) {
//             curr = mp(lift2[i].query(curr.f, curr.s), lift1[i].query(curr.f, curr.s));
//         }
//     }
//     if(curr.f <= en && en <= curr.s) return true;
//     else return false;
// }

int main() {
    // usaco();
    int n, k;
    scd(n);
    scd(k);
    int m;
    scd(m);

    vii vec(m);

    frange(i, m) {
        scd(vec[i].s);
        scd(vec[i].f);
    }

    sort(all(vec));
    seti act;
    frange(i, n) act.insert(i+1);

    sort(all(vec), greater<>());
    lift1[0].init(n+1, 0);
    forr(i, 1, n+1) {
        lift1[0].set(i, i);
    }
    for(auto p : vec) {
        if(p.f > p.s) {
            auto it = act.lower_bound(p.s);
            while(it != act.end() && *it < min(p.s+k, p.f)) {
                lift1[0].set(*it, p.f);
                act.erase(it);
                it=act.lower_bound(p.s);
            }
        }
    }
    lift1[0].build();
    frange(i, n) act.insert(i+1);

    sort(all(vec));
    lift2[0].init(n+1, 1e9);
    forr(i, 1, n+1) {
        lift2[0].set(i, i);
    }
    for(auto p : vec) {
        if(p.f < p.s) {
            auto it = act.lower_bound(max(p.f+1, p.s-k+1));
            while(it != act.end() && *it <= p.s) {
                lift2[0].set(*it, p.f);
                act.erase(it);
                it=act.lower_bound(max(p.f+1, p.s-k+1));
            }
        }
    }
    lift2[0].build();

    forr(i, 1, 20) {
        lift1[i].init(n+1, 0);
        lift2[i].init(n+1, 1e9);
        forr(j, 1, n+1) {
            lift1[i].set(j, lift1[i-1].query(lift2[i-1].query(j, j), lift1[i-1].query(j, j)));
            lift2[i].set(j, lift2[i-1].query(lift2[i-1].query(j, j), lift1[i-1].query(j, j)));
        }
        lift1[i].build();
        lift2[i].build();
    }

    int q;
    scd(q);

    frange(_, q) {
        int st, en;
        scd(st);
        scd(en);
        printf("%d\n", binlift(st, en));
        // int lo = 0;
        // int hi = m+1;

        // while(lo != hi) {
        //     int mid = (lo+hi)/2;
        //     if(check(st, en, mid)) hi = mid;
        //     else lo = mid+1;
        // }
        // if(hi == m+1) printf("-1\n");
        // else printf("%d\n", lo);
    }
}