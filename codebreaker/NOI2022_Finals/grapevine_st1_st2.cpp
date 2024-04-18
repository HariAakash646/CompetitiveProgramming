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
typedef pair<int, lli> pii;
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

lli inf = 1e18;

vector<vii> graph;
vll dist;
vb vec;

void dfs(int x, int prev)
{
    if (vec[x])
    {
        dist[x] = 0;
        return;
    }
    for (auto e : graph[x])
    {
        if (e.f != prev)
        {
            dfs(e.f, x);
            dist[x] = min(dist[x], dist[e.f] + e.s);
        }
    }
}

int main()
{
    int n, q;
    scd(n);
    scd(q);
    graph = vector<vii>(n + 1);
    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        lli w;
        sclld(w);
        graph[a].pb({b, w});
        graph[b].pb({a, w});
    }

    vec = vb(n + 1);
    frange(_, q)
    {
        int t;
        scd(t);
        if (t == 1)
        {
            dist = vll(n + 1, inf);
            int u;
            scd(u);
            dfs(u, 0);
            if (dist[u] >= inf)
                printf("-1\n");
            else
                printf("%lld\n", dist[u]);
        }
        else if (t == 2)
        {
            int u;
            scd(u);
            vec[u] = !vec[u];
        }
        else
        {
            int u, v;
            lli w;
            scd(u);
            scd(v);
            sclld(w);
            for (auto &p : graph[u])
            {
                if (p.f == v)
                    p.s = w;
            }
            for (auto &p : graph[v])
            {
                if (p.f == u)
                    p.s = w;
            }
        }
    }
}