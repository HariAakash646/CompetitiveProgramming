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
        vi vec(n + 1);
        forr(i, 1, n + 1) scd(vec[i]);

        vvi graph(n + 1);
        frange(i, m)
        {
            int a, b;
            scd(a);
            scd(b);
            graph[a].pb(b);
            graph[b].pb(a);
        }

        vb vis(n + 1);
        int ma = 0;
        forr(i, 1, n + 1)
        {
            if (vis[i])
            {
                continue;
            }
            vb tmp(n + 1);
            int c = 0;
            priority_queue<pii> pq;
            pq.push({-vec[i], i});

            while (pq.size())
            {
                auto p = pq.top();
                pq.pop();
                if (c < -p.f)
                    break;
                if (tmp[p.s])
                    continue;
                tmp[p.s] = true;
                vis[p.s] = true;
                c++;
                for (auto e : graph[p.s])
                    pq.push(mp(-vec[e], e));
            }
            ma = max(ma, c);
        }

        if (ma == n)
            printf("YES\n");
        else
            printf("NO\n");
    }
}