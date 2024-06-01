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

#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;


void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

vi val;
vvi graph;
vll tot;
vi mex;

vi st, en;
int timer = 0;

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

void dfs(int x) {
    st[x] = ++timer;
    for(auto e : graph[x]) {
        dfs(e);
    }
    en[x] = timer;
}

int main() {
    // usaco();
    int n, q;
    scd(n);
    scd(q);

    val = vi(n+q+1);
    graph = vvi(n+q+1);

    forr(i, 2, n+1) {
        int p;
        scd(p);
        graph[p].pb(i);
    }

    forr(i, 1, n+1) scd(val[i]);

    vi mv(n+q+1);
    forr(i, 1, n+1) mv[i] = i;

    int id = n;

    vvi quer(q);
    frange(i, q) {
        int t;
        scd(t);
        quer[i].pb(t);
        if(t == 1) {
            int p, u, val;
            scd(p);
            scd(u);
            scd(val);
            id++;
            graph[mv[p]].pb(id);
            quer[i].pb(p);
            quer[i].pb(u);
            quer[i].pb(val);
            mv[u] = id;
        }
        else if(t==2) {
            int u;
            scd(u);
            quer[i].pb(u);
        }
        else if(t==3) {
            int u, v;
            scd(u);
            scd(v);
            quer[i].pb(u);
            quer[i].pb(v);
        }
        else {
            int u;
            scd(u);
            quer[i].pb(u);
        }

    }

    mv = vi(n+q+1);

    forr(i, 1, n+1) mv[i] = i;

    id = n;


    st = en = vi(n+q+1);

    dfs(1);

    BIT<lli> bit(n+q+1);

    forr(i, 1, n+q+1) {
        bit.set(st[i], val[i]);
    }

    for(auto v : quer) {
        if(v[0] == 1) {
            id++;
            mv[v[2]] = id;
            val[id] = mv[v[3]];
            bit.set(st[id], val[id]);
        }
        else if(v[0] == 2) {
            val[mv[v[1]]] = 0;
            bit.set(st[mv[v[1]]], 0);
            for(auto e : graph[mv[v[1]]]) {
                val[e] = 0;
                bit.set(st[e], val[e]);
            }
        }
        else if(v[0] == 3) {
            val[mv[v[1]]] = v[2];
            bit.set(st[mv[v[1]]], v[2]);
        }
        else {
            printf("%lld\n", bit.query(en[v[1]]) - bit.query(st[v[1]]-1));
        }
    }
    

}