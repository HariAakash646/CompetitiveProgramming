#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define PB push_back
#define f first
#define s second

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

vvi graph;
vii cows;
vector<bool> visited;
vector<tuple<int, int, int, int>> coord;
tuple<int, int, int, int> dfs(int node, int &maxx, int &maxy, int &minx, int &miny)
{
    visited[node] = true;
    auto c = cows[node];
    maxx = max(c.f, maxx);
    maxy = max(c.s, maxy);
    minx = min(c.f, minx);
    miny = min(c.s, miny);

    for (auto e : graph[node])
    {
        if (!visited[e])
        {
            dfs(e, maxx, maxy, minx, miny);
        }
    }
    tuple<int, int, int, int> out{maxx, maxy, minx, miny};
    return out;
}

int main()
{
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);

    int n, m;
    scd(n);
    scd(m);
    visited = vector<bool>(n + 1, false);
    graph = vvi(n + 1);
    cows = vii(n + 1);
    frange(i, n)
    {
        scd(cows[i + 1].f);
        scd(cows[i + 1].s);
    }
    int a, b;
    frange(i, m)
    {
        scd(a);
        scd(b);
        graph[a].PB(b);
        graph[b].PB(a);
    }
    int maxx = 0;
    int maxy = 0;
    int minx = 1e9 + 5;
    int miny = 1e9 + 5;
    forr(i, 1, n + 1, 1)
    {
        if (!visited[i])
        {
            maxx = 0;
            maxy = 0;
            minx = 1e9 + 5;
            miny = 1e9 + 5;
            tuple<int, int, int, int> out = dfs(i, maxx, maxy, minx, miny);
            coord.PB(out);
        }
    }
    int min_peri = 1e9;
    for (auto e : coord)
    {
        int peri = 2 * (get<0>(e) - get<2>(e) + get<1>(e) - get<3>(e));
        min_peri = min(peri, min_peri);
    }
    cout << min_peri;
}