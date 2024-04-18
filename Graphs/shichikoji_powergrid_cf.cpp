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

vll cost;
vector<pair<lli, int>> mi;
vi disset, sze;

int findf(int x)
{
    while (x != disset[x])
    {
        x = disset[x];
    }
    return x;
}

bool unionf(int x, int y)
{
    x = findf(x);
    y = findf(y);
    if (x == y)
        return false;
    if (sze[x] < sze[y])
    {
        swap(x, y);
    }
    disset[y] = x;
    sze[x] = max(sze[x], sze[y] + 1);
    mi[x] = min(mi[x], mi[y]);
    return true;
}

int main()
{
    int n;
    scd(n);
    vii pos(n);
    frange(i, n)
    {
        scd(pos[i].f);
        scd(pos[i].s);
    }

    vll vec(n);
    cost = vll(n);
    mi = vector<pair<lli, int>>(n);
    frange(i, n)
    {
        sclld(cost[i]);
        mi[i] = {cost[i], i};
    }
    frange(i, n) sclld(vec[i]);

    vector<pair<lli, pii>> edges;

    frange(i, n)
    {
        forr(j, i + 1, n)
        {
            edges.pb({(vec[i] + vec[j]) * (abs(pos[i].f - pos[j].f) + abs(pos[i].s - pos[j].s)), mp(i, j)});
        }
    }
    sort(all(edges));
    disset = sze = vi(n, 1);
    frange(i, n) disset[i] = i;
    lli tot = 0;
    lli ans = 0;
    vii con, conout;
    vi pow;
    frange(i, n)
    {
        ans += cost[i];
        pow.pb(i);
    }

    for (auto p : edges)
    {
        if (unionf(p.s.f, p.s.s))
        {
            tot += p.f;
            lli v = tot;
            vb vis(n);
            con.pb({p.s.f, p.s.s});
            vi tmp;
            frange(i, n)
            {
                int x = findf(i);
                if (vis[x])
                    continue;
                vis[x] = true;
                v += mi[x].f;
                tmp.pb(mi[x].s);
            }
            if (v < ans)
            {
                ans = v;
                conout = con;
                pow = tmp;
            }
        }
    }
    printf("%lld\n", ans);
    printf("%d\n", pow.size());
    for (auto e : pow)
        printf("%d ", e + 1);
    printf("\n%d\n", conout.size());
    for (auto p : conout)
    {
        printf("%d %d\n", p.f + 1, p.s + 1);
    }
}