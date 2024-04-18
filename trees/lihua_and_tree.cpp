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

lli inf = 1e18;

struct Vert
{
    int id;
    lli w = -inf;
    bool operator<(const Vert &y) const
    {
        if (w > y.w)
            return true;
        else if (w == y.w)
        {
            return id < y.id;
        }
        else
            return false;
    }
};

vll vec;
vector<set<Vert>> graph;
vll imp, sub;

void dfs(int x, int prev)
{
    sub[x] = 1;
    imp[x] = vec[x];
    set<Vert> tmp;
    for (auto e : graph[x])
    {
        if (e.id != prev)
        {
            dfs(e.id, x);
            sub[x] += sub[e.id];
            imp[x] += imp[e.id];
            e.w = sub[e.id];
            tmp.insert(e);
        }
        else
            tmp.insert(e);
    }
    graph[x] = tmp;
}

int main()
{
    int n, m;
    scd(n);
    scd(m);
    imp = sub = vec = vll(n + 1);
    graph = vector<set<Vert>>(n + 1);
    forr(i, 1, n + 1) sclld(vec[i]);

    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        Vert v1, v2;
        v1.id = b;
        v2.id = a;
        graph[a].insert(v1);
        graph[b].insert(v2);
    }
    dfs(1, 0);

    frange(i, m)
    {
        int t, a;
        scd(t);
        scd(a);
        if (t == 1)
        {
            printf("%lld\n", imp[a]);
        }
        else
        {
            if (graph[a].size() == 1)
                continue;
            auto p = *graph[a].begin();
            graph[a].erase(graph[a].begin());
            auto par = *prev(graph[a].end());
            graph[a].erase(prev(graph[a].end()));
            graph[p.id].erase(prev(graph[p.id].end()));
            lli val = imp[p.id];
            imp[p.id] += imp[a];
            imp[a] -= val;
            val = sub[p.id];
            sub[p.id] += sub[a];
            sub[a] -= val;
            Vert v;
            v.id = p.id;
            p.id = a;
            p.w = sub[a];
            Vert pre, curr;
            pre.id = par.id;
            curr.id = v.id;
            curr.w = sub[v.id];
            graph[v.id].insert(p);
            graph[v.id].insert(pre);
            graph[par.id].insert(curr);
            graph[a].insert(v);
        }
    }
}