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
#define pb push_back
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
vi indeg;
queue<int> q;
vi topo;

void topo_bfs(int node)
{
    topo.pb(node);
    for (auto e : graph[node])
    {
        indeg[e]--;
        if (indeg[e] == 0)
            q.push(e);
    }
}

int main()
{
    int n, m;
    scd(n);
    scd(m);
    graph = vvi(n + 1);
    indeg = vi(n + 1, 0);
    int a, b;
    frange(i, m)
    {
        scd(a);
        scd(b);
        graph[a].pb(b);
        indeg[b]++;
    }
    forr(i, 1, n + 1, 1)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        topo_bfs(q.front());
        q.pop();
    }
    if (topo.size() != n)
    {
        printf("IMPOSSIBLE");
        return 0;
    }
    for (auto e : topo)
    {
        printf("%d ", e);
    }
}