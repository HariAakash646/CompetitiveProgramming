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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vvi graph;
vector<vii> graphid;
vb vis;
set<pii> bridge;
vi lo, tin;
int timer = 1;

void dfs(int x, int par)
{
    lo[x] = tin[x] = timer++;
    for (auto e : graph[x])
    {
        if (e == par)
        {
            continue;
        }
        if (tin[e])
        {
            lo[x] = min(lo[x], tin[e]);
        }
        else
        {
            dfs(e, x);
            lo[x] = min(lo[x], lo[e]);
            if (lo[e] > tin[x])
            {
                bridge.insert({x, e});
            }
        }
    }
}

vvi comp;
vi curr;

void con(int x)
{
    curr.pb(x);
    vis[x] = true;
    for (auto e : graph[x])
    {
        if (!vis[e] && bridge.find({x, e}) == bridge.end() && bridge.find({e, x}) == bridge.end())
        {
            con(e);
        }
    }
}

vii edges;
vii out;

void dfsdir(int x, int par)
{
    vis[x] = true;
    for (auto p : graphid[x])
    {
        int e = p.f;
        if (e == par || out[p.s] != mp(0, 0))
            continue;
        if (bridge.find({x, e}) == bridge.end() && bridge.find({e, x}) == bridge.end())
        {
            out[p.s] = {x, e};
        }
        else
        {
            out[p.s] = {e, x};
        }
        if (!vis[e])
            dfsdir(e, x);
    }
}

int main()
{
    fastio();
    int n, m;
    cin >> n >> m;
    graph = vvi(n + 1);
    vis = vb(n + 1);
    graphid = vector<vii>(n + 1);
    frange(i, m)
    {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
        graphid[a].pb({b, i});
        graphid[b].pb({a, i});
        edges.pb({a, b});
    }
    lo = tin = vi(n + 1);
    dfs(1, 0);
    vis = vb(n + 1);
    int ma = 0;
    int mid = 0;
    forr(i, 1, n + 1)
    {
        if (!vis[i])
        {
            curr = {};
            con(i);
            comp.pb(curr);
            if (curr.size() > ma)
            {
                ma = curr.size();
                mid = comp.size() - 1;
            }
        }
    }
    // for (auto p : bridge)
    //     cout << p.f << " " << p.s << "\n";
    vis = vb(n + 1);
    out = vii(m);
    // cout << comp[mid][0] << " ";
    dfsdir(comp[mid][0], 0);
    cout << ma << "\n";
    for (auto p : out)
    {
        cout << p.f << " " << p.s << "\n";
    }
}