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
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int n, m;
vector<vector<pair<int, lli>>> oggraph;

lli inf = 1e16;

int main()
{
    scd(n);
    scd(m);
    oggraph = vector<vector<pair<int, lli>>>(n + 1);
    frange(i, m)
    {
        int a, b, w;
        scd(a);
        scd(b);
        scd(w);
        oggraph[a].pb({b, w});
        oggraph[b].pb({a, w});
    }
    lli mi = inf;
    vector<vector<pair<int, lli>>> graph = oggraph;
    forr(i, 1, n + 1)
    {
        vll dist(n + 1, inf);
        priority_queue<pair<pair<lli, int>, int>> pq;
        pq.push({{0, i}, -1});
        vb processed(n + 1, false);
        while (pq.size())
        {
            pii p = pq.top().f;
            int prev = pq.top().s;
            pq.pop();
            if (processed[p.s])
                continue;
            processed[p.s] = true;

            frange(j, graph[p.s].size())
            {
                auto e = graph[p.s][j];
                if (e.f == prev && e.f == i)
                    continue;
                if (dist[e.f] > e.s - p.f)
                {
                    dist[e.f] = e.s - p.f;
                    pq.push({{-dist[e.f], e.f}, p.s});
                }
            }
        }
        graph = oggraph;
        mi = min(mi, dist[i]);
    }
    printf("%lld", mi);
}