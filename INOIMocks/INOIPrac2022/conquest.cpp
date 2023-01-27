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

int main()
{
    int n, q;
    scd(n);
    scd(q);
    vi vec(n + 1);
    forr(i, 1, n + 1)
    {
        scd(vec[i]);
    }
    vvi graph(n + 1);
    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    frange(i, q)
    {
        int a, b;
        scd(a);
        scd(b);
        priority_queue<pair<lli, pair<int, int>>> pq;
        pq.push({vec[a], {a, 0}});
        pq.push({0, {a, 1}});
        vector<vb> processed(2, vb(n + 1, false));
        vector<vector<lli>> dist(2, vector<lli>(n + 1, 0));
        dist[0][a] = vec[a];
        dist[1][a] = 0;

        while (pq.size())
        {
            auto p = pq.top();
            pq.pop();
            if (processed[p.s.s][p.s.f])
                continue;
            processed[p.s.s][p.s.f] = true;
            for (auto e : graph[p.s.f])
            {
                dist[!p.s.s][e] = dist[p.s.s][p.s.f] + vec[e] * p.s.s;
                pq.push({dist[!p.s.s][e], {e, !p.s.s}});
            }
        }
        printf("%lld\n", max(dist[0][b], dist[1][b]));
    }
}