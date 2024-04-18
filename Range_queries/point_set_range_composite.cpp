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

lli mod = 998244353;

struct func
{
    lli coeff, cons;
};

vector<func> vec;
vector<func> segtree;

func compute(func l, func r)
{
    func out;
    out.coeff = (l.coeff * r.coeff) % mod;
    out.cons = ((r.coeff * l.cons) % mod + r.cons) % mod;
    return out;
}

void recalculate(int x)
{
    // func l = segtree[2*x+1];
    // func r = segtree[2*x+2];
    // segtree[x].coeff = l.coeff * r.coeff;
    // segree[x].cons = r.coeff * l.cons + r.cons;
    segtree[x] = compute(segtree[2 * x + 1], segtree[2 * x + 2]);
}

void build(int x, int l, int r)
{
    if (l == r)
    {
        segtree[x] = vec[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * x + 1, l, mid);
    build(2 * x + 2, mid + 1, r);
    recalculate(x);
}

void update(int x, int l, int r, int id, func v)
{
    if (l == r)
    {
        segtree[x] = v;
        return;
    }
    int mid = (l + r) / 2;
    if (id <= mid)
    {
        update(2 * x + 1, l, mid, id, v);
    }
    else
    {
        update(2 * x + 2, mid + 1, r, id, v);
    }
    recalculate(x);
}

func query(int x, int l, int r, int li, int ri)
{
    if (li > r || ri < l)
    {
        func out;
        out.coeff = 1;
        out.cons = 0;
        return out;
    }

    if (li <= l && r <= ri)
    {
        return segtree[x];
    }
    int mid = (l + r) / 2;
    func f1 = query(2 * x + 1, l, mid, li, ri);
    func f2 = query(2 * x + 2, mid + 1, r, li, ri);
    return compute(f1, f2);
}

int main()
{
    int n, q;
    scd(n);
    scd(q);
    int sze = 1;
    while (sze < n)
        sze *= 2;
    vec = vector<func>(sze);
    frange(i, n)
    {
        sclld(vec[i].coeff);
        sclld(vec[i].cons);
    }
    forr(i, n, sze)
    {
        vec[i].coeff = 1;
        vec[i].cons = 1;
    }

    segtree = vector<func>(2 * sze);
    build(0, 0, sze - 1);

    frange(_, q)
    {
        int t;
        scd(t);
        if (t == 0)
        {
            int p;
            lli c, d;
            scd(p);
            sclld(c);
            sclld(d);
            func fu;
            fu.coeff = c;
            fu.cons = d;
            update(0, 0, sze - 1, p, fu);
        }
        else
        {
            int l, r;
            lli x;
            scd(l);
            scd(r);
            sclld(x);
            func fu = query(0, 0, sze - 1, l, r - 1);
            lli out = ((fu.coeff * x) % mod + fu.cons) % mod;
            printf("%lld\n", out);
        }
    }
}