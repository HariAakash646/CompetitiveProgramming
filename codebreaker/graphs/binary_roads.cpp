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
    int n, e;
    scd(n);
    scd(e);

    vector<vii> graph(n);
    frange(i, e)
    {
        int a, b, v;
        scd(a);
        scd(b);
        scd(v);
        graph[a].pb({b, v});
        graph[b].pb({a, v});
    }
    vector<vb> vis(n, vb(2));
    queue<pair<pii, int>> q;
    q.push(mp(mp(0, 0), 0));
    q.push(mp(mp(0, 1), 0));

    while (q.size())
    {
        auto p = q.front();
        q.pop();
        if (p.f.f == n - 1)
        {
            printf("%d", p.s);
            return 0;
        }
        if (vis[p.f.f][p.f.s])
            continue;
        vis[p.f.f][p.f.s] = true;
        for (auto e : graph[p.f.f])
        {
            if (e.s == p.f.s)
            {
                q.push(mp(mp(e.f, !p.f.s), p.s + 1));
            }
        }
    }
    printf("-1");
}