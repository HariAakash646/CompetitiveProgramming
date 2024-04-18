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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

template <class T>
struct LazySegTree
{
    int size = 1, n;
    vector<pair<T, T>> segtree;
    vector<T> mv;
    vector<T> vec;

    T def1; // Assign a value

    void init(int l, T d1)
    {
        n = l;
        def1 = d1;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, mp(def1, 0));
        mv.assign(2 * size, 0);
        vec.assign(size, def1);
    }

    T operation(T x, T y)
    {
        return x + y; // Any required operation
    }

    void recalculate(int x)
    {
        segtree[x].f = operation(segtree[2 * x + 1].f, segtree[2 * x + 2].f);
        mv[x] = max(mv[2 * x + 1], mv[2 * x + 2]);
    }

    void build(int x, int l, int r)
    {
        if (l == r)
        {
            segtree[x].f = vec[l];
            mv[x] = vec[l];
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
        segtree[x].f += (r - l + 1) * segtree[x].s;
        mv[x] += segtree[x].s;
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

    T query(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            return def1;
        }
        propagate(x, l, r);
        if (lx <= l && r <= rx)
        {
            return segtree[x].f;
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

    int queryma(int x, int l, int r, lli v)
    {
        propagate(x, l, r);
        if (l == r)
        {
            return l;
        }
        int mid = (l + r) / 2;
        propagate(2 * x + 1, l, mid);
        propagate(2 * x + 2, mid + 1, r);
        if (mv[2 * x + 1] >= v)
        {
            return queryma(2 * x + 1, l, mid, v);
        }
        else
        {
            return queryma(2 * x + 2, mid + 1, r, v);
        }
    }

    int queryma(lli v)
    {
        return queryma(0, 0, size - 1, v);
    }
};

int n, m;

int upp(lli x, LazySegTree<lli> &tree)
{
    int lo = tree.queryma(x);
    // frange(i, n)
    //     tree.query(i, i);
    // frange(i, n) printf("%lld ", tree.query(i, i));
    // printf("\n");
    // printf("%lld val: %d\n", x, lo);
    return min(n, lo);
}

int main()
{
    fastio();

    cin >>
        n >> m;
    LazySegTree<lli> segtree;
    segtree.init(n + 1, 0);
    vll vec(n);
    frange(i, n)
    {
        cin >> vec[i];
    }
    sort(all(vec));
    frange(i, n) segtree.set(i, vec[i]);
    segtree.set(n, 1e12);
    segtree.build();

    frange(i, m)
    {
        char c;
        cin >> c;
        lli a, b;
        cin >> a >> b;

        if (c == '1')
        {
            swap(a, b);
            int st = upp(a, segtree);
            if (st >= n)
                continue;
            int en = st + b - 1;
            if (en < n)
            {
                lli v = segtree.query(en, en);
                int p1 = upp(v + 1, segtree);
                int p2 = upp(v, segtree);
                int cn = p1 - p2;
                int c2 = en - p2 + 1;
                if (p2 > st)
                    segtree.update(st, p2 - 1, 1);
                if (c2 > 0)
                    segtree.update((p1 - 1) - c2 + 1, (p1 - 1), 1);
            }
            else
            {
                // st = min(st, n - 1);
                en = n - 1;
                segtree.update(st, en, 1);
            }
        }
        else
        {
            int p1 = upp(a, segtree);
            int p2 = upp(b + 1, segtree);
            // frange(i, n)
            // {
            //     printf("%d ", segtree.query(i, i));
            // }

            printf("%d\n", p2 - p1);
        }
    }
}