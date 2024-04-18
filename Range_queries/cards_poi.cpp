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
    bool flip[2][2] = {{false}};
    int l = 0, r = 0;
};

struct SegTree
{
    int size = 1, n;
    vector<Data> segtree;
    vector<pii> vec;

    void init(int l)
    {
        n = l;

        while (size < n)
            size *= 2;
        Data tmp;
        tmp.l = n - 1;
        tmp.r = n - 1;
        tmp.flip[0][0] = tmp.flip[1][1] = true;
        segtree.assign(2 * size, tmp);
        vec.assign(size, {1e9, 1e9});
        // frange(i, size-1) segtree[i].l = segtree[i].r = i;
    }

    Data operation(Data x, Data y)
    {
        Data out;

        frange(i, 2)
        {
            frange(j, 2)
            {
                if (x.flip[i][0] && y.flip[0][j])
                {
                    if (vec[x.r].f <= vec[y.l].f)
                    {
                        out.flip[i][j] = true;
                    }
                }
                if (x.flip[i][0] && y.flip[1][j])
                {
                    if (vec[x.r].f <= vec[y.l].s)
                    {
                        out.flip[i][j] = true;
                    }
                }
                if (x.flip[i][1] && y.flip[0][j])
                {
                    if (vec[x.r].s <= vec[y.l].f)
                    {
                        out.flip[i][j] = true;
                    }
                }
                if (x.flip[i][1] && y.flip[1][j])
                {
                    if (vec[x.r].s <= vec[y.l].s)
                    {
                        out.flip[i][j] = true;
                    }
                }
            }
        }
        out.l = x.l;
        out.r = y.r;

        return out;
    }

    void recalculate(int x)
    {
        segtree[x] = operation(segtree[2 * x + 1], segtree[2 * x + 2]);
    }

    void build(int x, int l, int r)
    {
        if (l == r)
        {
            segtree[x].l = l;
            segtree[x].r = r;

            segtree[x].flip[0][0] = segtree[x].flip[1][1] = true;
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

    void set(int id, pii val)
    {
        vec[id] = val;
    }

    void update(int x, int l, int r, int id, pii p)
    {
        if (l == r)
        {
            vec[id].f = min(p.f, p.s);
            vec[id].s = max(p.f, p.s);
            return;
        }
        int mid = (l + r) / 2;
        if (id <= mid)
        {
            update(2 * x + 1, l, mid, id, p);
        }
        else
        {
            update(2 * x + 2, mid + 1, r, id, p);
        }
        recalculate(x);
    }

    void update(int id, pii v)
    {
        update(0, 0, size - 1, id, v);
        // frange(i, n) printf("%d %d\n", vec[i].f, vec[i].s);
        // build(0, 0, size - 1);
    }

    Data query(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            Data tmp;
            return tmp;
        }
        if (lx <= l && r <= rx)
        {
            return segtree[x];
        }
        int mid = (l + r) / 2;

        return operation(query(2 * x + 1, l, mid, lx, rx), query(2 * x + 2, mid + 1, r, lx, rx));
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

    SegTree segtree;
    segtree.init(n);

    frange(i, n)
    {
        pii p;
        scd(p.f);
        scd(p.s);
        if (p.f > p.s)
            swap(p.f, p.s);
        segtree.set(i, p);
    }

    segtree.build();

    int m;
    scd(m);
    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        a--;
        b--;
        pii p1 = segtree.vec[a];
        pii p2 = segtree.vec[b];
        segtree.update(a, p2);
        segtree.update(b, p1);

        Data out = segtree.query(0, n - 1);
        if (out.flip[0][0] || out.flip[0][1] || out.flip[1][0] || out.flip[1][1])
            printf("TAK\n");
        else
            printf("NIE\n");
    }
}