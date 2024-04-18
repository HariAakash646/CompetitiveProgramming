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
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

vvi graph;
vb vis;

void dfs(int x)
{
    vis[x] = true;
    for (auto e : graph[x])
    {
        if (!vis[e])
        {
            dfs(e);
        }
    }
}

int main()
{
    int n, m;
    scd(n);
    scd(m);
    graph = vvi(n + 1);
    vii vec;
    seti frd;
    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        if (a > b)
            swap(a, b);
        if (a == 1)
        {
            graph[a].pb(b);
            frd.insert(b);
        }
        else
        {
            vec.pb({a, b});
        }
    }
    for (auto p : vec)
    {
        if (frd.find(p.f) != frd.end())
        {
            graph[p.f].pb(p.s);
        }
        if (frd.find(p.s) != frd.end())
        {
            graph[p.s].pb(p.f);
        }
    }
    vis = vb(n + 1);
    dfs(1);
    int c = 0;
    for (auto b : vis)
    {
        if (b)
            c++;
    }
    printf("%d", c - 1);
}