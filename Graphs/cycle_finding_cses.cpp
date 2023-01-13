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

lli inf = 1e13;

int main()
{
    int n, m;
    scd(n);
    scd(m);
    vector<tuple<int, int, int>> graph(n + 1);
    vector<lli> cost(n + 1, inf);
    vi prev(n + 1, -1);
    cost[1] = 0;
    int a, b, c;
    frange(i, m)
    {
        scd(a);
        scd(b);
        scd(c);
        graph.pb({a, b, c});
    }
    int cyc = -1;
    frange(i, n)
    {
        for (auto e : graph)
        {
            tie(a, b, c) = e;
            if (i == n - 1 && cost[a] + c < cost[b])
            {
                cyc = b;
            }
            if (cost[a] + c < cost[b])
                prev[b] = a;
            cost[b] = min(cost[b], cost[a] + c);
        }
    }
    if (cyc != -1)
    {
        printf("YES\n");
        frange(i, n)
        {
            cyc = prev[cyc];
        }
        vi cycle;
        for (int v = cyc;; v = prev[v])
        {
            cycle.pb(v);
            if (v == cyc && cycle.size() > 1)
            {
                break;
            }
        }
        reverse(all(cycle));
        for (auto e : cycle)
        {
            printf("%d ", e);
        }
    }
    else
    {
        printf("NO");
    }
}