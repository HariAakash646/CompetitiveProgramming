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

int n, m;
vector<vi> graph;
vector<pair<lli, pii>> edges;
vb vis;

void dfs(int x, int u, int v)
{
    if (vis[x])
        return;
    vis[x] = true;
    for (auto e : graph[x])
    {
        if (mp(x, e) != mp(u, v) && mp(e, x) != mp(u, v))
            dfs(e, u, v);
    }
}

bool check(lli x)
{
    graph = vvi(n + 1);
    for (auto p : edges)
    {
        if (p.f >= x)
        {
            graph[p.s.f].pb(p.s.s);
            graph[p.s.s].pb(p.s.f);
        }
    }
    for (auto p : edges)
    {
        if (p.f >= x)
        {
            // graph[p.s.f].erase(p.s.s);
            // graph[p.s.s].erase(p.s.f);
            vis = vb(n + 1);
            int c = 0;
            forr(i, 1, n + 1)
            {
                if (!vis[i])
                {
                    c++;
                    dfs(i, p.s.f, p.s.s);
                }
            }

            if (c >= 2)
                return false;
        }
    }
    // vis = vb(n + 1);
    // int c = 0;
    // forr(i, 1, n + 1)
    // {
    //     if (!vis[i])
    //     {
    //         c++;
    //         dfs(i);
    //     }
    // }
    return true;
}

int main()
{
    fastio();
    cin >> n >> m;
    edges = vector<pair<lli, pii>>(m);
    graph = vector<vi>(n + 1);
    frange(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        edges[i].f = 1e9;
        edges[i].s.f = a;
        edges[i].s.s = b;
    }
    vll val;
    forr(i, n - 1, m)
    {
        int a, b;
        lli c;
        cin >> a >> b >> c;
        edges[i].f = c;
        edges[i].s.f = a;
        edges[i].s.s = b;
        val.pb(c);
    }
    val.pb(1e9);
    val.pb(-1);
    sort(all(val));
    lli lo = 0;
    lli hi = val.size() - 1;

    while (lo != hi)
    {
        lli mid = (hi + lo + 1) / 2;
        if (check(val[mid]))
        {
            lo = mid;
        }
        else
            hi = mid - 1;
    }
    cout << val[lo];
}