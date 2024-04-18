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
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
    int n;
    scd(n);
    vii vec(n + 2);
    scd(vec[0].f);
    scd(vec[0].s);
    scd(vec[n + 1].f);
    scd(vec[n + 1].s);
    forr(i, 1, n + 1)
    {
        scd(vec[i].f);
        scd(vec[i].s);
    }
    map<int, pair<int, vi>> xcoor;
    map<int, pair<int, vi>> ycoor;
    frange(i, n + 2)
    {
        int x = vec[i].f;
        int y = vec[i].s;
        xcoor[x].s.pb(i);
        xcoor[x].f++;
        ycoor[y].s.pb(i);
        ycoor[y].f++;
    }
    vvi graph(n + 2);
    frange(i, n + 2)
    {
        int x = vec[i].f;
        int y = vec[i].s;
        auto val = xcoor[x];
        frange(j, val.f)
        {
            if (val.s[j] == i)
                continue;
            graph[i].pb(val.s[j]);
            // graph[val.s[j]].pb(i);
        }
        // xcoor[x].f = 0;
        val = ycoor[y];
        frange(j, val.f)
        {
            if (val.s[j] == i)
                continue;
            graph[i].pb(val.s[j]);
            // graph[val.s[j]].pb(i);
        }
        // ycoor[y].f = 0;
    }
    // frange(i, n + 2)
    // {
    //     printf("%d: ", i);
    //     for (auto e : graph[i])
    //     {
    //         printf("%d ", e);
    //     }
    //     printf("\n");
    // }
    queue<pii> q;
    vb vis(n + 2);
    q.push({0, 0});
    while (q.size())
    {
        pii v = q.front();
        q.pop();
        if (vis[v.f])
            continue;
        vis[v.f] = true;
        if (v.f == n + 1)
        {
            printf("%d", v.s - 1);
            return 0;
        }
        for (auto e : graph[v.f])
        {

            q.push(mp(e, v.s + 1));
        }
    }
    printf("-1\n");
}