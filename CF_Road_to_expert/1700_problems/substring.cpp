// WA. Better sol involves topo sort dp.
// I think this is debuggable
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

vvi graph;
vb vis;
vb curr;
vi ch;
vector<pair<int, vi>> node;

bool dfs(int x)
{
    if (curr[x])
        return true;
    if (vis[x])
        return false;
    vis[x] = true;
    curr[x] = true;
    for (auto e : graph[x])
    {
        bool out = dfs(e);
        if (out)
            return true;
    }
    curr[x] = false;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    ch = vi(n + 1);
    frange(i, n)
    {
        char c;
        cin >> c;
        ch[i + 1] = c - 'a';
    }
    graph = vvi(n + 1);
    vi indeg(n + 1);
    vvi ingraph(n + 1);
    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        ingraph[b].pb(a);
        indeg[b]++;
    }
    vis = vb(n + 1);
    forr(i, 1, n + 1)
    {
        curr = vb(n + 1, false);
        if (!vis[i])
        {
            bool out = dfs(i);
            if (out)
            {
                printf("-1");
                return 0;
            }
        }
    }

    node = vector<pair<int, vi>>(n + 1, {0, vi(26, 0)});
    queue<int> q;
    vis = vb(n + 1);
    forr(i, 1, n + 1)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }
    int cnt = 0;
    while (q.size())
    {
        cnt++;
        int x = q.front();
        q.pop();
        int ma = node[x].f;
        int id = 0;
        for (auto e : ingraph[x])
        {
            int v = node[e].f;
            int ad = node[e].s[ch[x]] + 1;
            v = max(ad, v);
            if (v >= ma)
            {
                ma = v;
                id = e;
            }
        }
        if (id)
        {
            node[x].f = ma;
            node[x].s = node[id].s;
        }
        else
        {
            node[x].f = 1;
        }
        node[x].s[ch[x]]++;
        node[x].f = max(node[x].f, node[x].s[ch[x]]);
        for (auto e : graph[x])
        {
            indeg[e]--;
            if (indeg[e] == 0)
            {
                q.push(e);
            }
        }
    }

    int ma = 0;
    forr(i, 1, n + 1)
    {
        ma = max(ma, node[i].f);
    }
    if (cnt == n)
        printf("%d", ma);
    else
        printf("Problem");
}