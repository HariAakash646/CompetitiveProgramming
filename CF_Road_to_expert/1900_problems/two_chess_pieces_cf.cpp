#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
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

vvi graph;
seti v1, v2;
vb vis1, vis2;

vvi lift;

int binlift(int x, int c)
{
    frange(i, 21)
    {
        if (c & (1 << i))
        {
            x = lift[i][x];
        }
    }
    return x;
}

void dfs(int x, int p)
{
    lift[0][x] = p;
    for (auto e : graph[x])
    {
        if (e != p)
        {
            dfs(e, x);
        }
    }
}

void dfs2(int x, int p, seti &v, vb &vis)
{

    if (v.find(x) != v.end())
    {
        int v = x;
        while (!vis[v])
        {
            vis[v] = true;
            v = lift[0][v];
        }
    }

    for (auto e : graph[x])
    {
        if (e != p)
        {
            dfs2(e, x, v, vis);
        }
    }
}

int main()
{
    int n, d;
    scd(n);
    scd(d);

    graph = vvi(n + 1);

    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    int m1, m2;
    scd(m1);

    frange(i, m1)
    {
        int a;
        scd(a);
        v1.insert(a);
    }

    scd(m2);

    frange(i, m2)
    {
        int a;
        scd(a);
        v2.insert(a);
    }

    lift = vvi(21, vi(n + 1));

    dfs(1, 1);

    forr(i, 1, 21)
    {
        forr(j, 1, n + 1)
        {
            lift[i][j] = lift[i - 1][lift[i - 1][j]];
        }
    }

    for (auto e : v1)
    {
        v2.insert(binlift(e, d));
    }
    for (auto e : v2)
    {
        v1.insert(binlift(e, d));
    }
    vis1 = vis2 = vb(n + 1);

    dfs2(1, 0, v1, vis1);
    dfs2(1, 0, v2, vis2);
    int c = 0;
    forr(i, 1, n + 1)
    {
        c += vis1[i] + vis2[i];
    }
    printf("%d", 2 * (c - 2));
}