#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
typedef long long int lli;
typedef vector<lli> vll;

struct dat
{
    lli sum = 0;
    lli pref = 0;
};

vll vec;
vector<dat> seg;

void recalculate(int x)
{
    seg[x].sum = seg[2 * x + 1].sum + seg[2 * x + 2].sum;
    seg[x].pref = max(seg[2 * x + 1].pref, seg[2 * x + 1].sum + seg[2 * x + 2].pref);
}

void build(int x, int l, int r)
{
    if (l == r)
    {
        seg[x].sum = vec[l];
        seg[x].pref = max(vec[l], 0LL);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * x + 1, l, mid);
    build(2 * x + 2, mid + 1, r);
    recalculate(x);
}

void update(int x, int l, int r, int idx, lli v)
{
    if (l == r)
    {
        seg[x].sum = v;
        seg[x].pref = max(v, 0LL);
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid)
    {
        update(2 * x + 1, l, mid, idx, v);
    }
    else
    {
        update(2 * x + 2, mid + 1, r, idx, v);
    }
    recalculate(x);
}

dat query(int x, int l, int r, int lx, int rx)
{
    if (r < lx || l > rx)
    {
        dat tmp;
        return tmp;
    }
    if (lx <= l && r <= rx)
    {
        return seg[x];
    }
    int mid = (l + r) / 2;
    dat d1 = query(2 * x + 1, l, mid, lx, rx);
    dat d2 = query(2 * x + 2, mid + 1, r, lx, rx);
    dat out;
    out.sum = d1.sum + d2.sum;
    out.pref = max(d1.pref, d1.sum + d2.pref);
    return out;
}

int main()
{
    int n, q;
    scd(n);
    scd(q);
    int sze = 1;
    while (sze < n)
        sze *= 2;
    vec = vll(sze + 1);
    forr(i, 0, n)
    {
        sclld(vec[i]);
    }
    seg = vector<dat>(2 * sze);
    build(0, 0, sze - 1);
    frange(_, q)
    {
        int typ;
        scd(typ);
        if (typ == 1)
        {
            int k;
            scd(k);
            k--;
            lli v;
            sclld(v);
            update(0, 0, sze - 1, k, v);
        }
        else if (typ == 2)
        {
            int l, r;
            scd(l);
            scd(r);
            l--;
            r--;
            dat ans = query(0, 0, sze - 1, l, r);
            printf("%lld\n", ans.pref);
        }
    }
}