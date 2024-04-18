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

int main()
{
    int n, e, k;
    scd(n);
    scd(e);
    scd(k);
    vector<vector<pair<int, lli>>> graph(n + 1);

    vi vec(k);
    frange(i, k) scd(vec[i]);

    frange(i, e)
    {
        int a, b;
        lli c;
        scd(a);
        scd(b);
        sclld(c);
        graph[a].pb({b, c});
    }
    int q;
    scd(q);
    frange(_, q)
    {
        int st;
        scd(st);
        int a;
        frange(i, 5) scd(a);
        vll dist(n + 1, inf);
        priority_queue<pair<lli, int>> pq;
        dist[st] = 0;
        pq.push({0, st});
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
        lli mi = inf;
        for (auto e : vec)
        {
            mi = min(mi, dist[e]);
        }
        if (mi >= inf)
            printf("-1\n");
        else
            printf("%lld\n", mi);
    }
}