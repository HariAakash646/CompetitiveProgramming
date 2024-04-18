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
typedef long double ld;

vector<vii> graph;
vi vec;
vb vis;
vi trav, up, down;
vi dp;
int curr = 0;

void dfs(int x)
{
    vis[x] = true;
    trav[x] = curr++;
    for (auto e : graph[x])
    {
        if (!vis[e.f])
        {
            vec[e.s] = 1;
            dfs(e.f);
        }
    }
}

void dfs2(int x)
{
    vis[x] = true;
    dp[x] = up[x] - down[x];
    for (auto e : graph[x])
    {
        if (!vis[e.f])
        {
            dfs2(e.f);
            dp[x] += dp[e.f];
        }
    }
}

int main()
{
    int n, m;
    scd(n);
    scd(m);

    graph = vector<vii>(n + 1);
    vii edges(m + 1);

    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb({b, i});
        graph[b].pb({a, i});
        edges[i] = {a, b};
    }

    trav = vi(n + 1);
    vec = vi(m);
    vis = vb(n + 1);
    dfs(1);

    up = down = vi(n + 1);

    forr(i, 1, n + 1)
    {
        for (auto e : graph[i])
        {
            if (vec[e.s] == 0)
            {
                if (trav[i] > trav[e.f])
                    up[i]++;
                else
                    down[i]++;
            }
        }
    }
    // for (auto e : trav)
    //     printf("%d ", e);
    // printf("\n");

    dp = vi(n + 1);
    vis = vb(n + 1);
    dfs2(1);
    // forr(i, 1, n + 1) printf("%d ", dp[i]);
    // printf("\n");
    frange(i, m)
    {
        int a, b;
        a = edges[i].f;
        b = edges[i].s;
        if (trav[a] > trav[b])
            swap(a, b);
        if (dp[b] == 0)
        {
            printf("0");
            return 0;
        }
    }
    frange(i, m)
    {
        int a = edges[i].f;
        int b = edges[i].s;
        if (trav[a] > trav[b])
            swap(a, b);
        if (vec[i])
        {
            printf("%d %d\n", a, b);
        }
        else
            printf("%d %d\n", b, a);
    }
}