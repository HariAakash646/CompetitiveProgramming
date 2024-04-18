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
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

vb vis;

bool cycle(int x, int prev, vvi &graph)
{
    if (vis[x])
    {
        return true;
    }
    vis[x] = true;
    for (auto e : graph[x])
    {
        if (e != prev)
        {
            bool out = cycle(e, x, graph);
            if (out)
                return true;
        }
    }
    return false;
}

void dfs2(int x, int v, vvi &graph, vi &vec)
{
    vec[x] = v + 1;
    vis[x] = true;
    for (auto e : graph[x])
    {
        if (!vis[e])
        {
            dfs2(e, !v, graph, vec);
        }
    }
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vi vec(n);
        frange(i, n) scd(vec[i]);
        vvi graph(n);
        frange(i, n)
        {
            if (i == 0)
            {
                if (vec[n - 1] != vec[0])
                    graph[i].pb(n - 1);
            }
            else
            {
                if (vec[i - 1] != vec[i])
                    graph[i].pb(i - 1);
            }
            if (i == n - 1)
            {
                if (vec[0] != vec[n - 1])
                    graph[i].pb(0);
            }
            else
            {
                if (vec[i] != vec[i + 1])
                    graph[i].pb(i + 1);
            }
        }
        int c = 1;
        bool two = false;
        frange(i, n)
        {
            if (graph[i].size())
                two = true;
        }
        if (!two)
        {
            printf("1\n");
            frange(i, n) printf("1 ");
            printf("\n");
            continue;
        }
        bool three = false;
        vi val(n);
        vis = vb(n + 1);
        if (!cycle(0, -1, graph) || n % 2 == 0)
        {

            printf("2\n");
            vis = vb(n + 1);
            frange(i, n)
            {
                if (!vis[i])
                {
                    dfs2(i, 0, graph, val);
                }
            }
            for (auto e : val)
                printf("%d ", e);
        }
        else
        {
            printf("3\n");
            printf("3 ");
            forr(i, 1, n)
            {
                if (i % 2)
                    printf("2 ");
                else
                    printf("1 ");
            }
        }

        printf("\n");
    }
}