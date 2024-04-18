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
        return min(x, y);
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

    int query(int x, int l, int r, lli v)
    {
        if(l == r) return l;
        int mid = (l + r) / 2;
        if(segtree[2*x+1] <= v) return query(2 * x + 1, l, mid, v);
        else if(segtree[2*x+2] <= v) return query(2 * x + 2, mid + 1, r, v);
        return 1e9;
    }

    int query(lli v)
    {
        return query(0, 0, size - 1, v);
    }
};

int main() {
    // usaco();
    int q;
    scd(q);

    SegTree<lli> segtree;
    segtree.init(q+1, 1e18);
    segtree.build();
    set<pair<int, lli>> st;
    int id = 1;
    vi type(q+1);
    vll val(q+1);

    frange(i, q) {
        int t;
        scd(t);
        if(t == 1) {
            lli v;
            int w;
            sclld(v);
            scd(w);
            if(w == 0) {
                segtree.update(id, v);
            }
            else {
                st.insert(mp(id, v));
            }
            type[id] = w;
            val[id] = v;
            id++;
        }
        else if(t == 2) {
            int pos;
            scd(pos);
            if(type[pos]) {
                st.erase(mp(pos, val[pos]));
            }
            else {
                segtree.update(pos, 1e18);
            }
        }
        else {
            int curr = 0;
            lli v;
            sclld(v);
            vector<pair<int, lli>> out;
            while(v) {
                int i1 = segtree.query(v);
                int i2 = 1e9;
                if(st.size()) i2 = (*st.begin()).f;
                if(i1 < i2) {
                    v -= val[i1];
                    out.pb(mp(i1, val[i1]));
                    segtree.update(i1, 1e18);
                    curr = i1;
                }
                else if(i2 < 1e9) {
                    lli tmp = v;
                    out.pb(mp(i2, min(v, val[i2])));
                    v = max(0LL, v-val[i2]);
                    st.erase(st.begin());
                    val[i2] = max(0LL, val[i2]-tmp);
                    if(val[i2]) st.insert(mp(i2, val[i2]));
                }
                else break;
            }
            printf("%d\n", (int)out.size());
            for(auto p : out) printf("%d %lld\n", p.f, p.s);
        }
    }
}