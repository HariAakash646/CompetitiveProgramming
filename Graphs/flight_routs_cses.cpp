// Not working

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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

lli inf = 1e14;

int main()
{
    int n, m, k;
    scd(n);
    scd(m);
    scd(k);
    vector<vector<pii>> graph(n + 1);
    vector<multiset<lli>> dist(n + 1);
    dist[1] = {0};
    int a, b, c;
    frange(i, m)
    {
        scd(a);
        scd(b);
        scd(c);
        graph[a].pb({b, c});
    }
    priority_queue<pair<lli, int>> pq;
    pq.push({0, 1});
    int idx = 0;
    bool out = false;
    while (pq.size())
    {
        auto p = pq.top();
        pq.pop();
        for (auto e : graph[p.s])
        {
            int nx = e.f;
            int w = e.s;
            for (auto d : dist[p.s])
            {
                dist[nx].insert(d + w);
                if (dist[nx].size() > k)
                    dist[nx].erase(prev(dist[nx].end()));

                idx++;
            }
            pq.push(pair<lli, int>{-(*dist[nx].begin()), nx});
        }
    }
    for (auto e : dist[n])
    {
        printf("%lld ", e);
    }
}