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
    int n, m;
    scd(n);
    scd(m);
    vvi graph(n + 1);
    vi indeg(n + 1);
    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[b].pb(a);
        indeg[a]++;
    }
    vi topo;
    priority_queue<int> pq;
    forr(i, 1, n + 1)
    {
        if (indeg[i] == 0)
            pq.push(i);
    }
    while (pq.size())
    {
        auto p = pq.top();
        pq.pop();
        topo.pb(p);
        for (auto e : graph[p])
        {
            indeg[e]--;
            if (indeg[e] == 0)
                pq.push(e);
        }
    }
    reverse(all(topo));
    for (auto e : topo)
        printf("%d ", e);
}