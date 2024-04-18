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
    lli val = -1;
    lli lzst = 0;
    bool left = false;
    bool right = false;
    dat *lc, *rc;
};

void recalculate(dat *x)
{
    x->val = 0;
    if (x->left || x->lc != x)
    {
        x->val += x->lc->val;
    }
    if (x->right || x->rc != x)
    {
        x->val += x->rc->val;
    }
}

void pushdown(dat *x, int l, int mid, int r)
{
    if (x->lzst)
    {
        dat *lef, *rig;
        if (!x->left || x->lc == x)
        {
            x->lc = lef;
        }
        if (!x->right || x->rc == x)
        {
            x->rc = rig;
        }
        x->lc->lzst = x->lzst;
        x->rc->lzst = x->lzst;
        x->lc->val = (mid - l + 1) * x->lzst;
        x->rc->val = (r - mid) * x->lzst;
        x->lzst = 0;
    }
}

void setval(dat *x, int l, int r, int lx, int rx, lli v)
{
    if (r < lx || l > rx)
    {
        return;
    }
    if (lx <= l && r <= rx)
    {
        x->val = (r - l + 1) * v;
        x->lzst = v;
        return;
    }
    int mid = (l + r) / 2;
    pushdown(x, l, mid, r);
    setval(x->lc, l, mid, lx, rx, v);
    setval(x->rc, mid + 1, r, lx, rx, v);
    recalculate(x);
}

lli query(dat *x, int l, int r, int lx, int rx)
{
    if (x->val == -1)
    {
        return 0;
    }
    if (r < lx || l > rx)
    {
        return 0;
    }
    if (lx <= l && r <= rx)
    {
        return x->val;
    }
    int mid = (l + r) / 2;
    pushdown(x, l, mid, r);
    lli out = 0;
    if (x->left || x->lc != x)
    {
        out += query(x->lc, l, mid, lx, rx);
    }
    if (x->right || x->rc != x)
    {
        out += query(x->rc, mid + 1, r, lx, rx);
    }
    return out;
}

int main()
{
    int n, q;
    n = 1e9;
    scd(q);
    int sze = 1;
    while (sze < n)
        sze *= 2;
    lli c = 0;
    frange(_, q)
    {
        int typ;
        scd(typ);
        int l, r;
        scd(l);
        scd(r);
        l--;
        r--;
        l += c;
        r += c;
        dat *st;
        st->val = 0;
        st->lc = st;
        st->rc = st;
        if (typ == 1)
        {

            lli out = query(st, 0, sze - 1, l, r);
            c += out;
            printf("%lld\n", out);
        }
        else if (typ == 2)
        {
            setval(st, 0, sze - 1, l, r, 1);
        }
    }
}