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

int mod = 1e9 + 7;

int main()
{
    int n, m;
    scd(n);
    scd(m);
    vector<vii> graph(n + 1);
    frange(i, m)
    {
        int a, b, c;
        scd(a);
        scd(b);
        scd(c);
        graph[a].pb({b, c});
    }
    priority_queue<pair<lli, int>> pq;
    vll dist(n + 1, 1e15);
    vi minf(n + 1, 0);
    vi maxf(n + 1, 0);
    vi cnt(n + 1, 1);
    vb proc(n + 1);
    dist[1] = 0;
    // minf[1] = 1;
    // maxf[1] = 1;
    pq.push({0, 1});
    while (pq.size())
    {
        auto p = pq.top();
        pq.pop();
        if (proc[p.s])
            continue;
        proc[p.s] = true;
        for (auto e : graph[p.s])
        {
            if (dist[p.s] + e.s < dist[e.f])
            {
                dist[e.f] = dist[p.s] + e.s;
                minf[e.f] = minf[p.s] + 1;
                maxf[e.f] = maxf[p.s] + 1;
                cnt[e.f] = cnt[p.s];
                pq.push({-dist[e.f], e.f});
            }
            else if (dist[p.s] + e.s == dist[e.f])
            {
                minf[e.f] = min(minf[e.f], minf[p.s] + 1);
                maxf[e.f] = max(maxf[e.f], maxf[p.s] + 1);
                cnt[e.f] += cnt[p.s];
                cnt[e.f] %= mod;
            }
        }
    }
    printf("%lld %d %d %d", dist[n], cnt[n], minf[n], maxf[n]);
}