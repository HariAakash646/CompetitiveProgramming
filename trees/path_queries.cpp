#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

struct Euler
{
    int elem;
    int subsze = 1;
    lli val = 0;
};

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

vvi graph;
vector<Euler> eul;
vll vec;

int dfs(int x, int prev, lli v)
{
    Euler el;
    el.elem = x;
    el.val = v + vec[x];
    eul.pb(el);
    int i = eul.size() - 1;
    for (auto e : graph[x])
    {
        if (e != prev)
        {
            int out = dfs(e, x, el.val);
            eul[i].subsze += out;
        }
    }

    return eul[i].subsze;
}

int main()
{
    int n, q;
    scd(n);
    scd(q);
    vec = vll(n + 1);
    frange(i, n) sclld(vec[i + 1]);
    graph = vvi(n + 1);
    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    Euler e;
    e.elem = 0;
    e.val = 0;
    e.subsze = 0;
    eul.pb(e);
    dfs(1, 0, 0);
    // printf("%lld\n", eul.size());
    vi pos(n + 1);
    forr(i, 1, n + 1)
    {
        pos[eul[i].elem] = i;
    }
    BIT<lli> bit(n + 1);
    forr(i, 1, n + 1)
    {
        bit.add(pos[i], vec[i]);
        bit.add(pos[i] + eul[pos[i]].subsze, -vec[i]);
    }
    frange(i, q)
    {
        int t, node;
        scd(t);
        scd(node);
        int p = pos[node];
        if (t == 1)
        {
            lli v;
            sclld(v);
            bit.add(p, v - vec[node]);
            bit.add(p + eul[p].subsze, -(v - vec[node]));
            vec[node] = v;
        }
        else
        {
            printf("%lld\n", bit.query(p));
        }
    }
}