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
typedef long double ld;

struct dat
{
    lli val = 0;
    lli lzad = 0;
    lli lzst = 0;
};

vll vec;
vector<dat> seg;

void recalculate(int x)
{
    seg[x].val = seg[2 * x + 1].val + seg[2 * x + 2].val;
}

void pushdown(int x, int l, int mid, int r)
{
    int lc = 2 * x + 1;
    int rc = 2 * x + 2;
    if (seg[x].lzst)
    {
        seg[lc].lzst = seg[x].lzst;
        seg[rc].lzst = seg[x].lzst;
        seg[lc].val = (mid - l + 1) * seg[lc].lzst;
        seg[rc].val = (r - mid) * seg[rc].lzst;
        seg[lc].lzad = 0;
        seg[rc].lzad = 0;
        seg[x].lzst = 0;
    }
    else if (seg[x].lzad)
    {
        if (seg[lc].lzst)
        {
            seg[lc].lzst += seg[x].lzad;
            seg[lc].lzad = 0;
        }
        else
        {
            seg[lc].lzad += seg[x].lzad;
        }
        if (seg[rc].lzst)
        {
            seg[rc].lzst += seg[x].lzad;
            seg[rc].lzad = 0;
        }
        else
        {
            seg[rc].lzad += seg[x].lzad;
        }
        seg[lc].val += (mid - l + 1) * seg[x].lzad;
        seg[rc].val += (r - mid) * seg[x].lzad;
        seg[x].lzad = 0;
    }
}

void build(int x, int l, int r)
{
    if (l == r)
    {
        seg[x].val = vec[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * x + 1, l, mid);
    build(2 * x + 2, mid + 1, r);
    recalculate(x);
}

void setval(int x, int l, int r, int lx, int rx, lli v)
{
    if (r < lx || l > rx)
    {
        return;
    }
    if (lx <= l && r <= rx)
    {
        seg[x].val = (r - l + 1) * v;
        seg[x].lzst = v;
        seg[x].lzad = 0;
        return;
    }
    int mid = (l + r) / 2;
    pushdown(x, l, mid, r);
    setval(2 * x + 1, l, mid, lx, rx, v);
    setval(2 * x + 2, mid + 1, r, lx, rx, v);
    recalculate(x);
}

void addval(int x, int l, int r, int lx, int rx, lli v)
{
    if (r < lx || l > rx)
    {
        return;
    }
    if (lx <= l && r <= rx)
    {
        seg[x].val += (r - l + 1) * v;
        if (seg[x].lzst)
            seg[x].lzst += v;
        else
            seg[x].lzad += v;
        return;
    }
    int mid = (l + r) / 2;
    pushdown(x, l, mid, r);
    addval(2 * x + 1, l, mid, lx, rx, v);
    addval(2 * x + 2, mid + 1, r, lx, rx, v);
    recalculate(x);
}

lli query(int x, int l, int r, int lx, int rx)
{
    if (r < lx || l > rx)
    {
        return 0;
    }
    if (lx <= l && r <= rx)
    {
        return seg[x].val;
    }
    int mid = (l + r) / 2;
    pushdown(x, l, mid, r);
    return query(2 * x + 1, l, mid, lx, rx) + query(2 * x + 2, mid + 1, r, lx, rx);
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
        int l, r;
        scd(l);
        scd(r);
        l--;
        r--;
        if (typ == 1)
        {
            lli v;
            sclld(v);
            addval(0, 0, sze - 1, l, r, v);
        }
        else if (typ == 2)
        {
            lli v;
            sclld(v);
            setval(0, 0, sze - 1, l, r, v);
        }
        else
        {
            printf("%lld\n", query(0, 0, sze - 1, l, r));
        }
    }
}