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

int inf = 1e9;

vb vis;
vvi graph;

void dfs(int x)
{
    if (vis[x])
        return;
    vis[x] = true;
    for (auto e : graph[x])
    {
        dfs(e);
    }
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vii vec(n);
        frange(i, n)
        {
            scd(vec[i].f);
            scd(vec[i].s);
        }
        sort(all(vec));
        graph = vvi(n);
        vi indeg(n);
        frange(i, n)
        {
            forr(j, i + 1, n)
            {
                if (vec[i].s >= vec[j].f)
                {
                    graph[i].pb(j);
                    indeg[j]++;
                }
            }
        }
        vi indeg2 = indeg;
        vi topo;
        queue<int> q;
        frange(i, n)
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

        if (topo.size() != n)
            printf("Not n\n");
        vi dp1(n, inf), dp2(n, inf), dp3(n);
        dp1[n - 1] = inf;
        dp2[n - 1] = 0;
        dp3[n - 1] = 1;
        vi idx(n);
        vis = vb(n);
        frange(i, n)
        {
            idx[topo[i]] = i;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            int x = topo[i];
            int tot = 0;
            dp3[i] = 1;
            for (auto e : graph[x])
            {
                tot += dp3[idx[e]];
                dp3[i] += min(dp1[idx[e]], dp3[idx[e]]);
            }
            dp2[i] = tot;
            for (auto e : graph[x])
            {
                dp1[i] = min(dp1[i], tot + dp2[idx[e]] - dp3[idx[e]]);
            }
            // if (indeg2[x] == 0)
            //     dp2[i] = inf;
        }
        int tot = 0;
        frange(i, n)
        {
            if (!vis[i])
            {
                dfs(i);
                tot += min({dp1[i], dp3[i]});
            }
        }
        printf("%d\n", tot);
    }
}