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

vll segtree;
vii vec;

void recalculate(int x)
{
    segtree[x] = max(segtree[2 * x + 1], segtree[2 * x + 2]);
}

void update(int x, int l, int r, int id, lli v)
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

lli query(int x, int l, int r, int lx, int rx)
{
    if (lx <= l && r <= rx)
    {
        return segtree[x];
    }
    if (lx > r || rx < l)
    {
        return 0;
    }
    int mid = (l + r) / 2;
    return max(query(2 * x + 1, l, mid, lx, rx), query(2 * x + 2, mid + 1, r, lx, rx));
}

int main()
{
    int n;
    scd(n);

    int sze = 1;
    while (sze < n)
        sze *= 2;
    vec = vii(sze);
    segtree = vll(2 * sze);

    frange(i, n) scd(vec[i].f);
    frange(i, n) scd(vec[i].s);

    vll dp(n);
    frange(i, n)
    {
        dp[i] = query(0, 0, n - 1, 0, vec[i].f - 1) + vec[i].s;
        update(0, 0, n - 1, vec[i].f - 1, dp[i]);
    }
    printf("%lld", *max_element(all(dp)));
}