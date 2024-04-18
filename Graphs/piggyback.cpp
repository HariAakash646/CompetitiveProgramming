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

vvi graph;
vb vis;

void bfs(int x, int v, vi &dist)
{
    queue<pii> q;
    q.push({x, 0});
    while (q.size())
    {
        auto p = q.front();
        q.pop();
        if (vis[p.f])
            continue;
        vis[p.f] = true;
        dist[p.f] = v * p.s;
        for (auto e : graph[p.f])
        {
            q.push({e, p.s + 1});
        }
    }
}

int main()
{
    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);
    int b, e, p, n, m;
    scd(b);
    scd(e);
    scd(p);
    scd(n);
    scd(m);
    graph = vvi(n + 1);
    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vi dist1(n + 1), dist2(n + 1), distn(n + 1);
    vis = vb(n + 1);
    bfs(1, b, dist1);
    vis = vb(n + 1);
    bfs(2, e, dist2);
    vis = vb(n + 1);
    bfs(n, p, distn);
    int mi = 2e9;
    forr(i, 1, n + 1)
    {
        mi = min(mi, dist1[i] + dist2[i] + distn[i]);
    }
    printf("%d\n", mi);
}