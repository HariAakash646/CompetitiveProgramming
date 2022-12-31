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
typedef vector<bool> vb;
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
vb vis;
vi team;

bool dfs(int node, int team_no)
{
    vis[node] = true;
    team[node] = team_no;
    for (auto e : graph[node])
    {
        if (vis[e])
        {
            if (team_no == team[e])
                return false;
        }
        else
        {
            bool out = dfs(e, (team_no == 1) ? 2 : 1);
            if (!out)
                return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    scd(n);
    scd(m);
    graph = vvi(n + 1);
    int a, b;
    vis = vb(n + 1, false);
    team = vi(n + 1, 0);
    frange(i, m)
    {
        scd(a);
        scd(b);
        graph[a].PB(b);
        graph[b].PB(a);
    }
    forr(i, 1, n + 1, 1)
    {
        if (!vis[i])
        {
            bool out = dfs(i, 1);
            if (!out)
            {
                printf("IMPOSSIBLE");
                return 0;
            }
        }
    }
    forr(i, 1, n + 1, 1)
    {
        cout << team[i] << " ";
    }
    return 0;
}
