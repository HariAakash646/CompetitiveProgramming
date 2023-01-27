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
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
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

int n, m;
vector<vii> graph;
vb vis;

bool dfs(int n1, int n2, int c)
{
    if (vis[n1])
        return false;
    vis[n1] = true;
    if (n1 == n2)
        return true;
    for (auto p : graph[n1])
    {
        if (p.s == c)
        {
            bool out = dfs(p.f, n2, c);
            if (out)
                return true;
        }
    }
    return false;
}

int main()
{
    scd(n);
    scd(m);
    graph = vector<vii>(n + 1);
    frange(i, m)
    {
        int a, b, c;
        scd(a);
        scd(b);
        scd(c);
        graph[a].pb({b, c});
        graph[b].pb({a, c});
    }

    int q;
    scd(q);
    frange(_, q)
    {
        int t = 0;
        vb col(m + 1, false);
        int n1, n2;
        scd(n1);
        scd(n2);
        for (auto p : graph[n1])
        {
            if (!col[p.s])
            {
                vis = vb(n + 1, false);
                bool out = dfs(n1, n2, p.s);
                if (out)
                    t++;
                col[p.s] = true;
            }
        }
        printf("%d\n", t);
    }
}