#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
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
    int n;
    scd(n);

    vll vec(n + 1);

    forr(i, 1, n + 1)
    {
        sclld(vec[i]);
    }
    vvi graph(n + 1), ing(n + 1);
    vi indeg(n + 1);

    forr(i, 1, n + 1)
    {
        int b;
        scd(b);
        if (b != -1)
        {
            graph[i].pb(b);
            ing[b].pb(i);
            indeg[b]++;
        }
    }

    queue<int> q;
    vi topo;

    forr(i, 1, n + 1)
    {
        if (indeg[i] == 0)
            q.push(i);
    }

    while (q.size())
    {
        auto x = q.front();
        q.pop();
        topo.pb(x);
        for (auto e : graph[x])
        {
            indeg[e]--;
            if (indeg[e] == 0)
                q.push(e);
        }
    }
    lli ans = 0;
    vvi ng(n + 1);
    indeg = vi(n + 1);
    for (auto e : topo)
    {
        for (auto x : ing[e])
        {
            if (vec[x] > 0)
            {
                ng[x].pb(e);
                vec[e] += vec[x];
                indeg[e]++;
            }
            else
            {
                ng[e].pb(x);
                indeg[x]++;
            }
        }
        ans += vec[e];
    }
    printf("%lld\n", ans);
    topo = vi();

    forr(i, 1, n + 1)
    {
        if (indeg[i] == 0)
            q.push(i);
    }

    while (q.size())
    {
        auto p = q.front();
        q.pop();
        topo.pb(p);
        for (auto e : ng[p])
        {
            indeg[e]--;
            if (indeg[e] == 0)
                q.push(e);
        }
    }
    for (auto e : topo)
        printf("%d ", e);
}