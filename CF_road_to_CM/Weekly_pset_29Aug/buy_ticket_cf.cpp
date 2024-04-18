#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
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

int main()
{
    int n, m;
    scd(n);
    scd(m);
    vector<vector<pair<int, lli>>> graph(n + 1);

    frange(i, m)
    {
        int a, b;
        lli c;
        scd(a);
        scd(b);
        sclld(c);
        graph[a].pb(mp(b, 2 * c));
        graph[b].pb(mp(a, 2 * c));
    }

    forr(i, 1, n + 1)
    {
        lli c;
        sclld(c);
        graph[0].pb(mp(i, c));
    }

    priority_queue<pair<lli, int>> pq;
    vll dist(n + 1, 1e18);
    dist[0] = 0;

    vb vis(n + 1);
    pq.push(mp(0, 0));

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
                pq.push(mp(-dist[e.f], e.f));
            }
        }
    }
    forr(i, 1, n + 1) printf("%lld ", dist[i]);
}