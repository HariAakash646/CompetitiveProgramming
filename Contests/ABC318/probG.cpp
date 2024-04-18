#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
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
typedef long double ld;

vvi graph;

vb vis;

void dfs(int x, int no)
{
    if (x == no)
        return;
    if (vis[x])
        return;
    vis[x] = true;
    for (auto e : graph[x])
    {
        dfs(e, no);
    }
}

int main()
{
    int n, m;
    scd(n);
    scd(m);
    int a, b, c;
    scd(a);
    scd(b);
    scd(c);
    graph = vvi(n + 1);

    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    vis = vb(n + 1);
    dfs(b, c);

    if (vis[a])
    {
        vis = vb(n + 1, false);
        dfs(b, a);
        if (vis[c])
            printf("Yes");
        else
            printf("No");
    }
    else
        printf("No");
}