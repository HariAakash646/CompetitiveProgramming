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
vi st;
vii pris;

vvi lift;
vector<vb> liftp;
vi depth;

void dfs(int x, int p, int d)
{
    depth[x] = d;
    lift[0][x] = p;
    if (!st[x] || !st[p])
        liftp[0][x] = true;
    else
        liftp[0][x] = false;

    for (auto e : graph[x])
    {
        if (e != p)
        {
            dfs(e, x, d + 1);
        }
    }
}

pair<bool, int> binlift(int x, int c)
{
    bool out = false;
    forr(i, 0, 20)
    {
        if (c & (1 << i))
        {
            out = out || liftp[i][x];
            x = lift[i][x];
        }
    }
    return mp(out, x);
}

bool lca(int u, int v)
{
    if (depth[u] > depth[v])
        swap(u, v);
    auto out = binlift(v, depth[v] - depth[u]);
    bool o = out.f;
    v = out.s;
    if (u == v)
        return o;
    for (int i = 19; i >= 0; i--)
    {
        int x = lift[i][u];
        int y = lift[i][v];
        if (x != y)
        {
            o = o || liftp[i][u];
            o = o || liftp[i][v];
            u = x;
            v = y;
        }
    }
    return o || liftp[0][u] || liftp[0][v];
}

vb vis;

void dfs2(int x, int y, int p)
{
    vis[x] = true;
    if (x == y)
        return;
    for (auto e : graph[x])
    {
        if (e != p)
        {
            dfs2(e, y, x);
        }
    }
}

int main()
{
    int q;
    scd(q);
    frange(_, q)
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

        int m;
        scd(m);
        pris = vii(m);
        st = vi(n + 1);
        st[0] = -1;
        frange(i, m)
        {
            int a, b;
            scd(a);
            scd(b);
            st[a] = b;
            pris.pb(mp(a, b));
        }
        // lift = vvi(20, vi(n+1));
        // liftp = vector<vb>(20, vb(n+1));

        // dfs(1, 0, 0);

        // forr(i, 1, 20) {
        //     forr(j, 1, n+1) {
        //         lift[i][j] = lift[i-1][lift[i-1][j]];
        //         liftp[i][j] = liftp[i-1][j] || liftp[i-1][lift[i-1][j]];
        //     }
        // }
        vector<seti> val(m);
        bool done = true;
        frange(j, m)
        {
            auto p = pris[j];
            vis = vb(n + 1);
            dfs2(p.f, p.s, 0);
            for (auto e : pris)
            {
                if (e != p)
                {
                    if (vis[e.f] && vis[e.s])
                        done = false;
                }
            }
            frange(i, m)
            {
                auto e = pris[i];
                if (e != p)
                {
                    if (val[i].find(j) != val[j].end())
                        done = false;
                    if (vis[e.f])
                        val[j].insert(i);
                }
            }
        }
        if (done)
            printf("YES\n");
        else
            printf("NO\n");
    }
}