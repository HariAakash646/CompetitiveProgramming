// TLE

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
stack<int> stk;
unordered_set<int> stkset;
bool cyc = false;
vector<bool> vis;

vector<int> dfs(int node)
{
    vis[node] = true;
    stk.push(node);
    stkset.insert(node);
    vector<int> out{};
    for (int e : graph[node])
    {
        if (stkset.find(e) != stkset.end())
        {
            cyc = true;
            stk.pop();
            return vi{};
        }
        if (!vis[e])
        {
            vi curr = dfs(e);
            if (curr.empty())
                return {};
            out.insert(out.end(), curr.begin(), curr.end());
        }
    }
    out.pb(node);
    stk.pop();
    stkset.erase(node);
    return out;
}

int main()
{
    int n, m;
    scd(n);
    scd(m);
    graph = vvi(n + 1);
    vvi indeg(n + 1);
    vis = vector<bool>(n + 1, false);
    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        indeg[b].pb(a);
    }
    vi indeg0;
    frange(i, n)
    {
        if (indeg[i + 1].size() == 0)
        {
            indeg0.pb(i + 1);
        }
    }
    if (indeg0.size() == 0)
    {
        printf("IMPOSSIBLE");
    }
    else
    {
        vi finvec = {};
        for (auto e : indeg0)
        {
            vi out = dfs(e);
            finvec.insert(finvec.end(), out.begin(), out.end());
        }
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j])
            {
                vi out = dfs(j);
                finvec.insert(finvec.end(), out.begin(), out.end());
            }
        }
        if (cyc)
            printf("IMPOSSIBLE");
        else
        {
            reverse(all(finvec));
            for (auto e : finvec)
            {
                printf("%d ", e);
            }
        }
    }
}