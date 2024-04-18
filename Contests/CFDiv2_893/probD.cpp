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
        return x + y; // Any required operation
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

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n, k;
        scd(n);
        scd(k);
        string str;
        cin >> str;
        SegTree<int> segtree;
        segtree.init(n, 0);
        frange(i, n) segtree.set(i, str[i] - '0');
        segtree.build();
        vvi mir1(n + 1, vi(n, 1e9));
        vvi mar1(n, vi(n + 1, -1e9));

        frange(i, n)
        {
            int mi = i;
            for (int j = n - i - 1; j >= 0; j--)
            {
                int v = segtree.query(j, j + i);
                mi = min(mi, (i + 1) - v);
                mir1[i + 1][j] = mi;
                mar1[j][mi] = max(mar1[j][mi], i + 1);
            }
        }
        vvi mil1(n + 1, vi(n, 1e9));
        vvi mal1(n, vi(n + 1, -1e9));
        frange(i, n)
        {
            int mi = i;
            for (int j = i; j - i >= 0; j--)
            {
                int v = segtree.query(j - i, j);
                mi = min(mi, (i + 1) - v);
                mil1[i + 1][j] = mi;
                mal1[j][mi] = max(mal1[j][mi], i + 1);
            }
        }
        frange(i, n) mir1[0][i] = mil1[0][i] = 0;

        frange(i, n)
        {
            int v1 = 0;
            int v2 = 0;
            frange(j, n + 1)
            {
                v1 = max(v1, mar1[i][j]);
                mar1[i][j] = v1;
                v2 = max(v2, mal1[i][j]);
                mal1[i][j] = v2;
            }
        }

        vi mval(n + 1, -1e9);
        frange(i, n)
        {
            for (int j = 0; j + i < n; j++)
            {
                int v = segtree.query(j, j + i);
                if (k - v < 0)
                    continue;
                if (j > 0)
                {
                    mval[i + 1] = max(mval[i + 1], mal1[j - 1][k - v]);
                }
                if (j + i < n - 1)
                {
                    mval[i + 1] = max(mval[i + 1], mar1[j + i + 1][k - v]);
                }
            }
        }
        mval[0] = max(mar1[0][k], mal1[n - 1][k]);

        forr(j, 1, n + 1)
        {
            lli v = 0;
            frange(i, n + 1)
            {
                v = max(v, lli(i) * j + mval[i]);
            }
            printf("%lld ", v);
        }
        printf("\n");
    }
}