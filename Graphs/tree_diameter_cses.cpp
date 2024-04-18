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
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

vvi graph;

pii dfs(int node, int prev)
{
    int c = 0;
    int ele = node;
    for (auto e : graph[node])
    {
        if (e != prev)
        {
            pii out = dfs(e, node);
            if (out.f + 1 > c)
            {
                ele = out.s;
                c = out.f + 1;
            }
        }
    }
    return pii{c, ele};
}

int main()
{
    int n;
    scd(n);
    graph = vvi(n + 1);
    int a, b;
    frange(i, n)
    {
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    pii step = dfs(1, 0);
    pii fin = dfs(step.s, 0);
    printf("%d", fin.f);
}