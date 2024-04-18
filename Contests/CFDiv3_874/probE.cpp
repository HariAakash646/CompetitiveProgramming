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

vector<seti> graph;
vb vis;

bool dfs(int x, int prev)
{
    if (vis[x])
        return true;
    vis[x] = true;
    for (auto e : graph[x])
    {
        if (e == prev)
            continue;
        bool out = dfs(e, x);
        if (out)
            return true;
    }
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
        graph = vector<seti>(n);
        frange(i, n)
        {
            int a;
            scd(a);
            a--;
            graph[a].insert(i);
            graph[i].insert(a);
        }
        vis = vb(n);
        int cyc = 0;
        int comp = 0;
        frange(i, n)
        {
            if (!vis[i])
            {
                bool out = dfs(i, 0);
                if (out)
                    cyc++;
                else
                    comp++;
            }
        }
        int ma = comp + cyc;
        if (comp)
            cyc++;
        printf("%d %d\n", cyc, ma);
    }
}