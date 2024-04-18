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
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

vvi graph;
vi dist1, distx;

void dfs1(int x, int pre)
{
    dist1[x] = dist1[pre] + 1;
    for (auto e : graph[x])
    {
        if (e != pre)
        {
            dfs1(e, x);
        }
    }
}

void dfsx(int x, int pre)
{
    distx[x] = distx[pre] + 1;
    if (distx[x] == dist1[x])
    {
        return;
    }
    for (auto e : graph[x])
    {
        if (e != pre)
        {
            dfsx(e, x);
        }
    }
}

int main()
{
    int n, x;
    scd(n);
    scd(x);
    graph = vvi(n + 1);
    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dist1 = distx = vi(n + 1, 1e9);
    dist1[0] = distx[0] = -1;
    dfs1(1, 0);
    dfsx(x, 0);
    int ma = 0;
    forr(i, 1, n + 1)
    {
        if (distx[i] <= dist1[i])
        {
            ma = max(ma, dist1[i]);
        }
    }
    printf("%d", 2 * ma);
}