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

vi seg;

void recalculate(int x)
{
    seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
}

void build(int x, int l, int r)
{
    if (l == r)
    {
        seg[x] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * x + 1, l, mid);
    build(2 * x + 2, mid + 1, r);
    recalculate(x);
}

int query(int x, int l, int r, int v)
{
    if (l == r)
    {
        return l;
    }
    int mid = (l + r) / 2;
    int out;
    if (seg[2 * x + 1] >= v)
    {
        out = query(2 * x + 1, l, mid, v);
    }
    else
    {
        out = query(2 * x + 2, mid + 1, r, v - seg[2 * x + 1]);
    }
    return out;
}

void update(int x, int l, int r, int id)
{
    if (l == r)
    {
        seg[x] = 0;
        return;
    }
    int mid = (l + r) / 2;
    if (id <= mid)
    {
        update(2 * x + 1, l, mid, id);
    }
    else
    {
        update(2 * x + 2, mid + 1, r, id);
    }
    recalculate(x);
}

int main()
{
    int n;
    scd(n);
    vi vec(n);
    frange(i, n)
    {
        scd(vec[i]);
    }
    int sze = 1;
    while (sze < n)
        sze *= 2;
    seg = vi(2 * sze);
    build(0, 0, sze - 1);
    frange(i, n)
    {
        int a;
        scd(a);
        int id = query(0, 0, sze - 1, a);
        update(0, 0, sze - 1, id);
        printf("%d ", vec[id]);
    }
}