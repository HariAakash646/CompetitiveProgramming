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

vector<vi> graph;
vi col;
vb vis;

bool dfs(int x, int c)
{
    if (vis[x])
    {
        if (col[x] == c)
            return true;
        else
            return false;
    }
    vis[x] = true;
    col[x] = c;
    for (auto e : graph[x])
    {
        bool out = dfs(e, !c);
        if (!out)
            return out;
    }
    return true;
}

int main()
{
    int n, m;
    scd(n);
    scd(m);

    graph = vector<vi>(n + 1);
    vector<pair<pii, int>> edges(m);
    frange(i, m)
    {
        int a, b;
        int t;
        scd(t);
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
        edges[i] = mp(mp(a, b), t);
    }
    vis = vb(n + 1);
    col = vi(n + 1);
    bool out = dfs(1, 0);

    if (!out)
    {
        printf("NO");
        return 0;
    }

    vvi dirg(n + 1);

    vi indeg(n + 1);

    for (auto p : edges)
    {
        if (p.s == 1)
        {
            if (col[p.f.s])
            {
                swap(p.f.f, p.f.s);
            }
            indeg[p.f.s]++;
            dirg[p.f.f].pb(p.f.s);
        }
        else
        {
            if (col[p.f.s])
            {
                swap(p.f.f, p.f.s);
            }
            indeg[p.f.f]++;
            dirg[p.f.s].pb(p.f.f);
        }
    }

    vi topo;
    queue<int> q;

    forr(i, 1, n + 1)
    {
        if (indeg[i] == 0)
            q.push(i);
    }

    while (q.size())
    {
        auto p = q.front();
        q.pop();
        topo.pb(p);
        for (auto e : dirg[p])
        {
            indeg[e]--;
            if (indeg[e] <= 0)
                q.push(e);
        }
        // if (topo.size() > n)
        // {
        //     printf("NO");
        //     return 0;
        // }
    }

    if (topo.size() != n)
    {
        printf("NO\n");
        return 0;
    }

    vi outv(n + 1);
    int v = -1e9;
    for (auto e : topo)
    {
        outv[e] = v;
        v++;
    }
    printf("YES\n");
    forr(i, 1, n + 1)
    {
        if (col[i] == 0)
            printf("R ");
        else
            printf("L ");
        printf("%d\n", outv[i]);
    }
}