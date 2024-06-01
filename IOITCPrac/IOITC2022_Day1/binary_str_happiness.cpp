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
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

template <class T>
struct BIT
{
    int size;
    vector<T> bit;
    vector<T> vec;

    BIT(int n) : size(n), bit(n + 1), vec(n + 1) {}

    int lsb(int x)
    {
        return x & (-x);
    }

    void set(int id, T v)
    {
        add(id, v - vec[id]);
    }

    void add(int id, T v)
    {
        if (id == 0)
            return;
        vec[id] += v;
        while (id <= size)
        {
            bit[id] += v;
            id += lsb(id);
        }
    }

    T query(int id)
    {
        T tot = 0;
        if (id == 0)
            return tot;
        while (id >= 1)
        {
            tot += bit[id];
            id -= lsb(id);
        }
        return tot;
    }
};

struct Data {
    int v1 = 0, v2 = 0;
    int i1 = -1, i2 = -1;
};

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
        T out;
        if(x.v1 < y.v1) swap(x, y);
        out.v1 = x.v1;
        out.i1 = x.i1;
        if(x.v2 > y.v1) {
            out.v2 = x.v2;
            out.i2 = x.i2;
        }
        else {
            out.v2 = y.v1;
            out.i2 = y.i1;
        }
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

int main() {
    // usaco();
    fastio();
    int n, q;
    cin >> n >> q;

    BIT<int> bit(n);
    SegTree<Data> prseg, sfseg, mseg;
    Data tmp;
    prseg.init(n+1, tmp);
    sfseg.init(n+1, tmp);
    mseg.init(n+1, tmp);

    forr(i, 1, n+1) {
        int l;
        cin >> l;
        string str;
        cin >> str;
        vi pref(l+1);
        int pra = 0;
        int sfa = 0;
        int ma = 0;

        forr(i, 1, l+1) {
            pref[i] = pref[i-1];
            if(str[i-1] == '0') pref[i]--;
            else pref[i]++;
            pra = max(pra, pref[i]);
            sfa = min(sfa, pref[i]);
            ma = max(ma, pref[i] - sfa);
        }
        int v = max(pref[l], 0);
        bit.set(i, v);
        Data tmp;
        tmp.i1 = i;
        tmp.v1 = ma;
        mseg.set(i, tmp);
        tmp.v1 = (pref[l]-sfa)-v;
        sfseg.set(i, tmp);
        tmp.v1 = pra - v;
        prseg.set(i, tmp);
    }
    mseg.build();
    sfseg.build();
    prseg.build();

    frange(_, q) {
        int l, r;
        cin >> l >> r;
        int ma = mseg.query(l, r).v1;
        int v = bit.query(r) - bit.query(l-1);
        Data sfd = sfseg.query(l, r);
        Data prd = prseg.query(l, r);
        if(sfd.i1 != prd.i1) {
            v += sfd.v1 + prd.v1;
        }
        else {
            v += max(sfd.v1 + prd.v2, sfd.v2 + prd.v1);
        }
        ma = max(ma, v);
        cout << ma << "\n";
    }
}