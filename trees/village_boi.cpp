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
vll dp1, dp2;

void dfs(int x, int prev)
{
    lli mi = 1e18 + 10;
    for (auto e : graph[x])
    {
        if (e != prev)
        {
            dfs(e, x);
            dp1[x] += min(dp2[e] + 2, dp1[e]);
            mi = min(mi, (dp2[e] + 2) - min(dp2[e] + 2, dp1[e]));
            dp2[x] += min(dp2[e] + 2, dp1[e]);
        }
    }
    dp1[x] += mi;
}

int main()
{
    int n;
    scd(n);
    graph = vvi(n + 1);

    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dp1 = dp2 = vll(n + 1);
    dfs(1, 0);
    printf("%lld\n", dp1[1]);
    queue<pair<bool, pii>> q;
    q.push(mp(true, mp(1, 0)));
    vi vec(n + 1);
    forr(i, 1, n + 1) vec[i] = i;
    while (q.size())
    {
        auto p = q.front();
        q.pop();
        if (!p.f)
        {
            swap(vec[p.s.f], vec[p.s.s]);
            for (auto e : graph[p.s.f])
            {
                if (e != p.s.s)
                {
                    if (dp2[e] + 2 <= dp1[e])
                    {
                        q.push(mp(false, mp(e, p.s.f)));
                    }
                    else
                    {
                        q.push(mp(true, mp(e, p.s.f)));
                    }
                }
            }
        }
        if (p.f)
        {
            lli mi = 1e18 + 10;
            int mid = 0;
            int mide = 0;
            vector<pair<bool, pii>> curr;
            bool done = false;
            int i = 0;
            for (auto e : graph[p.s.f])
            {
                if (e != p.s.s)
                {
                    if (dp2[e] + 2 <= dp1[e])
                    {
                        done = true;
                        curr.pb(mp(false, mp(e, p.s.f)));
                    }
                    else
                    {
                        curr.pb(mp(true, mp(e, p.s.f)));
                        if (dp2[e] + 2 - dp1[e] < mi)
                        {
                            mi = dp2[e] + 2 - dp1[e];
                            mid = i;
                            mide = e;
                        }
                    }
                    i++;
                }
            }
            if (!done)
            {
                curr[mid] = mp(false, mp(mide, p.s.f));
            }
            for (auto e : curr)
            {
                q.push(e);
            }
        }
    }
    forr(i, 1, n + 1)
        printf("%d ", vec[i]);
}