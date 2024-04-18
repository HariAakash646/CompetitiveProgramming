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

vector<lli> segtree;
vector<lli> vec;

lli inf = 1e13;

void recalculate(int node)
{
    segtree[node] = max(segtree[2 * node + 1], segtree[2 * node + 2]);
}

void build(int node, int l, int r)
{
    if (r == l)
    {
        segtree[node] = vec[l];
    }
    else
    {
        int mid = (r + l) / 2;
        build(2 * node + 1, l, mid);
        build(2 * node + 2, mid + 1, r);
        recalculate(node);
    }
}

pair<lli, int> query(int lx, int rx, int node, int v)
{
    if (lx == rx)
        return {segtree[node], node};
    int mid = (lx + rx) / 2;
    pair<lli, int> ret = {0, 0};
    if (segtree[2 * node + 1] >= v)
        ret = query(lx, mid, 2 * node + 1, v);
    else if (segtree[2 * node + 2] >= v)
        ret = query(mid + 1, rx, 2 * node + 2, v);
    else
        ret = {0, 0};
    return ret;
}

void update(int node, int l, int r, int v, int idx)
{
    if (l == r)
    {
        segtree[node] = v;
    }
    else
    {
        int mid = (l + r) / 2;
        if (idx <= mid)
        {
            update(2 * node + 1, l, mid, v, idx);
        }
        else
        {
            update(2 * node + 2, mid + 1, r, v, idx);
        }
        recalculate(node);
    }
}

int main()
{
    int n, m;
    scd(n);
    scd(m);
    int sze = 1;
    while (sze < m)
        sze *= 2;
    vector<lli> dish(n, 0LL);
    segtree = vector<lli>(2 * sze, 0LL);
    frange(i, n)
    {
        sclld(dish[i]);
    }
    sort(all(dish), greater<int>());

    int v;
    vec = vector<lli>(sze, 0LL);
    frange(i, m)
    {
        scd(vec[i]);
    }
    build(0, 0, sze - 1);
    int q;
    scd(q);
    vector<lli> og_segtree = segtree;
    vector<lli> og_dish = dish;
    frange(i, q)
    {

        int o, idx, x;
        scd(o);
        scd(idx);
        scd(x);
        if (o == 2)
        {
            update(0, 0, sze - 1, x, idx - 1);
        }
        else
        {
            dish[idx - 1] = x;
        }
        og_segtree = segtree;
        og_dish = dish;
        int id = 0;
        for (auto e : dish)
        {
            auto out = query(0, sze - 1, 0, int(e));
            int val = out.f;
            int pos = out.s - sze + 1;
            update(0, 0, sze - 1, 0, pos);
            if (out.s != 0)
            {
                dish[id] = 0;
            }
            ++id;
        }
        int val = *max_element(all(dish));
        if (val == 0)
            printf("-1\n");
        else
            printf("%d\n", val);
        segtree = og_segtree;
        dish = og_dish;
    }
}