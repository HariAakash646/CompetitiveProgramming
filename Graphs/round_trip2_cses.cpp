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

vi topo;
vvi graph;
vb vis, onstk;
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
}
vi cycle;
int match;
bool done = false;
bool cycle_dfs(int node)
{
    onstk[node] = true;
    vis[node] = true;
    for (auto e : graph[node])
    {
        if (onstk[e])
        {
            cycle = {e, node};
            match = e;
            return true;
        }
        else if (!vis[e])
        {
            bool out = cycle_dfs(e);
            if (out == true)
            {
                if (!done)
                {
                    cycle.pb(node);
                    if (match == node)
                    {
                        done = true;
                    }
                }
                return out;
            }
        }
    }
    onstk[node] = false;
    return false;
}

int main()
{
    scd(n);
    scd(m);
    graph = vvi(n + 1);
    vis = vb(n + 1, false);
    onstk = vb(n + 1, false);
    int a, b;
    frange(i, m)
    {
        scd(a);
        scd(b);
        graph[a].pb(b);
    }
    topo_sort();
    reverse(all(topo));
    vi idx(n + 1);
    frange(i, n)
    {
        idx[topo[i]] = i;
    }
    bool out = false;
    forr(i, 1, n + 1, 1)
    {
        for (auto e : graph[i])
        {
            if (idx[e] < idx[i])
            {
                vis = vb(n + 1, false);
                forr(j, 1, n + 1, 1)
                {
                    if (!vis[j])
                    {
                        out = cycle_dfs(j);
                        if (out)
                        {

                            reverse(all(cycle));
                            int c = cycle.size();

                            printf("%d\n", c);
                            for (auto k : cycle)
                            {
                                printf("%d ", k);
                            }
                            return 0;
                        }
                    }
                }
            }
        }
    }
    printf("IMPOSSIBLE");
}