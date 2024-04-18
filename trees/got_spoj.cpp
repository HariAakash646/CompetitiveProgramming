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
        return query(0, 0, size - 1, lx, rx);
    }
};

vvi graph;
vvi pos;
vi st, en, depth;

int timer = 1;

void dfs(int x, int p, int d) {
    depth[x] = d;
    st[x] = timer;
    pos[x].pb(timer++);
    for(auto e : graph[x]) {
        if(e != p) {
            
            dfs(e, x, d+1);
            pos[x].pb(timer++);
        }
    }
    en[x] = pos[x].back();
}

int main() {
    // usaco();
    int n, m;
    while(cin >> n){
        timer = 1;
        scd(m);

        vvi val(n+1);
        vi col(n+1);
        forr(i, 1, n+1) {
            int a;
            scd(a);
            val[a].pb(i);
            col[i] = a;
        }
    
        pos = graph = vvi(n+1);
    
        frange(i, n-1) {
            int a, b;
            scd(a);
            scd(b);
            graph[a].pb(b);
            graph[b].pb(a);
        }
    
        st = en = depth = vi(n+1);
        dfs(1, 0, 0);
    
        SegTree<pair<int, int>> segtree;
        segtree.init(timer+1, mp(1e9, 0));
    
        // forr(i, 1, n+1) segtree.set(st[i], mp(depth[i], i));
        // forr(i, 1, n+1) segtree.set(en[i], mp(depth[i], i));
    
        forr(i, 1, n+1) {
            for(auto e : pos[i]) {
                segtree.set(e, mp(depth[i], i));
            }
        }
    
        segtree.build();
        BIT<int> bit(timer+1);
    
        vector<pair<pii, pii>> quer(m);
    
        frange(i, m) {
            int a, b, c;
            scd(a);
            scd(b);
            scd(c);
            quer[i] = mp(mp(c, i), mp(a, b));
        }
        sort(all(quer));
        vi out(m);
        int pre = 0;
        for(auto p : quer) {
            int a = p.s.f;
            int b = p.s.s;
            // cout << a << " " << b <<" ";
            if(p.f.f != pre) {
                for(auto e : val[pre]) {
                    bit.set(st[e], 0);
                    bit.set(en[e], 0);
                }
                pre = p.f.f;
                for(auto e : val[pre]) {
                    bit.set(st[e], 1);
                    bit.set(en[e], -1);
                }
            }
    
            int lca = segtree.query(min(st[a], st[b]), max(st[a], st[b])).s;
            int v = bit.query(st[a]) + bit.query(st[b]) - 2*bit.query(st[lca]-1);
            // // cout << lca << " " << id << " ";
            // id = *prev(upper_bound(all(pos[lca]), st[b]));
            // v += bit.query(st[b]) - bit.query(id-1);
            
            out[p.f.s] = v;
            // cout << lca << "\n";
        }
    
        frange(i, m) {
            if(out[i]) {
                printf("Find\n");
            }
            else {
                printf("NotFind\n");
            }
        }
        printf("\n");
    }

}