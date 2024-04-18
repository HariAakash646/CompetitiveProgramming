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

struct SegTree
{
    int size = 1, n;
    vector<pii> segtree;
    vector<pii> vec;

    void init(int l)
    {
        n = l;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, {0, 0});
        vec.assign(size, {0, 0});
    }

    int dist(pii a, pii b)
    {
        return abs(a.f - b.f) + abs(a.s - b.s);
    }

    int operation(int x, int y)
    {
        return x + y; // Any required operation
    }

    void recalculate(int x, int l, int r)
    {
        int mid = (l + r) / 2;
        segtree[x].f = operation(segtree[2 * x + 1].f, segtree[2 * x + 2].f) + dist(vec[mid], vec[mid + 1]);
        segtree[x].s = max(segtree[2 * x + 1].s, segtree[2 * x + 2].s);

        if (mid - 1 >= l && mid + 1 <= r)
        {
            segtree[x].s = max(segtree[x].s, dist(vec[mid], vec[mid + 1]) + dist(vec[mid], vec[mid - 1]) - dist(vec[mid - 1], vec[mid + 1]));
        }
        mid++;
        if (mid - 1 >= l && mid + 1 <= r)
        {
            segtree[x].s = max(segtree[x].s, dist(vec[mid], vec[mid + 1]) + dist(vec[mid], vec[mid - 1]) - dist(vec[mid - 1], vec[mid + 1]));
        }
    }

    void build(int x, int l, int r)
    {
        if (l == r)
        {
            return;
        }
        int mid = (l + r) / 2;
        build(2 * x + 1, l, mid);
        build(2 * x + 2, mid + 1, r);
        recalculate(x, l, r);
    }

    void build()
    {
        build(0, 0, size - 1);
    }

    void set(int id, pii val)
    {
        vec[id] = val;
    }

    void update(int x, int l, int r, int id, pii val)
    {
        if (l == r)
        {
            vec[l] = val;
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
        recalculate(x, l, r);
    }

    void update(int id, pii val)
    {
        update(0, 0, size - 1, id, val);
        // frange(i, n) printf("%d %d\n", vec[i].f, vec[i].s);
        // build(0, 0, size - 1);
    }

    int query_sum(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            return 0;
        }
        if (lx <= l && r <= rx)
        {
            return segtree[x].f;
        }
        int mid = (l + r) / 2;
        int v1 = query_sum(2 * x + 1, l, mid, lx, rx);
        int v2 = query_sum(2 * x + 2, mid + 1, r, lx, rx);
        int d = 0;
        if (lx <= mid && mid + 1 <= rx)
            d = dist(vec[mid], vec[mid + 1]);
        return operation(v1, v2) + d;
    }

    int query_max(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            return 0;
        }
        if (lx <= l && r <= rx)
        {
            return segtree[x].s;
        }
        int mid = (l + r) / 2;
        int v1 = query_max(2 * x + 1, l, mid, lx, rx);
        int v2 = query_max(2 * x + 2, mid + 1, r, lx, rx);
        int d = 0;
        if (lx <= mid - 1 && mid + 1 <= rx)
            d = dist(vec[mid], vec[mid + 1]) + dist(vec[mid], vec[mid - 1]) - dist(vec[mid - 1], vec[mid + 1]);
        mid++;
        if (lx <= mid - 1 && mid + 1 <= rx)
            d = max(d, dist(vec[mid], vec[mid + 1]) + dist(vec[mid], vec[mid - 1]) - dist(vec[mid - 1], vec[mid + 1]));
        return max(max(v1, v2), d);
    }

    int query(int lx, int rx)
    {
        return query_sum(0, 0, size - 1, lx, rx) - query_max(0, 0, size - 1, lx, rx);
    }
};

void usaco()
{
    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();
    usaco();

    int n, q;
    cin >> n >> q;

    SegTree segtree;
    segtree.init(n);

    frange(i, n)
    {
        pii p;
        cin >> p.f >> p.s;
        segtree.set(i, p);
    }

    segtree.build();

    frange(i, q)
    {
        char typ;
        cin >> typ;
        if (typ == 'U')
        {
            int j, x, y;
            cin >> j >> x >> y;
            j--;
            segtree.update(j, mp(x, y));
        }
        else
        {
            int j, k;
            cin >> j >> k;
            j--;
            k--;
            cout << segtree.query(j, k) << "\n";
        }
    }
}