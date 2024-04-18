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

vi vec;
vi seg1;
vi seg2;

void recalculate(int x)
{
    seg1[x] = min(seg1[2 * x + 1], seg1[2 * x + 2]);
    seg2[x] = min(seg2[2 * x + 1], seg2[2 * x + 2]);
}

void build(int x, int l, int r)
{
    if (l == r)
    {
        seg1[x] = vec[l] + l;
        seg2[x] = vec[l] - l;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * x + 1, l, mid);
    build(2 * x + 2, mid + 1, r);
    recalculate(x);
}

void update(int x, int l, int r, int id, int v)
{
    if (l == r)
    {
        seg1[x] = v + id;
        seg2[x] = v - id;
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

int query(int x, int l, int r, int lx, int rx, vi &seg)
{
    if (lx > r || rx < l)
    {
        return 1e9;
    }
    if (lx <= l && r <= rx)
    {
        return seg[x];
    }
    int mid = (l + r) / 2;
    int m1 = query(2 * x + 1, l, mid, lx, rx, seg);
    int m2 = query(2 * x + 2, mid + 1, r, lx, rx, seg);
    return min(m1, m2);
}

int main()
{
    int n, q;
    scd(n);
    scd(q);
    int sze = 1;
    while (sze < n)
    {
        sze *= 2;
    }
    vec = vi(sze, 1e9);
    frange(i, n)
    {
        scd(vec[i]);
    }
    seg1 = vi(2 * sze);
    seg2 = vi(2 * sze);
    build(0, 0, sze - 1);
    frange(_, q)
    {
        int t;
        scd(t);
        if (t == 1)
        {
            int k, v;
            scd(k);
            scd(v);
            k--;
            update(0, 0, sze - 1, k, v);
        }
        else
        {
            int k;
            scd(k);
            k--;
            int m1 = query(0, 0, sze - 1, 0, k, seg2) + k;
            int m2 = query(0, 0, sze - 1, k + 1, n - 1, seg1) - k;
            printf("%d\n", min(m1, m2));
        }
    }
}