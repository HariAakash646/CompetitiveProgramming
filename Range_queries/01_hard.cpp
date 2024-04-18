// Not working
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
    int val = 0;
    int suf = 0;
    int pref = 0;
};

struct SegTree
{
    int size = 1, n;
    vector<Data> segtree;
    vector<int> vec;

    void init(int l)
    {
        n = l;

        while (size < n)
            size *= 2;
        Data tmp;
        segtree.assign(2 * size, tmp);
        vec.assign(size, 0);
    }

    void recalculate(int x, int l, int r)
    {
        int mid = (l + r) / 2;
        segtree[x].val = segtree[2 * x + 1].val + segtree[2 * x + 2].val + 2 * min(segtree[2 * x + 1].suf, segtree[2 * x + 2].pref);

        segtree[x].suf = segtree[2 * x + 2].suf;
        if (segtree[2 * x + 2].suf == (r - mid))
        {
            segtree[x].suf = segtree[2 * x + 1].suf + segtree[2 * x + 2].suf;
        }

        segtree[x].pref = segtree[2 * x + 1].pref;
        if (segtree[2 * x + 1].pref == (mid - l + 1))
        {
            segtree[x].pref = segtree[2 * x + 1].pref + segtree[2 * x + 2].pref;
        }
    }

    void build(int x, int l, int r)
    {
        if (l == r)
        {
            segtree[x].pref = vec[l];
            segtree[x].suf = !vec[l];
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

    void set(int id, int val)
    {
        vec[id] = val;
    }

    void update(int x, int l, int r, int id)
    {
        if (l == r)
        {
            vec[l] = !vec[l];
            segtree[x].pref = vec[l];
            segtree[x].suf = !vec[l];
            return;
        }
        int mid = (l + r) / 2;
        if (id <= mid)
        {
            update(2 * x + 1, l, mid, id);
        }
        else
        {
            update(2 * x + 2, mid + 1, r, id);
        }
        recalculate(x, l, r);
    }

    void update(int id)
    {
        update(0, 0, size - 1, id);
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
            return segtree[x].val;
        }
        int mid = (l + r) / 2;
        int v1 = query_sum(2 * x + 1, l, mid, lx, rx);
        int v2 = query_sum(2 * x + 2, mid + 1, r, lx, rx);
        int d = min(min(max(0, mid - lx + 1), segtree[2 * x + 1].suf), min(max(0, rx - mid), segtree[2 * x + 2].pref));
        return v1 + v2 + 2 * d;
    }

    int query(int lx, int rx)
    {
        return query_sum(0, 0, size - 1, lx, rx);
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

    string str;
    cin >> str;
    cin >> q;
    n = str.size();
    SegTree segtree;
    segtree.init(n);

    frange(i, n)
    {

        segtree.set(i, str[i] - '0');
    }

    segtree.build();

    frange(i, q)
    {
        int typ;
        cin >> typ;
        if (typ == 1)
        {
            int j;
            cin >> j;
            j--;
            segtree.update(j);
        }
        else
        {
            int j, k;
            cin >> j >> k;
            j--;
            k--;
            cout << (k - j + 1) - segtree.query(j, k) << "\n";
        }
    }
}