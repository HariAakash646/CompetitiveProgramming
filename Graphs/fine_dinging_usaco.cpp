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

int inf = 1e9 + 10;

int main()
{
    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);
    int n, m, k;
    scd(n);
    scd(m);
    scd(k);
    vector<vii> graph(n + 1);
    frange(i, m)
    {
        int a, b, c;
        scd(a);
        scd(b);
        scd(c);
        graph[a].pb({b, c});
        graph[b].pb({a, c});
    }
    vi dist(n + 1, inf);
    dist[n] = 0;
    priority_queue<pii> pq;
    pq.push({0, n});
    vb vis(n + 1);
    while (pq.size())
    {
        auto p = pq.top();
        pq.pop();
        if (vis[p.s])
            continue;
        vis[p.s] = true;

        for (auto e : graph[p.s])
        {
            if (dist[p.s] + e.s < dist[e.f])
            {
                dist[e.f] = dist[p.s] + e.s;
                pq.push({-dist[e.f], e.f});
            }
        }
    }

    vi taste(n + 1, -1);
    vi dist2(n + 1, inf);

    priority_queue<pair<pii, int>> pq2;

    frange(_, k)
    {
        int x, t;
        scd(x);
        scd(t);
        taste[x] = max(taste[x], t);
    }
    forr(i, 1, n + 1)
    {
        if (taste[i] != -1)
        {
            dist2[i] = dist[i];
            pq2.push(mp(mp(-dist2[i], i), taste[i]));
        }
    }
    vis = vb(n + 1);
    while (pq2.size())
    {
        auto p = pq2.top();
        pq2.pop();
        if (vis[p.f.s])
            continue;
        vis[p.f.s] = true;

        for (auto e : graph[p.f.s])
        {
            if (dist2[p.f.s] + e.s < dist2[e.f] && dist2[p.f.s] + e.s <= dist[e.f] + p.s)
            {
                dist2[e.f] = dist2[p.f.s] + e.s;
                pq2.push(mp(mp(-dist2[e.f], e.f), p.s));
            }
        }
    }
    forr(i, 1, n)
    {
        if (dist2[i] != inf)
            printf("1\n");
        else
            printf("0\n");
    }
}