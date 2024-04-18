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

template <class T>
struct LazySegTree
{
    int size = 1, n;
    vector<pair<T, T>> segtree;
    vector<T> vec;

    T def1; // Assign a value

    void init(int l, T d1)
    {
        n = l;
        def1 = d1;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, mp(def1, 0));
        vec.assign(size, def1);
    }

    T operation(T x, T y)
    {
        return max(x, y); // Any required operation
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

    void set(int id, T val)
    {
        vec[id] = val;
    }

    void propagate(int x, int l, int r)
    {
        segtree[x].f += segtree[x].s;
        if (l < r)
        {
            segtree[2 * x + 1].s += segtree[x].s;
            segtree[2 * x + 2].s += segtree[x].s;
        }
        segtree[x].s = 0;
    }

    void update(int x, int l, int r, int lx, int rx, T val)
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

    void update(int lx, int rx, T val)
    {
        if(lx <= rx)
        update(0, 0, size - 1, lx, rx, val);
    }

    T query(int x, int l, int r, int lx, int rx)
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
    int t;
    scd(t);

    frange(_, t) {
        int n;
        lli m;
        scd(n);
        sclld(m);

        vector<pair<pair<int, lli>, int>> vec(n);
        frange(i, n) {
            scd(vec[i].f.f);
            sclld(vec[i].f.s);
            vec[i].s = i;
        }
        sort(all(vec));
        vll val(n);

        multiset<lli> st;
        lli tot = 0;
        lli c = 0;
        frange(i, n) {
            tot += vec[i].f.s;
            c++;
            st.insert(vec[i].f.f + vec[i].f.s);
            val[i] = tot;
            if(i < n-1) {
                while(st.size() && *st.begin() < vec[i+1].f.f) {
                    int v = *st.begin();
                    st.erase(st.begin());
                    tot -= v - vec[i].f.f;
                    c--;
                }
                tot -= (vec[i+1].f.f - vec[i].f.f) * c;
            }
        }

        tot = 0;
        c = 0;
        for(int i=n-1; i>=0; i--) {
            
            c++;
            st.insert(-(vec[i].f.f - vec[i].f.s));
            val[i] += tot;
            tot += vec[i].f.s;
            if(i > 0) {
                while(st.size() && -(*st.begin()) > vec[i-1].f.f) {
                    int v = -(*st.begin());
                    st.erase(st.begin());
                    tot -= vec[i].f.f - v;
                    c--;
                }
                tot -= (vec[i].f.f - vec[i-1].f.f) * c;
            }
        }

        vector<pair<lli, int>> flo;
        frange(i, n) {
            if(val[i] > m) flo.pb(mp(val[i] - m, vec[i].f.f));
        }

        int x = flo.size();

        LazySegTree<lli> segtree;
        segtree.init(x+1, 0);

        frange(i, x) {
            segtree.set(i, flo[i].f + flo[i].s);
        }
        segtree.build();

        vi out(n);

        int pre = 0;
        int id = 0;
        frange(i, n) {
            while(id < x && flo[id].s < vec[i].f.f) {
                id++;
            }
            segtree.update(id, x-1, -(vec[i].f.f - pre));
            segtree.update(0, id-1, (vec[i].f.f - pre));
            lli v = segtree.query(0, x-1);
            pre = vec[i].f.f;
            if(v <= vec[i].f.s) out[vec[i].s] = 1;
        }
        for(auto e : out) printf("%d", e);
        printf("\n");

    }
}