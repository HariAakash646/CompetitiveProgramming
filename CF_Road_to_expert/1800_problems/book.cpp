#include <bits/stdc++.h>

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

vvi graph;
vvi ingraph;
vb curr;
vb vis;

bool dfs(int node)
{
    if (curr[node])
        return true;
    if (vis[node])
        return false;
    curr[node] = true;
    for (auto e : graph[node])
    {
        if (!vis[e])
        {
            bool out = dfs(e);
            if (out)
                return true;
        }
    }
    vis[node] = true;
    curr[node] = false;
    return false;
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        graph = vvi(n + 1);
        ingraph = vvi(n + 1);
        vi indeg(n + 1);
        forr(i, 1, n + 1)
        {
            int k;
            scd(k);
            indeg[i] = k;
            frange(j, k)
            {
                int a;
                scd(a);
                graph[a].pb(i);
                ingraph[i].pb(a);
            }
        }
        curr = vb(n + 1, false);
        vis = vb(n + 1, false);
        bool out = false;
        forr(i, 1, n + 1)
        {
            if (!vis[i])
            {
                out = dfs(i);
                if (out)
                    break;
            }
        }
        if (out)
        {
            printf("-1\n");
            continue;
        }
        queue<int> q;
        vi topo;
        forr(i, 1, n + 1)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }
        while (q.size())
        {
            int e = q.front();
            q.pop();
            topo.pb(e);
            for (auto p : graph[e])
            {
                indeg[p]--;
                if (indeg[p] == 0)
                {
                    q.push(p);
                }
            }
        }
        vi ans(n + 1);
        for (auto e : topo)
        {
            ans[e] = 1;
            for (auto p : ingraph[e])
            {
                if (p < e)
                {
                    ans[e] = max(ans[e], ans[p]);
                }
                else
                {
                    ans[e] = max(ans[e], ans[p] + 1);
                }
            }
        }
        printf("%d\n", *max_element(all(ans)));
    }
}