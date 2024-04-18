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
typedef vector<bool> vb;
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

int inf = 1e9 + 10;

int main()
{
    int c, k;
    scd(c);
    scd(k);
    vector<vii> graph(c + 1);
    int a, b, w;
    frange(i, k)
    {
        scd(a);
        scd(b);
        scd(w);
        graph[a].pb({b, w});
        graph[b].pb({a, w});
    }
    int maxd = 0;
    forr(i, 1, c + 1)
    {
        vi dist(c + 1, inf);
        vb processed(c + 1, false);
        dist[i] = 0;
        priority_queue<pii> pq;
        pq.push({0, i});
        while (pq.size())
        {
            int ele, w;
            tie(w, ele) = pq.top();
            pq.pop();
            if (processed[ele])
                continue;
            processed[ele] = true;
            for (auto e : graph[ele])
            {
                if (dist[ele] + e.s < dist[e.f])
                {
                    dist[e.f] = dist[ele] + e.s;
                    pq.push({-dist[e.f], e.f});
                }
            }
        }
        int currm = 0;
        for (auto e : dist)
        {
            if (e != inf)
            {
                currm = max(currm, e);
            }
        }
        maxd = max(maxd, currm);
    }
    printf("%d", maxd);
}