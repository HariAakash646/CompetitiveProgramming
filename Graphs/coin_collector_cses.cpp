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

vvi graph, invg;
set<pii, greater<pii>> out;
vi tout;
int c = 0;
vb vis;
int id = 0;
vvi ans;
vll vec;
lli tot;

void dfs(int x)
{
    if (vis[x])
        return;
    vis[x] = true;
    for (auto e : graph[x])
    {
        dfs(e);
    }
    out.insert({c, x});
    tout[x] = c;
    c++;
}

void dfs2(int x)
{
    if (vis[x])
        return;
    vis[x] = true;
    ans[id].pb(x);
    tot += vec[x];
    for (auto e : invg[x])
    {

        dfs2(e);
    }
    out.erase({tout[x], x});
}

int main()
{
    int n, m;
    scd(n);
    scd(m);

    invg = graph = vvi(n + 1);

    vec = vll(n + 1);
    forr(i, 1, n + 1) sclld(vec[i]);

    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        invg[b].pb(a);
    }
    tout = vi(n + 1);
    vis = vb(n + 1);
    forr(i, 1, n + 1)
    {
        if (!vis[i])
            dfs(i);
    }

    vis = vb(n + 1);
    vll val;
    while (out.size())
    {
        auto p = *out.begin();
        ans.pb({});
        tot = 0;
        dfs2(p.s);
        val.pb(tot);
        id++;
    }
    int k = ans.size();
    vector<seti> graph2(k);
    vi comp(n + 1);
    vi indeg(k);
    frange(i, k)
    {
        sort(all(ans[i]));
        for (auto e : ans[i])
            comp[e] = i;
    }
    frange(i, k)
    {
        for (auto e : ans[i])
        {
            for (auto x : graph[e])
            {
                if (!binary_search(all(ans[i]), x) && graph2[i].find(comp[x]) == graph2[i].end())
                {
                    graph2[i].insert(comp[x]);
                    indeg[comp[x]]++;
                }
            }
        }
    }
    vi topo;
    queue<int> q;
    frange(i, k)
    {
        if (indeg[i] == 0)
            q.push(i);
    }
    while (q.size())
    {
        auto x = q.front();
        q.pop();
        topo.pb(x);
        for (auto e : graph2[x])
        {
            indeg[e]--;
            if (indeg[e] == 0)
                q.push(e);
        }
    }
    vi pos(k);
    frange(i, k)
    {
        pos[topo[i]] = i;
    }
    vll dp(k);
    for (int i = k - 1; i >= 0; i--)
    {
        lli ma = 0;
        int x = topo[i];
        for (auto e : graph2[x])
            ma = max(ma, dp[e]);
        dp[x] = ma + val[x];
    }
    printf("%lld", *max_element(all(dp)));
}