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

struct Data {
    lli li=-1, la=-1, ri=1e18, ra=1e18;
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
        out.li = x.li;
        if(x.li != -1 && x.ri <= y.li) {
            out.ri = y.ri;
        }
        else if(x.li != -1 && x.ri <= y.la) {
            out.ri = y.ra;
        }
        else {
            out.li = -1;
            out.ri = 1e18;
        }
        out.la = x.la;
        if(x.la != -1 && x.ra <= y.li) {
            out.ra = y.ri;
        }
        else if(x.la != -1 && x.ra <= y.la) {
            out.ra = y.ra;
        }
        else {
            out.la = -1;
            out.ra = 1e18;
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
    int n;
    scd(n);
    vector<pair<lli, lli>> vec(n);
    SegTree<Data> segtree;
    Data tmp;
    tmp.li = tmp.la = -1;
    tmp.ri = tmp.ra = 1e18;
    segtree.init(n, tmp);

    frange(i, n) {
        sclld(vec[i].f);
        sclld(vec[i].s);
        if(vec[i].s < vec[i].f) swap(vec[i].f, vec[i].s);
        tmp.li = tmp.ri = vec[i].f;
        tmp.la = tmp.ra = vec[i].s;
        segtree.set(i, tmp);
    }

    segtree.build();

    int q;
    scd(q);

    frange(_, q) {
        int i, j;
        scd(i);
        scd(j);
        i--;
        j--;
        swap(vec[i], vec[j]);
        tmp.li = tmp.ri = vec[i].f;
        tmp.la = tmp.ra = vec[i].s;
        segtree.update(i, tmp);
        tmp.li = tmp.ri = vec[j].f;
        tmp.la = tmp.ra = vec[j].s;
        segtree.update(j, tmp);
        Data out = segtree.query(0, n-1);
        if(out.li != -1 || out.la != -1) {
            printf("TAK\n");
        }
        else printf("NIE\n");

    }
}