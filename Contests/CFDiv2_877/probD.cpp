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
        return x | y; // Any required operation
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
    int n, q;
    cin >> n >> q;
    string str;
    cin >> str;
    vi c1(n), c2(n);
    if (str[0] == '(')
        c1[0] = 1;
    if (str[n - 1] == ')')
        c2[n - 1] = 1;
    forr(i, 1, n)
    {
        c1[i] = c1[i - 1];
        if (str[i] == '(')
            c1[i]++;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        c2[i] = c2[i + 1];
        if (str[i] == ')')
            c2[i]++;
    }
    vb v1(n), v2(n);
    frange(i, n)
    {
        if (c2[i] > c1[i])
        {
            v1[i] = true;
        }
    }
    for (int i = n - 1; i >= 0; j--)
    {
        if (c1[i] > c2[i])
        {
            v2[i] = true;
        }
    }
    SegTree<int> seg1, seg2;
    seg1.init(n, 0);
    seg2.init(n, 0);

    frange(i, n - 1)
    {
        if (str[i] == str[i + 1] && str[i] == '(')
        {
            seg1.set(i, 1);
        }
    }
    for (int i = n - 1; i >= 1; i--)
    {
        if (str[i] == str[i - 1] && str[i] == ')')
        {
            seg1.set(i, 1);
        }
    }
    bool curr = true;
    frange(i, n)
    {
        if (v1[i])
        {
            if (i == 0)
            {
                curr = false;
            }
        }
    }
}