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

void recalculate(int node)
{
    segtree[node] = segtree[2 * node + 1] + segtree[2 * node + 2];
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

lli query(int l, int r, int lx, int rx, int node)
{
    if (lx > r || rx < l)
        return 0;
    if (lx >= l && rx <= r)
        return segtree[node];
    int mid = (lx + rx) / 2;
    lli s1 = query(l, r, lx, mid, 2 * node + 1);
    lli s2 = query(l, r, mid + 1, rx, 2 * node + 2);
    return s1 + s2;
}

int main()
{
    int n, m;
    scd(n);
    scd(m);
    int sze = 1;
    while (sze < n)
        sze *= 2;
    segtree.assign(2 * sze, 0LL);
    int a;
    vec = vector<lli>(sze, 0LL);
    frange(i, n)
    {
        scd(vec[i]);
    }
    build(0, 0, sze - 1);
    int q, b, c;
    frange(i, m)
    {
        scd(q);
        scd(b);
        scd(c);
        if (q == 1)
        {
            update(0, 0, sze - 1, c, b - 1);
        }
        else
        {
            lli out = query(b - 1, c - 1, 0, sze - 1, 0);
            printf("%lld\n", out);
        }
    }
}