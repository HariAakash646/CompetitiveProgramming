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
typedef pair<int, pii> piii;

vi graph;
vb vis;
vb cycle;
seti curr;

int dfs(int x)
{
    if (curr.find(x) != curr.end())
    {
        cycle[x] = true;
        return x;
    }
    if (vis[x])
    {
        return 0;
    }
    curr.insert(x);
    vis[x] = true;
    if (graph[x])
    {
        int out = dfs(graph[x]);
        if (out)
        {
            cycle[graph[x]] = true;
        }
        if (out == x)
        {
            return 0;
        }
        else
        {
            return out;
        }
    }
    return 0;
}

int main()
{
    int n;
    scd(n);
    graph = vi(n + 1);
    vis = cycle = vb(n + 1);
    forr(i, 1, n + 1)
    {
        int a;
        scd(a);
        graph[i] = a;
    }
    forr(i, 1, n + 1)
    {
        if (!vis[i])
        {
            curr = {};
            dfs(i);
        }
    }
    int c = 0;
    for (auto e : cycle)
    {
        if (e)
            c++;
    }
    printf("%d", c);
}