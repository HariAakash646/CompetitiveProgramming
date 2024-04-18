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
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

vi vec;

struct dat
{
    lli pref, suf, sum, ma;
};

dat make_data(int val)
{
    dat res;
    res.sum = val;
    res.pref = res.suf = res.ma = max(0, val);
    return res;
}

void recalculate(vector<dat> &segtree, int node)
{
    int l = 2 * node + 1;
    int r = 2 * node + 2;
    segtree[node].sum = segtree[l].sum + segtree[r].sum;
    segtree[node].ma = max({segtree[l].ma, segtree[r].ma, segtree[l].suf + segtree[r].pref});
    segtree[node].pref = max(segtree[l].pref, segtree[l].sum + segtree[r].pref);
    segtree[node].suf = max(segtree[r].suf, segtree[r].sum + segtree[l].suf);
}

void build(vector<dat> &segtree, int node, int l, int r)
{
    if (l == r)
    {
        segtree[node] = make_data(vec[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(segtree, 2 * node + 1, l, mid);
    build(segtree, 2 * node + 2, mid + 1, r);
    recalculate(segtree, node);
}

void update(vector<dat> &segtree, int node, int l, int r, int pos, int v)
{
    if (l == r)
    {
        segtree[node] = make_data(v);
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
    {
        update(segtree, 2 * node + 1, l, mid, pos, v);
    }
    else
    {
        update(segtree, 2 * node + 2, mid + 1, r, pos, v);
    }
    recalculate(segtree, node);
}

int main()
{
    int n, m;
    scd(n);
    scd(m);

    int sz = 1;
    while (sz < n)
        sz *= 2;

    vec = vi(n);
    vector<dat> segtree(2 * sz);

    frange(i, n)
    {
        scd(vec[i]);
    }
    build(segtree, 0, 0, n - 1);
    frange(_, m)
    {
        int k, v;
        scd(k);
        scd(v);
        update(segtree, 0, 0, n - 1, k - 1, v);
        printf("%lld\n", segtree[0].ma);
    }
}