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

int main()
{
    int n, m;
    scd(n);
    scd(m);
    vvi graph(n + 1);
    vii edges(m);
    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
        edges[i] = {a, b};
    }
    int mi = 1e8;
    forr(i, 1, n + 1)
    {
        queue<pii> q;
        vb vis(n + 1);
        q.push({i, 0});
        vi dist(n + 1, 1e8);
        while (q.size())
        {
            auto p = q.front();
            q.pop();

            if (vis[p.f])
                continue;
            dist[p.f] = p.s;
            vis[p.f] = true;
            for (auto x : graph[p.f])
            {
                if (!vis[x])
                    q.push({x, p.s + 1});
                else if (dist[x] >= dist[p.f])
                    mi = min(mi, dist[p.f] + dist[x] + 1);
            }
        }
        // for (auto p : edges)
        // {
        //     if (p.f != i && p.s != i)
        //         mi = min(mi, dist[p.f] + dist[p.s] + 1);
        // }
    }
    if (mi >= 1e8)
    {
        printf("-1");
    }
    else
        printf("%d", mi);
}