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

int n, d;
vvi graph;
seti v1, v2;

vvi binlift;

void dfs(int x, int prev)
{
    binlift[x][0] = prev;
    forr(i, 1, 20)
    {
        binlift[x][i] = binlift[binlift[x][i - 1]][i - 1];
    }
    for (auto e : graph[x])
    {
        if (e != prev)
            dfs(e, x);
    }
}

int lift(int x, int d)
{
    frange(i, 20)
    {
        if (d & (1 << i))
        {
            x = binlift[x][i];
        }
    }
    return x;
}

int main()
{

    scd(n);
    scd(d);
    graph = vvi(n + 1);

    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    int m1;
    scd(m1);
    frange(i, m1)
    {
        int a;
        scd(a);
        v1.insert(a);
    }
    v2 = vi(m2);
    frange(i, m2)
    {
        int a;
        scd(a);
        v2.insert(a);
    }
    binlift = vvi(n + 1, vi(20));

    for (auto e : v1)
    {
        v2.insert(binlift(e, d));
    }
    for (auto e : v2)
    {
        v1.insert(binlift(e, d));
    }
}