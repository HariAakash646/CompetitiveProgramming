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

lli inf = 1e13;
vb vis;
vvi graph;
bool dfs(int node, int fin)
{
    if (node == fin)
        return true;
    vis[node] = true;
    for (auto e : graph[node])
    {
        if (!vis[e])
        {
            bool out = dfs(e, fin);
            if (out)
                return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    scd(n);
    scd(m);
    vector<tuple<int, int, int>> edges(m);
    graph = vvi(n + 1);
    int a, b, w;
    frange(i, m)
    {
        scd(a);
        scd(b);
        scd(w);
        edges[i] = {a, b, w};
        graph[a].pb(b);
    }
    vector<lli> dist(n + 1, -inf);
    dist[1] = 0;
    frange(i, n + 1)
    {
        for (auto e : edges)
        {
            tie(a, b, w) = e;
            if (i == n)
            {
                if (dist[a] + w > dist[b])
                {
                    vis = vb(n + 1, false);
                    bool out1 = dfs(1, b);
                    vis = vb(n + 1, false);
                    bool out2 = dfs(b, n);

                    if (out1 && out2)
                    {
                        printf("-1");
                        return 0;
                    }
                }
            }
            dist[b] = max(dist[b], dist[a] + w);
        }
    }
    printf("%lld", dist[n]);
}