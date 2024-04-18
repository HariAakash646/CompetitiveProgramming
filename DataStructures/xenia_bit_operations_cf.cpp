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
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
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

vi vec;
vi seg;

void update(int node, bool orbool)
{
    if (orbool)
        seg[node] = seg[2 * node + 1] | seg[2 * node + 2];
    else
        seg[node] = seg[2 * node + 1] ^ seg[2 * node + 2];
}

void build(int l, int r, int node, bool orbool)
{
    if (l == r)
    {
        seg[node] = vec[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * node + 1, !orbool);
    build(mid + 1, r, 2 * node + 2, !orbool);
    update(node, orbool);
}

void query(int l, int r, int node, int pos, int v, bool orbool)
{
    if (l == r)
    {
        seg[node] = v;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
    {
        query(l, mid, 2 * node + 1, pos, v, !orbool);
    }
    else
    {
        query(mid + 1, r, 2 * node + 2, pos, v, !orbool);
    }
    update(node, orbool);
}

int main()
{
    int n, q;
    scd(n);
    scd(q);
    int len = pow(2, n);
    vec = vi(len);
    seg = vi(2 * len, 0);
    bool orbool = n % 2 == 1;
    frange(i, len)
    {
        scd(vec[i]);
    }
    build(0, len - 1, 0, orbool);
    frange(i, q)
    {
        int p, b;
        scd(p);
        scd(b);
        p--;
        query(0, len - 1, 0, p, b, orbool);
        printf("%d\n", seg[0]);
    }
}