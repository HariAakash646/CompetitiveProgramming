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
    int cmp = 0;
    int prev = 0;
    while (out.size())
    {
        cmp++;
        auto p = *out.begin();
        dfs2(p.s);
        if (cmp >= 2)
        {
            printf("NO\n");
            printf("%d %d", p.s, prev);
            return 0;
        }
        prev = p.s;
    }
    printf("YES");
}