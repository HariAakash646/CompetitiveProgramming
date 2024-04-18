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
vvi sze;

void bfs(int x)
{
    queue<pii> q;
    q.push({x, 0});
    while (q.size())
    {
        pii p = q.front();
        int e = p.f;
        q.pop();
        if (vis[e])
            continue;
        vis[e] = true;
        sze[x][e] = p.s;
        for (auto k : graph[e])
        {
            q.push({k, p.s + 1});
        }
    }
}

int main()
{
    int n, m;
    scd(n);
    scd(m);
    graph = vvi(n + 1);
    vis = vb(n + 1);
    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    sze = vvi(n + 1, vi(n + 1));
    forr(i, 1, n + 1)
    {
        vis = vb(n + 1);
        bfs(i);
    }
    int k;
    scd(k);
    seti st;
    vii quer;
    forr(i, 1, n + 1) st.insert(i);
    frange(i, k)
    {
        int p, d;
        scd(p);
        scd(d);
        quer.pb({p, d});
        forr(i, 1, n + 1)
        {
            if (sze[p][i] < d && st.find(i) != st.end())
                st.erase(i);
        }
    }
    for (auto p : quer)
    {
        bool done = false;
        int i = p.f;
        for (auto e : st)
        {
            if (sze[i][e] == p.s)
            {
                done = true;
                break;
            }
        }
        if (!done)
        {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");
    forr(i, 1, n + 1)
    {
        if (st.find(i) != st.end())
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
}