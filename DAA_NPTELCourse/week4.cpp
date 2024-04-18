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

int inf = 1e9 + 10;

int main()
{
    int n;
    scd(n);
    vector<pair<pii, int>> vec;
    frange(_, n)
    {
        int a, b, c;
        scd(a);
        scd(b);
        scd(c);
        vec.pb({{a, b}, c});
    }
    int mi = inf;
    for (auto e : vec)
    {
        vector<vii> graph(301);
        for (auto p : vec)
        {
            if (p != e)
            {
                graph[p.f.f].pb({p.f.s, p.s});
                graph[p.f.s].pb({p.f.f, p.s});
            }
        }
        vi dist(301, inf);
        dist[e.f.f] = 0;
        priority_queue<pii> pq;
        pq.push({0, e.f.f});
        vb proc(301, false);
        while (pq.size())
        {
            auto p = pq.top();
            pq.pop();
            if (proc[p.s])
                continue;
            proc[p.s] = true;
            for (auto l : graph[p.s])
            {
                if (dist[l.f] > dist[p.s] + l.s)
                {
                    dist[l.f] = dist[p.s] + l.s;
                    pq.push({-dist[l.f], l.f});
                }
            }
        }
        mi = min(dist[e.f.s] + e.s, mi);
    }

    printf("%d", mi);
}