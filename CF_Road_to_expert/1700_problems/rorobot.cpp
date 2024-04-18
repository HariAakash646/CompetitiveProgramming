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

lli query(int l, int r, int lx, int rx, int node)
{
    if (lx > r || rx < l)
        return 0;
    if (lx >= l && rx <= r)
        return segtree[node];
    int mid = (lx + rx) / 2;
    lli s1 = query(l, r, lx, mid, 2 * node + 1);
    lli s2 = query(l, r, mid + 1, rx, 2 * node + 2);
    return max(s1, s2);
}

int main()
{
    int n, m;
    scd(n);
    scd(m);
    int sze = 1;
    while (sze < m)
        sze *= 2;
    segtree = vll(2 * sze);
    vec = vll(m);
    frange(i, m)
    {
        scd(vec[i]);
    }
    build(0, 0, m - 1);
    int q;
    scd(q);
    frange(_, q)
    {
        int xs, ys, xf, yf, k;
        scd(xs);
        scd(ys);
        scd(xf);
        scd(yf);
        scd(k);
        int ma = query(min(ys, yf) - 1, max(ys, yf) - 1, 0, m - 1, 0);
        if (abs(ys - yf) % k == 0 && abs(xs - xf) % k == 0 && (n - (n - xs) % k) > ma && (n - (n - xf) % k) > ma)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}