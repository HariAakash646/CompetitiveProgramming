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

int n, m;
vvi graph;
vvi tree;
vi lvl;
vii out;
vb eve;
vb vis;

void dfs(int x, int prev)
{
    vis[x] = true;
    lvl[x] = lvl[prev] + 1;
    for (auto e : graph[x])
    {
        if (e == prev)
            continue;
        if (lvl[e])
        {
            if (lvl[e] < lvl[x])
            {
                out.pb(mp(x, e));
                eve[x] = !eve[x];
            }
            // else
            // {
            //     out.pb(mp(e, x));
            //     eve[e] = !eve[e];
            // }
        }
        else
        {
            dfs(e, x);
            tree[x].pb(e);
            tree[e].pb(x);
        }
    }
}

void dfs2(int x, int prev)
{
    for (auto e : tree[x])
    {
        if (e != prev)
        {
            dfs2(e, x);
            if (eve[e])
            {
                out.pb({x, e});
                eve[x] = !eve[x];
            }
            else
            {
                eve[e] = !eve[e];
                out.pb({e, x});
            }
        }
    }
}

int main()
{
    scd(n);
    scd(m);
    graph = vvi(n + 1);

    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    lvl = vi(n + 1);
    eve = vb(n + 1, true);
    tree = vvi(n + 1);
    vis = vb(n + 1);
    forr(i, 1, n + 1)
    {
        if (!vis[i])
        {
            dfs(i, 0);
            dfs2(i, 0);
            if (!eve[i])
            {
                printf("IMPOSSIBLE");
                return 0;
            }
        }
    }

    for (auto p : out)
    {
        printf("%d %d\n", p.f, p.s);
    }
}