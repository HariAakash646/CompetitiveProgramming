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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vvi graph;
vi id;  // Vis time of each node
vi low; // Lowest id of each node cnnected directly/ indirectly except parent
int timer = 0;
stack<int> stk;
vvi comp;

void dfs(int x, int par)
{
    low[x] = id[x] = ++timer;
    bool multiedge = false;
    stk.push(x);

    for (auto e : graph[x])
    {
        if (e == par && !multiedge)
        {
            multiedge = true;
            continue;
        }
        if (!id[e])
        {
            dfs(e, x);
            low[x] = min(low[x], low[e]);
        }
        else
        {
            low[x] = min(low[x], id[e]);
        }
    }
    vi curr;
    if (low[x] == id[x])
    {
        while (stk.top() != x)
        {
            curr.pb(stk.top());
            stk.pop();
        }
        curr.pb(stk.top());
        stk.pop();
        comp.pb(curr);
    }
}

int main()
{
    fastio();
    int n, m;
    cin >> n >> m;

    graph = vvi(n);
    id = low = vi(n);

    frange(i, m)
    {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    frange(i, n)
    {
        if (!id[i])
        {
            timer = 0;
            dfs(i, -1);
        }
    }
    printf("%d\n", comp.size());
    frange(i, comp.size())
    {
        printf("%d ", comp[i].size());
        for (auto e : comp[i])
            printf("%d ", e);
        printf("\n");
    }
}