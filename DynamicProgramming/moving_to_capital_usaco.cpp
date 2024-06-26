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

vvi graph;
vi dist;
vi dp;
int inf = 1e9;

int main()
{
    int t;
    scd(t);

    frange(_, t)
    {
        int n, m;
        scd(n);
        scd(m);
        graph = vvi(n + 1);
        dist = dp = vi(n + 1, inf);
        frange(i, m)
        {
            int a, b;
            scd(a);
            scd(b);
            graph[a].pb(b);
        }
        queue<pii> q;
        q.push({1, 0});
        vb vis(n + 1);
        while (q.size())
        {
            auto p = q.front();
            q.pop();
            if (vis[p.f])
                continue;
            vis[p.f] = true;
            dist[p.f] = min(dist[p.f], p.s);
            for (auto e : graph[p.f])
            {
                q.push({e, p.s + 1});
            }
        }
        vii dvec(n);
        frange(i, n) dvec[i] = {dist[i + 1], i + 1};
        sort(all(dvec), greater<>());

        for (auto p : dvec)
        {
            dp[p.s] = dist[p.s];
            for (auto e : graph[p.s])
            {
                if (dist[e] <= p.f)
                    dp[p.s] = min(dp[p.s], dist[e]);
                else
                    dp[p.s] = min(dp[p.s], dp[e]);
            }
        }
        forr(i, 1, n + 1) printf("%d ", dp[i]);
        printf("\n");
    }
}