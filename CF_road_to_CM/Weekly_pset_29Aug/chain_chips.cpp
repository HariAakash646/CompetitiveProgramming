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

struct Data
{
    lli arr[2][2] = {{lli(1e17)}};
};

template <class T>
struct SegTree
{
    int size = 1, n;
    vector<Data> segtree;
    vector<lli> vec;

    T def; // Assign a value

    void init(int l, T defv)
    {
        n = l;
        def = defv;

        while (size < n)
            size *= 2;
        Data tmp;
        segtree.assign(2 * size, tmp);
        vec.assign(size, 1e18);
    }

    Data operation(Data v1, Data v2, int id)
    {
        Data out;
        auto x = v1.arr;
        auto y = v2.arr;
        frange(i, 2)
        {
            frange(j, 2)
            {
                out.arr[i][j] = min({x[i][0] + y[1][j] + vec[id], x[i][1] + y[0][j] + vec[id], x[i][0] + y[0][j] + vec[id], x[i][1] + y[1][j]});
            }
        }
        return out;
    }

    void recalculate(int x, int mid)
    {
        segtree[x] = operation(segtree[2 * x + 1], segtree[2 * x + 2], mid);
    }

    void build(int x, int l, int r)
    {
        if (l == r)
        {
            segtree[x].arr[1][0] = segtree[x].arr[0][1] = segtree[x].arr[0][0] = 0;
            segtree[x].arr[1][1] = 1e17;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * x + 1, l, mid);
        build(2 * x + 2, mid + 1, r);
        recalculate(x, mid);
        // cout << l << " " << r << " " << segtree[x].arr[1][1] << "\n";
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
        recalculate(x, mid);
    }

    void update(int id, T val)
    {
        update(0, 0, size - 1, id, val);
    }

    Data query(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            Data tmp;
            frange(i, 2)
            {
                frange(j, 2)
                {
                    tmp.arr[i][j] = 0;
                }
            }

            return tmp;
        }
        if (lx <= l && r <= rx)
        {
            return segtree[x];
        }
        int mid = (l + r) / 2;
        Data v1 = query(2 * x + 1, l, mid, lx, rx);
        Data v2 = query(2 * x + 2, mid + 1, r, lx, rx);
        return operation(v1, v2, mid);
    }

    Data query(int lx, int rx)
    {
        return query(0, 0, size - 1, lx, rx);
    }
};

int main()
{
    int n;
    scd(n);

    SegTree<lli> segtree;
    segtree.init(n, 0);

    frange(i, n - 1)
    {
        lli a;
        sclld(a);
        segtree.set(i, a);
    }
    segtree.build();
    int q;
    scd(q);
    frange(i, q)
    {
        int k;
        lli x;
        scd(k);
        sclld(x);
        k--;
        segtree.update(k, x);
        Data out = segtree.query(0, n - 1);
        printf("%lld\n", 2 * out.arr[1][1]);
    }
}