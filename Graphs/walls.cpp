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
    int m, n, l;
    scd(m);
    scd(n);
    scd(l);
    vi vec(l);
    frange(i, l) scd(vec[i]);
    vector<seti> graph(n + 1);
    vvi regions(m);
    frange(i, m)
    {
        int c;
        scd(c);
        regions[i] = vi(c);
        int prev = 0;
        frange(j, c)
        {
            int a;
            scd(a);
            regions[i][j] = a;

            if (prev)
            {
                graph[prev].insert(a);
                graph[a].insert(prev);
            }
            prev = a;
        }
        graph[regions[i][c - 1]].insert(regions[i][0]);
        graph[regions[i][0]].insert(regions[i][c - 1]);
    }

    vvi dist(l, vi(n + 1, 1e9));

    frange(i, l)
    {
        queue<pii> q;
        q.push({vec[i], 0});
        vb vis(n + 1);
        while (q.size())
        {
            auto p = q.front();
            q.pop();
            if (vis[p.f])
                continue;
            vis[p.f] = true;
            dist[i][p.f] = p.s;
            for (auto e : graph[p.f])
            {
                q.push({e, p.s + 1});
            }
        }
    }
    int mi = 1e9;
    int mid = 0;
    frange(i, m)
    {
        int tot = 0;
        frange(j, l)
        {
            int mv = 1e9;
            for (auto e : regions[i])
            {
                mv = min(mv, dist[j][e]);
            }
            tot += mv;
        }
        if (tot <= mi)
        {
            mi = tot;
            mid = i + 1;
        }
    }
    printf("%d\n%d", mi, mid);
}