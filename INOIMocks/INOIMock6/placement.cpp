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

vvi graph;
vi sport;
vi sub;
vll dist1, dist2;
int n, k;

void dfs(int x, int prev)
{
    sub[x] = sport[x];
    for (auto e : graph[x])
    {
        if (e != prev)
        {
            dfs(e, x);
            sub[x] += sub[e];
        }
    }
}

void dfs2(int x, int prev)
{

    for (auto e : graph[x])
    {
        if (e != prev)
        {
            dfs2(e, x);
            dist1[x] += dist1[e] + sub[e];
        }
    }
    // dist2[x] = dist1[prev] - (dist1[x] + sub[x]) + (sub[prev] - sub[x]) + dist2[prev] + 2*(sub);
}

void dfs3(int x, int prev)
{
    if (prev != 0)
        dist2[x] = dist1[prev] - (dist1[x] + sub[x]) + (sub[prev] - sub[x]) + dist2[prev] + (k - sub[prev]);
    for (auto e : graph[x])
    {
        if (e != prev)
        {
            dfs3(e, x);
        }
    }
}

int main()
{

    scd(n);
    graph = vvi(n + 1);
    sub = vi(n + 1);

    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    scd(k);
    sport = vi(n + 1);

    frange(i, k)
    {
        int a;
        scd(a);
        sport[a] = 1;
    }
    dfs(1, 0);
    dist1 = dist2 = vll(n + 1);
    dfs2(1, 0);
    dfs3(1, 0);
    lli mi = 1e18;
    forr(i, 1, n + 1)
    {
        mi = min(mi, dist1[i] + dist2[i]);
        // printf("%lld\n", dist1[i] + dist2[i]);
    }
    int c = 0;
    forr(i, 1, n + 1)
    {
        if (dist1[i] + dist2[i] == mi)
            c++;
    }
    printf("%d %lld", c, mi);
}