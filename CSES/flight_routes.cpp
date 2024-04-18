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

lli inf = 1e18;

int main()
{
    int n, m, k;
    scd(n);
    scd(m);
    scd(k);
    vector<vector<pair<int, lli>>> graph(n + 1);

    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        lli c;
        sclld(c);
        graph[a].pb({b, c});
    }
    vector<vll> dist(n + 1, vll(k + 1, inf));
    priority_queue<pair<lli, int>> pq;
    vi cnt(n + 1);
    dist[1][0] = 0;
    pq.push({0, 1});

    while (pq.size())
    {
        auto p = pq.top();
        pq.pop();
        if (cnt[p.s] >= k)
        {
            continue;
        }
        cnt[p.s]++;
        for (auto e : graph[p.s])
        {
            frange(i, k)
            {
                if (-p.f + e.s < dist[e.f][i])
                {
                    for (int j = k - 1; j >= i; j--)
                    {
                        dist[e.f][j + 1] = dist[e.f][j];
                    }
                    dist[e.f][i] = -p.f + e.s;
                    pq.push({-dist[e.f][i], e.f});
                    break;
                }
            }
        }
    }

    frange(i, k)
    {
        printf("%lld ", dist[n][i]);
    }
}