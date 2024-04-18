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
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

lli inf = 1e18;

int main()
{
    int n, e, q;
    scd(n);
    scd(e);
    scd(q);
    vector<vector<pair<int, lli>>> graph(n);

    frange(i, e)
    {
        int a, b;
        lli w;
        scd(a);
        scd(b);
        sclld(w);
        graph[a].pb({b, w});
        graph[b].pb({a, w});
    }
    vvll dist(n, vll(n, 1e18));

    frange(i, n)
    {
        priority_queue<pair<lli, int>> pq;
        vb vis(n);
        dist[i][i] = 0;
        pq.push({0, i});

        while (pq.size())
        {
            pii p = pq.top();
            pq.pop();
            if (vis[p.s])
                continue;
            vis[p.s] = true;
            for (auto e : graph[p.s])
            {
                if (max(e.s, dist[i][p.s]) < dist[i][e.f])
                {
                    dist[i][e.f] = max(e.s, dist[i][p.s]);
                    pq.push({-dist[i][e.f], e.f});
                }
            }
        }
    }

    frange(i, q)
    {
        int a, b;
        scd(a);
        scd(b);
        printf("%lld\n", dist[a][b]);
    }
}