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

vi disset, sze;
vector<vii> graph;
vvi lift, liftma;
vi depth;

int findf(int x)
{
    while (x != disset[x])
    {
        x = disset[x];
    }
    return x;
}

void unionf(int x, int y, int v)
{
    int x1 = x;
    int y1 = y;
    x = findf(x);
    y = findf(y);
    if (x == y)
        return;
    if (sze[x] < sze[y])
    {
        swap(x, y);
    }
    disset[y] = x;
    sze[x] = max(sze[x], sze[y] + 1);
    graph[x1].pb({y1, v});
    graph[y1].pb({x1, v});
}

void dfs(int x)
{

    forr(i, 1, 20)
    {
        lift[x][i] = lift[lift[x][i - 1]][i - 1];
        liftma[x][i] = max(liftma[x][i - 1], liftma[lift[x][i - 1]][i - 1]);
    }
    for (auto e : graph[x])
    {
        if (e.f != lift[x][0])
        {
            depth[e.f] = depth[x] + 1;
            liftma[e.f][0] = e.s;
            lift[e.f][0] = x;
            dfs(e.f);
        }
    }
}

int liftup(int a, int x)
{
    frange(i, 20)
    {
        if (x & (1 << i))
        {
            a = lift[a][i];
        }
    }
    return a;
}

int findmax(int a, int x)
{
    int ma = 0;
    frange(i, 20)
    {
        if (x & (1 << i))
        {
            ma = max(ma, liftma[a][i]);
            a = lift[a][i];
        }
    }
    return ma;
}

int query(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    int ma = findmax(a, depth[a] - depth[b]);
    a = liftup(a, depth[a] - depth[b]);
    if (a == b)
        return ma;

    for (int i = 19; i >= 0; i--)
    {
        if (lift[a][i] != lift[b][i])
        {
            ma = max(ma, liftma[a][i]);
            ma = max(ma, liftma[b][i]);
            a = lift[a][i];
            b = lift[b][i];
        }
    }
    ma = max(ma, liftma[a][0]);
    ma = max(ma, liftma[b][0]);

    return ma;
}

int main()
{
    int n, m, q;
    scd(n);
    scd(m);
    scd(q);

    set<pair<int, pii>> edges;

    forr(i, 1, m + 1)
    {
        int a, b;
        scd(a);
        scd(b);
        edges.insert(mp(i, mp(a, b)));
    }

    graph = vector<vii>(n + 1);
    disset = sze = vi(n + 1);

    forr(i, 1, n + 1) disset[i] = i;

    for (auto e : edges)
    {
        unionf(e.s.f, e.s.s, e.f);
    }

    liftma = lift = vvi(n + 1, vi(20));
    depth = vi(n + 1);
    depth[1] = 1;
    vb vis(n + 1);
    forr(i, 1, n + 1)
    {
        if (!vis[findf(i)])
        {
            vis[findf(i)] = true;
            dfs(i);
        }
    }

    frange(i, q)
    {
        int a, b;
        scd(a);
        scd(b);
        if (findf(a) != findf(b))
            printf("-1\n");
        else
            printf("%d\n", query(a, b));
    }
}