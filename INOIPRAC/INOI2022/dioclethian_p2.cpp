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

void dfs(int x, int v)
{
    if (x == v)
    {
        // vis[x] = true;
        return;
    }
    if (vis[x])
        return;
    vis[x] = true;
    for (auto e : graph[x])
    {
        dfs(e, v);
    }
}

int main()
{
    int n, m, p;
    scd(n);
    scd(m);
    scd(p);

    graph = vvi(n + 1);
    vii edges(m);

    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
        edges[i] = {a, b};
    }

    vector<string> vec;
    vis = vb(n + 1);
    dfs(2, 1);
    bool done = true;
    forr(i, 1, n + 1)
    {
        done = done && vis[i];
    }
    if (done)
    {
        string out = "";

        frange(j, n) out += '1';
        out[0] = '0';
        vec.pb(out);
    }
    forr(i, 2, n + 1)
    {
        vis = vb(n + 1);
        dfs(1, i);
        string out = "";
        frange(j, n) out += '1';
        forr(j, 1, n + 1)
        {
            if (vis[j])
                out[j - 1] = '0';
        }
        vec.pb(out);
    }
    printf("%d\n", vec.size());
    for (auto e : vec)
        cout << e << "\n";
}