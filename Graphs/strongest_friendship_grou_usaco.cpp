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

vi disset, sze, cnt;

int findf(int x)
{
    while (x != disset[x])
    {
        x = disset[x];
    }
    return x;
}

int unionf(int x, int y)
{
    x = findf(x);
    y = findf(y);
    if (x == y)
        return cnt[x];
    if (sze[x] < sze[y])
    {
        swap(x, y);
    }
    disset[y] = x;
    sze[x] = max(sze[x], sze[y] + 1);
    cnt[x] += cnt[y];
    return cnt[x];
}

int main()
{
    int n, m;
    scd(n);
    scd(m);
    vvi graph(n + 1);
    vii deg(n + 1);
    forr(i, 1, n + 1) deg[i].s = i;
    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        deg[a].f++;
        deg[b].f++;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vi order, degrees;
    set<pii> vert;
    forr(i, 1, n + 1) vert.insert(mp(deg[i].f, i));
    vb vis(n + 1);
    frange(i, n)
    {
        auto p = *vert.begin();
        vis[p.s] = true;
        order.pb(p.s);
        degrees.pb(deg[p.s].f);
        for (auto e : graph[p.s])
        {
            if (!vis[e])
            {
                vert.erase(mp(deg[e].f, e));
                deg[e].f--;
                vert.insert(mp(deg[e].f, e));
            }
        }
        vert.erase({deg[p.s].f, p.s});
    }
    reverse(all(order));
    reverse(all(degrees));
    disset = sze = cnt = vi(n + 1, 1);
    forr(i, 0, n + 1) disset[i] = i;
    lli ans = 0;
    vis = vb(n + 1);
    forr(i, 0, n)
    {
        pii p = {degrees[i], order[i]};
        lli ma = 0;
        vis[p.s] = true;
        for (auto e : graph[p.s])
        {
            if (vis[e])
                ma = max(ma, lli(unionf(e, p.s)));
        }
        ans = max(ans, ma * p.f);
    }
    printf("%lld", ans);
}