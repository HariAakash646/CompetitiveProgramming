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

lli mod = 1e9 + 7;

vvi graph;
vb vis;

void dfs(int n1)
{
    if (vis[n1])
        return;
    vis[n1] = true;
    for (auto e : graph[n1])
    {
        dfs(e);
    }
    return;
}

vb vis2;

int cyc(int n1, int n2)
{
    if (vis[n1])
        return 0;
    int sz = 1;
    for (auto e : graph[n1])
    {
        if (e == n2)
        {
            return sz + 1;
        }
        sz += dfs(e, n2);
    }
}

int main()
{
    lli n, m, k;
    sclld(n);
    sclld(m);
    sclld(k);
    graph = vvi(n + 1);
    vis = vb(n + 1, false);
    vis2 = vb(n + 1, false);
    int a, b;
    frange(i, m)
    {
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    int c = 0;
    lli out = 1;
    int sz;
    forr(i, 1, n + 1)
    {
        if (!vis[i])
        {
            c++;
            dfs(i);
            out = (out * k) % mod;
        }
    }
    printf("%lld", out);
}