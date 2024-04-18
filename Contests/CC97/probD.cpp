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

vvi graph, rev;
vb vis;
vi order, comp;
lli k;
vll sze;
vll pref;

void dfs1(int v)
{
    vis[v] = true;

    for (auto u : graph[v])
        if (!vis[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v)
{
    vis[v] = true;
    comp.push_back(v);

    for (auto u : rev[v])
        if (!vis[u])
            dfs2(u);
}

int main()
{
    int n, m;
    scd(n);
    scd(m);
    graph = rev = vvi(n + 1);
    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        rev[b].pb(a);
    }
    vis = vb(n + 1);
    forr(i, 1, n + 1)
    {
        if (!vis[i])
            dfs1(i);
    }
    vis = vb(n + 1);
    reverse(all(order));

    forr(i, 1, n + 1)
    {
        if (!vis[i])
        {
            comp = {};
            dfs2(i);
            sze.pb(comp.size());
        }
    }
    sort(all(sze), greater<>());
    pref = vll(n + 1);
    lli curr = 0;
    for (auto e : sze)
    {
        for (int j = curr + 1; j <= curr + e; j++)
        {
            pref[j] = pref[j - 1] + curr;
        }
        curr += e;
    }
    int q;
    scd(q);
    frange(_, q)
    {
        sclld(k);
        lli hi = n;
        lli lo = 1;
        while (lo != hi)
        {
            lli mid = (hi + lo + 1) / 2;
            if (pref[mid] <= k)
            {
                lo = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }
        printf("%lld\n", lo);
    }
}