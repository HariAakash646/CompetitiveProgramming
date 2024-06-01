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

int n, m, q;
vvi graph;
vii edg;
vector<pair<lli, int>> ckpt;

vi depth;
vi st, en;
vvi lift;
int timer = 0;

void dfs(int x, int p) {
    depth[x] = depth[p] + 1;
    st[x] = ++timer;
    lift[0][x] = p;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x);
        }
    }
    en[x] = ++timer;
}

int binlift(int x, int c) {
    frange(i, 20) {
        if(c & (1<<i)) {
            x = lift[i][x];
        }
    }
    return x;
}

int lca(int a, int b) {
    if(depth[a] > depth[b]) swap(a, b);
    b = binlift(b, depth[b]-depth[a]);
    if(a == b) return a;

    for(int i=19; i>=0; i--) {
        int at = lift[i][a];
        int bt = lift[i][b];
        if(at != bt) {
            a = at;
            b = bt;
        }
    }
    return lift[0][a];
}

struct Query {
    int id, st, en;
    lli x, y;
};

vector<vector<int>> pos;
BIT<lli> bit(0);

void rec(int l, int r, vector<Query> vec) {
    if(l == r) {
        for(auto p : vec)
            pos[l-1].pb(p.id);
        return;
    }
    
    int mid = (l+r)/2;
    forr(i, l, mid+1) {
        auto p = ckpt[i];
        bit.add(st[p.s], p.f);
        bit.add(en[p.s], -p.f);
    }

    vector<Query> lv, rv;
    for(auto p : vec) {
        int l = lca(p.st, p.en);
        lli v1 = bit.query(st[p.st]) + bit.query(st[p.en]) - 2*bit.query(st[l]);
        if(v1 <= p.y) {
            p.y -= v1;
            rv.pb(p);
        }
        else {
            lv.pb(p);
        }
    }

    forr(i, l, mid+1) {
        auto p = ckpt[i];
        bit.add(st[p.s], -p.f);
        bit.add(en[p.s], p.f);
    }

    rec(l, mid, lv);
    rec(mid+1, r, rv);
}

int main() {
    // usaco();
    fastio();

    cin >> n >> m >> q;
    graph = vvi(n+1);
    edg = vii(n);

    frange(i, n-1) {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
        edg[i+1] = mp(a, b);
    }

    depth = st = en = vi(n+1);
    lift = vvi(20, vi(n+1));
    dfs(1, 0);

    forr(i, 1, 20) {
        forr(j, 1, n+1) {
            lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }

    ckpt.pb(mp(0LL, 0));

    frange(i, m) {
        int p;
        lli c;
        cin >> p >> c;
        int a = edg[p].f;
        int b = edg[p].s;
        if(depth[a]>depth[b]) swap(a, b);
        ckpt.pb(mp(c, b));
    }

    sort(all(ckpt));

    vector<Query> quer(q);

    frange(i, q) {
        quer[i].id = i;
        cin>>(quer[i].st)>>(quer[i].en)>>(quer[i].x)>>(quer[i].y);
    }
    pos = vvi(m+1);
    bit = BIT<lli>(timer);
    rec(1, m+1, quer);

    BIT<lli> bit2(timer);
    for(auto p : ckpt) {
        bit2.add(st[p.s], 1);
        bit2.add(en[p.s], -1);
    }

    vll out(q);

    frange(i, m+1) {
        auto p = ckpt[i];
        bit2.add(st[p.s], -1);
        bit2.add(en[p.s], 1);
        bit.add(st[p.s], p.f);
        bit.add(en[p.s], -p.f);

        for(auto e : pos[i]) {
            int a = quer[e].st;
            int b = quer[e].en;
            int l = lca(a, b);
            lli v = bit2.query(st[a]) + bit2.query(st[b]) - 2*bit2.query(st[l]);
            out[e] = max(-1LL, quer[e].x-v);
        }
    }

    for(auto e : out) cout << e << "\n";

}