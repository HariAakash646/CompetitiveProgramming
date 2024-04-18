#include <bits/stdc++.h>

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

int main()
{
    int n, m, q;
    scd(n);
    scd(m);
    scd(q);
    vii edges(m + 1);
    vvi graph(n + 1);

    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        edges[i + 1] = {a, b};
        graph[a].pb(b);
        graph[b].pb(a);
    }

    vi dist(n + 1, 1e9);
    queue<pii> qu;
    qu.push(mp(1, 0));

    while (qu.size())
    {
        auto p = qu.front();
        qu.pop();
        if (dist[p.f] <= p.s)
        {
            continue;
        }

        dist[p.f] = p.s;

        for (auto e : graph[p.f])
        {
            qu.push(mp(e, p.s + 1));
        }
    }

    vi quer(q);
    frange(i, q)
    {
        scd(quer[i]);
        int v = quer[i];
        int a = edges[v].f;
        int b = edges[v].s;
        graph[a].erase(find(all(graph[a]), b));
        graph[b].erase(find(all(graph[b]), a));
        vi dist1(n + 1, 1e9);
        qu.push(mp(1, 0));

        while (qu.size())
        {
            auto p = qu.front();
            qu.pop();
            if (dist1[p.f] <= p.s)
            {
                continue;
            }

            dist1[p.f] = p.s;

            for (auto e : graph[p.f])
            {
                qu.push(mp(e, p.s + 1));
            }
        }
        int c = 0;
        forr(i, 1, n + 1)
        {
            if (dist[i] < dist1[i])
                c++;
        }
        printf("%d\n", c);
    }
}