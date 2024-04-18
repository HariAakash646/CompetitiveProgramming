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

pair<vi, vi> toposort(vvi &graph, vi &indeg)
{
    int n = graph.size() - 1;
    queue<int> q;
    vi topo;
    vi idx(n + 1);
    forr(i, 1, n + 1)
    {
        if (indeg[i] == 0)
            q.push(i);
    }
    while (q.size())
    {
        int e = q.front();
        q.pop();
        topo.pb(e);
        idx[e] = topo.size();
        for (auto x : graph[e])
        {
            indeg[x]--;
            if (indeg[x] == 0)
                q.push(x);
        }
    }
    return mp(topo, idx);
}

int main()
{
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);
    int n, m, c;
    scd(n);
    scd(m);
    scd(c);
    vi vec(n + 1);
    frange(i, n) scd(vec[i + 1]);
    vvi graph(n + 1);
    vi indeg(n + 1);
    vector<vii> ingraph(n + 1);
    frange(i, c)
    {
        int a, b, d;
        scd(a);
        scd(b);
        scd(d);
        graph[a].pb(b);
        indeg[b]++;
        ingraph[b].pb({a, d});
    }
    pair<vi, vi> out = toposort(graph, indeg);
    vi topo = out.f;
    vi idx = out.s;
    vi dp(n + 1);
    forr(i, 1, n + 1)
    {
        int x = topo[i - 1];
        dp[i] = vec[x];
        for (auto p : ingraph[x])
        {
            dp[i] = max(dp[i], dp[idx[p.f]] + p.s);
        }
    }
    forr(i, 1, n + 1)
    {
        printf("%d\n", dp[idx[i]]);
    }
}