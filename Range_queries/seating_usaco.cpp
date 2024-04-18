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
    freopen("seating.in", "r", stdin);
    freopen("seating.out", "w", stdout);
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct Data
{
    int val = 0;
    int pref = 0;
    int suf = 0;
    int l = 0, r;
};

template <class T>
struct LazySegTree
{
    int size = 1, n;
    vector<pair<T, int>> segtree;
    vector<T> vec;

    T def1; // Assign a value

    void init(int l, T d1)
    {
        n = l;
        def1 = d1;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, mp(def1, -1));
        vec.assign(size, def1);
    }

    T operation(T x, T y)
    {
        Data out;
        out.val = max(x.val, y.val);
        out.val = max(out.val, x.suf + y.pref);

        out.pref = x.pref;
        if (x.val == (x.r - x.l + 1))
            out.pref = x.val + y.pref;

        out.suf = y.suf;
        if (y.val == (y.r - y.l + 1))
            out.suf = y.val + x.suf;

        out.l = x.l;
        out.r = max(x.r, y.r);

        return out;
    }

    void recalculate(int x)
    {
        segtree[x].f = operation(segtree[2 * x + 1].f, segtree[2 * x + 2].f);
    }

    void build(int x, int l, int r)
    {
        if (l == r)
        {
            segtree[x].f = vec[l];
            // segtree[x].f.r = r;
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
        // frange(i, n)
        // {
        //     printf("%d %d %d %d %d\n", segtree[i].f.l, segtree[i].f.r, segtree[i].f.val, segtree[i].f.pref, segtree[i].f.suf);
        // }
    }

    void set(int id, T val)
    {
        vec[id] = val;
    }

    void propagate(int x, int l, int r)
    {
        if (segtree[x].s == -1)
            return;
        segtree[x].f.val = (r - l + 1) * segtree[x].s;
        segtree[x].f.pref = (r - l + 1) * segtree[x].s;
        segtree[x].f.suf = (r - l + 1) * segtree[x].s;
        if (l < r)
        {
            segtree[2 * x + 1].s = segtree[x].s;
            segtree[2 * x + 2].s = segtree[x].s;
        }
        segtree[x].s = -1;
    }

    void update(int x, int l, int r, int lx, int rx, int val)
    {
        propagate(x, l, r);
        if (lx <= l && r <= rx)
        {
            segtree[x].s = val;
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

    void update(int lx, int rx, int val)
    {
        update(0, 0, size - 1, lx, rx, val);
    }

    int query(int x, int l, int r, int k)
    {
        // printf("%d %d\n", l, r);
        propagate(x, l, r);
        if (segtree[x].f.val < k)
            return -1;
        if (segtree[x].f.pref >= k)
            return l;
        int mid = (l + r) / 2;
        propagate(2 * x + 1, l, mid);
        propagate(2 * x + 2, mid + 1, r);
        if (segtree[2 * x + 1].f.val >= k)
        {
            return query(2 * x + 1, l, mid, k);
        }
        else if (segtree[2 * x + 1].f.suf + segtree[2 * x + 2].f.pref >= k)
        {
            return segtree[2 * x + 1].f.r - segtree[2 * x + 1].f.suf + 1;
        }
        else
            return query(2 * x + 2, mid + 1, r, k);
    }

    int query(int k)
    {
        return query(0, 0, size - 1, k);
    }
};

int main()
{

    fastio();
    usaco();

    int n, m;
    cin >> n >> m;

    LazySegTree<Data> segtree;
    Data tmp;
    segtree.init(n, tmp);

    frange(i, n)
    {
        Data tmp;
        tmp.r = i;
        tmp.l = i;
        tmp.val = tmp.pref = tmp.suf = 1;
        segtree.set(i, tmp);
    }
    segtree.build();

    int c = 0;
    frange(i, m)
    {
        char t;
        cin >> t;

        if (t == 'A')
        {
            int x;
            cin >> x;
            int l = segtree.query(x);
            if (l == -1)
                c++;
            else
            {
                // cout << l << " " << l + x - 1 << "\n";
                segtree.update(l, l + x - 1, 0);
            }
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            segtree.update(l, r, 1);
        }
    }
    cout << c;
}