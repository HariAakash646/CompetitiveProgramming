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

vvi graph;
vi par;
vi child;
stack<int> leaves;
int n, k;
vb vis;
int inf = 1e9;

int dfs(int x, int v, int sz)
{
    // if (vis[x])
    //     return 0;
    // vis[x] = true;
    if (x == 1)
        return 0;
    if (v >= sz - 1)
    {
        child[par[x]]--;
        if (child[par[x]] == 0 && par[x])
        {
            leaves.push(par[x]);
        }
        if (par[x] > 1)
            return 1;
        else
            return 0;
    }
    else
    {
        return dfs(par[x], v + 1, sz);
    }
}

bool check(int x)
{
    forr(i, 2, n + 1)
    {
        if (child[i] == 0)
            leaves.push(i);
    }
    int c = 0;
    while (leaves.size())
    {
        auto l = leaves.top();
        leaves.pop();
        c += dfs(l, 0, x);
    }
    return c <= k;
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {

        scd(n);
        scd(k);
        graph = vvi(n + 1);
        par = child = vi(n + 1);
        vis = vb(n + 1);
        forr(i, 2, n + 1)
        {
            int a;
            scd(a);
            par[i] = a;
            graph[a].pb(i);
            graph[i].pb(a);
            child[a]++;
        }
        int l = 1;
        int h = n;
        while (l != h)
        {
            int mid = (l + h) / 2;
            if (check(mid))
                h = mid;
            else
                l = mid + 1;
        }
        printf("%d\n", l);
    }
}