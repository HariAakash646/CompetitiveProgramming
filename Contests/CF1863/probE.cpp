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
    int t;
    scd(t);

    frange(_, t)
    {
        int n, m;
        scd(n);
        scd(m);
        lli k;
        sclld(k);

        vll hr(n + 1);
        forr(i, 1, n + 1)
        {
            sclld(hr[i]);
        }
        vvi graph(n + 1), ing(n + 1);
        vi indeg(n + 1);
        frange(i, m)
        {
            int a, b;
            scd(a);
            scd(b);
            graph[a].pb(b);
            ing[b].pb(a);
            indeg[b]++;
        }
        vi topo;
        queue<int> q;
        vector<pair<lli, int>> st;
        forr(i, 1, n + 1)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
                st.pb(mp(hr[i], i));
            }
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
        lli mi = 1e18;
        lli ma = 0;
        vll dp(n + 1);
        for (auto x : topo)
        {
            lli mv = 0;
            for (auto e : ing[x])
            {
                mv = max(mv, dp[e]);
            }
            lli h = mv % k;
            if (hr[x] >= h)
            {
                dp[x] = mv + (hr[x] - h);
            }
            else
            {
                dp[x] = mv + hr[x] + k - h;
            }
            mi = min(mi, dp[x]);
            ma = max(ma, dp[x]);
        }
        lli ans = ma - mi;
        sort(all(st));
        forr(i, 0, st.size() - 1)
        {
            auto p = st[i];
            mi = st[i + 1].f;
            queue<int> q;
            q.push(p.s);
            dp[p.s] = p.f + k;
            while (q.size())
            {
                auto x = q.front();
                q.pop();
                for (auto e : graph[x])
                {
                    lli h = dp[x] % k;
                    lli og = dp[e];
                    if (hr[e] >= h)
                        dp[e] = max(dp[e], dp[x] + (hr[e] - h));
                    else
                        dp[e] = max(dp[e], dp[x] + hr[e] + k - h);
                    if (og != dp[e])
                        q.push(e);
                }
                ma = max(ma, dp[x]);
            }
            ans = min(ma - mi, ans);
        }
        printf("%lld\n", ans);
    }
}