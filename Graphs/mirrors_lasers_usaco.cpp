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
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

struct Elem
{
    int curr, dep, dir;
};

int main()
{
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
    int n, xl, yl, xb, yb;
    scd(n);
    scd(xl);
    scd(yl);
    scd(xb);
    scd(yb);

    vii vec(n + 2);
    map<int, vi> xcoor;
    map<int, vi> ycoor;
    vec[0] = {xl, yl};
    xcoor[xl].pb(0);
    ycoor[yl].pb(0);
    vec[n + 1] = {xb, yb};
    xcoor[xb].pb(n + 1);
    ycoor[yb].pb(n + 1);
    forr(i, 1, n + 1)
    {
        scd(vec[i].f);
        scd(vec[i].s);
        xcoor[vec[i].f].pb(i);
        ycoor[vec[i].s].pb(i);
    }
    queue<Elem> q;
    Elem e;
    e.curr = 0;
    e.dep = 0;
    e.dir = 0;
    q.push(e);
    vb vis(n + 2);
    while (q.size())
    {
        auto p = q.front();
        q.pop();
        if (p.curr == n + 1)
        {
            printf("%d", p.dep - 1);
            return 0;
        }
        if (vis[p.curr])
            continue;
        vis[p.curr] = true;

        for (auto x : ycoor[vec[p.curr].s])
        {
            if (!vis[x])
            {
                e.curr = x;
                e.dep = p.dep + 1;
                e.dir = -1;
                q.push(e);
            }
        }
        for (auto x : xcoor[vec[p.curr].f])
        {
            if (!vis[x])
            {
                e.curr = x;
                e.dep = p.dep + 1;
                e.dir = 1;
                q.push(e);
            }
        }
    }
    printf("-1");
}