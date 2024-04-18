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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
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

vi topo, dist;
vvi graph, ingraph;
vb vis;
int n, m;

void dfs(int node)
{
    vis[node] = true;
    for (auto e : graph[node])
    {
        if (!vis[e])
        {
            dfs(e);
        }
    }
    topo.pb(node);
}

void topo_sort()
{
    forr(i, 1, n + 1, 1)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    reverse(all(topo));
}

void path(int n, vi &out)
{
    out.pb(n);
    for (auto e : ingraph[n])
    {
        if (dist[e] == dist[n] - 1)
        {
            if (e == 1)
            {
                out.pb(e);
                break;
            }
            path(e, out);
            break;
        }
    }
}

int main()
{
    scd(n);
    scd(m);
    graph = vvi(n + 1);
    ingraph = vvi(n + 1);
    vis = vb(n + 1, false);
    dist = vi(n + 1, 0);
    int a, b;
    frange(i, m)
    {
        scd(a);
        scd(b);
        graph[a].pb(b);
        ingraph[b].pb(a);
    }
    topo_sort();
    auto beg = find(all(topo), 1);
    dist[1] = 1;
    beg++;
    while (beg != topo.end())
    {
        int maxi = 0;
        for (auto e : ingraph[*beg])
        {
            maxi = max(maxi, dist[e] + 1);
        }
        dist[*beg] = maxi;
        beg++;
    }
    if (dist[n] == 0)
    {
        printf("IMPOSSIBLE");
    }
    else
    {
        vi out = {};
        printf("%d\n", dist[n]);
        path(n, out);
        reverse(all(out));
        for (auto e : out)
        {
            printf("%d ", e);
        }
    }
}