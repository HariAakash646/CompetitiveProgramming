// TLE
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
vector<seti> col;
vi out;

void dfs(int x, int prev)
{
    for (auto e : graph[x])
    {
        if (e != prev)
        {
            dfs(e, x);
            if (col[e].size() > col[x].size())
                swap(col[e], col[x]);
            for (auto p : col[e])
                col[x].insert(p);
        }
    }
    out[x] = col[x].size();
}

int main()
{
    int n;
    scd(n);
    col = vector<seti>(n + 1);
    out = vi(n + 1);
    forr(i, 1, n + 1)
    {
        int a;
        scd(a);
        col[i].insert(a);
    }
    graph = vvi(n + 1);
    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dfs(1, 0);
    forr(i, 1, n + 1)
    {
        printf("%d ", out[i]);
    }
}