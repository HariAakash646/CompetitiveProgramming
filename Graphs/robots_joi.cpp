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

struct Vert
{
    int id, c;
    lli val;
};

lli inf = 1e18;

int main()
{
    int n, m;
    scd(n);
    scd(m);
    vector<vector<Vert>> graph(n + 1);

    frange(i, m)
    {
        int a, b, c;
        lli v;
        scd(a);
        scd(b);
        scd(c);
        sclld(v);

        graph[a].id = b;
        graph[a].c = c;
        graph[a].val = v;

        graph[b].id = a;
        graph[b].c = c;
        graph[b].val = v;
    }

    forr(i, 1, n + 1)
    {
        map<int, lli> cost;
        for (auto e : graph[i])
        {
            cost[e.c] += e.val;
        }
        for (auto e : graph[i])
        {
            graph[e.id].val = min(graph[e.id].val, cost[e.c] - graph[e.id].val);
        }
    }

    vll dist(n + 1, inf);
    priorit_queue<pair<lli, int>> pq;
}