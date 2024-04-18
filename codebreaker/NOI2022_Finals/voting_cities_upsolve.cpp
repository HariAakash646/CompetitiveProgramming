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
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

lli inf = 1e18;

int main()
{
    int n, e, k;
    scd(n);
    scd(e);
    scd(k);

    vector<vector<vector<pair<pii, lli>>>> graph(n + 1, vector<vector<pair<pii, lli>>>(32));
    frange(i, k)
    {
        int a;
        scd(a);
        a++;
        graph[0][0].pb(mp(mp(a, 0), 0));
    }

    frange(_, e)
    {
        int a, b;
        lli c;
        scd(a);
        scd(b);
        sclld(c);
        a++;
        b++;
        frange(i, 32)
        {
            graph[b][i].pb(mp(mp(a, i), c));
            frange(j, 5)
            {
                if (!(i & (1 << j)))
                {
                    graph[b][i].pb(mp(mp(a, i ^ (1 << j)), c * (10 - j - 1) / 10));
                }
            }
        }
    }

    vector<vector<lli>> dist(n + 1, vll(32, inf));
    priority_queue<pair<lli, pii>> pq;
    vector<vb> vis(n + 1, vb(32));
    dist[0][0] = 0;
    pq.push(mp(0, mp(0, 0)));

    while (pq.size())
    {
        auto p = pq.top();
        pq.pop();
        if (vis[p.s.f][p.s.s])
            continue;
        vis[p.s.f][p.s.s] = true;
        for (auto e : graph[p.s.f][p.s.s])
        {
            if (-p.f + e.s < dist[e.f.f][e.f.s])
            {
                dist[e.f.f][e.f.s] = -p.f + e.s;
                pq.push(mp(-dist[e.f.f][e.f.s], mp(e.f.f, e.f.s)));
            }
        }
    }
    int q;
    scd(q);
    frange(_, q)
    {
        int a;
        scd(a);
        a++;
        vi vp(5);
        frange(i, 5) sclld(vp[i]);
        lli mi = inf;
        frange(i, 32)
        {
            lli curr = 0;
            bool skip = false;
            frange(j, 5)
            {
                if (i & (1 << j))
                {
                    if (vp[j] == -1)
                    {
                        skip = true;
                        break;
                    }
                    curr += vp[j];
                }
            }
            if (skip)
                continue;
            mi = min(mi, dist[a][i] + curr);
        }
        if (mi >= inf)
            printf("-1\n");
        else
            printf("%lld\n", mi);
    }
}