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

// int lower(vi &vec, int x)
// {
//     int hi = vec.size();
//     int lo = 0;
//     while (lo != hi)
//     {
//         int mid = (hi + lo) / 2;
//         if (vec[mid] < x)
//         {
//             hi = mid;
//         }
//         else
//         {
//             lo = mid + 1;
//         }
//     }
//     return lo;
// }

// int upper(vi &vec, int x)
// {
//     int hi = vec.size();
//     int lo = 0;
//     while (lo != hi)
//     {
//         int mid = (hi + lo) / 2;
//         if (vec[mid] <= x)
//         {
//             hi = mid;
//         }
//         else
//         {
//             lo = mid + 1;
//         }
//     }
//     return lo;
// }

template <class T>
struct SegTree
{
    int size = 1, n;
    vector<T> segtree;
    vector<int> vec;

    T def; // Assign a value

    void init(int l, T defv)
    {
        n = l;
        def = defv;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, def);
        vec.assign(size, 0);
    }

    void operation(T x, T y, T &v3)
    {
        v3.assign(x.size() + y.size(), 0);
        merge(all(x), all(y), v3.begin());
    }

    void recalculate(int x)
    {
        operation(segtree[2 * x + 1], segtree[2 * x + 2], segtree[x]);
    }

    void build(int x, int l, int r)
    {
        if (l == r)
        {
            segtree[x].pb(vec[l]);
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

    void set(int id, int val)
    {
        vec[id] = val;
    }

    void update(int x, int l, int r, int id, int val)
    {
        if (l == r)
        {
            segtree[x].pb(val);
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

    int query(int x, int l, int r, int lx, int rx, int k)
    {
        if (l == r)
        {
            return segtree[x][0];
        }
        // if (lx <= l && r <= rx)
        // {
        //     return segtree[x].end() - lower_bound(all(segtree[x]), v);
        // }
        int mid = (l + r) / 2;
        int p = upper_bound(all(segtree[2 * x + 1]), rx) - lower_bound(all(segtree[2 * x + 1]), lx);
        if (p >= k)
            return query(2 * x + 1, l, mid, lx, rx, k);
        else
            return query(2 * x + 2, mid + 1, r, lx, rx, k - p);
    }

    int query(int lx, int rx, int k)
    {
        return query(0, 0, size - 1, lx, rx, k);
    }

    int query_val(int x, int l, int r, int lx, int rx, int v)
    {
        if (l == r)
        {
            return segtree[x][0] == v;
        }
        if (lx > r || rx < l)
            return 0;
        if (lx <= l && r <= rx)
        {
            return upper_bound(all(segtree[x]), v) - lower_bound(all(segtree[x]), v);
        }
        int mid = (l + r) / 2;
        return query_val(2 * x + 1, l, mid, lx, rx, v) + query_val(2 * x + 2, mid + 1, r, lx, rx, v);
    }

    int query_val(int lx, int rx, int k)
    {
        return query_val(0, 0, size - 1, lx, rx, k);
    }
};

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();
    int n, q;
    cin >> n >> q;
    SegTree<vi> segtree;
    SegTree<vi> segtree2;
    segtree.init(n, vi());
    segtree2.init(n, vi());
    vii vec(n);
    vi uns(n);
    frange(i, n)
    {
        cin >>
            vec[i].f;
        vec[i].s = i;
        uns[i] = vec[i].f;
        segtree2.set(i, vec[i].f);
    }
    sort(all(vec));
    frange(i, n)
    {
        segtree.set(i, vec[i].s);
    }

    segtree.build();
    segtree2.build();
    frange(i, q)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int id = segtree.query(l, r, (r - l + 3) / 2);
        int k = uns[id];
        int c = segtree2.query_val(l, r, k);

        if (2 * c > (r - l + 1))
        {
            printf("%d\n", k);
        }
        else
            printf("-1\n");
    }
}