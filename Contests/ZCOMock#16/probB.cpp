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

vi val;

template <class T>
struct SegTree
{
    int size = 1, n;
    vector<T> segtree;

    T def; // Assign a value

    void init(int l, T defv)
    {
        n = l;
        def = defv;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, def);
    }

    T operation(T x, T y)
    {
        return max(x, y); // Any required operation
    }

    void build()
    {
        for (int i = n - 1; i > 0; --i)
            segtree[i] = operation(segtree[i << 1], segtree[i << 1 | 1]);
    }

    void set(int id, T val)
    {
        segtree[n + id] = val;
    }

    void update(int id, T val)
    {
        id += n;
        for (segtree[id] = val; id > 1; id >>= 1)
            segtree[id >> 1] = operation(segtree[id], segtree[id ^ 1]);
    }

    T query(int l, int r)
    {
        T res = def;
        r++;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = operation(res, segtree[l++]);
            if (r & 1)
                res = operation(res, segtree[--r]);
        }
        return res;
    }
};

SegTree<int> lift[21];

int main()
{
    int n, q;
    scd(n);
    scd(q);

    val = vi(n + 1);
    forr(i, 1, n + 1) scd(val[i]);

    lift[0].init(n + 1, 0);
    forr(i, 1, n + 1)
    {
        lift[0].set(i, i + val[i]);
        // liftc[0][i] = i + val[i];
    }
    lift[0].build();
    forr(i, 1, 21)
    {
        lift[i].init(n + 1, 0);
        forr(j, 1, n + 1)
        {
            int v = lift[i - 1].query(j, lift[i - 1].query(j, j));
            lift[i].set(j, v);
            // liftc[i][j] = v;
        }
        lift[i].build();
    }

    frange(_, q)
    {
        int x, y;
        scd(x);
        scd(y);
        int u = x;
        if (y < x)
        {
            printf("-1\n");
            continue;
        }
        if (x == y)
        {
            printf("0\n");
            continue;
        }
        int k = 0;
        for (int i = 20; i >= 0; i--)
        {
            int v = lift[i].query(x, u);
            if (v < y)
            {
                u = v;
                k += (1 << i);
            }
        }
        u = lift[0].query(x, u);
        k++;
        if (u >= y)
        {
            printf("%d\n", k);
        }
        else
            printf("-1\n");
    }
}