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
    vector<vector<pair<pii, int>>> graph(n + 1);
    vector<map<int, mseti>> cnt(n + 1);

    frange(i, m)
    {
        int a, b, c, p;
        scd(a);
        scd(b);
        scd(c);
        scd(p);
        graph[a].pb(mp(mp(b, p), c));
        graph[b].pb(mp(mp(a, p), c));
        cnt[a][c].insert(p);
        cnt[b][c].insert(p);
    }
    vector<map<int, lli>> val(n + 1);

    forr(i, 1, n + 1)
    {
        for (auto p : cnt[i])
        {
            int x = p.f;
            int c = p.s.size();
            auto it = p.s.begin();
            frange(j, c - 1)
            {
                val[i][x] += *it;
                it++;
            }
            // printf("%lld ", val[i][x]);
        }
        // printf("\n");
    }

    vll dist(n + 1, 1e18);
    dist[1] = 0;
    priority_queue<pair<lli, int>> pq;
    vb vis(n + 1);
    pq.push(mp(0, 1));

    while (pq.size())
    {
        auto p = pq.top();
        pq.pop();
        if (vis[p.s])
            continue;
        vis[p.s] = true;

        for (auto e : graph[p.s])
        {
            if (dist[p.s] + min(lli(e.f.s), val[p.s][e.s]) < dist[e.f.f])
            {
                dist[e.f.f] = dist[p.s] + min(lli(e.f.s), val[p.s][e.s]);
                pq.push(mp(-dist[e.f.f], e.f.f));
            }
        }
    }
    if (dist[n] == 1e18)
        printf("-1");
    else
        printf("%lld", dist[n]);
}