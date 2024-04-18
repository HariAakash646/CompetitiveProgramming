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
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

vb vis;
seti curr;

bool cycle(int x, vvi &graph)
{
    if (curr.find(x) != curr.end())
    {
        return true;
    }
    if (vis[x])
        return false;
    vis[x] = true;
    curr.insert(x);
    for (auto e : graph[x])
    {
        bool out = cycle(e, graph);
        if (out)
            return out;
    }
    return false;
}

int main()
{

    // freopen("milkorder.in", "r", stdin);
    // freopen("milkorder.out", "w", stdout);
    int n, m;
    scd(n);
    scd(m);
    vvi graph(n + 1);

    vvi vec(m);
    frange(i, m)
    {
        int a;
        scd(a);
        vec[i] = vi(a);
        frange(j, a) scd(vec[i][j]);
    }

    int l = 0;
    int h = m;

    while (l != h)
    {
        int mid = (l + h + 1) / 2;
        vis = vb(n + 1);
        vvi gr(n + 1);
        frange(i, mid)
        {
            frange(j, vec[i].size() - 1)
            {
                gr[vec[i][j]].pb(vec[i][j + 1]);
            }
        }
        bool cyc = false;
        forr(i, 1, n + 1)
        {
            if (!vis[i])
            {
                curr = {};
                bool out = cycle(i, gr);
                if (out)
                {
                    cyc = true;
                    break;
                }
            }
        }
        if (cyc)
        {
            h = mid - 1;
        }
        else
            l = mid;
    }
    // printf("%d\n", l);
    vi indeg(n + 1);
    vvi ingraph(n + 1);
    frange(i, l)
    {
        frange(j, vec[i].size() - 1)
        {
            graph[vec[i][j]].pb(vec[i][j + 1]);
            indeg[vec[i][j + 1]]++;
            ingraph[vec[i][j + 1]].pb(vec[i][j]);
        }
    }

    seti q;
    vi topo;
    forr(i, 1, n + 1)
    {
        if (indeg[i] == 0)
            q.insert(i);
    }
    while (q.size())
    {
        int p = *q.begin();
        q.erase(q.begin());
        topo.pb(p);
        for (auto e : graph[p])
        {
            indeg[e]--;
            // printf("%d %d %d\n", p.s, e, ma[e]);
            if (indeg[e] == 0)
            {
                q.insert(e);
            }
        }
    }

    frange(i, topo.size() - 1)
        printf("%d ", topo[i]);
    printf("%d", topo[topo.size() - 1]);
}