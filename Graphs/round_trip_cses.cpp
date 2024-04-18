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
typedef vector<bool> vb;
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
vb visited;
vb curr;
vi currstk;

bool dfs(int node, int prev)
{
    visited[node] = true;
    curr[node] = true;
    currstk.pb(node);
    for (auto e : graph[node])
    {
        if (curr[e] && e != prev)
        {
            currstk.pb(e);
            return true;
        }
        if (!visited[e])
        {
            bool out = dfs(e, node);
            if (out)
                return true;
            currstk.pop_back();
        }
    }
    return false;
}

int main()
{
    int n, m;
    scd(n);
    scd(m);
    graph = vvi(n + 1);
    visited = vb(n + 1, false);
    int a, b;
    frange(i, m)
    {
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    forr(i, 1, n + 1)
    {
        if (!visited[i])
        {
            curr = vb(n + 1, false);
            currstk = {};
            bool out = dfs(i, 0);
            if (out)
            {
                reverse(currstk.begin(), currstk.end());
                int ele = currstk[0];
                int idx = find(next(currstk.begin()), currstk.end(), ele) - currstk.begin();
                printf("%d\n", idx + 1);
                frange(i, idx + 1)
                {
                    printf("%d ", currstk[i]);
                }
                return 0;
            }
        }
    }
    printf("IMPOSSIBLE");
}