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

int n;
vector<vii> graph;

vll dist;
vi st, en;
int timer = 0;

void dfs(int x, int p) {
    st[x] = timer++;
    for(auto e : graph[x]) {
        if(e.f != p) {
            dist[e.f] = dist[x] + e.s;
            dfs(e.f, x);
        }
    }
    en[x] = timer;
}

template <class T>
struct LazySegTree
{
    int size = 1, n;
    vector<pair<pair<T, int>, T>> segtree;
    vector<pair<T, int>> vec;

    T def1; // Assign a value

    void init(int l, T d1)
    {
        n = l;
        def1 = d1;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, mp(mp(def1, 0), 0));
        vec.assign(size, mp(def1, 0));
    }

    pair<T, int> operation(pair<T, int> x, pair<T, int> y)
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

    void set(int id, pair<T, int> val)
    {
        vec[id] = val;
    }

    void propagate(int x, int l, int r)
    {
        segtree[x].f.f += segtree[x].s;
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
        update(0, 0, size - 1, lx, rx, val);
    }

    pair<T, int> query(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            return mp(def1, 0);
        }
        propagate(x, l, r);
        if (lx <= l && r <= rx)
        {
            return segtree[x].f;
        }
        int mid = (l + r) / 2;
        pair<T, int> v1 = query(2 * x + 1, l, mid, lx, rx);
        pair<T, int> v2 = query(2 * x + 2, mid + 1, r, lx, rx);
        return operation(v1, v2);
    }

    pair<T, int> query(int lx, int rx)
    {
        return query(0, 0, size - 1, lx, rx);
    }
};

int main() {
    // usaco();
    int q;

    scd(n);
    scd(q);

    graph = vector<vii>(n+1);

    frange(i, n-1) {
        int a, b, c;
        scd(a);
        scd(b);
        scd(c);
        a++;
        b++;
        graph[a].pb(mp(b, c));
        graph[b].pb(mp(a, c));
    }

    dist = vll(n+1);
    st = en= vi(n+1);
    dfs(1, 0);
    

    // forr(i, 1, n+1) printf("%lld ", dist[i]);

    LazySegTree<lli> segtree;
    segtree.init(timer+1, -1e18);

    forr(i, 1, n+1) segtree.set(st[i], mp(dist[i], i));
    segtree.build();
    vb vis(n+1);
    frange(_, q) {
        int t;
        scd(t);
        if(t == 1) {
            int i;
            scd(i);
            i++;
            auto v = segtree.query(st[i], en[i]-1);
            if(!vis[i]) {
                printf("%d\n", v.s-1);
                vis[v.s] = true;
                segtree.update(st[v.s], en[v.s]-1, -1e12);
            }
            else printf("%d\n", -1);
        }
        else {
            int i;
            scd(i);
            i++;
            segtree.update(st[i], en[i]-1, 1e12);
            vis[i] = false;
        }
    }

}