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

vvi graph;
vb vis;
int ma, mi;
int tot;
lli outeve, outodd;

void dfs1(int node)
{
    if (vis[node])
        return;
    vis[node] = true;
    ma = max(ma, node);
    mi = min(mi, node);
    tot++;
    for (auto e : graph[node])
    {
        dfs1(e);
    }
}

void dfs2(int node, int l, int type)
{
    if (vis[node])
        return;
    vis[node] = true;
    if (type == 0)
        outeve += l;
    else
        outodd += l;
    for (auto e : graph[node])
    {
        dfs2(e, l + 1, type);
    }
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n, m;
        scd(n);
        scd(m);
        graph = vvi(n + 1);
        vis = vb(n + 1, false);
        frange(i, m)
        {
            int u, v;
            scd(u);
            scd(v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        vii root;
        forr(i, 1, n + 1)
        {
            if (!vis[i])
            {
                ma = i;
                mi = i;
                tot = 0;
                dfs1(i);
                if (tot % 2 == 0)
                    root.pb({mi, 0});
                else
                    root.pb({ma, 1});
            }
        }
        vis = vb(n + 1, false);
        outeve = 0;
        outodd = 0;
        for (auto e : root)
        {
            dfs2(e.f, 1, e.s);
        }
        printf("%lld %lld\n", outeve, outodd);
    }
}