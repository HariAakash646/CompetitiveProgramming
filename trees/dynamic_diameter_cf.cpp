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
vi path;
vb diam;
vi misze;
vi inc;

pii dfs(int x, int par)
{
    pii d = {x, 0};
    for (auto e : graph[x])
    {
        if (e != par)
        {
            pii v = dfs(e, x);
            if (v.s + 1 > d.s)
            {
                d.f = v.f;
                d.s = v.s + 1;
            }
        }
    }
    return d;
}

bool dfs2(int x, int v, int par)
{
    path.pb(x);
    if (x == v)
    {
        return true;
    }
    for (auto e : graph[x])
    {
        if (e != par)
        {
            bool out = dfs2(e, v, x);
            if (out)
                return true;
        }
    }
    path.pop_back();
    return false;
}

void dfs3(int x, int par, int d, int v)
{
    if (d >= v)
        inc[x] = 1;
    for (auto e : graph[x])
    {
        if (e != par && !diam[e])
        {
            dfs3(e, x, d + 1, v);
        }
    }
}

int main()
{
    int n;
    scd(n);

    graph = vvi(n + 1);

    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    pii v1 = dfs(1, 0);
    pii v2 = dfs(v1.f, 0);

    dfs2(v1.f, v2.f, 0);

    diam = vb(n + 1);
    for (auto e : path)
        diam[e] = true;

    misze = vi(n + 1);

    frange(i, path.size())
    {
        misze[path[i]] = min((int)path.size() - 1 - i, i);
    }

    inc = vi(n + 1);

    for (auto e : path)
    {
        dfs3(e, 0, 0, misze[e]);
    }

    forr(i, 1, n + 1)
    {
        printf("%d\n", v2.s + inc[i]);
    }
}