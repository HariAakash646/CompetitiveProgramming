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
    freopen("problem.in", "r", stdin);
    freopen("problem.out", "w", stdout);
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

template <class T1, class T2>
struct LazySegTree
{
    int size = 1, n;
    vector<pair<T1, T2>> segtree;
    vector<T1> vec;

    T1 def1; // Assign a value

    void init(int l, T1 d1)
    {
        n = l;
        def1 = d1;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, mp(def1, 0));
        vec.assign(size, def1);
    }

    T1 operation(T1 x, T1 y)
    {
        return min(x, y); // Any required operation
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

    void set(int id, T1 val)
    {
        vec[id] = val;
    }

    void propagate(int x, int l, int r)
    {
        segtree[x].f.f += segtree[x].s;
        if (l < r)
        {
            segtree[2 * x + 1].s += segtree[x].s;
            segtree[2 * x + 2].s += segtree[x].s;
        }
        segtree[x].s = 0;
    }

    void update(int x, int l, int r, int lx, int rx, T2 val)
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

    void update(int lx, int rx, T2 val)
    {
        update(0, 0, size - 1, lx, rx, val);
    }

    T1 query(int x, int l, int r, int lx, int rx)
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
        T1 v1 = query(2 * x + 1, l, mid, lx, rx);
        T1 v2 = query(2 * x + 2, mid + 1, r, lx, rx);
        return operation(v1, v2);
    }

    T1 query(int lx, int rx)
    {
        return query(0, 0, size - 1, lx, rx);
    }
};

int main()
{
    int n, qu;
    scd(n);
    scd(qu);
    vector<vii> graph(n);

    LazySegTree<pii, int> segtree;
    segtree.init(n, mp(1e9 + 10, n + 1));

    frange(i, n) segtree.set(i, mp(0, i));

    segtree.build();

    frange(i, qu)
    {
        int l, r, c;
        scd(l);
        scd(r);
        scd(c);
        l--;
        r--;
        c--;
        graph[c].pb({l, r});
        segtree.update(l, r, 1);
        segtree.update(c, c, -1);
    }

    queue<int> q;
    int curr = 0;
    while (curr < n)
    {
        auto p = segtree.query(curr, n - 1);
        if (p.f != 0)
            break;
        q.push(p.s);
        curr = p.s + 1;
    }

    vi out;

    while (q.size())
    {
        auto x = q.front();
        q.pop();
        out.pb(x);
        for (auto p : graph[x])
        {
            segtree.update(p.f, p.s, -1);
            segtree.update(x, x, 1);
            int curr = p.f;
            while (curr <= p.s)
            {
                auto e = segtree.query(curr, p.s);
                if (e.f != 0)
                    break;
                curr = e.s + 1;
                if (e.s == x)
                    continue;
                q.push(e.s);
            }
        }
    }
    vi vec(n);
    if (out.size() != n)
    {
        printf("-1");
    }
    else
    {
        forr(i, 1, n + 1)
        {
            vec[out[i - 1]] = i;
        }
        for (auto e : vec)
            printf("%d ", e);
    }
}