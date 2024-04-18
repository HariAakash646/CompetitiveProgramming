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

vvi graph;
vb vis;
vvi dist;

void dfs(int x, int itr)
{
    vis[x] = true;
    int c = 1;
    for (auto e : graph[x])
    {
        if (!vis[e])
        {
            dfs(e, itr);
            c += dist[itr][e];
            dist[itr][e] = 0;
        }
    }
    dist[itr][x] = c;
}

bool findf(int x, int v)
{
    if (v == x)
    {
        return true;
    }
    vis[x] = true;
    for (auto e : graph[x])
    {
        if (!vis[e])
        {
            bool out = findf(e, v);
            if (out)
                return true;
        }
    }
    return false;
}

int main()
{
    int n, d;
    scd(n);
    scd(d);
    graph = vvi(n + 1);
    dist = vvi(d, vi(n + 1));
    vii quer(d);
    frange(i, d)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
        vis = vb(n + 1, false);
        quer[i] = {a, b};
        forr(j, 1, n + 1)
        {
            if (!vis[j])
                dfs(j, i);
        }
        // printf("%d\n", ans - 1);
    }
    graph = vvi(n + 1);
    int c = 1;
    frange(i, d)
    {
        int a = quer[i].f;
        int b = quer[i].s;
        vis = vb(n + 1, false);

        if (findf(a, b))
        {
            c++;
        }
        graph[a].pb(b);
        graph[b].pb(a);
        sort(all(dist[i]), greater<int>());
        int out = 0;
        frange(j, c)
        {
            out += dist[i][j];
        }
        printf("%d\n", out - 1);
    }
}