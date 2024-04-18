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
        return min(x, y); // Any required operation
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
        if(lx > rx) return 2e9;
        return query(0, 0, size - 1, lx, rx);
    }
};


int main() {
    // usaco();
    int n, q;
    scd(n);
    scd(q);

    vi vec(n);

    frange(i, n) {
        scd(vec[i]);
    }

    SegTree<int> minseg[30];
    vll pref[30];

    vi posl[30], posr[30];

    frange(i, 30) {
        int l = (1<<i);
        int r = (1<<(i+1)) - 1;

        // printf("%d %d\n", l, r);

        // minseg[i].init(n, 2e9);
        vii val;
        pref[i] = vll(n+1);
        posl[i] = posr[i] = vi(n+1);
        frange(j, n) {
            if(l <= vec[j] && vec[j] <= r) {
                val.pb(mp(j, vec[j]));
                pref[i][j+1] = vec[j];
            }
            
            pref[i][j+1] += pref[i][j];
        }
        minseg[i].init(val.size(), 2e9);
        frange(k, val.size()) {
            minseg[i].set(k, val[k].s);
            int r = n;
            if(k+1<val.size()) r = val[k+1].f; 
            forr(j, val[k].f, r) posr[i][j] = k;
            int l = 0;
            if(k - 1 >=0) l = val[k-1].f+1;
            forr(j, l, val[k].f+1) posl[i][j] = k; 
        }
        if(val.size()) {frange(j, val[0].f) posr[i][j] = 0;
                forr(j, val.back().f+1, n) posl[i][j] = n;}
        minseg[i].build();
    }

    frange(_, q) {
        int l, r;
        scd(l);
        scd(r);
        lli curr = 0;
        lli ans = 0;
        frange(i, 30) {
            int lim = (1<<(i+1)) - 1;
            if(curr+1 > lim) {
                curr += pref[i][r] - pref[i][l-1];
                continue;
            }
            int v = minseg[i].query(posl[i][l-1], posr[i][r-1]);
            // printf("%d %d %d\n", v, l, r);
            if(v <= 1e9 && v <= curr+1) {
                curr += pref[i][r] - pref[i][l-1];
            }
            else {
                ans = curr + 1;
                break;
            }
        }
        if(!ans) ans = curr+1;
        printf("%lld\n", ans);
    }





}