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

int n;
vb proc;
vvi graph;

bool overlap(pii c1, pii c2)
{
    if (pow((c1.f - c2.f), 2) + pow((c1.s - c2.s), 2) <= 40000)
    {
        return true;
    }
    return false;
}

bool dfs(int node)
{
    if (node == n + 1)
    {
        return true;
    }
    if (proc[node])
        return false;
    proc[node] = true;
    for (auto e : graph[node])
    {
        bool out = dfs(e);
        if (out)
            return true;
    }
    return false;
}

int main()
{
    int l, w;
    scd(l);
    scd(w);
    scd(n);
    vii vec(n);
    frange(i, n)
    {
        int li, wi;
        scd(li);
        scd(wi);
        vec[i] = {li, wi};
    }
    graph = vvi(n + 2);
    proc = vb(n + 2);
    frange(i, n)
    {
        auto e = vec[i];
        if (overlap(e, {e.f, -100}))
        {
            graph[0].pb(i + 1);
            graph[i + 1].pb(0);
        }
        if (overlap(e, {e.f, w + 100}))
        {
            graph[n + 1].pb(i + 1);
            graph[i + 1].pb(n + 1);
        }
        frange(j, n)
        {
            if (j == i)
                continue;
            auto p = vec[j];
            if (overlap(e, p))
            {
                graph[j + 1].pb(i + 1);
                graph[i + 1].pb(j + 1);
            }
        }
    }
    bool out = dfs(0);
    if (out)
    {
        bool left = false;
        bool right = false;
        frange(i, n)
        {
            auto e = vec[i];
            if (overlap(e, {e.f, -100}))
                left = true;
            if (overlap(e, {e.f, w + 100}))
                right = true;
        }
        if (left && right)
            cout << 1;
    }
    else
        cout << 0;
}