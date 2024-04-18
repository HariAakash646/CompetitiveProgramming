#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

vvi graph;
vii trav;

void dfs(int node, int depth, int prev)
{
    trav.pb({node, depth});
    for (auto e : graph[node])
    {
        dfs(e, depth + 1, node);
    }
    if (prev)
        trav.pb({prev, depth - 1});
}

vector<pair<int, lli>> segtree;
vector<pair<int, lli>> vec;

lli inf = 1e13;

void recalculate(int node)
{
    if (segtree[2 * node + 1].s <= segtree[2 * node + 2].s)
    {
        segtree[node].f = segtree[2 * node + 1].f;
        segtree[node].s = segtree[2 * node + 1].s;
    }
    else
    {
        segtree[node].f = segtree[2 * node + 2].f;
        segtree[node].s = segtree[2 * node + 2].s;
    }
}

void build(int node, int l, int r)
{
    if (r == l)
    {
        segtree[node].f = vec[l].f;
        segtree[node].s = vec[l].s;
    }
    else
    {
        int mid = (r + l) / 2;
        build(2 * node + 1, l, mid);
        build(2 * node + 2, mid + 1, r);
        recalculate(node);
    }
}

pair<int, lli> query(int l, int r, int lx, int rx, int node)
{
    if (lx > r || rx < l)
        return {0, inf};
    if (lx >= l && rx <= r)
        return segtree[node];
    int mid = (lx + rx) / 2;
    auto s1 = query(l, r, lx, mid, 2 * node + 1);
    auto s2 = query(l, r, mid + 1, rx, 2 * node + 2);
    if (s1.s <= s2.s)
        return s1;
    else
        return s2;
}

int main()
{
    int n, q;
    scd(n);
    scd(q);
    graph = vvi(n + 1);
    int a;
    forr(i, 2, n + 1, 1)
    {
        scd(a);
        graph[a].pb(i);
    }
    dfs(1, 1, 0);
    int sz = trav.size();
    int sze = 1;
    while (sze < sz)
        sze *= 2;
    segtree.assign(2 * sze, {0, 0});
    vec = vector<pair<int, lli>>(sze, {0, 0});
    vector<lli> vecidx(sze, inf);
    lli idx = 0;
    for (auto p : trav)
    {
        vecidx[p.f] = min(idx, vecidx[p.f]);
        vec[idx] = {p.f, p.s};
        ++idx;
        // cout << p.f << " " << p.s << "\n";
    }
    build(0, 0, sze - 1);
    int b, c;
    frange(i, q)
    {
        scd(b);
        scd(c);
        auto out = query(min(vecidx[b], vecidx[c]), max(vecidx[b], vecidx[c]), 0, sze - 1, 0);
        printf("%lld\n", out.f);
    }
}