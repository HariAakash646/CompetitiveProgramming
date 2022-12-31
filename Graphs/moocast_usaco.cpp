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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define PB push_back
#define f first
#define s second

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

vvi graph;

int sqr(int a)
{
    return a * a;
}

int dfs(int node, vector<bool> &visited)
{
    int tot = 1;
    visited[node] = true;
    for (auto i : graph[node])
    {
        if (!visited[i])
        {
            tot += dfs(i, visited);
        }
    }
    return tot;
}

int main()
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int n;
    scd(n);
    vector<pair<pii, int>> vec(n);
    int a, b, c;
    frange(i, n)
    {
        scd(a);
        scd(b);
        scd(c);
        vec[i].f.f = a;
        vec[i].f.s = b;
        vec[i].s = c;
    }
    graph = vvi(n);
    frange(i, n)
    {
        frange(j, n)
        {
            if (i == j)
                continue;
            if (sqr(vec[i].f.f - vec[j].f.f) + sqr(vec[i].f.s - vec[j].f.s) <= sqr(vec[i].s))
                graph[i].PB(j);
        }
    }
    int ma = 0;
    frange(i, n)
    {
        vector<bool> visited(n, false);
        ma = max(ma, dfs(i, visited));
    }
    cout << ma;
}