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
    // freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
    freopen("milkvisits.in", "r", stdin);
   freopen("milkvisits.out", "w", stdout);
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

vvi graph, lift;
vi st, en, depth;
int timer = 1;

void dfs(int x, int p) {
    st[x] = timer++;
    depth[x] = depth[p] + 1;
    lift[0][x] = p;
    for(auto e : graph[x]) {
        if(e != p) dfs(e, x);
    }
    en[x] = timer++;
}

int binlift(int x, int c) {
    frange(i, 21) {
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

    for(int i=20; i>=0; i--) {
        int at = lift[i][a];
        int bt = lift[i][b];
        if(at != bt) {
            a = at;
            b = bt;
        }
    }
    return lift[0][a];
}

int main() {
    usaco();
    int n, m;
    scd(n);
    scd(m);
    vvi val(n+1);

    forr(i, 1, n+1) {
        int a;
        scd(a);
        val[a].pb(i);
    }
    graph = vvi(n+1);
    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    depth = st = en = vi(n+1);
    lift = vvi(21, vi(n+1));
    dfs(1, 0);

    forr(i, 1, 21) {
        forr(j, 1, n+1) {
            lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }

    BIT<int> bit(timer);

    vector<pair<pii, pii>> vec(m);
    frange(i, m) {
        scd(vec[i].s.f);
        scd(vec[i].s.s);
        scd(vec[i].f.f);
        vec[i].f.s = i;
    }

    sort(all(vec));
    vi out(m);
    vi on(n+1);

    int pre = 0;
    for(auto p : vec) {
        if(p.f.f != pre) {
            for(auto e : val[pre]) {
                bit.add(st[e], -1);
                bit.add(en[e], 1);
                on[e] = 0;
            }
            for(auto e : val[p.f.f]) {
                bit.add(st[e], 1);
                bit.add(en[e], -1);
                on[e] = 1;
            }
            pre = p.f.f;
        } 
        int v = 0;
        int a= p.s.f;
        int b = p.s.s;
        int l = lca(a, b);
        // forr(i, 1, n+1) {
        //     printf("%d ", bit.query(st[i]) - bit.query(st[i]-1));
        // }
        // printf("\n");
        v = bit.query(st[a]) + bit.query(st[b]) - 2*bit.query(st[l]) + on[l];
        // printf("%d %d\n", l, v);
        if(v) out[p.f.s] = 1;

    }
    for(auto e : out) printf("%d", e);

}