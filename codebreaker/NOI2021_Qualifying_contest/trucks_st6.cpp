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

lli mod = 1e9 + 7;

int n;
lli g;

struct node
{
    int id;
    lli dist = 0, toll = 0;
};

vector<vector<node>> graph;

pair<lli, bool> dfs1(int x, int v, int prev, lli d)
{
    if (x == v)
    {
        return {d, true};
    }

    for (auto e : graph[x])
    {
        if (e.id != prev)
        {
            pii p = dfs1(e.id, v, x, e.toll);
            if (p.s)
            {
                return {(p.f + d) % mod, true};
            }
        }
    }
    return {0, false};
}

pair<lli, bool> dfs2(int x, int v, int prev, lli d)
{
    if (x == v)
    {
        return {0, true};
    }

    for (auto e : graph[x])
    {
        if (e.id != prev)
        {
            pii p = dfs2(e.id, v, x, (d - e.toll + mod) % mod);
            if (p.s)
            {
                d -= e.toll;
                d = (d + mod) % mod;
                return {(p.f + (d * e.dist) % mod) % mod, true};
            }
        }
    }
    return {0, false};
}

pair<lli, bool> dfs3(int x, int v, int prev, lli d)
{
    if (x == v)
    {
        return {d, true};
    }

    for (auto e : graph[x])
    {
        if (e.id != prev)
        {
            pii p = dfs3(e.id, v, x, e.dist);
            if (p.s)
            {
                return {(p.f + d) % mod, true};
            }
        }
    }
    return {0, false};
}

int main()
{
    scd(n);
    sclld(g);
    graph = vector<vector<node>>(n + 1);
    frange(i, n - 1)
    {
        node e1, e2;
        int a, b;
        scd(a);
        scd(b);
        e1.id = b;
        e2.id = a;
        sclld(e1.dist);
        sclld(e1.toll);

        e2.dist = e1.dist;
        e2.toll = e1.toll;

        graph[a].pb(e1);
        graph[b].pb(e2);
    }

    int q;
    scd(q);

    frange(_, q)
    {
        int v;
        scd(v);
        if (v)
        {
            int x, y;
            scd(x);
            scd(y);
            lli d = dfs1(x, y, 0, 0).f;
            printf("%lld\n", (dfs2(x, y, 0, d).f + (g * dfs3(x, y, 0, 0).f) % mod) % mod); // dfs2(x, y, 0, d).f + g *
        }
        else
        {
            int x, y;
            lli t;
            scd(x);
            scd(y);
            sclld(t);
            for (auto &e : graph[x])
            {
                if (e.id == y)
                    e.toll = t;
            }
            for (auto &e : graph[y])
            {
                if (e.id == x)
                    e.toll = t;
            }
        }
    }
}